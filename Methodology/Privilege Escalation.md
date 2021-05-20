1. `find / -perm -o=s 2>/dev/null` => SUID files
2. [[LinEnum]]
3. [[LinPEAS]]
4. [[enum4linux]]


- LinEnum outputs:
	- kernel info
	- can we read/write sensitive files
	- SUID files
		- type of file permissions given to a file allowing the file to run with permissions of whoever the owner is (it can allow us to escalate privileges)
		- when special permission is given to a file, the file becomes SUID (Set user ID) or SGID (Set Group ID)
		- when extra bit “4” is set to user (Owner) it becomes SUID
		- when bit “2” is set to group it becomes SGID
		- finding them: `find / -perm -u=s -type f 2>/dev/null`
	- crontab contents - scheduled jobs
		- exploiting cron:
			- cat /etc/crontab
			- format: 
		```
		# = ID
		m = Minute
		h = Hour
		dom = Day of the month
		mon = Month
		dow = Day of the week
		user = What user the command will run as
		command = What command should be run
		```
		- eg: #  m   h dom mon dow user  command
     		`17  *  1   *    *    *     root  cd / && run-parts --report /etc/cron.hourly`
	- exploiting writable /etc/passwd
		- stores essential info for system login ~ stores user account info
		- plain text file
		- format is: `user_name:password:UID:GID:UID_info:home_directory:shell`; eg: `test:x:0:0:root:/root:/bin/bash`
		- when ‘x’ in passwd field it means that the password is stored in /etc/shadow
		- UID0 (user id) is reserved for roor user
		- GID (group id) - stored in /etc/group 
		- we can create new user, password hash, put him as root
		- passwd: `openssl passwd -1 -salt [salt] [password]` (salt=123, passwd=new)
		- add to /etc/passwd in format: `new:$1$new$p7ptkEKU1HnaHpRtzNizS1:0:0:/root:/bin/bash`
		- `su new > passwd: 123 `       
	- exploiting misconfigured binaries and GTFOBins
	- sudo -l
		- user can have permission to NOPASSWD a binary

- GTFOBins = binaries that are easily exploited (CTF, Pentest) [link](https://gtfobins.github.io/)
	- eg.: `sudo -l` (NOPASSWD to vi) > `sudo vi`> `:!sh` (privilege escalation to shell as root)


