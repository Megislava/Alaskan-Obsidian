1. If
	- must start with `if` and end with `fi`
	```sh
	if somecommand; then
		# do something
	fi
	```
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