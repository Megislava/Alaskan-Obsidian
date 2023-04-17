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

def compareId(conn, send, want):
    conn.send(b"" + send.encode() + b"\a\b")
    clientKeyId = conn.recv(1024)[:-2].decode()
    if clientKeyId == want:
        print("[SECRETS MATCHED]")
    elif any(char.isalpha() for char in clientKeyId):
        conn.send(SERVER_SYNTAX_ERROR)
        conn.close()
    else:
        conn.send(SERVER_LOGIN_FAILED)
        conn.close()

def auth(conn):
    conn.send(SERVER_KEY_REQUEST)
    keyId = int(conn.recv(1024)[:-2].decode())
    print(f"[KEY ID IS: {keyId}]")
    # parse keyId to get only
    if keyId == 0:
        compareId(conn, "23019", "32037")
        print("send-delivered-checked")
    elif keyId == 1:
        compareId(conn, "32037", "29295")
    elif keyId == 2:
        compareId(conn, "18789", "13603")
    elif keyId == 3:
        compareId(conn, "16443", "29533")
    elif keyId == 4:
        compareId(conn, "18189", "21952")
    else:
        if keyId > 4 or keyId < 0:
            print(f"[KEY ID, that should not be 0, 1, 2, 3 or 4, IS: {keyId}]")
            conn.send(SERVER_KEY_OUT_OF_RANGE_ERROR)
            conn.close()
        else:
            print(f"[KEY ID, should be non-number, IS: {keyId}]")
            conn.send(SERVER_LOGIN_ERROR)
            conn.close()


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
            auth(conn)
                

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