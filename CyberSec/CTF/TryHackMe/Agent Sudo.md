- 10.10.108.139

- `nmap -sS -sV -A <IP>`
	- 21: ftp
		- open
		- vsftpd 3.0.3
	- 22: ssh
		- OpenSSH 7.6
	- 80: http
		- Apache 2.4.29

- website
	- nothing on Burp
	- gobuster
		- noting
	- HINT:
		- intercept request - change user-agent
		- → **username: chris**

- ftp
	- not anon
	- try to breach chris's password w/ hydra
		- → **chris:crystal**
	- got 3 files:
		- txt with instructions, jpeg, png (stego)
	- `foremost -x <steg_file>`
		- → zip password: **alien**
	- crack zip w/ john
		- → **QXJlYTUx**
		- use for second steg file
		- got second creds
			- **james:hackerrules!**

- ssh
	- james's creds
		- → user flag
	- privilege escalation
		- `sudo l` → (ALL, !root) /bin/bash
		- `sudo -u#-1 /bin/bash`  (1 not l)