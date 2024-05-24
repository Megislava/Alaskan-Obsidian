- relational database management system (RDBMS) based on Structured Query Language (SQL)
	- database: persistent, organized collection of structured data
	- RDBMS: SW used to creat and manage DB based on relational model 
		- relational: data stored in the dataset is organized as tables
- made up of the server and utility programs
- the server handles all DB instructions (creating, editing and accessing data)
	1. MySQL creates a DB for storing and manipulating data, defining the relationship of each table
	2. clients make requsts by making specific statements in SQL
	3. the server will respond to the client with whatever information has been requested
- if on website explore with [[sqlmap]]
- `sudo apt install mysql` - installs the MySQL client
- find out if the service is running with nmap
- connect with `mysql -h [IP] -u [username] -p` to check if the creds are working
- exploit with module mysql_sql in Metasploit
- get the schema with module mysql_schemadump (auxiliary/scanner/mysql/mysql_schemadump) in Metasploit
- dump the DB with mysql_hashdump (auxiliary/scanner/mysql/mysql_hashdump) in Metasploit
- play

1. connect
	- `mysql -h <IP> -u <username>`
2. show databases
	- `show databases;`
	- `use <database>;`
3. show tables
	- `show tables;`
4. confinue with SQL calls
	- `SELECT * FROM <table>;`