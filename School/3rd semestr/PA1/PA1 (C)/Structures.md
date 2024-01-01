- used for grouping related data to more complex structures
- in memory saved as one block
- using `typedef` vs `define`
	- false = 0, true = any non-zero value
	- with `define`: 
	```c
	#define TRUE 1
	#define FALSE 2
	```
	- with  `typedef`:
	```c
	typedef enum{FALSE = 0, TRUE} BOOLEAN;
	...
	BOOLEAN a = TRUE;
	```
- `struct` vs `typedef`
	- `typedef` defines a new variable type which is `struct` with some name
- each structure is then accessed by `.` or `->`
	- `student->jmeno` is really `(*student*).jmeno`
- `union`
	- similar to `struct` but the insides are overlapping instead sorted behind each other
	- from C99 can be structure with open array
		- array with unknown number of items
- `enum`
	- enumerating type
	- used for increase in code readability
	- for compiler compatible with `int` type
	- when listing items:
		- first has value `0`, and the other are then `+1` bigger then before
- bit fields
	- can be only part of `struct` or `union` structures
	- defined:
	```c
	struct {
		typ [jméno] : šířka ;
		[další položka]
	};
	```
	- `typ` can be `int`, `unsigned int` (= `unsigned`) či `signed int` (= `signed`), od C99 i `char`, `short`, `long` a `long long`
	- 