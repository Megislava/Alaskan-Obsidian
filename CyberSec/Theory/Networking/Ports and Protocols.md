### Transfer data
- HTTP/HTTPS
	- HyperText Transfer Protocol (Secure)
	- http :80 (port from transfer layer)
	- https :443 (-||-)

### File transfer
- FTP/sFTP
	- (secure) File Transfer Protocol)
	- FTP :20 / :21
	- sFTP :22
- TFTP
	- Trivial File Transfer Protocol
	- TFTP :69
- SMB
	- Server Message Board
	- SMB :445
	- SMB => treba Network tab na woknech (vytvori lokalni server?)

### Email
- POP3, IMAP
	- take email from server and transfer to client
	- POP3 :110/ :995 (non-encrypted / encrypted)
	- IMAP :143/ :993 (-||-)
- SMTP
	- simple mail transfer protocol, send to server
	- SMTP :25 / :465 (-||-) (/ :587)

### Authentication
- LDAP(s)
	- Lightweight Directory Access Protocol (secure)
	- LDAP :389
	- LDAPs :636

### Network services ~ transferring data
- DHCP
	- throws back to client: IP address, subnet mask, default gateway, DNS server, other info
	- IP config with DHCP:
			- DHCP: cmd => ipcofig
			- ipconfig /release + ipconfig /renew freeing our IP address and receiving a new one 
- DNS
	- domain main system ~ FQDN (Fully Qualified Domain Name) 
	=> using simple names instead of IP addresses = phonebook of the internet
	- application layer because applications need to use host name
	- hierarchy:
		- root level
		- top level domains (eg .com, .net, .cz,...)
		- second level domains
		- subdomains
		- hosts
		- ![[6.PNG]]
	- if we don’t know “udacity.com”: ![[7.PNG]]
	- _ipconfig /all => show entire IP config_
	- _nslookup URL => gives back IP address of URL inc ip6_
	- _if nslookup => local IP could be changed with: > server 8.8.8.8 => pak proste muzu psat jenom URL_
	- webapp can have more than one IP address ~ hosting at more places ~ more stable
- NTP
	- network time protocol - automaticaly configure all the times on client to be the same
	=> UTC = coordinated universal time 
- telnet + SSH
	- network management
	- telnet - clear text, SSH - crypted
	- telnet :23
	- SSH :22
	- SSH => Putty - client - put in IP address => opens session
- SNMP
	- gets info about device on our network and save them into SNMP server
- RDP
	- remote desktop protocol
	- RDP :3389
- audio/visual protocol
	- H.323 :1720 - video conferences
	- SIP :5060 / 5061 - voice over IP communication => telephones 

- port numbers: 0 - 65 535
- server port numbers: 
	- well known = 0 - 1 023
	- registered = 1 024 - 49 151
- client port numbers: ephemeral 49  152 - 65 535
- client port numbers - official and unofficial

- protocol dependencies: (7th layer / port number / 4th layer)
![[8.PNG]]