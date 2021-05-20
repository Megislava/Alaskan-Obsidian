- Simple Mail Transfer Protocol
	- handling the sending of emails
	- protocol pair is required: SMTP + POP/IMAP
	- 3 basic functions:	
		- verifies who is sending emails through SMTP server
		- sends outgoing mail
		- if the outgoing mail cannot be delivered it sends the message back to sender
	- steps:
		1. SMTP handshake
		2. client submits senders and recipient's email address, the body of email and attachements to the server
		3.  the SMTP server checks whether the domain name of the recipient and the sender is the same
		4.  SMTP server connects to the recipient's SMTP server before relaying the email, if the server cannot be accessed/isn't available the email gets put into SMTP queue
		5.  recipient's SMTP server verifies the incomming email, if the domain and user name has been recongnized the server forwards the mail to the POP/IMAP server
		6.  the email will show up in the recipient's inbox
- POP + IMAP: both responsible for the transfer of email between client and mail server
- POP = Post Office Protocol
	- download the inbox from mail server to the client
- IMAP = Internet Message Access Protocol
	- synchronize the current inbox with new mail on the server, downloading anything new
- enumerate with smtp_version (auxiliary/scanner/smtp/smtp_version) and smtp_enum (auxiliary/scanner/smtp/smtp_enum) modules in Metasploit
- bruteforce the password