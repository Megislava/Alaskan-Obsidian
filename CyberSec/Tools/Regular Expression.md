#### Character(s)
- `<char>` - one specific character
- `.` - any single character
	- `grep -v '.' words` - print empty lines
	- `grep '^.$' words` - between start and end of line is one char
	- `grep '\.' words` - print lines which has `.`
	- `grep '^[xyz].$' words` - at the start f line is x, y or z, then one more char and EOL
- `[abc]` -  list or range of characters to match
	- `grep '[MTWTFS][ouehra][neduit][sneru]*day' words` - reads day in a week - HIGHLY UNSTABLE
		- better: `grep -E '(Mon|T(ue|hur)s|Wednes|Fri|S(atur|un))day' words`
	- -> same with months,...
- `[^abc]` - NOT the chars
- `[a-z]` - interval/range
- `[[:lower:]]`, `[[:upper:]]`, `[[:alpha:]]` - classes
	- `grep '^[^[:alpha:]]' words` - no alphabetic characters at the start of the line (-> `1st`, `30th`,...)

#### Ancors
- `^` - the string to match is on the beginning
	- `grep '^[wW]ord' words` - finds `words` or `Words` strings in words file
- `$` - the string to match is on the end
- `\<` - start of word
- `\>` - end of word

#### Kvantificators
- `*` - previous character repeated random times (including 0)
- `\+` - at least one occurence of character
- `\{m,n\}` - range of occurences
	- without `n` it is `m+`, if without `,` then exactly `m`
	- `grep -E '^([[:upper:]].*){5}$' words` - exactly 5 upper case letters
	- `grep -E '(.)(.).\2\1$' words` - palindrom
- `\?` - an optional character

#### Groups
- `\(<RegEx>\)` - subexpression
	- allows to work with more kvantificators or it is allowed to address it later
- `<RegEx1>\|<RegEx2>` - "OR"
- `\1....\9` - address to subexpression

#### Special characters
- `\` - escape symbol
	- `grep '\[error]' log` same as `grep -F [error] logs`
	- `grep '\.zip' network`
- `\b` - whitespace between two words
- `\B` - whitespace INSIDE a word
- `\w` - a word
- `\W` - not a word
- `\s` - whitespace
- `\S` - not a whitespace
