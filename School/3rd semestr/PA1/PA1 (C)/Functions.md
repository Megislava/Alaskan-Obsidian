- closing code to specially named block 
- for:
	- reuse of code
	- easier improvements and fixes of code on one place
	- easier debugging
	- increased readability

## Function declaration vs definition 
- function must be declared before it is used
- when using function from library, include the lib
- declaration: `void randomFunctio(void);`
	- no return type, no parameter

## Basic input and output functions
- input - `scanf`
	- reads from stdin
	- returns number of successfully loaded and into memory saved variables
	- for `%d` conversion:
		- ignores starting and trailing spaces
		- number have to start with sign or with number
		- reading ends on first non-decadic character
		- at least one decadic character has to be loaded
	- |Znak|Význam|
		|---|---|
		|d|Celé číslo|
		|i|Celé číslo, zápis odpovídá konstantě v C, (např. `0x` v šestnáctkové soustavě)|
		|u|Celé číslo bez znaménka|
		|o|Osmičkové celé číslo|
		|x|Šestnáctkové celé číslo|
		|n|Počet dosud přečtených znaků aktuálním voláním funkce `scanf()`|
		|e, f, g|Racionální čísla typu `float`, lze je modifikovat pomocí `l` a `L`|
		|s|Řetězec; úvodní oddělovače jsou přeskočeny, na konci je přidán znak `'\0'`|
		|c|Vstup znaku; je li určena šířka, je čten řetězec bez přeskočení oddělovačů|
		|[search_set]|Jako `s`, ale se specifikací vstupní množiny znaků *****|
- output - `printf`
	- type: 
		- |Type|Význam|
			|---|---|
			|d, i|Celé číslo se znaménkem|
			|u|Celé číslo bez znaménka|
			|o|Číslo v osmičkové soustavě|
			|x, X|Číslo v šestnáctkové soustavě. (lowercase vs uppercase) |
			|f|Racionální číslo (`float`, `double`) bez exponentu|
			|e, E|Racionální číslo s exponentem (by default <1>.<6> positions, lowercase vs uppercase)|
			|g, G|Racionální číslo s/bez exponentu (decides according to absolute value, no decimal point when not needed)|
			|c|Znak|
			|s|Řetězec|
	- width:
		- |Width|Význam|
		|---|---|
		|n|Nejméně `n` znaků doplněných mezerami|
		|0n|Nejméně `n` znaků doplněných nulami|
		|\*|Nejméně `n` znaků, `n` je další argument funkce `printf()`|
	- flags:
		- |Flag|Význam|
			|---|---|
			|-|Výsledek je zarovnán zleva|
			|+|U čísla bude vždy zobrazeno znaménko|
			|mezera|U kladných čísel bude místo znaménka `+` mezera|
			|#|Pro `o`, `x`, `X` výstup jako konstanty jazyka C  <br>pro `e`, `E`, `f`, `g` a `G` vždy zobrazí desetinnou tečku  <br>pro `g`, `G` ponechá nevýznamné nuly  <br>pro `c`, `d`, `i`, `s`, `u` nemá význam|
	- .prec:
		- |.prec|význam|
		|---|---|
		|.0|Pro `e`, `E`, `f` nezobrazí desetinnou tečku  <br>pro `d`, `i`, `o`, `u` a `x` nastaví standardní hodnoty|
		|.n|Pro `d`, `i`, `o`, `u` a `x` minimální počet číslic  <br>pro `e`, `E`, `f` počet desetinných číslic  <br>pro `g`, `G` počet platných míst  <br>pro `s` maximální počet znaků|
		|.\*|Jako přesnost bude použit následující parametr funkce `printf()`|

## Mathematical function
- `#include <math.h>`, also `#include <stdlib.h>`
- when issues while compile add `-lm` flag (`link math`)
- basic math functions:
	- `abs` - return absolute value from `int` (`labs` for `long`, `llabs` for `long long`)
	- `fabs` - return absolute value of `double`
	- `div` - whole number difference (`a / b`)
	- `fmod` - modulo for `double`
	- `exp` - Euler number
	- `log` - natural logarithm of number `x` (`double log(double x)`)
	- `sqrt` - square root of `x`
	- `pow` - number `x` to power
	- `sin`, `asin` (arcus sinus), `sinh` (hyperbolic sinus)
	- `ceil` - whole upper part, eg. `ceil(5.1)` returns `6.0`
	- `floor` - whole bottom part, eg. `floor(5.8)` returns `5.0`
	- `trunc` - rounding down, eg. `trunc(2.7)` returns `2.0`
	- `round` - normal rounding, eg. `round(5.3)` returns `5.0`; `round(5.8)` returns `6.0`
	- `rand` - pseudorandom number from interval `<0;RAND_MAX>`
		- `RAND_MAX` is defined in `stdlib`, it's `32 767`
	- `srand` - rand with start from seed (`void srand(unsigned seed)`)

## Strings functions
- `#include <string.h>`
- basic string functions:
	- `strcpy`
		- `char *strcpy(char *destination, char *source)`
			- arguments are pointers to start of the string (can be moved)
		- copies also ending `\0`
		- destination capacity is not controlled
	- `strncpy`
		- `char *strncpy(char *dest, char *src, size_t n)`
			- added argument for maximum length of copied string
		- if the length of `src` is longer then `n` only part of `src` is copied and is NOT ended with `\0`, otherwise it is added
	- `strcat`
		- `char *strcat(char *dest, const char *src)`
		- concatenates destination with source
		- does not do an automatic realloc!
			- programmer must do that
	- `strlen` - returns length of string
	- `strcmp`
		- `int strcmp(const char *lhs, const char *rhs)`
		- returns:
			- negative number if `lhs` is less then `rhs`
			- `0` if the strings are same
			- else positive number
		- does not compare with nation specific symbols
	- `strcoll` - `strcmp` but with nation specific symbols
	- `strchr`
		- `char *strchr(const char *str, int ch)`
		- finds first occurrence of `ch`and returns pointer to position
		- returns `NULL` is not found
		- `\0` is considered are part of string
	- `srspn`
		- `size_t strspn(const char *dest, const char *src)`
		- returns maximum length of prefix that is same in `dest` and `src`
		- eg. `strspn("13572468auto","1234abcd")` returns `2` (because `5` is not `src`)
	- `strbrk`
		- `char *strpbrk(const char *dest, const char *src)`
		- returns pointer to first character in `dest` that is also in `src`
	- `strstr`
		- `char *strstr(const char *str, const char *substr)`
		- returns pointer to first occurrence of `substr` in `str`
		- ending character `\0` is not considered
	- `strerror` - transfers error number to string describing error
	- `atof` - converts longest possible prefix of string to `double`
	- `sscanf` - `int sscanf(const char *buffer, const char *format, ...)`

## Function design
- function definition contains:
	- return type
		- defines type of result
		- if nothing is returned return type is `void`
	- function name
		- function identification
	- list of parameters
		- function can have `0` to `253` parameters
		- no parameter is `void`
	- body

## Formal vs. real parameter
- formal parameter
	- definition of parameter in a function
- real parameter
	- the real "input" that is send as a parameter
- parameters are position sensitive

## Input vs input/output parameters
- better to use input/output parameter then global variable
	- sending pointer to the parameter not the whole parameter
```c
	void prohod(int x, int y) { /* předávám hodnotou, typ int */
		printf("PROHOD X: %d, Y: %d\n", x, y);
		x = x ^ y; /* pracuji přímo s proměnnými, které jsou na zásobníku */
		y = x ^ y;
		x = x ^ y;
		printf("PROHOD X: %d, Y: %d\n", x, y);
	}
	int main() {
		int x = 20, y = 10;
		printf("MAIN X: %d, Y: %d\n", x, y);
		prohod(x, y);          /* předání hodnotou */
		printf("MAIN X: %d, Y: %d\n", x, y);
		return 0;
	}```
- vs. 
 ```c
void prohod(int * px, int * py) { // passing variable address (int *)
	printf("PROHOD X: %d, Y: %d\n", *px, *py);
	*px = *px ^ *py; // working with pointers
	*py = *px ^ *py;
	*px = *px ^ *py;
	printf("PROHOD X: %d, Y: %d\n", *px, *py);
}
int main() {
	int x = 20, y = 10;
	printf("MAIN X: %d, Y: %d\n", x,y);
	prohod(&x, &y); // passing variable address
	printf("MAIN X: %d, Y: %d\n", x,y);
	return 0;
} ```


## Variable number of parameters
- declaration function with variable number of parameters:
	- `int printf ( const char * format, ... )`
- have to be used with `#include <srdarg.h>`
- definition of a parameter variable:
```c
va_list param;
va_start(param, d1);
```

## main()
- main function :D
- has no parameters
- if parameters are needed
	- `int main (int argc, char * argv[]) { `
	- `int argc` - how make arguments will be passed
	- `char *argv[]` - list of parameters

## Recursion
- function calling itself
	- can be direct and indirect