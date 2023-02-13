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
		- number of bytes taken

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
  - `-u` - removes duplicite lines
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

- `grep <string> <file>` 
	- find data inside of data
	- you can search through multiple files: `… <file1> <file2> …`
	- supports [[Regular Expression]]!
	- `-E` - egrep, extended use
	- `-e` - expression, usually a regex
		- `grep -E` vs `grep -e -E` - `-E` is not an argument
		- can be used multiple times, if more it is used as OR
	- `-f` - file - list of regex templates
	- `-F` - for normal strings (fixed string)
	- `-o` - returns only matching parts of line
	- `-v` - find lines that do NOT have that symbol (vise versa)
	- `-w` - contained as a word (not part of word )
	- `-i` - case-insensitive
	- `-c` - count, how many results it found in each file
	- `-n` - number of line where the match is
	- `-l` - for more files: if match is in file, filename is returned
	- `--color` - will color matched parts
		- can be setup as `--color=always`
		- `A<int>` (after), `B<int>` (before), `C<int>` (context = A+B) - number of lines that will be printed after/before/around the matches
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

- `sed` - [[sed]]
- `awk` - [[awk]]

### Scripting
- [[CyberSec/Theory/Programming Languages/Bash/Intro]]

#### Blocks of commands
- `{ <command1>; <command2>; }` - block in current shell
	- list of commands ends with `;` or new line
	- if directory is non-existent, create it (if successful print message), go into it, if it will not suceed print "Wasn't successful"
	```bash
	D=/tmp/foo
	cd "$D" || { mkdir "$D" && echo "Adresar '$D' je vytvoren"; cd "$D"; } || echo "Wasn't successful"
	```
	- 
- `( <command1>; <command2> )` - block of code in **subshell**
	- runs in different thread
	- if used with `$( <command> )` we want the output
	- `echo $BASH_SUBSHELL` - testing if user is in subshell ( is subshell)

#### Quotes
- double quotes `""
	- stop the shell from misinterpreting some metachars including glob characters (wild cards)
	- still allow command and variable susbtitution
		- `echo "The path is $PATH" - will print the path
- single quotes `''`
	- prevent the shell from dooing any inty interpreting of special chars, including globs, variables, command substitutions and other metachars
	- `echo "$foo"` → `bar`
	- `echo '$foo'` → `foo` ~ literal strings
- backlash `\`
	- escaping special chars
		- `echo The service costs \$1 and the path is $PATH` → prints dollar 1 and PATH
- backquotes
	- "treat as command"
		- `echo Today is `date`
l
### Permissions
- read, write, execute
	- for folders also `t` = sticky bit + execute
		- `T` - have sticky bit, cannot execute
		- sticky bit modifies write permissions to file in folder
		- ![[Pasted image 20221215163359.png]]
	- without execute permission, no right to change content of folder
	- write permission for others is highly risky
		- RWX permission to folder with a wanted file (file permission is only read)
		- -> create a new file in the folder and copy the file content into the new file
	- even without the R permission you can try to list SPECIFIC names of files
		- with permission X
		- `ls x-only/file{1,2,3}`
	- `1`- X; `2` - W; `4` - R; `3` - X+W; `5` - X+R; `6` - W+R; `7` - R+W+X
		- 341 = user that owns the file can X+W, group that owns it can R, everyone else can X
		- 777 = everyone can do anything
- 3 types of users -> 3x3 permissions
	- owner, group, others
- together 12 bits/ 4 octal digits:
	- specials + user/owner + group + others
	- = BASIC MODEL

##### Access Control List
- expansion of basic model
- there can be more users and groups on one object
- `getfacl`, `setfacl`

- `stat` - information about a file
	- `-L` - follow links (only permission at the end of link interests us)
	- `-c` - format - will print according to format
	- `%a`, `%A` - permissions in octal, in human readable form
	- `%i` - inode number
	- `%n` - file name
	- `%s` - total size, in bytes
	- `%u`/`%U` - user ID/name of owner
	- `%w`, `%x`, `%z` - last access, data modification, status change

- `chmod <permission> <file/s>` - allows set permission to read/write/execute files and folders to various users and groups
	- `-R` - recursive
		- `chmod -R =rwX dir` - for all content in "dir" set permissions to read, write and execute for folders
	- absolute
		- octal (one digit for each group from: user and group and everyone else) or symbolic
	- relative
		- symbolic (generally plus/minus permission)
		- to whom | how | what
		- if to whom is empty is goes to all
		- if `=` is empty is will remove all permissions
		- `+r` (plus read), `-w` (minus write), `=x` (just execute for file and for folder), `X` (execute for folder only)
		- `s` and `t` - set and sticky bit
		- `u/g/o` - set same rights as user/group/others
		- `u` (user), `g` (group), `o` (others), `a` (all), `<empty>`

- `umask` - removes set of permissions for newly created files and folders
	- `-S` - prints permissions in symbolic representation
		- `chmod $( umask -S | tr x X ) file dir` - changes `x` for `X` for "file" and "dir"
	- different build-in security levels
		- Permissive: umask lvl 022; effective permission 755; `rwxr-xr-x`
		- Moderate: 026; 751; `rwxr-x--x`
		- Moderate: 027; 750; `rwxr-x---`
		- Severe: 077; 700; `rwx------`
	- 

- `chown user:group file` - changing the ownership of file to user/group

- `getent passwd <username>` - get info about your account



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

- `find *filename* `- [[find]]
	- alternative to `find`: [fd](https://github.com/sharkdp/fd)
	- find and fd are not indexed searched

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


### Processes (unix) and jobs (shell)
- Process ID = PID
- processes are made/created from another process
	- parent-child relationship
- `ps` - process status
	- shows current running processes
	- `-f` - more info
	- `-o` - what specific information I want
	- `--forest` - similar to `pstree` prints parent-child relationship
	- `-u` - shows processes runing under specific user
		- or to use `ps -eo user,pid,args | grep "^ *$USER "`
- `pstree` - tree of all running processes
	- prints family tree of processes
- `pgrep` - effective searching for processes
	- `-l`
	- `-x`
	- `-U` - username
	- `ps -o pid,ppid,user,args -p "$(pgrep -U "$USER" sleep)"` - find all processes "sleep" running under my current user

- `top` - viewing processes in real time
	- together with CPU utilization
	- is interactive:
		- `K` - terminate a process
		- `R` - adjust the priority of a process

- `prstat` - process statistics

- it's possible to control processes with signals
	
- `kill <PID>` - kill running task/process
	- by default SIGTERM (terminate)
	- `-s`, `-n` - signal name/number
	- `-l` - list signal numbers
	- SIGKILL and SIGSTOP cannot be ignored
		- others have programmable response

- `pkill` - sending signal to multiple processes
	- `pkill -U "$USER" sleep` - kill all speeps running under current user
	- have almost the same syntax as `pgrep`

- `lsof -l` - "List open files" show running services

- processes vs jobs:
	- ![[Pasted image 20221214211119.png]]

- `fg` - move job to foreground
- `bg` - more job to background
- `jobs` - running jobs

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

### Installing, updating
`apt-get install *X*` - installs *X* package

`apt update` - update

`apt upgrade` - upgrade

`apt purge *X*` - uninstall/remove a *X* package


