- `for` and `while`

1. `for`
	- two different fors
		- `for <variable> in <list>; do <command>; done`
		- `for ((<init>;<condition>;<iteration>)); do <command>; done`
```sh
#!/bin/bash

#prints each server name
SERVERS="servera serverb serverc"
for S in $SERVERS; do
  echo "Doing something to $S"
done

#prints "<File name>":"<bytes>" from currect directory
for file in *; do printf '%s : %d bytes' "$file" "$( stat -c %s "$file" )"; done

#prints numbers (according to arithmetic operation) from 1->100 on each line
for (( i=1, j=0; i<=100; i++, j=i*4 )); do
	printf '%s\n' $(( i*i ))
done
```
2. `while`
	- `while <command>; do <command>; done`
```sh
#!/bin/bash

i=0
while [ $i -lt 10 ]; do
  echo $i
  i=$(( $i + 1))
done
echo “Done counting”
```
