import socket
import threading

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
SERVER_LOGIC_ERROR = b"302 LOGIC ERROR\a\b"
SERVER_KEY_OUT_OF_RANGE_ERROR = b"303 KEY OUT OF RANGE\a\b"
# END

serverKeys = [23019,32037,18789,16443,18189]
clientKeys = [32037,29295,13603,29533,21952]

# je to po smeru hodinovych rucicek
UP = 0
RIGHT = 1
DOWN = 2
LEFT = 3


class Client(threading.Thread):
    def __init__(self, conn, username, usernameHash, keyId, serverConfirm, clientConfirm, lastCoords, curentCoords, lastDirection, secretMessage, timeout = 4, direction = 0):
        threading.Thread.__init__(self)
        self.conn = conn
        self.username = username
        self.usernameHash = usernameHash
        self.keyId = keyId
        self.serverConfirm = serverConfirm
        self.clientConfirm = clientConfirm
        self.lastCoords = lastCoords
        self.currentCoords = curentCoords
        self.lastDirection = lastDirection
        self.direction = direction
        self.secretMessage = secretMessage
        self.timeout = timeout
        self.response = None
    def run(self):
        self.handleResponse(20)
        self.username = self.getResponse()
        
        self.validateUsername()        
        auth(self)
        getToCenter(self)
    def handleResponse(self, maxLength):
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
                if b"\a\b" in data:
                    # TODO - handle RECHARGING?
                    
                    parts = data.split(b"\a\b")
                    self.response = [part.decode() for part in parts]
                    if len(self.response) > 1:
                        self.keyId = self.response[1]
                    if len(self.response) > 2:
                        self.clientConfirm = self.response[2]
                    self.response = self.response[0]
                    break
                else:
                    if len(data) >= maxLength:
                        self.handleRequest(SERVER_SYNTAX_ERROR, True)
            except socket.timeout:
                # Handle the timeout here
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
        if " " in self.keyId:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if any(char.isalpha() for char in self.keyId) or len(self.keyId) > 1:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if int(self.keyId) < 0 or int(self.keyId) > 4:
            self.handleRequest(SERVER_KEY_OUT_OF_RANGE_ERROR, True)
    
    def validateClientConfirmation(self):
        if " " in self.clientConfirm:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if len(self.clientConfirm) > 5:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
    
    def validateCoords(self):
        if "." in self.currentCoords or "," in self.currentCoords:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if "OK" not in self.currentCoords:
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        if self.currentCoords[len(self.currentCoords) - 1] == " ":
            self.handleRequest(SERVER_SYNTAX_ERROR, True)
        self.currentCoords = [int(x) for x in self.currentCoords.split()[1:]]
        if any(char.isalpha() for x in self.currentCoords for char in str(x)):
            self.handleRequest(SERVER_SYNTAX_ERROR, True) 
    def getDirection(self):
        if self.lastCoords[1] > self.currentCoords[1]:
            self.direction = DOWN
        elif self.lastCoords[1] < self.currentCoords[1]:
            self.direction = UP
        elif self.lastCoords[0] > self.currentCoords[0]:
            self.direction = LEFT
        elif self.lastCoords[0] < self.currentCoords[0]:
            self.direction = RIGHT
    def validateSecretMessage(self):
        if self.secretMessage != "RECHARCHING":
            self.handleRequest(SERVER_LOGOUT, True)
    def turn90(self):
        currentDirection = self.direction
        self.turnTo(self.lastDirection)
        self.lastDirection = currentDirection
    
    def getSecretMessage(self):
        # retrieve secret
        self.handleRequest(SERVER_PICK_UP)
        self.handleResponse(100)
        self.secretMessage = self.getResponse()
        self.validateSecretMessage()
    def move(self, direction):
        self.handleRequest(direction)
        self.handleResponse(12)
        if direction == SERVER_MOVE:
            self.lastCoords = self.currentCoords
        else:
            if direction == SERVER_TURN_LEFT:
                self.direction = (self.direction - 1) % 4
            elif direction == SERVER_TURN_RIGHT:
                self.direction = (self.direction + 1) % 4
        self.currentCoords = self.getResponse()
        self.validateCoords()
        if self.currentCoords[0] == 0 and self.currentCoords[1] == 0:
            self.getSecretMessage()
        
    def turnTo(self, wantedDirection):
        while wantedDirection != self.direction:
            self.move(SERVER_TURN_LEFT)

    def turnToCenter(self):
        if self.currentCoords[0] > 0 and self.currentCoords[1] > 0:
            self.turnTo(DOWN)
            self.lastDirection = LEFT
        elif self.currentCoords[0] > 0 and self.currentCoords[1] < 0:
            self.turnTo(LEFT)
            self.lastDirection = UP
        elif self.currentCoords[0] < 0 and self.currentCoords[1] < 0:
            self.turnTo(UP)
            self.lastDirection = RIGHT
        elif self.currentCoords[0] < 0 and self.currentCoords[1] > 0:
            self.turnTo(RIGHT)
            self.lastDirection = DOWN
        elif self.currentCoords[0] == 0 and self.currentCoords[1] > 0:
            self.turnTo(DOWN)
            self.lastDirection = DOWN
        elif self.currentCoords[0] == 0 and self.currentCoords[1] < 0:
            self.turnTo(UP)
            self.lastDirection = UP
        elif self.currentCoords[1] == 0 and self.currentCoords[0] > 0:
            self.turnTo(LEFT)
            self.lastDirection = LEFT
        elif self.currentCoords[1] == 0 and self.currentCoords[0] < 0:
            self.turnTo(RIGHT)
            self.lastDirection = RIGHT
    
    def handleObstacle(self):
        if self.currentCoords[0] == 0 or self.currentCoords[1] == 0:
            self.move(SERVER_TURN_LEFT)
            
            self.move(SERVER_MOVE)
            self.move(SERVER_TURN_RIGHT)

            self.move(SERVER_MOVE)

            self.move(SERVER_MOVE)

            self.move(SERVER_TURN_RIGHT)

            self.move(SERVER_MOVE)
            self.move(SERVER_TURN_LEFT)
        
        else:
            self.turn90() # opacne ke stredu
            self.move(SERVER_MOVE)


# --------- NEW CLIENT/THREAD ------------#
def startNewThreats(server):
    while True:
        conn, addr = server.accept()
        client = Client(conn, "", "", "", "", "", "", "", "", "")
        thread = threading.Thread(target=client.run)
        thread.start()

# ------------- AUTH ------------------#
def auth(client):
    # get usernameHash
    client.getUsernameHash()

    client.handleRequest(SERVER_KEY_REQUEST)
    client.handleResponse(5)
    if client.keyId == "":
        client.keyId = client.getResponse()
    client.validateKeyId() 

    client.serverConfirm = (int(client.usernameHash) + serverKeys[int(client.keyId)]) % 65536
    expectedClientConfirm = (int(client.usernameHash) + clientKeys[int(client.keyId)]) % 65536

    # send server confirmation
    client.handleRequest(str(client.serverConfirm).encode() + b"\a\b")
    # get client confirmation and validate
    client.handleResponse(7)
    if client.clientConfirm == "":
        client.clientConfirm = client.getResponse()
    client.validateClientConfirmation()

    # if all ok, continue
    if int(client.clientConfirm) != expectedClientConfirm:
        client.handleRequest(SERVER_LOGIN_FAILED, True)
    else:
        client.handleRequest(SERVER_OK)
# ------------------ CREATE PATH ----------#
def getToCenter(client):
    client.handleRequest(SERVER_TURN_RIGHT)
    client.handleResponse(12)
    client.currentCoords = client.getResponse()
    client.validateCoords()
    
    client.move(SERVER_MOVE)
    if client.currentCoords == client.lastCoords:
        client.move(SERVER_TURN_RIGHT)
        client.move(SERVER_MOVE)

    client.getDirection()
    
    # turn to center if neccesary
    client.turnToCenter()
    
    while True:
        if client.currentCoords[0] == 0 or client.currentCoords[1] == 0:
            client.turnToCenter()          

        client.move(SERVER_MOVE)
        if client.currentCoords == client.lastCoords:
            client.handleObstacle()
        

def main():
    host = socket.gethostbyname(socket.gethostname())
    port = 9999

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen()
    print(f"[STARTED LISTENING on {host}:{port}]")
    startNewThreats(server)

if __name__ == "__main__":
    main()