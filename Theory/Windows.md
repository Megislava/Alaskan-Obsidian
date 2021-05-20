1. File strucure
	- Logical drives, Folders, Files
	- interesting folders:
		- PerfLogs - Stores the system issues and other reports regarding performance
		- Program Files and Program Files (x86) - Is the location where programs install unless you change their path
		- Users - In this folder are stored the users created. It also stores users generated data
		- Windows - It's the folder which basically contains the code to run the operating system and some utility tools
2. File permissions
	- to users and groups
		- Full control, Modify, Read & Execute, List folders content, Read, Write, Special permissions
	- in cmd: `icacls <folder>`
letter | meaning
------| ---------
I | permission inherited from the parent container
F | full access (full control)
M | Modify right/access  
OI | object inherit
IO | inherit only  
CI | container inherit
RX | read and execute  
AD | append data (add subdirectories)  
WD | write data and add files

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

4. Utility tools
	- Computer Management
		- Task Scheduler, Event Viewer, Shared Folders, Local users and computers, Performance Monitor, Disk Management, Services and Applications
	- Local Security Policy
		- group of settings you can configure to strengthen the computers security
	- Disk Cleanup
		- can delete files that are no longer needed by the system
	- Registry Editor
		- stores OS low-level settings
		- HKEY CLASSES ROOT, HKEY CURRENT USER, HKEY LOCAL MACHINE, HKEY USERS, HKEY CURRENT CONFIG 
	- Command-line tools
		- CMD, PowerShell, Windows Terminal

5. Types of servers
	- Domain Controller, File server, Web server, FTP server, Mail server, Database server, Proxy server, Application server