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
	- when used with `|`, eg. `history | grep ping` -> will find how the specific command was used
	- history based suggestion tool: [fish](https://fishshell.com/)
	- can be enabled in zsh
	- history behaviour can be changed in `.bashrc`
		- `HISTCONTROL=ignorespace`
	
- directory navigation
	- symlinks `ln -s`
	- `fasd` (frequency + recency), `autojump`
	- `tree` - get tree view of directories
	- `nnn`, `ranger`

- `>` - output redirection
	- `echo hello > file`; `cat file` -> `hello`
	- if the "receiving" file does not exist, will be created

- `<` - rewiring output like with `>` but the other way round
	- ```missing:~$ echo hello > hello.txt
	missing:~$ cat hello.txt
	hello
	missing:~$ cat < hello.txt
	hello
	missing:~$ cat < hello.txt > hello2.txt
	missing:~$ cat hello2.txt
	hello

- `>>` - output redirection - appends to the end of file
	-  `echo nood >> file` => `cat file -> hello \n nood`
	- if the "receiving" file does not exist, will be created

- `&&` - and
	- eg. `echo hey >> file2 && cat file2` -> `hey`

- `$` - denotes environment variables
	- eg. `echo $USER` -> prints current user

- `|` - pipe - take the output of previous command and uses it in the next

- `;` - similar to pipe but it does not require the first command to execute successfully
	- eg. `./somebullshitthatdontexit ; ls` - ls will still list
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
	- `-h` - print size in human readable form (must be used with `-l`)
	- `-S` - sorting by size (big->small); reversed sorting w/ `-r`
	- `-t` - sort by last modified
	- `--full-time` - full time of last modification
	- `?????` - prints all 5-characters long files in folder
		- of course can be used with different lenghts of filenames
	- `-w <number>` - "width" print only `<number>` of chars per line
	- certain folder can be specified
		- `ls -laR /dev /tmp` - will print EVERYTHING and recursively from `/dev` and `/tmp`
	- File Types -> Permissions -> Hard Link count -> User Owner -> Group Owner -> File Size -> Time Stamp -> File Name
		- `d` (directory), `-` (regular file), `l` (symbolic link), `s` (socket), `p` (pipe), `b` (block file), `c` (character file)
    
- `mkdir` - create a folder 
	- `-p` - with parent folder (`mkdir -p a/c/d/v/` )

- `rmdir` - delete a folder
	- only if the directory is empty

- `tree` - prints the current file system tree

- `ps` - shows list of running tasks with their PID (process ID), PPID (parent process ID)
list of all system processes: `-ef`

- `kill <PID>` - kill running task/process

- `lsof -l` - "List open files" show running services


### Documentation
- `man` vs `help` - if the command is internal or external
	- can be found out by `type`
- `help`
- `man`
	- `-k` - searches both the name and the description
		- `man -k copy` - will print all commands that have keywords copy, or have copy in came
		- `apropos` have the same functionality as `man -k`
	- `-f` - same as `whatis`
		- returns in what section a man page is stored in
- `info`

### Variables, Paths, Programs

- `key=value` variable definition
	- will persist only until Term is closed
	- around `=` cannot be spaces
	- without type
	- in case of special characters, use `''`
	- if hyphens are not used, it's interepreted on call ad a command
	- in case of using space, the word after 1. space is taken as command
		- `runsomething=hey passwd random_user` ; `declare -p runsomething` will run `passwd`
- `$key` get the value of variable
- `unset` - remove a variable

- `declare` 
	-  `-p <variable>` - printing list of variables

- `type` - gives you type of a utility/program/executable
	- `-a` - prints all info (home, type, hashed/nonhashed)
	- internal build-in command
		- `type type` -> `type is a shell builtdin`
		- `type`, `cd`, `echo
	- external commands
		- `type date` -> `date is hashed (<home of date>)`
		- also `which` can give you its home
	- `type passwrd` -> `passwd is <home of password>`
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
	- `-c` - how many result it has
	- `-b` - limits that the searched filename is the whole filename or other limitations
		- `locate -b "\passwd"`

- `whereis *filename*` - finding binaries in the whole system directory
	- returns PATH to the file as well as man page (if it has)

- `which *filename*` - return PATH of *filename*

- `find *filename* `- more powerfull search
	- path can be added =>  find /… *filename*
	- `-name`
	- `-size `- bitsize,...
	- `-type` - file, folder,...
	- `-user` - user owning it
	- `-perm` - permissions
	-  ```
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
	- alternative to `find`: [fd](https://github.com/sharkdp/fd)
	- find and fd are not indexed searched

### Viewing, creating and editing files
- `touch` - create an empty file

- `less` - newer then more
	- can move forward (arrow down) AND back (arrow up)
	- searched values are highlighted
	- can open multiple files (jumping with `n` and `N`)
	- `q` - quit; `h` - help
	- `/text` - searching text forward
	- `?text` - searching text backwords
	- `n` - jump to following text/file `N` jump to previous text/file
	- `10G` - jump to line 10, or just `G` to jump to the end

- `more` - prints first page of a document and then can be moved and "revelaed" more

- `nl` - number of line
	- prins line numbers - can be used when piping results and testing

- `cat` - reading file
	- `-n` - prints a number of line on start of a line

- `file` - what is the type of the file

- `rm` - delete a file or directory
  -  `-r` - recursive
  -  `-f` - force
  -  `-v` - verbouse
  -  `-i` - interactive mode, confirm the choice for each file

- `mv *path to current* *part to destination*` - move *current* *to where* 
	- can be used for renaming as well -> MOVING + RENAMING
	- `-v` - verbous - will print the change in path for the file
	- `-i` - interactive mode - will ask to confirm change for every file
	- `-n` - to answer n (no) to each prompt automatically -> do not override

- `cp *path to current* *path to destination*` - copy a file 
	- `-r` - including its content
	- `-v` - verbous - will print the change in path for the file
	- `-i` - interactive mode - will ask to confirm change for every file
	- `-n` - to answer n (no) to each prompt automatically -> do not override

- `head`/`tail` - prints first/last line of file

- `wc` - number of lines, words and chars

- `sort` - sorts the text inside of a file
  -  `-r` reverse
  -  `-u` - remove duplicite lines
  - `-t` - field delimeter (how the result will be splitted)
  - `-k` - field number (sort by field)
  - `-n` - sort type (numerical sort)

- `uniq *parametry* *soubor*` - odstraneni unikatnich radku

- `vim` - text editor
	- enter INSERT mode : `i`
	- enter VIEWING mode: `ESC`
	- save and exit: `wq`

- `diff` - differentiate between files

- `cut` - cut chosen file parts

- `sed` - stream editor
	- line length: `-l <number>`

- `grep <string> <file>` 
	- find data inside of data
	- you can search through multiple files: `… <file1> <file2> …`
	- supports regular expression!
	- `-v` - find lines that do NOT have that symbol
	- `-i` - case insensitive
	- alternatives: `ack`, `ag`, `rg`

- `rp` - ripgrep
	```
	# Find all python files where I used the requests library
	rg -t py 'import requests'
	# Find all files (including hidden files) without a shebang line
	rg -u --files-without-match "^#!"
	# Find all matches of foo and print the following 5 lines
	rg foo -A 5
	# Print statistics of matches (# of matched lines and files )
	rg --stats PATTERN
	```

- `tr` - "translate" / replace
	- `tr : '\n' `-  replaces `:` for `\n`


### Network
- `wget *cesta*` - stahne cestu tam kde zrovna je

- `netstat -ano` - all ports that are open and what is connected to those ports

- `route` - shows routing table

- `ifconfig` - get and display IP address

- `service *X* start` - start a *X* on your IP address
	- apache2 - server
	- ssh
	- postgresql - DB

- `ip a` - jako `ifconfig` ale pro jinou dist

- `traceroute` - hops that traffic take to get to target

- `ssh <username>@<target>` - remote connection to target

- `ssh-keygen` - utility for generating SSH keys
	- SSH key
		- fingerprint of server (to check if we trust it)
		- privite part and public part (`.pub`)
	- in `.ssh` folder there is:
		- privite, public key
		- known hosts

- `ssh-copy-id <username>@<target>` - add SSH key to a server



### Users and permissions
- `id` - prints info about user
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

- `sudo su` - change to sudo

- `su *X*` - change user to *X*

- `adduser X` - creates a new user X

- `addgroup X` - creates a new group X

- `passwd X` - changes password for X user

- `chmod <permission> <file>` - allows set permission to read/write/execute files and folders to various users and groups
one digit for each group from: user and group and everyone else
eg.: 
341 = user that owns the file can X+W, group that owns it can R, everyone else can X
777 = everyone can do anything
    
Digit
Meaning
1
That file can be executed (X)
2
That file can be written to (W)
3
That file can be executed and written to
4
That file can be read (R)
5
That file can be read and executed
6
That file can be written to and read
7
That file can be read, written to, and executed

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


### Generic and common places
`/etc/passwd` - Stores user information - Often used to see all the users on a system

`/etc/shadow` - Has all the passwords of these users

`/tmp` - Every file inside it gets deleted upon shutdown - used for temporary files

`/etc/sudoers` - Used to control the sudo permissions of every user on the system    
  
`/home` - The directory where all your downloads, documents etc are. 
The equivalent on Windows is C:\Users\<user>

`/root` - The root user's home directory 
The equivalent on Windows is C:\Users\Administrator

`/usr` - Where all your software is installed 

`/bin` and `/sbin` - Used for system critical files - DO NOT DELETE

`/var` - The Linux miscellaneous directory, a myriad of processes store data in /var


### Scripting
1. Functions
	- can be declared in shell
	- `function_name () {}`
	- in shell it looks weird:
	```
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
			-   `false || echo "Oops, fail"` => `Oops, fail`
			-   `true || echo "Always true"` => ``
		- `&&` - and
			- `true && echo "Is true"` => `Is true`
			- `false && echo "False"` => ``
		- `;` - just a division of commands - both will execute
			- `true ; echo "Will print"` => `Will print`
			- `false ; echo "Will print"` => `Will print`
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


##### Quotes
- double quotes `""
	- stop the shell fro minterpreting some metachars including glob characters (wild cards)
	- still allow command and variable susbtitution
		- `echo "The path is $PATH" - will print the path
- single quotes `''`
	- orevent the shell from dooing any inty interpreting of special chars, including globs, variables, command substitutions and other metachars
	- `echo "$foo"` -> `bar`
	- `echo '$foo'` -> `foo` ~ literal strings
- backlash `\`
	- escaping special chars
		- `echo The service costs \$1 and the path is $PATH` -> prints dollar 1 and PATH
- backquotes
	- "treat as command"
		- `echo Today is `date`
