- return codes (0->255)
	- `$0` - true
	- others - false
	- `$?` - last return code
1. If
	- must start with `if` and end with `fi`
	```sh
	if somecommand; then
		# do something
	fi
	```
	- `:` - if we don't care about the "positive" case
		- or we use `!` - negation
	- often used command [[CyberSec/Tools/test]] 
	- also `else`  and `elif` can be added
	```sh
	#!/bin/bash
	if [ "$1" = "hello" ]; then
		echo "hello yourself"
	elif [ "$1" = "goodbuy" ]; then
		echo "nice to have met you"
		echo "hope to see you again"
	else
		echo "didn't understand"
	fi	
	```
2. Case
	- makes sense for more conditions
	- `break` is `;;`
	- `default` is `*)`
	- ![[Pasted image 20221210181615.png]]
	```sh
	#!/bin/bash

	case "$1" in
	hello|hi)
	  echo "hello yourself"
	  ;;
	goodbye)
	  echo "nice to have met you"
	  echo "I hope to see you again"
	  ;;
	*)
	  echo "I didn't understand that"
	esac
```
3. Logical conditions
- `&&` (AND), `||` (OR)
	- `grep -ml -q ^root: /etc/passwd && echo "root nalezen"` - prints if both are true
	- `grep -ml -q ^roOot: /etc/passwd || echo "root nenalezen"` - prints if first is false