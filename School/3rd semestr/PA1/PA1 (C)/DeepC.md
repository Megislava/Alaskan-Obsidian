### Deep C
1. 
	```c
	int main() 
	{
		int a = 42;
		printf("%d\n", a);
	}
	```
	→
	```c
	#include <stdio.h>
	
	int main(void) 
	{
		int a = 42;
		printf("%d\n", a);
		return 0;
	}
	
	```
	Changes:
	1. `#include <stdio.h>`
		- includes library for build in functions
		- explicit declaration for `printf()`
		- would actually compile even without
			- it would like a standart library
	2. `void`
		- argument in function is a standart
		- if `void` is missing it can mean that the function can take any number of arguments
	3. `\n` at the end
		- new line at the end is also standart
2. 
```c
#include <stdio.h>

void foo(void) 
{
	int a = 3;
	++a;
	printf("%d\n", a);
}

int main(void) 
{
	foo();
	foo();
	foo();
}
```
- what it will print?
	- → 4\n4\n4\n
	- a is set to 3, increased by one in next line and printed in next line
	
```c
#include <stdio.h>

void foo(void) 
{
	static int a = 3;
	++a;
	printf("%d\n", a);
}

int main(void) 
{
	foo();
	foo();
	foo();
}
```
- what happends now?
	- prints: 4\n5\n6\n
	- why? a is declared as a **static variable**
		- preserves their value even after they are out for their scope (something like global variables)
		- setting variables to 0 increases the cost of function calls

```c
#include <stdio.h>

void foo(void) 
{
	static int a;
	++a;
	printf("%d\n", a);
}

int main(void) 
{
	foo();
	foo();
	foo();
}
```
- prints: 1\n2\n3\n
	- static when not assigned value is 0

```c
#include <stdio.h>

void foo(void) 
{
	int a;
	++a;
	printf("%d\n", a);
}

int main(void) 
{
	foo();
	foo();
	foo();
}
```
- prints: undefined
	- **but** in memory can be remnants of previous compilation 

```c
#include <stdio.h>

static int a;

void foo(void) 
{
	++a;
	printf("%d\n", a);
}

int main(void) 
{
	foo();
	foo();
	foo();
}
```
vs. 
```c
#include <stdio.h>

int a;

void foo(void) 
{
	++a;
	printf("%d\n", a);
}

int main(void) 
{
	foo();
	foo();
	foo();
}
```
- with static is prints: 1\m2\n3\n
- without static: 1\n2\n3\n
	- the variable is still statically allocated from previous compile

```c
#include 

void foo(void) 
{
	int a; 
	printf("%d\n", a); 
}

void bar(void) 
{ 
	int a = 42;
}

int main(void)
{
	bar();
	foo(); 
}
```
- can print different values, depends on optimizer

```c
#include 

void foo(void) 
{
	int a = 41;
	a = a++; 
	printf("%d\n", a); 
}

int main(void)
{
	foo(); 
}
```
- prints: 42 on low warning levels
	- but the code is undefined (on higher level of warning)
		- because `a = a++` - you cannot increase variable twice in same line



```c
#include <stdio.h>

int b(void) {puts("3"); return 3; }
int c(void) {puts("4)"; return 4; }
int main(void)
{
	int a = b() + c();
	printf("%d\n", a);
}
```

- evaluation order in most expressions in C and C++ are unspecified
	- compiler decides in what order to evaluate them
	- code will print: 3,4,7 or 4,3,7


- what code snippets will prints?
	- `int a=41; a++; printf("%d\n", a);` → 42
	- `int a=41; a++ & print("%d\n", a);` → undefined
	- `int a=41; a++ && printf("%d\n", a);` → 42
	- `int a=41; if (a++ < 42) printf("%d\n", a);` → 42
	- `int a=41; a=a++; printf("%d\n", a);` →undefined

- when do side-effects take place?
	- sequence points
		- sequence point is a point in the program's execution sequence where all previous side-effects have taken place and where all subsequent side-effects shall not have taken place
		- rule I.
			- between the previous and the next sequence pint an object shall have its  tored value modified at most once by the evaluation of an expression
			- `a=a++` UNDEFINED
		- rule II.
			- the prior value shall be read only to determine the value to be stored 
			- `a=a++` UNDEFINED

```c
#include <stdio.h>

struct X {int a; char b; int c; };

int main (void)
{
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(struct X));
}
```
fix to:
```c
#include <stdio.h>

struct X {int a; char b; int c; };

int main (void)
{
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(char));
	printf("%zu\n", sizeof(struct X));
}
```
- correct type specification `%d` to `%zu`
- sizeof - number of bytes
	- what it prints also depends how many bit is the machine running on
		- 64-bit vs 32-bit
- code prints: 4,1,12
	- but it als odepends on compilation flags
		- if used `-fpack-struc` in `gcc` it can print 4,1,9
		- it is expensive to work on subword datta types - compiler will optimize the code
- memory model
	- static storage
		- object whose identifier is declared with external or internal link or with storage-class specifier `static` has static storage duration
		```c
		int * immortal (void)
		{
			static int storage = 42;
			return &storage;
		}
		```
	- automatic storage
		- object whose identifier is declared with no linkage and w/o the storage-class specifier `static` has automatic storage duration
		- lifetime extends from entry into the block with which it is associated until execution of that block ends in any way
		```c
		int * zombie(void)
		{
			auto int storage = 42;
			return &storage;
		}
		```
	- allocated storage
		- storage allocated by calloc, malloc and realloc
		- lifetime extends from the alllocation to the dealocation
		```c
		int *(void)
		{
			int * ptr = malloc(sizeof *ptr);
			*ptr = 42;
			return ptr;
		}
		```
- optimization
	- by defualt the compiler shuld compile with optimization on
	- forcing it helps find more potentional issues