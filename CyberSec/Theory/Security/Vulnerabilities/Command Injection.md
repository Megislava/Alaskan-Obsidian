<<<<<<< HEAD
#server-side 

- vulnerability allowing the attacker to exeute arbitrary OS commands on server where the web application is running
- to easily test for this vuln use `echo`
- put the command to some place that is validated

- __Blind OS command injection vulnerabilities__
	- blind = the application does not return the output from the command via HTTP response
	- ways to exploit
	1. time delays
		- using ping
	2. redirecting output
		- putting output of a command somewhere where the application lives
			- if the app takes data from `/var/www/static` then output the command there ~ `whoami > /var/www/static/whoami.txt`
	3. using out-of-band techniques
		- command will trigger out-of-band network interaction (with system you control)


- different command separators: `|`, `||`, `&`, `&&`; only for Unix-based: `;` and newline `0x0a` or `\n`
- inline execution for Unix-based systems: `(backtick)injected command(backtick)`, `$(injected command)`

- __how to prevent__
	- do not call out OS commands from application-layer code
=======
#server-side 

- vulnerability allowing the attacker to exeute arbitrary OS commands on server where the web application is running
- to easily test for this vuln use `echo`
- put the command to some place that is validated

- __Blind OS command injection vulnerabilities__
	- blind = the application does not return the output from the command via HTTP response
	- ways to exploit
	1. time delays
		- using ping
	2. redirecting output
		- putting output of a command somewhere where the application lives
			- if the app takes data from `/var/www/static` then output the command there ~ `whoami > /var/www/static/whoami.txt`
	3. using out-of-band techniques
		- command will trigger out-of-band network interaction (with system you control)


- different command separators: `|`, `||`, `&`, `&&`; only for Unix-based: `;` and newline `0x0a` or `\n`
- inline execution for Unix-based systems: `(backtick)injected command(backtick)`, `$(injected command)`

- __how to prevent__
	- do not call out OS commands from application-layer code
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
	- if necesary then sanitize, whitelist, validate