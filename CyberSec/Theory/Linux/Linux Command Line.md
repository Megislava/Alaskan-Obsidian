- CASE SENSITIVE


### General, Folders and Paths

- `~` - absolute route to /home 
- `date` - prints date and time
- `echo` - vypise do console 
	- vytvori soubor s nejakym obsahem `echo “Hello world!” > hello.txt`
	- pri pouziti `>>` se prida string na posledni radek

- `printf` - more possibilities how to print stuff to console
	- does not have `\n` by default
	- `printf '%s\n' "$ENVVAR"` - print the value of `ENVVAR` 


- `history` - shows bash history
	- when used with `|`, eg. `history | grep ping` → will find how the specific command was used
	- history based suggestion tool: [fish](https://fishshell.com/)
	- can be enabled in zsh
	- history behaviour can be changed in `.bashrc`
		- `HISTCONTROL=ignorespace`
	
- directory navigation
	- `ln` - create a hardlink
		- `-s` - symbolic link (symlink, soft link)
		- hardlinks - files will share an inode
			- inode = keeps metadata of file (perms, owner, etc)
			- don't have a single point for failure
		- symlink
			- do not link via inodes but with names
			- easier to see and can link to directory
	- `fasd` (frequency + recency), `autojump`
	- `tree` - get tree view of directories
	- `nnn`, `ranger`

- `>` - output redirection
	- `echo hello > file`; `cat file` → `hello`
	- if the “receiving” file does not exist, will be created

- `<` - rewiring output like with `>` but the other way round
	```sh
	missing:~$ echo hello > hello.txt
	missing:~$ cat hello.txt
	hello
	missing:~$ cat < hello.txt
	hello
	missing:~$ cat < hello.txt > hello2.txt
	missing:~$ cat hello2.txt
	hello
	```
- `>>` - output redirection - appends to the end of file
	-  `echo nood >> file` → `cat file → hello \n nood`
	- if the "receiving" file does not exist, will be created

- `&&` - and
	- eg. `echo hey >> file2 && cat file2` → `hey`

- `$` - denotes environment variables
	- eg. `echo $USER` → prints current user

- `|` - pipe - take the output of previous command and uses it in the next

- `;` - similar to pipe but it does not require the first command to execute successfully
	- eg. `./somebullshitthatdontexit ; ls` - ls will still list
- `&` - command will run in the background
- `*` -wildcard
	- `echo /etc/r.conf` - will return `echo/resolv.conf` and `/etc/rsyslog.conf`
- `?` - ? character
	- represents each character
		- `echo /etc/t???????` - will tprint `etc/timezone` and `etc/terminfo`
- `[]` - matching chars inside the brackets
	- `echo /etc/[gu]*` - prints files from etc starting with g or u
	- `echo /ect/[a-d]*` - prints files from etc starting with a, b, c, d
	- `echo /etc/*[0-9]*` - prints files from etc that contains number
- `!` - used together with `[]` and negates the range
	- `echo /etc/[!a-t]*` - prints files NOT starting with a-t characters
 
- `pwd` - "Path to a Working Directory" print working path = find yourself
	- `pwd > absolute_path `- saving absolute path into a file absolute_path

- `cd` - folder orientations

- `ls` - list a folder
	- `-l` - long
	- `-a` - including hidden ones
	- `-R` - recursive
	- `-d` - information about spefied folder (don't care about insides)
	- `-h` - print size in human-readable form (must be used with `-l`)
	- `-S` - sorting by size (big→small); reversed sorting w/ `-r`
	- `-t` - sort by last modified
	- `--full-time` - full time of last modification
	- `-i` - display the inode number of a file 
	- `?????` - prints all 5-characters long files in folder
		- of course can be used with different lenghts of filenames
	- `-w <number>` - "width" print only `<number>` of chars per line
	- certain folder can be specified
		- `ls -laR /dev /tmp` - will print EVERYTHING and recursively from `/dev` and `/tmp`
	- File Types → Permissions → Hard Link count → User Owner → Group Owner → File Size → Time Stamp → File Name
		- `d` (directory), `-` (regular file), `l` (symbolic link), `s` (socket), `p` (pipe), `b` (block file), `c` (character file)
	- `-1` - print one info on one line
    
- `mkdir` - create a folder 
	- `-p` - with parent folder (`mkdir -p a/c/d/v/` )

- `rmdir` - delete a folder
	- only if the directory is empty

- `tree` - prints the current file system tree

- `pstree` - prints family tree of processes

- `ps` - shows list of running tasks with their PID (process ID), PPID (parent process ID)
	- list of all system processes: `-ef`
	- `--forest` - similar to `pstree` prints parent-child relationship
	- `-u` - shows processes runing under specific user

- `top` - viewing processes in real time
	- together with CPU utilization
	- is interactive:
		- `K` - terminate a process
		- `R` - adjust the priority of a process

- `kill <PID>` - kill running task/process

- `lsof -l` - "List open files" show running services

- `bind` - manages key-bindings
	- `-l` - lists what keyboard shortcuts are bind to specific action
		- `ESC+.` - fills in last used argument

### Documentation
- `man` vs `help` - if the command is internal or external
	- can be found out by `type`
- `man`
	- `-k` - searches both the name and the description
		- `man -k copy` - will print all commands that have keywords copy, or have copy in came
		- `apropos` have the same functionality as `man -k`
	- `-f` - same as `whatis`
		- returns in what section a man page is stored in
	- it read manual pages and then displays it
- `help`
- `info`

### Variables, Paths, Programs

- `key=value` - variable definition
	- will persist only until term is closed
	- around `=` cannot be spaces
	- without type
	- in case of special characters, use `''`
	- if hyphens are not used, it's interepreted on call ad a command
	- in case of using space, the word after 1. space is taken as command
		- `runsomething=hey passwd random_user` ; `declare -p runsomething` will run `passwd`
- `$key` get the value of variable
- `unset` - remove a variable

- `declare` 
	- set a new variable
		- `declare KEY VALUE`
	- `-p <variable>` - printing list of variables

- `type` - gives you type of utility/program/executable
	- `-a` - prints all info (home, type, hashed/nonhashed)
	- internal build-in command
		- `type type` → `type is a shell builtdin`
		- `type`, `cd`, `echo
	- external commands
		- `type date` → `date is hashed (<home of date>)`
		- also `which` can give you its home
	- `type passwrd` → `passwd is <home of password>`
	- `hashed` vs `<non-hashed>`
		- `hashed` program was previously ran in shell and the address is being remembered
		- `<it's not written there>`  not run
		- makes calling utilities quicker

- running programs
	- `date` - searching in PATH if the path to the command is known
	- `./` - running from the folder
		- `user@machime:/usr/bin > ./date` - with `./`
	- `./`  - **absolute** path `/usr/bin/date`
	- using **relative** path when you are already partially in the path
		- `user@machine:/usr > bin/date` - without `/`
	
- `$PATH` - Stores all the binaries you're able to run
- `export -p` - prints all exported variables

- `alias` - creates a shortcut
	- `alias lsa=ls -la`

### Finding stuff in file structure
- `locate *filename*` - searches for a filename in the whole system directory
	- is indexed search, indexed by daily cron job
	- but uses/searched by name only
	- `-c` - how many results it has
	- `-b` - limits that the searched filename is the whole filename or other limitations
		- `locate -b "\passwd"`

- `whereis *filename*` - finding binaries in the whole system directory
	- returns PATH to the file as well as man page (if it has)

- `which *filename*` - return PATH of *filename*

- `find *filename* `- more powerfull search
	- path can be added → find /… *filename*
	- `-name`
	- `-size `- bitsize, ...
	- `-type` - file, folder, ...
	- `-user` - user owning it
	- `-perm` - permissions
	```sh
	# Find all directories named src
	find . -name src -type d
	# Find all python files that have a folder named test in their path
	find . -path '*/test/*.py' -type f
	# Find all files modified in the last day
	find . -mtime -1
	# Find all zip files with size in range 500k to 10M
	find . -size +500k -size -10M -name '*.tar.gz'
	# Delete all files with .tmp extension
	find . -name '*.tmp' -exec rm {} \;
	# Find all PNG files and convert them to JPG
	find . -name '*.png' -exec convert {} {}.jpg \;
	```
	- alternative to `find`: [fd](https://github.com/sharkdp/fd)
	- find and fd are not indexed searched

### Viewing, creating and editing files

- `touch` - create an empty file

- `cat` - reading file
	- `-n` - prints a number of line on start of a line

- `less` - newer than more
	- can move forward `\n` AND back (arrow up)
	- window forward ` ` or window back `B`
	- searched values are highlighted
	- can open multiple files (jumping with `n` and `N`)
	- `q` - quit; `h` - help
	- `/text` - searching text forward
	- `?text` - searching text backwords
	- `n` - jump to following text/file `N` jump to previous text/file
	- `10G` - jump to line 10, or just `G` to jump to the end

- `more` - prints first page of a document and then can be moved and "revelaed" more

- `file` - what is the type of the file

- `rm` - delete a file(s) or directory
  -  `-r` - recursive
  -  `-f` - force
  -  `-v` - verbouse
  -  `-i` - interactive mode, confirm the choice for each file

- `mv *path to current* *part to destination*` - move *current* *to where* 
	- can be used for renaming as well → MOVING + RENAMING
	- `-v` - verbous - will print the change in path for the file
	- `-i` - interactive mode - will ask to confirm change for every file
	- `-n` - to answer n (no) to each prompt automatically → do not override

- `cp *path to current* *path to destination*` - copy a file 
	- `-r` - including its content
	- `-v` - verbous - will print the change in path for the file
	- `-i` - interactive mode - will ask to confirm change for every file
	- `-n` - to answer n (no) to each prompt automatically → do not override

- `vim` -[[Vim]] 
	- text editor
	- enter INSERT mode : `i`
	- enter VIEWING mode: `ESC`
	- save and exit: `wq`

### Filtering
- "vertical" splitting and joining
	- `head`, `tail`, `split`, `cat`
- "horizontal" splitting and joining
	- `cut`, `paste`
- joining based on value - `join`
- ![[Pasted image 20221130151251.png]]

- `tee <files>` - duplicates stdout to file/s
	- `-a` - append to file

- `nl` - number of line
	- prins line numbers - can be used when piping results and testing
	- `-s΄<string>΄` - splitting text from line of text with `<string>`
	- `bp΄<string>΄` - returns only number of lines containg `<string>`

- `wc` - number of lines, words and chars
	- can take multiple files
	- `-l` - prints only number of lines
	- `-c` - prints only number of characters
	- `-w` - prints only number of words

- `head` - prints first (10) lines of file
	- `-n 20` - 20 lines will be printed
		- can be written as `-20`
	- `-n -20` - whole document except last 20 lines will be printed
	- `-c 20` - number of characters ~ prints first 20 characters

- `tail` - prints last (10) lines of file
	- `-n 20` - last 20 lines will be printed
	- `-n +20` - prints from number of line to the end
	- `-f` - prints changes in file end overtime
	- `-r` - prints in reverse

- get only one line from a file
	- `cat <file> | head -n 25 | tail -n 1`
		- or the other way round

- `split [flags] <file> [name]` - splits file by value
	- `-l 100` - will create files with insides of parameter file splitted every 100 lines
		- files created have alphabetical names
	- `-d` - files created will have numerical names
	- `-a 3` - file name will have lenght of x+3
	- `-b` - defines size of outputted files

- `cat x* > y` - joins all `x` files to `y` file

- `cut` - cut chosen file parts by columns
	- `-d<char>` - delimiter is `:`
	- `-f<int>`-> `-f1` - field is 1
		- can be also interval `3-5` or splitted by `,` (`3, 4, 9`)
	- `-c<char>` -> `-c1` - take one character

- `paste <files>` - joins same lines from one or more files to one file
	- `-d:` - delimiter
	- `-f<int>` - number of field

- `tr` - translate from a to b
	- `-s` - squeez - repeating characters are replaced with one symbol/char
		- `-s ' '` - from `   ` to ` `
	- `-c` - complement
	- `-d` - delete
		- `-cd 'a-zA-Z'` - delete everything alphabetical
	- class names - `[:alpha:]` (alphabetic), `[:lower:]`, `[:upper:]`
	- `tr : '\n' `- replaces `:` for `\n`

- `join` - joins lines from 2 files based on a value
	- `-t` - delimiter
	- `-a<number>` - adds lines even if they don't exist in the second file

- `sort` - sorting by one or more criterieas (by default alphanumericaly)
  -  `-r` - reverse
  - `-f` - ignores upper/lower case
  -  `-u` - removes duplicite lines
  - `-M` - first 3 letters are months (sorting by month)
  - `-t` - table delimeter (how the result will be separated)
  - `-k<start_column>[type][end_column]` - key - defines by which columns the sort will go
  - `-n` - sort type (numerical sort)

- `uniq [flags] <files>` - removes unique lines
	- `-c` - counting duplicites
	- `-d` - returns only duplicities
	- `-u` - returns only uniques

- `comm [-123] <file1> <file2>` - common lines
	- prints 3 columns - what is only in first file, what is only in second file and what is both
	- `-[123]` - prints everything EXCEPT 1st, 2nd, or 3rd column

- `diff [flags] <file1> <file2>` - differentiate between files
	- returns:
		- `3c3` - **c**hange in 3. line in the first and second file
		- `5d4` - **d**elete character on 5.line first file and 4. line of second file
		- `6a6,7` - **a**ddition of char to 6. and 7. line in second file
	- `-u[char]` - what changes (in 1st, missing in 2nd (`-`), in 2nd not in 1st (`-`)) happen in files
		- returns nicer changes (looks like git changes)
	- `-c[char]` - `[char]` can be `+-!` different return
	- `vimdiff` - shows the changes in two panels in vim

- `cmp [flags] <file1> <file2>` - compare two files and returns first diff
	- works also with binary files
	- `-s` - silent (prints nothing only return code)

- `patch` - files versing

- `sed` - stream editor
	- line length: `-l <number>`

- `grep <string> <file>` 
	- find data inside of data
	- you can search through multiple files: `… <file1> <file2> …`
	- supports [[Regular Expression]]!
	- `-E` - egrep, extended use
	- `-F` - for normal strings (fixed string)
	- `-o` - returns only matching parts of line
	- `-v` - find lines that do NOT have that symbol (vise versa)
	- `-w` - contained as a word (not part of word )
	- `-i` - case-insensitive
	- `-c` - count, how many results it found in each file
	- `-n` - number of line where the match is
	- `-l` - for more files: if match is in file, filename is returned
	- alternatives: `ack`, `ag`, `rg`

- `rp` - ripgrep
	```sh
	# Find all python files where I used the requests library
	rg -t py 'import requests'
	# Find all files (including hidden files) without a shebang line
	rg -u --files-without-match "^#!"
	# Find all matches of foo and print the following 5 lines
	rg foo -A 5
	# Print statistics of matches (# of matched lines and files )
	rg --stats PATTERN
	```


### Network
- specific files to network config are dependent on distro used
	- CentOS - `/etc/sysconfig/network-scripts/ifcfg-eth0`

- `ifconfig` - get and display IP address

- `ip a` - like `ifconfig`

- `route` - shows routing table
	- `-n` - prefer numberic info (default = 0.0.0.0)
	- obsolete → replaced with `ip route show`

- `ping` - test if host is reachable
	- `-c` - limits how many pings will be sent
	- test only if ICMP is open

- `netstat` - large amout of information about network
	- `-i` - display statistics regarding network traffic
	- `-r` - display routing info
	- `-t` - TCP
	- `-l` - lists ports that are listening (open)
	- `-n` - show numbers (not names)
	- `-a` - all info (?)
	- `-o` - show open ports

- `ss` - show socket statistics
	- supports all major packet and sock type
	- a possible replacement for `netstat`
	- data displayed in collumns:
		- Netid - socket type and transport protocol
		- State - connected/unconnected (depends on protocol)
		- Recv-Q - amount of data queued up for being processed having been received
		- Send-Q – amountof data queued up for being sent to another host
		- Local Address - address and port of the local host's portion of the connection
		- Peer Address - address and port of the remote host's portion of the connection
	- `-s` - displayes mostly types of sockets, statistics

- `dig` - manual querying of recursive DNS server of our choice
	- useful tool for network troubleshooting - testing the functionality if the DNS server that the host is using
	- syntax: `dig <domain @<dns-server-ip>>`

- `host` - works with DNS to associate a hostname with IP
	- `-t` - use CNAME/SOA → `host -t CNAME/SOA example.com`
	- `-a` - all options

- `ssh <username>@<target>` - remote connection to target
- `ssh-keygen` - generate an SSH key
	- stored in `/home/<user>/.ssh`
		- fingerprint of server (to check if we trust it)
		- two files `id_rsa` (privite) and `id_rsa.pub` (public)
		- known hosts
	- `-R <hostname>` - remove SSH key of hostname

- `ssh-copy-id <username>@<target>` - add SSH key to a server

- `scp` - for copying files from one machine to another
	- 

- `wget *cesta*` - display the route taken to target

- `service *X* start` - start a *X* on your IP address
	- apache2 - server
	- ssh
	- postgresql - DB

- `traceroute` - hops that traffic take to get to target

### Users and groups

- `su` - allows you to run a shell as a different iser
	- `su *X*` - change user to *X*
	- `su -`/`su -l`/`su --login` - login shell
	- `su -` = `su - root`- by default if username is not defined, `su` opens new shell as root

- `sudo [options] command` - allows users to execute commands as another user

- `id [options] username` - prints info about user
	- id and name of user and id and name of its group(s)

- `uname` - prints info about host machine
	- `-a` - all info

- `who` - who is also logged into the machine
	- contains from where they are logged in, time, etc
	- `who am i` - subpart of `who` but prints same info ONLY about current user
	-
- `whoami` - prints name of current user

- `tty` - "TeleTYpe"
	- whole route to file representing your connection to the machine

- `useradd` - creates a user
	- `-D` - view or change some values
	- `-g` - change primary group
	- `-G` - change supplementary group
	- `-b` - change base directory
	- `-d` - allows to specify existing directory or new home directory to create for the user
	- `-f` - allows you to use a different INACTIVE value than the default one
	- `-e` - set up EXPIRE
	- `-s` - change default shell/bash/zhs/fsh
	- `-k` - change SKEL (skeleton) directory
	- `-u` - specify user id (UID)
	- `-m` and `-M` - defines if home directory is created or not

- `usermod` - modify a user
	- `-c` - set a COMMENT
	- basically same options as with `useradd`
		- `-d <HOME_DIR>`, `-e <EXPIRE_DATE>`, `-f INACTIVE`, `-g GROUP`, `-G GROUPS`, `-s SHELL`, `-u NEW_UID`
	- `-L` and `-U` - lock and unlock
	- `-a` - append additional groups

- `userdel` - delete a user

- `groupadd` - creates a new group
	- `-g` - specify the group id
	- `-r` - assigns the new group a GID that is less then the lowest standart GIDy

- `groupmod` - modifying a existing group
	- `-n` - change name of group
	- `-g` - change a group id (GID)

- `groupdel` - delete a group

*- `addgroup X` - creates a new group X*
*- `adduser X` - creates a new user X*

- `passwd X` - changes password for X user

- `chage` - options for managing the password aging info in `/etc/shadow`
	- `-l` - list account aging info
	- `-d <LAST_DAY>` - set the date of the last password change to `<LAST_DAY>`
	- `-E <EXPIRE_DATE>` - set account to expire on `<EXPIRE_DATE>`
	- `-I` - set account to permit login for INACTIVE days after password expires
	- `-m <MIN_DAYS>`/ `-M <MAX_DAYS>` - sets minimum/maximum number of days before the password can be changed
	- `-W <WARN_DAYS>` - days before it starts warning user


### Permissions

- `chmod <permission> <file>` - allows set permission to read/write/execute files and folders to various users and groups
	- one digit for each group from: user and group and everyone else
	- eg. 
		- 341 = user that owns the file can X+W, group that owns it can R, everyone else can X
		- 777 = everyone can do anything    
Digit | Meaning
--------- | --------
1 | That file can be executed (X)
2 | That file can be written to (W)
3 | That file can be executed and written to
4 | That file can be read (R)
5 | That file can be read and executed
6 | That file can be written to and read
7 | That file can be read, written to, and executed

- `chown user:group file` - changing the ownership of file to user/group

- `getent passwd <username>` - get info about your account



### Installing, updating
`apt-get install *X*` - installs *X* package

`apt update` - update

`apt upgrade` - upgrade

`apt purge *X*` - uninstall/remove a *X* package


### Archiving and Compression
- archiving
	- combine multiple files eliminating overhead in individual files and makes the files easier to transport
	- [[tar]]
- compression
	- makes the files smaller by removing redundant information
	- lossless
		- no information is removed from the file
	- lossy
		- information is removed from the file
		- if the files is compresed and then decompressed, it is different then the original one
	- [[gzip]]


### Scripting
- define type of code
	- `#!/bin/bash` - bash
1. Functions
	- can be declared in shell
	- `function_name () {}`
	- in shell it looks weird:
	```sh
	my_function () {
	> ls /home
	> cal 2022
	> echo "No interesting function"
	> }
	```
	- by default created with `+x` so it can run without `./`
	-  ```
			mcd () {
				mkdir -p "$1"
				cd "$1"
			}
		- creates a new folder with name given from parametr and enters it
		- 	- arguments and special characters:
		- `$0` - Name of the script
		-   `$1` to `$9` - Arguments to the script. `$1` is the first argument and so on.
		-   `$@` - All the arguments
		-   `$#` - Number of arguments
		-   `$?` - Return code of the previous command
		-   `$$` - Process identification number (PID) for the current script
		-   `!!` - Entire last command, including arguments. A common pattern is to execute a command only for it to fail due to missing permissions; you can quickly re-execute the command with sudo by doing `sudo !!`
		-   `$_` - Last argument from the last command. If you are in an interactive shell, you can also quickly get this value by typing `Esc` followed by `.` or `Alt+.`
		-   [some more special chars](https://tldp.org/LDP/abs/html/special-chars.html)
	-   binary decidions:
		-   `||` - or
			-   `false || echo "Oops, fail"` → `Oops, fail`
			-   `true || echo "Always true"` → ``
		- `&&` - and
			- `true && echo "Is true"` → `Is true`
			- `false && echo "False"` → ``
		- `;` - just a division of commands - both will execute
			- `true ; echo "Will print"` → `Will print`
			- `false ; echo "Will print"` → `Will print`
	- running command in command ~ command substition:
		- the inner command will run first
			- `diff <(ls bar) <(ls foo)` - difference between ls of bar and foo
			- `for file in $(ls)` - do something with each file in ls of some dir
	- standart output and error:
		- `grep foobar "$file" > /dev/null 2>dev/null` - moving STDOUT and STDERR to /dev/null
	- comparissons:
		- using double brackets `[[ ]]`
		- [more info](http://mywiki.wooledge.org/BashFAQ/031)
	- globbing
		- wildcards, curly braces
			- `foo*` - match foo-something
			- `foo*.{php,html,js}` - matches foo-something with extenstions php/html/js
			- `mv *.{sh,py} folder` - will move all sh and py to folder
	- [spellcheck shellcheck tool](https://github.com/koalaman/shellcheck)
2. Conditions
	1. If
		- must start with `if` and end with `fi`
		```sh
		if somecommand; then
			# do something
		fi
		```
		- often used command [[CyberSec/Tools/test]] 
		- also `else`  and `elif` can be added
		```sh
		#!/bin/bash
		if [ "$1" = "hello" ]; then
			echo "hello yourself"
		elif [ "$1" = "goodbuy" ]; then
			echo "nice to have met you"
			echo "hope to see you again"
		else
			echo "didn't understand"
		fi	
		```
	2. Case
		- makes sense for more conditions
		```sh
		#!/bin/bash

		case "$1" in
		hello|hi)
		  echo "hello yourself"
		  ;;
		goodbye)
		  echo "nice to have met you"
		  echo "I hope to see you again"
		  ;;
		*)
		  echo "I didn't understand that"
		esac
```
3. Loops
	- `for` and `while`
	- for:
	```sh
	#!/bin/bash

	SERVERS="servera serverb serverc"
	for S in $SERVERS; do
	  echo "Doing something to $S"
	done
```
	- while:
	```sh
	#!/bin/bash

	i=0
	while [ $i -lt 10 ]; do
	  echo $i
	  i=$(( $i + 1))
	done
	echo “Done counting”
```

### Quotes
- double quotes `""
	- stop the shell fro minterpreting some metachars including glob characters (wild cards)
	- still allow command and variable susbtitution
		- `echo "The path is $PATH" - will print the path
- single quotes `''`
	- orevent the shell from dooing any inty interpreting of special chars, including globs, variables, command substitutions and other metachars
	- `echo "$foo"` → `bar`
	- `echo '$foo'` → `foo` ~ literal strings
- backlash `\`
	- escaping special chars
		- `echo The service costs \$1 and the path is $PATH` → prints dollar 1 and PATH
- backquotes
	- "treat as command"
		- `echo Today is `date`
