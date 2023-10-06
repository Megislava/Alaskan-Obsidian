- basically a programming language
- programmable filtr 
- tool for processing data streams
	- takes line according to a pattern and does action
- similar to C
	- = Aho Weinberger Kerningham
![[Pasted image 20221208161711.png]]
- also understands columns

##### Workflow
- input is stdin or file/s
- input is splitted to RS and NR
- records will be splitted to fields (FS, NF, $0, $1, $...)
- result outputted (ORS, OFS)

1. RS - record separator
2. NR - number of records
3. FS - field separator
	- can be set with `-F`
	- `aws -F '5\\>' '{ print $1 }'` - prints all before new line after `5 ` (`\>` is end of word, `\` needs to be escaped)
4. NF - number of fields
5. $0, $1, $... - each field
6. ORS - output record separator
	- `awk '{ OFS="."; ORS="--" $3,$2,$1 }'` - at the end of each record will be `--` string (instead of `\n`) and between fields will be `.`
7. OFS - output field separator
	- `awk '{ OFS="."; $3,$2,$1 }'` - between all fields will be printed `.`
		- equivalent to: `awk '{ print $3"."$2"."$1 }'`


##### Syntax
- `pattern { action }` (spaces are not required)
- `-f` - script saved in file

1. Pattern
	- empty patters matches every line
		- `awk ''` - will print nothing
		- `awk '{ print $1 }'` - prints first column (empty pattern)
	- logical expressions (`+`, `-`, `*`, `/`, `%`, `&&`, `||`, `>`, `<`, `=`)
		- `awk '0'`  or `awk '1'`- true (same as `''` - prints nothing) vs false (prints all) (empty action)
		- `awk 'NR == 5'` - if the record is 5, print
		- `awk '(NR % 2) == 1'` - prints only odd records
	- regular expressions (extended regular expression)
		- `awk '!/ 5+ /'` - prints lines that do not (`!` is negation) contain one or more 5's
		- `awk '$3 ~/^[37]/'` - third column starts with 3 or 7
	- range of lines (absolute `&&`, interval `,` with logical or regular expressions)
		- `awk 'NR >= 5 && NR <=8'` - lines between 5 and 8 will be printed
		- `awk 'NR == 5,/80/'` - lines from 5 to line containing 80 will be printed
	- `BEGIN` (before input processing)
		- `awk 'BEGIN { ORS="|" }; { print }` - lines will be printed but splitted with | and not new line (therefore the result is one long line)
	- `END` (after input processing)
		- `awk 'END { print $0 }'` - print last line
		- `awk '{ c += $nf }; END { print c }'` - will print sum of all numbers
	
2. Action
	- script parts can be splitted with `;` or `\n`
	- can be empty
		- `awk 'NR==5'` will behave same as `awk 'NR==5 {print}'` and `awk 'NR==5 {print $0}'` - printing like 5  
	- loads of build-in functions:
		- `length` - function to return length of line
			- `awk '{ print lenght }'` (also `awk '{ print lenght() }'` and `awk '{ print lenght($0) }'`)
		- `rand()`, `srand()` - without `BEGIN` will be VERY pseudo random
			- `awk 'BEGIN { srand() }; { print rand() }'` - prints random numbers line-by-line (according to number of lines in stdin)
			- `awk 'BEGIN { srand() }; { print $(NF*rand() + 1) }'` - prints random number from line
		- `substr` - prints substring
			- arguments: which line, which character, how many chars to print
			- `awk 'BEGIN { srand() }; { print substr($0, lenght($0)*rand() + 1, 6) }'`
		- substitution functions
			- `sub`, `gsub`, `gensub`
			- `sub` vs `gsub` - first vs. all occurences of match
	- `print` - will print records according to pattern
		- `awk '{ print $1,$3,$5 }'` - will print 1., 3. and 5. column
		- `awk '{ print $(NF-1) }'` - will print next from last column




