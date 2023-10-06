- can be declared in shell
- `function_name () {}`
- in shell it looks weird:
```sh
my_function () {
> ls /home
> cal 2022
> echo "Function will print a calender for 2022"
> }
```
- by default created with `+x` so it can run without `./`
-  ```
		mcd () {
			mkdir -p "$1"
			cd "$1"
		}
	- creates a new folder with name given from parametr and enters it
	- 	- arguments and special characters:
	- `$0` - Name of the script
	-   `$1` to `$9` - Arguments to the script. `$1` is the first argument and so on.
	-   `$@` - All the arguments
	-   `$#` - Number of arguments
	-   `$?` - Return code of the previous command
	-   `$$` - Process identification number (PID) for the current script
	-   `!!` - Entire last command, including arguments. A common pattern is to execute a command only for it to fail due to missing permissions; you can quickly re-execute the command with sudo by doing `sudo !!`
	-   `$_` - Last argument from the last command. If you are in an interactive shell, you can also quickly get this value by typing `Esc` followed by `.` or `Alt+.`
	-   [some more special chars](https://tldp.org/LDP/abs/html/special-chars.html)
-   binary decidions:
	-   `||` - or
		-   `false || echo "Oops, fail"` → `Oops, fail`
		-   `true || echo "Always true"` → ``
	- `&&` - and
		- `true && echo "Is true"` → `Is true`
		- `false && echo "False"` → ``
	- `;` - just a division of commands - both will execute
		- `true ; echo "Will print"` → `Will print`
		- `false ; echo "Will print"` → `Will print`
- running command in command ~ command substition:
	- the inner command will run first
		- `diff <(ls bar) <(ls foo)` - difference between ls of bar and foo
		- `for file in $(ls)` - do something with each file in ls of some dir
- standart output and error:
	- `grep foobar "$file" > /dev/null 2>dev/null` - moving STDOUT and STDERR to /dev/null
- comparissons:
	- using double brackets `[[ ]]`
	- [more info](http://mywiki.wooledge.org/BashFAQ/031)
- globbing
	- wildcards, curly braces
		- `foo*` - match foo-something
		- `foo*.{php,html,js}` - matches foo-something with extenstions php/html/js
		- `mv *.{sh,py} folder` - will move all sh and py to folder
- [spellcheck shellcheck tool](https://github.com/koalaman/shellcheck)