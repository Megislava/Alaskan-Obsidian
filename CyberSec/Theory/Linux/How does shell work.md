
- before interpreting a command, steps are taken
	- detection of characters breaking special meaning (quoting)
		- ` " ' `
	- removing comments (from `#` till end of line)
	- splitting lines to particular commands (pipelines, `;`)
	- expansion of special characters (`~- $ ( )`)
	- word splitting
	- replacing name of files
	- redirection
	- searching for command

- shell special chars
	- metacharacters `| & ;  ( ) < > space tab`
	- control operators `|| & && ; ;; ( ) | |& \n`