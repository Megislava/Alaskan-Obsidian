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
	- why: to identify a compromised account/better understand what an attacker did
	- artifacts: too many → users can:
		- start processes
			- single artifact category → Program Run = record the program that was launched (and sometimes the time)
			- how to analyze:
				- Is the program flagged as malware? Is the program signed with a legitimate certificate? Is the program in atypical location (Temp/AppData)? Was the program started in a suspicious time? Was the file created at a suspicious time? Can the program be user as recon? ...
		- access data:
			- Data Access Artifacts:
				- record host, path (and sometimes time) that a resource was accessed
				- host could be "local"
				- based on config of applications, process handles
				- → File Explorer (ShellBags - what folder was opened; RunMRU - some users enter file and folder names), Application Most Recently Used (= MRU - many apps will store which files were recently created/opened), Web Artifacts (each browser has its own DB with history, cookies,...), Memory (may contain commands, remote desktop info, paths,...), Continuous Monitoring
			- how to analyze:
				- Did the user access any malicious websites? Did the user access network-based files not needed for their job role? Did the user mass copy file from their computer? ...
		- seach resources
			- Search Artifacts:
				- Records terms and times that a search was performed, based on setting of appcations/OS
				- → Web Artifacts (interpreting URLs from web history), OS (saved previous searches)
			- how to analyze:
				- Was the search for resources relevant to their job? Was this search for malicious programs/techniques?
		- remotely execute things
			- Remote Execution Artifacts:
				- record remote host and user name, if the session was interactive or what command/script was run, (may have time)
				- → Remote Logins (which hosts and accounts were used, event log may have entries based on auth type), Remote Processes (may have entries abount remote PowerShell executions)
			- how to analyze:
				- Was the remote user the same as the local user? Is the remote host expected for the local user? Was the remote program expected?
	

[[16.PNG]]