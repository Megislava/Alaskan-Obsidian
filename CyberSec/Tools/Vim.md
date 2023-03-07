- `vim` - start
	- file as param
		- if does not exist will be created

- there is difference between empty line (`\n`) and non-existent line (`~`)

- last "line" is a information/progress/state line

- `@` - text is continuing
	- if all last line is with `...@@@@...` then the content isn't possible to show in full


##### Info bar
- 3 informations
	- current activity (insert, viewing, replace)
		- displaying can be turned off/on: `:set noshowmode` / `:set show mode`
	- start of command
		- can be removed by `:set noshowcmd` and brought back `set showcmd`
	- cursor position
		- two numbers - number of line, number of char in line
		- displaying on/off: `:set ruler`/ `:set noruler`


##### Operating modes
![[Pasted image 20221130145344.png]]
- possible to switch between them with `ESC`
1. Normal (`ESC`)
	- default the one where vim is opened in
2. Insert mode (`i`)
	- `o`/`O` - insert new line below/above
	- `dw`/`d$`/`d0`- delete word/to end of line/to beginning og line
	- `x`/`dl` - delete character
	- `s`/`cl` - substitude char
	- putting things together
		- `3w` - move 3 words forward
		- `5j` - move 5 lines down
		- `7dw` - delete 7 words
3. Replace mode (`r`)
	- 
4. Visual mode (`v`)
5. Command-line (`:`)
	- executing commands
	- `:ls` - show open buffers
	- `:e <name_of_file>` - open file for editing
	- `:help` - shows help
	- quitting:
		- `:q` - quit
		- `:q!` - force quit
		- `:wq` - write (save) and quit
	- changing various visuals
		- `:set wrap` - puts overflowing lines to new line (wraps them)
			- will split words!
		- `:set linebreat` - will split where there is whitespace (` `, `\t`)
		- `:set nolinebreak` - back to `:set wap`
		- `:set nowrap` - one line - one line (default)
			- the rest is "out of screen"
		- `:set number` - shows number of lines
		- `:set nonumber` - no numbers

### Movement
- `hjkl` - left, down, up, right
- Words: 
	- `w` - next word, `b` - beginning of word, `e` - end of word, 
- Lines:
	- `0` - beginning of line, `^` - first non-blank character, `$` - end of line
- Screen
	- `H` - top, `M` - middle, `L` - bottom
- Scroll
	- `CTRL-u` - up, `CTRL-d` - down
- File
	- `gg` - beginning of  file, `G` - end of file
- Line numbers
	- `:<number><CR>` or `<number>G (line <number>)`
- Find
	- `f<char>`, `t<char>` - find/to char
	- `F<char>`, `T<char>` - forward/backward char
- Search
	- `/{regex}`, `n` and `N` for navigating matches in [[Regular Expression]]