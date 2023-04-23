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

class Client(threading.Thread):
    def __init__(self, conn, username, usernameHash, keyId, serverConfirm, clientConfirm, lastCoords, curentCoords, direction, secretMessage, timeout = 4):
        threading.Thread.__init__(self)
        self.conn = conn
        self.username = username
        self.usernameHash = usernameHash
        self.keyId = keyId
        self.serverConfirm = serverConfirm
        self.clientConfirm = clientConfirm
        self.lastCoords = lastCoords
        self.currentCoords = curentCoords
        self.direction = direction
        self.secretMessage = secretMessage
        self.timeout = timeout
        self.response = None
    def run(self):
        print("[THREAD STARTED]")
        self.handleResponse()
        self.username = self.getResponse()
        
        self.validateUsername()        
        auth(self)
        getToCenter(self)
    def handleResponse(self):
        # Handle the HTTP request here
        data = b""
        while True:
            # Set a timeout value for the recv method
            self.conn.settimeout(self.timeout)
            try:
                chunk = self.conn.recv(1)
                if not chunk:
                    break
                data += chunk
                print(f"data is: {data}")
                if b"\a\b" in data:
                    if b"RECHARGING" in data:
                        data = b""
                        self.timeout = 5
                        self.conn.settimeout(self.timeout)
                        continue
                    parts = data.split(b"\a\b")
                    self.response = [part.decode() for part in parts]
                    print(f"response is {self.response}")
                    if len(self.response) > 1:
                        self.keyId = self.response[1]
                    if len(self.response) > 2:
                        self.clientConfirm = self.response[2]
                    self.response = self.response[0]
                    break
            except socket.timeout:
                # Handle the timeout here
                print("timeouting")
                self.conn.close()
                exit(0)
                
            
    def handleRequest(self, body, isError = False):
        self.conn.send(body)
        if isError:
            self.conn.close()
            exit(0)
    def getResponse(self):
        if type(self.response) == list:
            return self.response[0]
        return self.response
    def getUsernameHash(self):
        usernameHash = 0
        for char in self.username:
            usernameHash += ord(char)
        self.usernameHash = (usernameHash * 1000) % 65536
    def validateUsername(self):
        if len(self.username) > 18:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
    
    def validateKeyId(self):
        print(f"keyId is: {self.keyId}")
        if any(char.isalpha() for char in self.keyId) or len(self.keyId) > 1:
            print(f"some weird shit in keyID: {self.keyId}")
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if int(self.keyId) < 0 or int(self.keyId) > 4:
            print(f"KEY ID too bit or too small: {self.keyId}")
            self.handleRequest(SERVER_KEY_OUT_OF_RANGE_ERROR, True)
    
    def validateClientConfirmation(self):
        if len(self.clientConfirm) > 5:
            print(f"clientConfirmation is: {self.clientConfirm}")
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
    
    def validateCoords(self, isMove = False):
        print(f"response is {self.response}; currentCoords: {self.currentCoords}")
        if "OK" not in self.currentCoords or len(self.currentCoords) > 12:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        print(f" CURRENT COORDS IS: {self.currentCoords}")
        self.currentCoords = [int(x) for x in self.currentCoords.split()[1:]]
        if any(char.isalpha() for x in self.currentCoords for char in str(x)):
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if isMove:
            if self.lastCoords[0] == self.currentCoords[0] and self.lastCoords[1] == self.currentCoords[1]:
                # TODO odecist od sebe tam kam jsem se chtela dostat a momentalni coods to get "minuly" a spravny smer
                print(f"[SHOULD GO TO OBSTACLE HANDLING WITH: {self.lastCoords}:{self.currentCoords}]")
                self.handleObstacle() 
                print(f"[AFTER OBSTACLE HANDLING WITH: {self.lastCoords}:{self.currentCoords}]")   
    def getDirection(self):
        if self.lastCoords[0] == self.currentCoords[0] and self.lastCoords[1] > self.currentCoords[1]:
            self.direction = "down"
        elif self.lastCoords[0] == self.currentCoords[0] and self.lastCoords[1] < self.currentCoords[1]:
            self.direction = "up"
        elif self.lastCoords[1] == self.currentCoords[1] and self.lastCoords[0] > self.currentCoords[0]:
            self.direction = "left"
        elif self.lastCoords[1] == self.currentCoords[1] and self.lastCoords[0] < self.currentCoords[0]:
            self.direction = "right"
    def validateSecretMessage(self):
        if self.secretMessage != "RECHARCHING":
            self.handleRequest(SERVER_LOGOUT, True)
        if len(self.secretMessage) > 100:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
    def turn90(self):
        self.getDirection()
        if self.direction == "left":
            if self.currentCoords[1] < 0:
                self.handleRequest(SERVER_TURN_RIGHT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
            elif self.currentCoords[1] > 0:
                self.handleRequest(SERVER_TURN_LEFT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
        elif self.direction == "right":
            if self.currentCoords[1] > 0:
                self.handleRequest(SERVER_TURN_RIGHT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
            elif self.currentCoords[1] < 0:
                self.handleRequest(SERVER_TURN_LEFT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
        elif self.direction == "up":
            if self.currentCoords[0] > 0:
                self.handleRequest(SERVER_TURN_LEFT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
            elif self.currentCoords[0] < 0:
                self.handleRequest(SERVER_TURN_RIGHT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
        elif self.direction == "down":
            if self.currentCoords[0] > 0:
                self.handleRequest(SERVER_TURN_RIGHT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
            elif self.currentCoords[0] < 0:
                self.handleRequest(SERVER_TURN_LEFT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                self.validateCoords()
        else:
               print("----- NO DIRECTION -> TURNING")
               self.handleRequest(SERVER_TURN_RIGHT)
               self.handleResponse()
               self.currentCoords = self.getResponse()   
        print(f"[IN TURNING: {self.lastCoords}=>{self.currentCoords}]")
    def updateLastCoords(self):
        print(f"get difference from CC:{self.currentCoords} and LC:{self.lastCoords}")
        if self.currentCoords[0] == self.lastCoords[0]:
            if self.currentCoords[1] > self.lastCoords[1]:
                self.lastCoords[1] = self.currentCoords[1] - 1
            elif self.currentCoords[1] < self.lastCoords[1]:
                self.lastCoords[1] = self.currentCoords[1] + 1
        if self.currentCoords[1] == self.lastCoords[1]:
            if self.currentCoords[0] > self.lastCoords[0]:
                self.lastCoords[0] = self.currentCoords[0] - 1
            elif self.currentCoords[0] < self.lastCoords[0]:
                self.lastCoords[0] = self.currentCoords[0] + 1
        print(f"should be moved:{self.currentCoords} and LC:{self.lastCoords}")
    def handleObstacle(self):
            print(f"IN HANDLE OBSTACLE")
            if self.currentCoords[0] == 0 or self.currentCoords[1] == 0:
                print("sending turn right")
                self.handleRequest(SERVER_TURN_LEFT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                print(f"current response is {self.response} and currentCoords is {self.currentCoords}")
                self.validateCoords()
                
                print("[---FORWARD MOVE---]")
                self.handleRequest(SERVER_MOVE)
                self.handleResponse()
                #self.lastCoords = self.currentCoords
                self.currentCoords = self.getResponse()
                self.validateCoords(True)

                print("sending turn left")
                self.handleRequest(SERVER_TURN_RIGHT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                print(f"current response is {self.response} and currentCoords is {self.currentCoords}")
                self.validateCoords()

                print("[---FORWARD MOVE---]")
                self.handleRequest(SERVER_MOVE)
                self.handleResponse()
                #self.lastCoords = self.currentCoords
                self.currentCoords = self.getResponse()
                self.validateCoords(True)

                print("[---FORWARD MOVE---]")
                self.handleRequest(SERVER_MOVE)
                self.handleResponse()
                #self.lastCoords = self.currentCoords
                self.currentCoords = self.getResponse()
                self.validateCoords(True)

                print("sending turn left")
                self.handleRequest(SERVER_TURN_RIGHT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                print(f"current response is {self.response} and currentCoords is {self.currentCoords}")
                self.validateCoords()

                print("[---FORWARD MOVE---]")
                self.handleRequest(SERVER_MOVE)
                self.handleResponse()
                #self.lastCoords = self.currentCoords
                self.currentCoords = self.getResponse()
                self.validateCoords(True)

                print("sending turn right")
                self.handleRequest(SERVER_TURN_LEFT)
                self.handleResponse()
                self.currentCoords = self.getResponse()
                print(f"current response is {self.response} and currentCoords is {self.currentCoords}")
                self.validateCoords()

                self.updateLastCoords()
            
            else:
                self.turn90()
                print("[---FORWARD MOVE---]")
                self.handleRequest(SERVER_MOVE)
                self.handleResponse()
                self.lastCoords = self.currentCoords
                self.currentCoords = self.getResponse()
                print(f"last coords: {self.lastCoords}; current coords: {self.currentCoords}")
                self.validateCoords(True)

                self.turn90()

# --------- NEW CLIENT/THREAD ------------#
def startNewThreats(server):
    while True:
        conn, addr = server.accept()
        print(f"[CONNECTION FROM {addr}]")    
        
        client = Client(conn, "", "", "", "", "", "", "", "", "")
        client.start()
        client.join()

# ------------- AUTH ------------------#
def auth(client):
    # get usernameHash
    client.getUsernameHash()

    print("sending key id")
    client.handleRequest(SERVER_KEY_REQUEST)
    client.handleResponse()
    print(f"response is: {client.response}")
    if client.keyId == "":
        client.keyId = client.getResponse()
    client.validateKeyId() 
    print(f"key id is: {client.keyId} ")

    client.serverConfirm = (int(client.usernameHash) + serverKeys[int(client.keyId)]) % 65536
    expectedClientConfirm = (int(client.usernameHash) + clientKeys[int(client.keyId)]) % 65536
    
    print("sending server confirm")
    # send server confirmation
    client.handleRequest(str(client.serverConfirm).encode() + b"\a\b")
    # get client confirmation and validate
    client.handleResponse()
    if client.clientConfirm == "":
        client.clientConfirm = client.getResponse()
    client.validateClientConfirmation()
    print(f"client conrim is: {client.clientConfirm} and expected is {expectedClientConfirm}")

    # if all ok, continue
    if int(client.clientConfirm) != expectedClientConfirm:
        print("sending login failed")
        client.handleRequest(SERVER_LOGIN_FAILED, True)
    else:
        client.handleRequest(SERVER_OK)
    print(f"[CONTINUE AFTER AUTH with username {client.username}]")
# ------------------ CREATE PATH ----------#
def getToCenter(client):
    print("sending turn right")
    client.handleRequest(SERVER_TURN_RIGHT)
    client.handleResponse()
    client.currentCoords = client.getResponse()
    print(f"current response is {client.response} and currentCoords is {client.currentCoords}")
    client.validateCoords()
    
    print("[---FORWARD MOVE---]")
    client.handleRequest(SERVER_MOVE)
    client.handleResponse()
    client.lastCoords = client.currentCoords
    client.currentCoords = client.getResponse()
    client.validateCoords(True)

    print(f"[BEFORE WHILE: {client.lastCoords}=>{client.currentCoords}]")

    # turn to center if neccesary
    client.turn90()
    while client.currentCoords != [0,0]:
        print(f"[CURRENT COORDINATES BEFORE FORWARD MOVE: {client.lastCoords}:{client.currentCoords}]")
        if client.currentCoords[0] == 0 or client.currentCoords[1] == 0:
            print(f"goes to turn")
            client.turn90()

        print("[---FORWARD MOVE---]")
        client.handleRequest(SERVER_MOVE)
        client.handleResponse()
        print(f"[response to move was: {client.response}]")
        print(f"[AFTER MOVE before COORDS SWITCHED: {client.lastCoords}=>{client.currentCoords}]")
        client.lastCoords = client.currentCoords
        client.currentCoords = client.getResponse()
        print(f"[AFTER MOVE after COORDS SWITCHED: {client.lastCoords}=>{client.currentCoords}]")
        
        client.validateCoords(True)
        
        print(f"[CURRENT COORDINATES AFTER FORWARD MOVE/OBSACTLE HANDLE AND SWICHED COORDS: {client.lastCoords}:{client.currentCoords}]")
        
    # retrieve secret
    client.handleRequest(SERVER_PICK_UP)
    client.handleResponse()
    client.secretMessage = client.getResponse()
    client.validateSecretMessage()

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