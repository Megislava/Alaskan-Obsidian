3. Authentication
	- process of verifying the identity of a person (/object/service)
	- the goal is to verify that the person is not an imposter

	- **local authentication**
		- done using Local Security Authority (LSA)
			- protected subsystem keeping track of the security policies and accounts that are on a computer system
			- maintains information about all aspects of local security on a computer
			
	- **active directory**
		- On-Premise AD
			- record of all users, PCs and servers
			- authenticated the user signing in, once signed in the AD also governs what the user are (not) allowed to do/access
			- auth using these protocols:
				- NTLM - challenge-response sequence of messages between client and server, does not provide data integrity or data confidentiality
				- LDAP/LDAPS - sending cred using an API, if S then the trafic is encryptred
				- Kerberos - symmetric-key cryptography, requires trusted third-party auth to verify user identity
		- Azure AD
			- secure online authentication store containing users and groups
			- using these protocols:
				- SAML (Security Assertion Markup Language) - type of single Sign-On standard, defines a set of rules/protocols that allow users to access web apps with a single login, this is possible because those app trust the systems that verify the users identity; Service and Identity provides
				- OAuth 2.0 - 4 important roles - authorisation server issues access token, resource owner grants access to the resource server with an access token, client passes it to the resource server, resource server accepts the token and verify its validity
				- OpenId Connect - auth biuld on top of OAuth 2.0, adds additional token (ID token), uses JSON Web Tokens