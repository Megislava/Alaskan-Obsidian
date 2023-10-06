<<<<<<< HEAD
### RECON 
###### Scanning 
 * `nmap -A X.X.X.X`
	 * 3333: web server
	 * ...
 
###### Locating directories
 * `gobuster dir -u X.X.X.X:3333 -w rockuou.txt`
	 * /internal
 
###### Go through the site
* files can be uploaded // possible place to exploit

### COMPROMISE
* .php extension is blocked
* .phtml is "allowed" ~ exploit
* upload PHP reverse shell
* `nc -lvnp 4444`
* <b>users:</b>
	* bill

### PRIVILEGE ESCALATION
* find SUID files
	* `find / -user root -perm 4000 2>/dev/null`
	* /bin/systemctl
* run systemctl through GTFOBin
=======
### RECON 
###### Scanning 
 * `nmap -A X.X.X.X`
	 * 3333: web server
	 * ...
 
###### Locating directories
 * `gobuster dir -u X.X.X.X:3333 -w rockuou.txt`
	 * /internal
 
###### Go through the site
* files can be uploaded // possible place to exploit

### COMPROMISE
* .php extension is blocked
* .phtml is "allowed" ~ exploit
* upload PHP reverse shell
* `nc -lvnp 4444`
* <b>users:</b>
	* bill

### PRIVILEGE ESCALATION
* find SUID files
	* `find / -user root -perm 4000 2>/dev/null`
	* /bin/systemctl
* run systemctl through GTFOBin
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
* exploit