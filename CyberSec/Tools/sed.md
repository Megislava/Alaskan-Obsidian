- stream editor
	- input stream -> pattern buffer -> output stream

1. takes one line of document
2. does random work
	- contains address and command (`'10p'` = `10` is address, `p` is command)
	- parts of script are splitted with `;` or `\n`
		- `sed '10p;15p'` - prints 10th and 15th line
	1. address
		- empty = every line
		- `<int>` - number of line
			- `sed -n '10p'` - prints ONLY specific line
		- `$` - last line
		- `/<RegEx>/` - line corresponding to a regex
			- for use with extended regex add `-r`
			- `sed -nr '/1+$/p'` - prints line where at the end is one or more 1's
		- `<int>,<int>` - range from to
			- can be combined with regex
			- `sed -n '/0$/,$p'` - prints line from first line with 0 at the end, to EOF
		- `N=10 | sed -n "${N}p"` - prints value of N
	2. command
		- `p` - print
		- `d` - delete line
			- `sed '6,$d'` - print only lines 1 to 5 (inc).
			- `sed '1,/^$/d'` - prints only body without header (line one to empty line)
		- `q`, `Q` - print line and quit
			- `q` - prints one line/pattern and then quits
			- `Q` - immediate quitting of the script/when it hits the target line (prints w/o the line)
				- only in GNU
		- `=` - line number
		- `s/<RegEx>/<ToSubs>/[flags]` - substitution
			- `n` - substitute nth occurence of RegEx
			- `g` - substitute all RegEx occurences
			- `p` - if substitution is done, print the line
3. output goes to output stream
	- `-n` - cancels implicit output

- `-f` - script file
	- type is: `#!/bin/sed`
 - `-l <number>` - line length
