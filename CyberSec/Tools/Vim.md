- `vim` - start
	- file as param
		- if does not exist will be created

- there is difference between empty line (`\n`) and non-existent line (`~`)

- last "line" is a information/progress/state line

- `@` - text is continuing
	- if all last line is with `...@@@@...` then the content isn't possible to show in full

- quitting:
	- `:q` - quit
	- `:q!` - force quit
	- `:wq` - write (save) and quit


##### Text split, number of line
- `:set wrap` - puts overflowing lines to new line (wraps them)
	- will split words!
- `:set linebreat` - will split where there is whitespace (` `, `\t`)
- `:set nolinebreak` - back to `:set wap`
- `:set nowrap` - one line - one line (default)
	- the rest is "out of screen"

- `:set number` - shows number of lines
- `:set nonumber` - no numbers


##### Info bar
- 3 informations
	- current activity (insert, viewing, replace)
		- displaying can be turned off/on: `:set noshowmode` / `:set show mode`
	- start of command
		- can be removed by `:set noshowcmd` and brought back `set showcmd`
	- cursor position
		- two numbers - number of line, number of char in line
		- displaying on/off: `:set ruler`/ `:set noruler`


##### Three modes
1. Normal
	- the one where vim is opened in
2. Insert and Replace
3. Command-line (executing)