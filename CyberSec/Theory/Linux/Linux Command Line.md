2- CASE SENSITIVE


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

- `&&` - and, eg. `echo hey >> file2 && cat file2` -> `hey`

`$` - denotes environment variables, eg. echo $USER -> prints current user

`|` - pipe - take the output of previous command and uses it in the next

`;` - similar to pipe but it does not require the first command to execute successfully, eg. ./somebullshitthatdontexit ; ls (ls will still list)

- `pwd` - "Path to a Working Directory" print working path = find yourself
	- `pwd > absolute_path `- saving absolute path into a file absolute_path

- `cd` - folder orientations

- `ls` - list a folder
	- `-l` - long
	- `-a` - including hidden ones
	- `-R` - recursive
	- `-d` - information about spefied folder (don't care about insides)
	- `?????` - prints all 5-characters long files in folder
		- of course can be used with different lenghts of filenames
	- `-w <number>` - "width" print only `<number>` of chars per line
	- certain folder can be specified
		- `ls -laR /dev /tmp` - will print EVERYTHING and recursively from `/dev` and `/tmp`
    
- `mkdir` - create a folder 
	- `-p` - with parent folder (`mkdir -p a/c/d/v/` )

- `rmdir` - delete a folder

- `tree` - prints the current file system tree

- `ps` - shows list of running tasks with their PID (process ID), PPID (parent process ID)
list of all system processes: `-ef`

- `kill <PID>` - kill running task/process

- `lsof -l` - "List open files" show running services

##### Documentation
- `man` vs `help` - if the command is internal or external
	- can be found out by `type`
- `help`
- `man`
- `info`

### Variables, Paths, Programs

- `key=value` variable definition
	- will persist only until Term is closed
	- around `=` cannot be spaces
	- without type
	- in case of special characters, use `''`
	- in case of using space, the word after 1. space is taken as command
		- `runsomething=hey passwd random_user` ; `declare -p runsomething` will run `passwd`
- `$key` get the value of variable

- `declare` 
	-  `-p <variable>` - printing list of variables

- `type` - gives you type of a utility/program/executable
	- `type type` -> `type is a shell builtdin`
	- `type date` -> `date is hashed (<home of date>)`
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
	


### Finding stuff in file structure
- `locate *filename*` - searches for a filename in the whole system directory
	- is indexed search, indexed by daily cron job
	- but uses/searched by name only

- `whereis *filename*` - finding binaries in the whole system directory
returns PATH to the file as well as man page (if it has)

- `which *filename*` - return PATH of *filename*

- `find *filename* `- more powerfull search
	- path can be added =>  find /… *filename*
	- `-name`
	- `-size `- bitsize,...
	- `-type` - file, folder,...
	- `-user` - user owning it
	- `-perm` - permissions
	-  ```# Find all directories named src
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

- `cat` - reading file
	- `-n` - prints a number of line on start of a line

- `file` - what is the type of the file

- `rm` - delete a file
   ` -r` - recursive
   ` -f` - force
   ` -v` - verbouse
   ` -i `- inform; bude ptat jestli to myslim vazne

`mv *path to current* *part to destination*` - move *current* *to where* 
can be used for renaming as well
=> MOVING + RENAMING

`cp *path to current* *path to destination*` - copy a file 
-r = including its content

`head`/`tail` - prints first/last line of file

`unzip`/`zip` - zip/unzip a file

`wc` - number of lines, words and chars

`sort` - sorts theinside of a file
   ` -r` reverse
   ` -u` - remove duplicite lines

`uniq *parametry* *soubor*` - odstraneni unikatnich radku

- `vim` - text editor
	- enter INSERT mode : `i`
	- enter VIEWING mode: `ESC`
	- save and exit: `wq`

`diff` - differentiate between files

`cut` - cut chosen file parts

`sed` - stream editor
line length: `-l <number>`

`grep <string> <file>` - find data inside of data
you can search through multiple files: `… <file1> <file2> …`
supports regular expression!
find lines that do NOT have that symbol: `-v`
case insensitive: `-i`

- `tr` - "translate" / replace
	- `tr : '\n' `-  replaces `:` for `\n`

### Network
`wget *cesta*` - stahne cestu tam kde zrovna je

`netstat -ano` - all ports that are open and what is connected to those ports

`route` - shows routing table

`ifconfig` - get and display IP address

`service *X* start` - start a *X* on your IP address
apache2 - server
ssh - 
postgresql - DB

`ip a` - jako `ifconfig` ale pro jinou dist

`traceroute` - hops that traffic take to get to target

`ssh <username>@<target>` - remote connection to target

`ssh-keygen` - utility for generating SSH keys
	- SSH key
		- fingerprint of server (to check if we trust it)
		- privite part and public part (`.pub`)
	- in `.ssh` folder there is:
		- privite, public key
		- known hosts

`ssh-copy-id <username>@<target>` - add SSH key to a server



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

`$PATH` - Stores all the binaries you're able to run
`export -p` - prints all exported variables