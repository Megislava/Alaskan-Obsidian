<<<<<<< HEAD
#server-side

- __authentication__
	- = process of verifyng the identity of a given user/client ~ making sure that they are who they say they are
	- 3 authentication factors:
		- something you __know__, something you __have__ and something you __are__
	- __vs authorization__
		- proces of verifying whether user is allowd to do something

- __potentional impact__ 
	- direct access to sensitive data and functionality
		- in worst case the breached user is privileged one - the attacker can gain full access to the system

- __different authentication mechanisms__
	1. Password-based login
		1. Brute force
			- trial and error, typicaly automated using wordlists
			- usernames: recognisable pattern → usually easy to guess
			- passwords: based on password policy, can be make "stronger" (mypassword =→ MyPa\$\$w0rd)
		2. Username enumeration
			- pay closer attenction to returned status codes, error messages and response times 
		3. Flawed brute-force protection
			- most common brute-force protections and their vulnerabilities 
			1. Account locking
				- locking the account that the remote host is trying to access after too many failed attempts
				- fails when user is trying to gain access to random account
			2. User rate limiting
				- blocking attackers IP
				- can be avoided by signing in with correct creds
				- IP can be unblocker by: waiting, manually by administrator, manually by user completing CAPTCHA
		4. HTTP basic authentication
			- old, simple
			- client receives auth token from the server (concatenated username and password + encoded into Base64)
			- token is managed and stored in browser - automatically adds 'Authorization' header
			- eg. `Authorization: Basic base64(username:password)`
	2. Multi-factor authentication
		- usually something you know (password) + something you have (verification code)
		- if verification code is on different page the user is effectively logged in
		- changing cookies - sign in as you and change username in cookies to sign in as different user
		- brute-forcing the verification key
	3. Other authentication methods
		- reset/change password → more vulnerabilities
		1. Keeping users logged in
			- usually "remember me" token generated and stored as persistent cookie
			- the token can be created:
				- with guessable strings - concatenating username and password, username and timestamp
				- with simple Base64 encoding, or hashing and not using salt
		2. Resetting user password
			1. Sending passwords by email
				- sending cleartext password via insecure is not great 
			2. Resetting passwords using a URL
				- sending a unique URL via email
				- can have guessable parameter (user='xxx')
				- better to implement:
					- highly entropic token
					- check whether it's connected to correct username on backend
					- expire short after the password is resetted
					- link has some expiration
		3. Changing user passwords
			- similar to login page - check username and password combo → similar vulnerabilities
			- can be exploited by enumerating possible usernames and brute-forcing their passwords


- __prevention__
	- take care with user credentials
		- never send any login data over unencrypted connection
	- don't count on users for security
		- enforce security behavior ~ introduce effective password policy
		- eg JS library _zxcvbn_ - password complexity checker
	- prevent username enumeration
		- use generic/identical error message for wrong password and username
		- same HTTP status code with each login request
		- same response times for different scenarios
	-  implement robust brute-force protection
		-  different methods, eg. strict IP-based user rate limiting, CAPTCHA test with every login after a certain limit is reached
	-  triple-check your verification login
		-  eliminate login flaws for robust authentication
	-  don't forget supplementary functionality
		-  password change, password reset is also valid attack surface
=======
#server-side

- __authentication__
	- = process of verifyng the identity of a given user/client ~ making sure that they are who they say they are
	- 3 authentication factors:
		- something you __know__, something you __have__ and something you __are__
	- __vs authorization__
		- proces of verifying whether user is allowd to do something

- __potentional impact__ 
	- direct access to sensitive data and functionality
		- in worst case the breached user is privileged one - the attacker can gain full access to the system

- __different authentication mechanisms__
	1. Password-based login
		1. Brute force
			- trial and error, typicaly automated using wordlists
			- usernames: recognisable pattern → usually easy to guess
			- passwords: based on password policy, can be make "stronger" (mypassword =→ MyPa\$\$w0rd)
		2. Username enumeration
			- pay closer attenction to returned status codes, error messages and response times 
		3. Flawed brute-force protection
			- most common brute-force protections and their vulnerabilities 
			1. Account locking
				- locking the account that the remote host is trying to access after too many failed attempts
				- fails when user is trying to gain access to random account
			2. User rate limiting
				- blocking attackers IP
				- can be avoided by signing in with correct creds
				- IP can be unblocker by: waiting, manually by administrator, manually by user completing CAPTCHA
		4. HTTP basic authentication
			- old, simple
			- client receives auth token from the server (concatenated username and password + encoded into Base64)
			- token is managed and stored in browser - automatically adds 'Authorization' header
			- eg. `Authorization: Basic base64(username:password)`
	2. Multi-factor authentication
		- usually something you know (password) + something you have (verification code)
		- if verification code is on different page the user is effectively logged in
		- changing cookies - sign in as you and change username in cookies to sign in as different user
		- brute-forcing the verification key
	3. Other authentication methods
		- reset/change password → more vulnerabilities
		1. Keeping users logged in
			- usually "remember me" token generated and stored as persistent cookie
			- the token can be created:
				- with guessable strings - concatenating username and password, username and timestamp
				- with simple Base64 encoding, or hashing and not using salt
		2. Resetting user password
			1. Sending passwords by email
				- sending cleartext password via insecure is not great 
			2. Resetting passwords using a URL
				- sending a unique URL via email
				- can have guessable parameter (user='xxx')
				- better to implement:
					- highly entropic token
					- check whether it's connected to correct username on backend
					- expire short after the password is resetted
					- link has some expiration
		3. Changing user passwords
			- similar to login page - check username and password combo → similar vulnerabilities
			- can be exploited by enumerating possible usernames and brute-forcing their passwords


- __prevention__
	- take care with user credentials
		- never send any login data over unencrypted connection
	- don't count on users for security
		- enforce security behavior ~ introduce effective password policy
		- eg JS library _zxcvbn_ - password complexity checker
	- prevent username enumeration
		- use generic/identical error message for wrong password and username
		- same HTTP status code with each login request
		- same response times for different scenarios
	-  implement robust brute-force protection
		-  different methods, eg. strict IP-based user rate limiting, CAPTCHA test with every login after a certain limit is reached
	-  triple-check your verification login
		-  eliminate login flaws for robust authentication
	-  don't forget supplementary functionality
		-  password change, password reset is also valid attack surface
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
	-  implement proper multi-factor authentication