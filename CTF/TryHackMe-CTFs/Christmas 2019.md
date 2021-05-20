13. ## Accumulate

### RECON
###### Scanning
 * <code> nmap -A X.X.X.X </code>
* 80: webserver
* 3389: ms-wbt-server (RDP)
 
###### Locating directories
 * <code>gobuster dir -u X.X.X.X:3333 -w rockuou.txt </code>
* /retro
* /retro/wp-admin
* /retro/wp-login.php
* /retro/index.php/2019
 * username:
* Wade:parzival
 
###### Go through the site
 * it's possible to sign in to WordPress with given creds


### COMPROMISE
* put PHP reverse shell to 404 page
* <code>nc -lnvp 4444</code>
* the reverse shell doesn't work
* let's try RDP
* <code>xfreerdp /f /v:X.X.X.X /u:USERNAME /p:PASSWORD</code>


### PRIVILEGE ESCALATION
* exploit hhupd.exe (CVE-2019-1388) and get the flag



14. ## Unknown Storage

### RECON
* I have name of S3 bucket and need to get some flags
* <code>curl https://NAME_OF_BUCKET.s3.amazonaws.com</code>
* or just visit the "site"


15. ## LFI

### RECON
###### Scanning
 * <code> nmap X.X.X.X </code>
* 22: ssh
* 80: webserver

* <code>curl -s X.X.X.X</code>
* from that find out that /get-file/ gets you files
* read /etc/shadow and get hash
* run hashcat on the hash
* USERNAME:
* charlie:password1

### COMPROMISE
* use ssh to log into the machine ~ exploit


18. ## ELF JS

### RECON
###### Go through the site
* register and login
* exploit with use od XSS


19. ## Commands

### RECON
###### Go through the site
* in /api/cmd found command that works
* <code>curl -s X.X.X.X/api/cmd/ls</code>
* list directories and find flag
* remember that " " is replaced by %20 and "/" is %2f


20. ## Cronjob Privilege Escalation

### RECON
###### Scanning
 * <code> nmap X.X.X.X </code>
* 4567: tram (? -> SSH)
 
### COMPROMISE
* crack password for user sam through SSH
* sam:chocolate
* ssh into machine, find flag

### PRIVILEGE ESCALATION
* get linPEAS and run
* find where flag2.txt is
* <code>/home/ubuntu</code>
* is owned by user ubuntu
* check that else ubuntu user owns
* <code>find / -user ubuntu 2>/dev/null</code>
* <code>/home/scripts/clean_up.sh</code>
* change /clean_up.sh to run <code>cat /home/ubuntu/flag2.txt</code>


16. ## File Confusion
* I should write a script but in the end I did everything by hand

21. ## Reverse Elf-ineering
* I should work with the supporting materials but either I didn't understood well or didn't care enough. In the end I guessed

22. ## If Santa, Then Christmas
* same as previous case

23. ## LapLANd (SQL injection)
* I didn't finish this one

24. ## Elf Stalk
### RECON
###### Scanning
 * <code> nmap -A X.X.X.X </code>
* 22: ssh
* 111: rcpbind
* 5601: esmagent; KIBANA
* 8000: http-alt; webserver
* 9200: wap-wsp; ELASTIC SEARCH 6.4.2
 
###### Go through the site
* go to <code>X.X.X.X:9200/_search?q=password</code> (or something else what you are searching for)
* this can be done with curl but the result is not that nice
* on port 5601 there is KIBANA which can be viewed as a website
* find the exploit for the version
