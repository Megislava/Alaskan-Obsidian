1. Are there suspisious accounts?
	- user enumeration
	- why: to get a general idea about who used the computer and what permissions they have
	- how to get them/artifacts:
		- Windows
			- SAM registry hive - both local and domain
			- deleted account are removed from SAM but event log have remnants of past accounts (and failed logins), old home directories also still exist for deleted accounts
	- how to analyze: 
		- username (does the first and last name match the convention), rights (admin?), scope (is it correctly domain or local), creation date
2. Are there suspicious logins?
	- why: if an account was compromised (but you don't know that) the login times and locations may make it suspicious
	- artifacts:	
		- store times, login name and other metadata associated with a login event
		- Active Users (Windows APIs and memory), Logins (Local event logs, Domain Controller event logs)
	- how to analyze:
		- account (should the user be using the computer), history (are they new to the computer), remote host (does the account usually come from the computer), time (is the login date expected for the user), failed logins (does the account have lots of failed logins)
3. Did the users do anything suspicious?
	- why: 
	- artifacts:
	- how to analyze:
		- 

