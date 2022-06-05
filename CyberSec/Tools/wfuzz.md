- fuzzing tool 
- more information then gobuster
- can fuzz between / /
- `wfuzz -c -z file,usr/share/wordlists/dirb/big.txt localhost:80/FUZZ/note.txt`
	- fuzzing diffent usernames to get their note.txt
- `-c`: shows output in color
- `-d`: specify the params you want to fuzz with, where the data is encoded for a HTML form
- `-z`: specifies what will replace FUZZ in the request
- `--hc`: don't whow certain http response codes
- `--hl`: don't show for a certain amount of lines in response
- `--hh`: don't show for a certain amount of words

=> `wfuzz -c -z file,muwordlist.txt -d "username=FUZZ&password=FUZZ" -u http://shibes.thm/login.php`