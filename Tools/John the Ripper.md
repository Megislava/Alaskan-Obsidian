- hash cracker

- wordlists in: `/usr/share/wordlists`
	- SecLists -> /Passwords/Leaked-Databases

- `john [options] [path-to_file_to_crack]`

- automatic cracking: `john --wordlist=[path_to_wordlist] [path_to_file]`
- identify hash with hash-identifier
- format specific cracking: `john --format=[format] --wordlist=[path_to_wordlist] [path_to_file]`

- list formats with: `john --list=formats`

- cracking /etc/shadow
	- `unshadow [path_to_passwd] [path_to_shadow]`
	- `john --format=sha512crypt --wordlist=[path_to_wordlist] [path_to_file]`

- single crack mode
	- taking info about the username and creating possible passwords heuristically from it
	- Markus -> Markus1, Markus2, MArkus, MARkuS, Markus!, Markus@,....
	- the flag is: `--single`

- custom rules
	- similar to single crack mode but much more possibilities
	- creating rules for making dictionary attack
	- create rule
		- rules defined in john.conf (usually in /etc/john/john.conf)
		- define the name: `[List.Rules:<NAME>]`
		- define where the word will be modified:
			- `Az` - appends defined chars
			- `A0` - prepends defined chars
			- `c` - capitalize the char
			- can be used together
		- define the chars that will be appended, prepended or otherwise included
			- put the rules in `"[<RULES>]"`
			- `[0-9]` - include numbers
			- `[0]` - include 0
			- `[A-z]` - include both upper and lowercase
			- `[A-Z]` / `[a-z]` - include only upper/lowercase 
			- `[a]` - include only a
			- `[!@#$%^]` - include symbols !@#$%^
	- running the rule: `john --wordlist=[path_to_wordlist] --rule=[name_of_rule] [path_to_file]`

- cracking ZIP, RAR, SSH
	- run `<zip/rar/ssh/...>2john [options] <path_to_file> > <output_file>`
	- you get hash of the original file
	- run the hash through john
		- `john --wordlist=<wordlist> <path_to_file>`
		- -> password