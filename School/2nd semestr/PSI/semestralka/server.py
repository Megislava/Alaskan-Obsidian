import socket
import threading

threatLock = threading.Lock()

# GLOBAL MESSAGES - SERVER
SERVER_CONFIRMATION = ""
SERVER_MOVE = b"102 MOVE\a\b"
SERVER_TURN_LEFT = b"103 TURN LEFT\a\b"
SERVER_TURN_RIGHT = b"104 TURN RIGHT\a\b"
SERVER_PICK_UP = b"105 GET MESSAGE\a\b"
SERVER_LOGOUT = b"106 LOGOUT\a\b"
SERVER_KEY_REQUEST = b"107 KEY REQUEST\a\b"
SERVER_OK = b"200 OK\a\b"
SERVER_LOGIN_FAILED = b"300 LOGIN FAILED\a\b"
SERVER_SYNTAX_ERROR = b"301 SYNTAX ERROR\a\b"
SERVER_LOGIN_ERROR = b"302 LOGIC ERROR\a\b"
SERVER_KEY_OUT_OF_RANGE_ERROR = b"303 KEY OUT OF RANGE\a\b"
# END

serverKeys = [23019,32037,18789,16443,18189]
clientKeys = [32037,29295,13603,29533,21952]

def compareId(conn, serverConfirmHash, clientConfirmHash):
    conn.send(b"" + serverConfirmHash + b"\a\b")
    print(f"[SERVER_CONFIRMATION w/ key {serverConfirmHash}]")
    clientKeyId = conn.recv(1024)[:-2].decode()    
    print("[CLIENT_CONFIRMATION got: {clientKeyId} want: {clientConfirmHash}]")
    if clientKeyId == clientConfirmHash:
        print("[SECRETS MATCHED; SERVER_OK]")
        conn.send(SERVER_OK)
    elif any(char.isalpha() for char in clientKeyId):
        conn.send(SERVER_SYNTAX_ERROR)
        conn.close()
    else:
        conn.send(SERVER_LOGIN_FAILED)
        conn.close()

def auth(conn, usernameHash):
    conn.send(SERVER_KEY_REQUEST)
    keyId = int(conn.recv(1024)[:-2].decode())
    print(f"[KEY ID IS: {keyId}]")
    # parse keyId to get only
    if keyId >= 0 and keyId <= 4:
        serverConfirmHash = (usernameHash + serverKeys[keyId]) % 65536
        clientConfirmHash = (usernameHash + clientConfirmHash[keyId]) % 65536
        compareId(conn, serverConfirmHash, clientConfirmHash)
        print("send-delivered-checked")
    elif keyId > 4 or keyId < 0:
        print(f"[KEY ID, that should not be 0, 1, 2, 3 or 4, IS: {keyId}]")
        conn.send(SERVER_KEY_OUT_OF_RANGE_ERROR)
        conn.close()
    else:
        print(f"[KEY ID, should be non-number, IS: {keyId}]")
        conn.send(SERVER_LOGIN_ERROR)
        conn.close()

def handleObstacle(conn, currentCoords):
    if currentCoords[0] > 0 and currentCoords[1] > 0:
        conn.send(SERVER_TURN_LEFT)
        conn.send(SERVER_MOVE)

def getToCenter(conn):
    coordsVisited = {}
    conn.send(SERVER_TURN_LEFT)
    resp = conn.recv(1024)[:-2].decode()
    coordsVisited[0] = resp.split[2:](" ")
    print(f"[FIRST COORDINATES: {coordsVisited[0][0]}:{coordsVisited[0][1]}]")
    conn.send(SERVER_MOVE)
    resp = conn.recv(1024)[:-2].decode()
    coordsVisited[1] = resp.split[2:](" ")
    print(f"[SECOND COORDINATES: {coordsVisited[1][0]}:{coordsVisited[1][1]}]")
    # turn to center
    if coordsVisited[0][0] < coordsVisited[0][1] and coordsVisited[0][1] > 0:
        conn.send(SERVER_TURN_LEFT)
        conn.send(SERVER_TURN_LEFT)
    elif coordsVisited[0][0] > coordsVisited[0][1] and coordsVisited[0][0] < 0:
        conn.send(SERVER_TURN_LEFT)
        conn.send(SERVER_TURN_LEFT)
    elif coordsVisited[1][0] < coordsVisited[1][1] and coordsVisited[1][1] > 0:
        conn.send(SERVER_TURN_LEFT)
        conn.send(SERVER_TURN_LEFT)
    elif coordsVisited[1][0] > coordsVisited[1][1] and coordsVisited[1][0] < 0:
        conn.send(SERVER_TURN_LEFT)
        conn.send(SERVER_TURN_LEFT)
    currentCoords = coordsVisited[1]
    if currentCoords[0] == 0 or currentCoords[1] == 0:
        while currentCoords != [0,0]:
            # do I have the correct direction?
            # handle obsacles
            conn.send(SERVER_MOVE)
    else:
        while currentCoords != [0,0]:
            print(f"[CURRENT COORDINATES: {currentCoords[0]}:{currentCoords[1]}]")
            conn.send(SERVER_MOVE)
            resp = conn.recv(1024)[:-2].decode()
            if resp.split(" ") == currentCoords:
                currentCoords = handleObstacle(conn, currentCoords)
            else:
                # handle 
                conn.send(SERVER_MOVE)
    # retrieve secret
    conn.send(SERVER_PICK_UP)
    resp = conn.recv(1024)[:-2].decode()
    if resp != "RECHARCHING":
        conn.send(SERVER_LOGOUT)

def handleClient(conn, addr):
    print(f"[CONNECTION FROM {addr}]")
    while True:
        # handle disconnect here
        req = conn.recv(1024)
        if not req:
            print("[DISCONNECTING]")
            threatLock.release()
            break
        print(f"[GOT MESSAGE: {req[:-2].decode()}]")
        username = req[:-2].decode()
        if len(username) <= 20 and username != "RECHARGING":            
            usernameHash += (((ord(char) for char in username)) * 1000) % 65536
            auth(conn, usernameHash)
            print("[AUTH DONE]")
        getToCenter(conn)
            
                

    conn.close()

def startNewThreats(server):
    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handleClient, args=(conn, addr))
        thread.start()

def main():
    host = socket.gethostbyname(socket.gethostname())
    port = 9999

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen()
    threatLock.acquire()
    print(f"[STARTED LISTENING on {host}:{port}]")

    startNewThreats(server)


if __name__ == "__main__":
    main()