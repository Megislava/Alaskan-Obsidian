1.  ##### 21 - FTP
	- `nmap –script ftp-anon,ftp-bounce,ftp-libopie,ftp-proftpd-backdoor,ftp-vsftpd-backdoor,ftp-vuln-cve2010-4221,tftp-enum -p 21 <IP>`
	- FileZilla, [[telnet]]
	
2. ##### 80/8080 - HTTP/S
	- browser
	- enumerate hostnames within domain using DNS:
		```
		#!/bin/bash
		i="0"
		while [ $i -lt "255" ]
		do nslookup 10.11.1.$i 
		10.11.1.XX | grep -v "NXDOMAIN" | grep name | cut -f1,3 -d" "
        i=$[ $i+1 ]
		done 
		```
	1. [[dig]]
	2. [[Harvester]]
	3. [[dirbuster]]
	4. [[Gobuster]]
	5. [[sublist3r]]
	6. [[Burp Suite]]
	7. [[OWASP Zap]]
	8. [[nikto]]
	9. [[Hydra]]
	10. [[sqlmap]] (restricted for OSCP exam => [cheatsheet](http://pentestmonkey.net/cheat-sheet/sql-injection/mysql-sql-injection-cheat-sheet) )

3. ##### 22 - SSH
	- [[telnet]]
	- [[Hydra]]
	- `nmap -sV -p 80 --script http-shellshock --script-args uri=/cgi-bin/admin.cgi $IP`
	- 
1. ##### 445/139/135 - SMB 

5. ##### 161 - SNMP

6. ##### 3306 - MySQL 

7. ##### 1560 - ORACLE

8. ##### 111/139/334 - RPC

9. ##### Hausec checklist