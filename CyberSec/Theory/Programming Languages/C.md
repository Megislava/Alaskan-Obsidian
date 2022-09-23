### Deep C
1. 
	```c
	int main() 
	{
		int a = 42;
		printf("%d\n", a);
	}
	```
	=>
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
	- => 4\n4\n4\n
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


- declarative language
- `%f` - float
- `$.2f` - float with 2 points rounded