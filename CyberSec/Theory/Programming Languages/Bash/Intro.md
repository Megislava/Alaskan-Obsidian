- define type of code
	- `#!/bin/bash` - bash

- `alias 100='printf "$(echo %4d{,,,,,,,,,})\n" {1..100}'`
	- command 100 will print a number from 1 to 100 on its own line
	- 9 lines -> 10 "columns"
	- `%4d` - max 4 spaces before the number
	- `\n` - after first 10 numbers (9 commas), new line

- often used with [[test]]

1. [[CyberSec/Theory/Programming Languages/Bash/Functions]]
2. [[Conditions]]
3. [[Loops]]