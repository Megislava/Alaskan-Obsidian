<<<<<<< HEAD
- faucets:
	- trust the programmer
	- keep the language small and simple
	- provide only one way to do an operation
	- make it fast
		- even if it is not guranteed to be portable
	- to maintain conceptual simplicity
	- don't prevent the programmed from doing what needs to be done


- declarative language


### Keywords
- `auto`
	- defining that the following has local lifetime
	- `auto int au;`
	- not often used
	- no implicit initialization
	- stored in `zasobnik`
	- has different meaning from c++11
		-variable, which type is derived from typr inference
- `break`
	- quits running other commands - `while`, `do while`, `for`, `switch`
- `case`
	- with `switch`
- `char`
	- data type for characters
- `const`
	- following variable or pointer is immutable - constant
	- `const int max = 20;`
	- similalry is defined, `#define MAX 20`
	- often used in function parameters
- `continue`
	- quits running the most inner part of function `while`, `do while` and `for`
	- `break` vs `continue`
		```c
		for (int i =1; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				break;
			}
			printf("%d\n", i);
		}
		```
		- prints: 1
		```c
		for (int i =1; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				continue;
			}
			printf("%d\n", i);
		}
		```
		- prints 1, 3, 5, 7, 9
- `default`
	- together with `switch`
- `do`
	- part of `do while` cycle
		```c
		int i = 1;
		do
		{
			printf("%d", i*i);
			i++;
		} while (i < 10);
		```
		- first 10 squares
- `double`
	- data type for rational numbers
- `else`
	- with `if`
- `enum`
	- set of constants of  `int` type
	- `enum [tag] {name [=value], ...};`
		- `enum Mocniny {Nulta = 1, Prvni, Druha = 4, Treti = 8};`
	- if no value is set (`key=value`) then it's the previous value +1
	- if no value is set for 1./0. element it is set on 0
	- it is not necessary to name keys
		- `enum Mocniny x, y; ` is valid
- `extern`
	- variable is stored and initialized somewhere else then the function definition
	- used for global variables
	- stored in static part of the program
	- visible in declated module and the ones with `extern`
	- lifes the whole program life
		```c
		extern int sum;
		extern void factorial(int n);
		```
- `float`
	- data type for rational numbers
- `for`
	- type of cycle
		```c
		int sum = 0;
		for (int i = 1; i <= 100; i++)
		{
			sum += i;
		}
		```
		- sum of numbers from 1 to 100
- `goto`
	- control takeover
	- it is permitted to jump out of the visibility block
	- not permitted to jump inside a block
		- eg. from one function to another
- `if`
	- description of decisions forking
		```c
		int a = 7, b = 11, max;

		if (a > b)
		{
			max = a;
		} else {
			max = b;
		}

		if (max % 2 == 0)
		{
			printf("Bigger number is even");
		} else {
			printf("Bigger number is odd")
		}
		```
		- which number is bigger and if it's even or odd
- `int`
	- data type for integers
- `long`
	- data type for integers
- `register`
	- notify compiler suggestions to save particular variable to processor registry so work with it is faster
	- `registry int r;`
- `return`
	- ends function and returns a certain result
		```c
		int min (int x, int y) {
			if (x < y) {
				return x;
			}
			return y;
		}
		
		int main () {
			int a, b, lower;
			printf("Input two numbers: ");
			if (scanf("%d%d",&a, &b) < 2) { /* INPUT VALIDATION CHECK */
				printf("Incorrect input.\n");
				return 1;
			}
			lower = min(a,b); /* CALLING THE MIN FUNCTION */
			printf("Smaller number is %d\n", lower);
			return 0;
		}
		```
- `short`
	- data type for not so big integers
- `signed`
	- modifier for integer data types
		- they are implicitely `signed` - the usage is therefore voluntary
- `sizeof`
	- returns the size of allocated memory for data type or other parameter
		```c
		printf(" %zd, ", sizeof(int));
		printf(" %zd, ", sizeof 12);
		printf(" %zd, ", sizeof 4.4);
		printf(" %f, ", sizeof 4.4 - 4.4);
		printf(" %zd.\n", sizeof (4.4 - 45));
		```
		- prints: 4, 4, 8, 3.6000000, 8
- `static`
	- local or global variable
	- stored in the program memory
	- can be used while defining functions or variables
		- changing the visibility of a function
		- specifies how variable behaves in between functions
			- is more specified in [[DeepC]]
- `struct`
	- putting variables into more complex structure
	- created structure contains names and types of included variables
		- separated by semicolon
		```c
		#include <stdio.h>
		#include <stdlib.h>
		
		struct student{
			char name[20];
			double grade;
		};
		
		int main() {
			struct student chuck = {"Chuck Norris", 0.99};
			printf("Best student is %s, with grade %lf\n", chuck.name, chuck.grade);
			return 0;
		}
		```
- `switch`
	- decision forking function
	- `switch (argument) { case 0: break; default: printf("Default");}`
- `typedef`
	- defining user-created data type
	- usually used for better code readability
		```c
		typedef unsigned char byte;
		typedef char string20[21];
		typedef int * pointerToInt;
		typedef struct complex {double re, im;} Complex;
		typedef int (*pointertoFcion)(int);
		```
- `union`
	- putting vairables togerther to share space
	- when using `struct` the memory is allocated for all variables
	- `union` allocates memory for the biggest variable
- `unsigned`
	- integer is for positive numbers only
- `void`
	-  3 usages:
		- no return type
		- no function parameter
		- pointer usage
			- but  because pointer wold not know how much memory it needs it needs to be retuped before usage
- `volatile`
	- no optimalizations with this variable
- `while`
	- cycle
		```c
		int i = 1;
		while (i < 10) {
		    printf("%d ", i * i);
		    i++;
		}
		```



### Identifiers (variable, function names)
- used for naming entities like variables, function, structures, used-defined data types etc
- naming conventions
	- only letters of english alphabet, numbers and underscore
	- first charaster is letter or underscore
		- not recommended to start with underscore
	- the lenght recommended to be max 32 characters
		- can be really longer but has to be identifiable in the first 63
			- if longer compilator can have issues
	- case-sensitive
- `i, j, k` - usually in cycles
- camelCase vs snake_case


### Literals/constants
- more in [[Data Type & Variables]]

### Operator's
- more in [[Expressions]]
- `[]`
	- with arrays
		- for defining array dimension
	- if used as operator then there `v1[v2]`, `*((v1) + (v2))` are equivalent
- `()`
	- grouping, calling functions, operator of retyping
- `{}`
	- opening/closing a function or block
	- initialization of a fields, declaration of types, structures and sets
- `=`
	- separation of declaration of a variable and its initialization
	- in enums and other joining value to key
- `,`
	- `int a, b[] = {1, 5};`
- `;`
- `:`

### Comments
- `/* */`
- with each function
=======
- faucets:
	- trust the programmer
	- keep the language small and simple
	- provide only one way to do an operation
	- make it fast
		- even if it is not guranteed to be portable
	- to maintain conceptual simplicity
	- don't prevent the programmed from doing what needs to be done


- declarative language


### Keywords
- `auto`
	- defining that the following has local lifetime
	- `auto int au;`
	- not often used
	- no implicit initialization
	- stored in `zasobnik`
	- has different meaning from c++11
		-variable, which type is derived from typr inference
- `break`
	- quits running other commands - `while`, `do while`, `for`, `switch`
- `case`
	- with `switch`
- `char`
	- data type for characters
- `const`
	- following variable or pointer is immutable - constant
	- `const int max = 20;`
	- similalry is defined, `#define MAX 20`
	- often used in function parameters
- `continue`
	- quits running the most inner part of function `while`, `do while` and `for`
	- `break` vs `continue`
		```c
		for (int i =1; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				break;
			}
			printf("%d\n", i);
		}
		```
		- prints: 1
		```c
		for (int i =1; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				continue;
			}
			printf("%d\n", i);
		}
		```
		- prints 1, 3, 5, 7, 9
- `default`
	- together with `switch`
- `do`
	- part of `do while` cycle
		```c
		int i = 1;
		do
		{
			printf("%d", i*i);
			i++;
		} while (i < 10);
		```
		- first 10 squares
- `double`
	- data type for rational numbers
- `else`
	- with `if`
- `enum`
	- set of constants of  `int` type
	- `enum [tag] {name [=value], ...};`
		- `enum Mocniny {Nulta = 1, Prvni, Druha = 4, Treti = 8};`
	- if no value is set (`key=value`) then it's the previous value +1
	- if no value is set for 1./0. element it is set on 0
	- it is not necessary to name keys
		- `enum Mocniny x, y; ` is valid
- `extern`
	- variable is stored and initialized somewhere else then the function definition
	- used for global variables
	- stored in static part of the program
	- visible in declated module and the ones with `extern`
	- lifes the whole program life
		```c
		extern int sum;
		extern void factorial(int n);
		```
- `float`
	- data type for rational numbers
- `for`
	- type of cycle
		```c
		int sum = 0;
		for (int i = 1; i <= 100; i++)
		{
			sum += i;
		}
		```
		- sum of numbers from 1 to 100
- `goto`
	- control takeover
	- it is permitted to jump out of the visibility block
	- not permitted to jump inside a block
		- eg. from one function to another
- `if`
	- description of decisions forking
		```c
		int a = 7, b = 11, max;

		if (a > b)
		{
			max = a;
		} else {
			max = b;
		}

		if (max % 2 == 0)
		{
			printf("Bigger number is even");
		} else {
			printf("Bigger number is odd")
		}
		```
		- which number is bigger and if it's even or odd
- `int`
	- data type for integers
- `long`
	- data type for integers
- `register`
	- notify compiler suggestions to save particular variable to processor registry so work with it is faster
	- `registry int r;`
- `return`
	- ends function and returns a certain result
		```c
		int min (int x, int y) {
			if (x < y) {
				return x;
			}
			return y;
		}
		
		int main () {
			int a, b, lower;
			printf("Input two numbers: ");
			if (scanf("%d%d",&a, &b) < 2) { /* INPUT VALIDATION CHECK */
				printf("Incorrect input.\n");
				return 1;
			}
			lower = min(a,b); /* CALLING THE MIN FUNCTION */
			printf("Smaller number is %d\n", lower);
			return 0;
		}
		```
- `short`
	- data type for not so big integers
- `signed`
	- modifier for integer data types
		- they are implicitely `signed` - the usage is therefore voluntary
- `sizeof`
	- returns the size of allocated memory for data type or other parameter
		```c
		printf(" %zd, ", sizeof(int));
		printf(" %zd, ", sizeof 12);
		printf(" %zd, ", sizeof 4.4);
		printf(" %f, ", sizeof 4.4 - 4.4);
		printf(" %zd.\n", sizeof (4.4 - 45));
		```
		- prints: 4, 4, 8, 3.6000000, 8
- `static`
	- local or global variable
	- stored in the program memory
	- can be used while defining functions or variables
		- changing the visibility of a function
		- specifies how variable behaves in between functions
			- is more specified in [[DeepC]]
- `struct`
	- putting variables into more complex structure
	- created structure contains names and types of included variables
		- separated by semicolon
		```c
		#include <stdio.h>
		#include <stdlib.h>
		
		struct student{
			char name[20];
			double grade;
		};
		
		int main() {
			struct student chuck = {"Chuck Norris", 0.99};
			printf("Best student is %s, with grade %lf\n", chuck.name, chuck.grade);
			return 0;
		}
		```
- `switch`
	- decision forking function
	- `switch (argument) { case 0: break; default: printf("Default");}`
- `typedef`
	- defining user-created data type
	- usually used for better code readability
		```c
		typedef unsigned char byte;
		typedef char string20[21];
		typedef int * pointerToInt;
		typedef struct complex {double re, im;} Complex;
		typedef int (*pointertoFcion)(int);
		```
- `union`
	- putting vairables togerther to share space
	- when using `struct` the memory is allocated for all variables
	- `union` allocates memory for the biggest variable
- `unsigned`
	- integer is for positive numbers only
- `void`
	-  3 usages:
		- no return type
		- no function parameter
		- pointer usage
			- but  because pointer wold not know how much memory it needs it needs to be retuped before usage
- `volatile`
	- no optimalizations with this variable
- `while`
	- cycle
		```c
		int i = 1;
		while (i < 10) {
		    printf("%d ", i * i);
		    i++;
		}
		```



### Identifiers (variable, function names)
- used for naming entities like variables, function, structures, used-defined data types etc
- naming conventions
	- only letters of english alphabet, numbers and underscore
	- first charaster is letter or underscore
		- not recommended to start with underscore
	- the lenght recommended to be max 32 characters
		- can be really longer but has to be identifiable in the first 63
			- if longer compilator can have issues
	- case-sensitive
- `i, j, k` - usually in cycles
- camelCase vs snake_case


### Literals/constants
- more in [[Data Type & Variables]]

### Operator's
- more in [[Expressions]]
- `[]`
	- with arrays
		- for defining array dimension
	- if used as operator then there `v1[v2]`, `*((v1) + (v2))` are equivalent
- `()`
	- grouping, calling functions, operator of retyping
- `{}`
	- opening/closing a function or block
	- initialization of a fields, declaration of types, structures and sets
- `=`
	- separation of declaration of a variable and its initialization
	- in enums and other joining value to key
- `,`
	- `int a, b[] = {1, 5};`
- `;`
- `:`

### Comments
- `/* */`
- with each function
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
	- purpose of function, parameters and return function