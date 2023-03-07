- very fast online password cracking tool
- rapid directory attack against more then 50 protocols (inc. Telnet, RDP, SSH, FTP, HTTP, HTTPS, SMB, several databases and much more)
- eg.: `hydra -t 4 -l dale -P /usr/share/wordlists/rockyou.txt -vV 10.10.10.6 ftp`

SECTION | FUNCTION
--------- | ---------
hydra | Runs the hydra tool
-t 4 |  Number of parallel connections per target
-l [user] | Username
-L [users from file] | Get usernames from file in path
-p [password] | Password
-P [path to dictionary] | Points to the file containing the list of possible passwords
-vV | Sets verbose mode to very verbose, shows the login+pass combination for each attempt
[IP] | The IP address of the target machine
[protocol] | Sets the protocol

