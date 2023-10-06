- testing variables
- can be used as `test` or `[ <expression> ]`
	- also can be tested as `(( <expression> ))`

##### Arithmetic operations
- `-lt` (`<`), `-gt` (`>`)
- `-le` (`<=`), `-ge` (`>=`)
- `-eq` (`=`), `-ne` (`!=`)
	- `test 1 –eq 1`  - returns `0` if numeric comparison succeeds
	- `test ! 1 –eq 1` - returns `NOT – 0` if the comparison fails
	- `test 1 –ne 1` - Easier, `test` for numeric inequality

##### String comparisson
- `=`, `!=`
	- `test “a” = “a”`  - returns `0` if the string comparison succeeds
	- `test “a” != “a”`  - returns `0` if the strings are different
- `\>`, `\<` (later or earlier in alphabet)
- `-z` (is empty), `-n` (is not empty/null)

##### Logical operations
- `-o` (OR)
	- `test 1 –eq 1 –o 2 –eq 2`  - returns `-o` is OR: either can be the same
- `-a` (AND)
	-  `test 1 –eq 1 –a 2 –eq 2`  - returns `-a` is AND: both must be the same
- `!` (NOT)
	- `[ -d "$.T" -a ! -L "$.T"] && echo "it's a directory and not symlink"`

##### File operators
- `-e` (file exist?), `-f` (is it normal file?), `-d` (directory exists?), `-L` (symbolic link?), `-s` (contains the file something? is it not empty?), `-r` (is readable?), `-w` (is writtable?), `-x` (is it executable?), `-0` (is the file mine?)
	- `test –f /dev/ttyS0`  - returns `0` if the file exists
	- `test ! –f /dev/ttyS0` - returns `0` if the file doesn’t exist
	- `test –d /tmp`  - returns `0` if the directory exists
	- `test –x 'which ls'`  - returns substitute the location of `ls` then `test` if the user can execute
- `-nt` (newer then <another_file>), `-ot` (older then <another_file>), `-ef` (hard link?)

![[Pasted image 20221211193301.png]]
nicer version:
![[Pasted image 20221211193443.png]]
even nicer version:
![[Pasted image 20221211193703.png]]