- part of Samba default suite
- `smbclient //[IP]/[SHARE]`
- `-U [name]`: specify the user
- `-p [port]`: specify the port
- `-L` - list all direcories
- `-N` - no password

1. test the connection
	- `smbclient //IP//`
2. list the directories
	- `smbclient -L //IP/`
3. try to get to each DIR
	- `smbclient //IP/DIR`
	- you will get `>` or Access Denied
4. get the files
	- `get FILE`
