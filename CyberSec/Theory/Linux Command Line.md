##### General, Folders and Paths

- `echo` - vypise do console 
	- vytvori soubor s nejakym obsahem `echo “Hello world!” > hello.txt`
	- pri pouziti `>>` se prida string na posledni radek

- `history` - shows bash history
	- when used with `|`, eg. `history | grep ping` -> will find how the specific command was used

- `>` - output redirection, eg. echo hello > file; cat file -> hello

- `>>` - output redirection - appends to the end of file, eg."
	-  `echo nood >> file` => `cat file -> hello \n nood`

&& - and, eg. echo hey >> file2 && cat file2 -> hey

$ - denotes environment variables, eg. echo $USER -> prints current user

| - pipe - take the output of previous command and uses it in the next

; - similar to pipe but it does not require the first command to execute successfully, eg. ./somebullshitthatdontexit ; ls (ls will still list)

pwd - print working path = find yourself
pwd > absolute_path - saving absolute path into a file absolute_path

cd - folder orientations

ls - list a folder
-l = long
-a = including hidden ones
    
mkdir - create a folder 

rmdir - delete a folder

tree - prints the current file system tree

ps - shows list of running tasks with their PID (process ID), PPID (parent process ID)
list of all system processes: -ef

kill <PID> - kill running task/process

finding stuff in file structure
locate *filename* - searches for a filename in the whole system directory

whereis *filename* - finding binaries in the whole system directory
returns PATH to the file as well as man page (if it has)

which *filename* - return PATH of *filename*

find *filename* - more powerfull search
path can be added =>  find /… *filename*
-name
-size - bitsize,...
-type - file, folder,...
-user - user owning it
-perm - permissions

viewing, creating and editing files
touch - create an empty file

cat - reading file
prints a number of line on start of a line: -n 

file - what is the type of the file

rm - delete a file
    -r - recursive
    -f - force
    -v - ukecany
    -i - bude ptat jestli to myslim vazne

mv *path to current* *part to destination* - move *current* *to where* 
can be used for renaming as well
=> MOVING + RENAMING

cp *path to current* *path to destination* - copy a file 
-r = including its content

head/tail - prints first/last line of file

unzip/zip - zip/unzip a file

wc - number of lines, words and chars

sort - sorts theinside of a file
    -r reverse
    -u - remove duplicite lines

uniq *parametry* *soubor* - odstraneni unikatnich radku

vim - text editor
enter INSERT mode : i
enter VIEWING mode: ESC
save and exit: wq

diff - differentiate between files

cut - cut chosen file parts

sed - stream editor
line length: -l <number>

grep <string> <file> - find data inside of data
you can search through multiple files: … <file1> <file2> …
supports regular expression!
find lines that do NOT have that symbol: -v
case insensitive: -i

network
wget *cesta* - stahne cestu tam kde zrovna je

netstat -ano - all ports that are open and what is connected to those ports

route - shows routing table

ifconfig - get and display IP address

service *X* start - start a *X* on your IP address
apache2 - server
ssh - 
postgresql - DB



nmap (in Tools)
users and permissions
whoami - current user

sudo su - change to sudo

su *X* - change user to *X*

adduser X - creates a new user X

addgroup X - creates a new group X

passwd X - changes password for X user

chmod <permission> <file> - allows set permission to read/write/execute files and folders to various users and groups
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

chown user:group file - changing the ownership of file to user/group
installing, updating
apt-get install *X* - installs *X* package

apt update - update

apt upgrade - upgrade

apt purge *X* - uninstall/remove a *X* package


generic and common places
/etc/passwd - Stores user information - Often used to see all the users on a system

/etc/shadow - Has all the passwords of these users

/tmp - Every file inside it gets deleted upon shutdown - used for temporary files

/etc/sudoers - Used to control the sudo permissions of every user on the system    
  
/home - The directory where all your downloads, documents etc are. 
The equivalent on Windows is C:\Users\<user>

/root - The root user's home directory 
The equivalent on Windows is C:\Users\Administrator

/usr - Where all your software is installed 

/bin and /sbin - Used for system critical files - DO NOT DELETE

/var - The Linux miscellaneous directory, a myriad of processes store data in /var

$PATH - Stores all the binaries you're able to run
