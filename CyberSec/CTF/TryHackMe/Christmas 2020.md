1. A Christmas Crisis
- cookie exploitation
	1. visit the site
	2. register and login
	3. figure out what is the format for the auth cookie (HEX, JSON)
	4. decode the cookie (try [Cyber Chef](http://icyberchef.com/))
	5. change username for the desired one
	6. enter the new cookie and reload

2. The Elf Strikes Back!
- RCE - File Upload, URL fuzzing and Reverse Shell
	1. visit the site and find a place to upload the file
	2. find out what extentions can you upload
	3. change reverse shell so it's in format eg .jpg.php
	4. upload the file
	5. make listener
	6. find the upload folder and open the file
	7. you get the reverse shell and dig in the system

3. Christmas Chaos
- auth with default username/password combo
	1. intercept login request, send to intruder
	2. select cluster bomb
	3. check positions
	4. add payloads, run
	5. find different response


4. Santa's watching
- fuzz directories and find an API that can get the note you want
	1. fuzz directories with gobuster
	2. find the API endpoint
	3. fuzz throught the api endpoint with ?date param and find open note

5. Someone stole Santa's gift list
	1. find login page
	2. SQL injection the login page
	3. SQL inject the search for DB with sqlmap

6. 