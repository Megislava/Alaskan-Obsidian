- basically reservation of memory space for future
- program is always run as it is written/in the same flow

- declaration
	- specifiyng data type + name
- initialization
	- giving a value to declared variable
	- can be also `undefined`



### `int` (and `unsigned`, `short`, `long`)
```c
int i = -27;
long l = 123456789012345678L;
short s = 500;
int ii = 0xFF;
int iii = +007;
unsigned int ui = 3000000000u;
long long x = 1234567890123456789LL;
```
- integer = whole number
- 32-bit (biggest number is: 4 294 967 296)
	- `-2 147 483 648` → `+2 147 483 647` (`-2^31` → `2^31-1`)
- `+`/`-`/no sign - interpreeted as `int`
- norm for sizes: `short int <= int <= long int`

Type; Equivalent signature | Bytes | Bits | Range 
------ | ----- | ---- | -----
**signed char** | 1 | 8 | -128 ⇒ +127
**unsigned char** | 1 | 8 | 0 ⇒ +255
signed short int = **short int** = short | 2 | 16 | -32 768 ⇒ +32 767
**unsigned short int** = unsigned short | 2 | 16 | 0 ⇒ +65 535
signed int = signed = **int** | 4 | 32 | -2 147 483 648 ⇒ +2 147 483 647
**unsigned int** = unsigned | 4 | 32 | 0 ⇒ +4 294 967 295
signed long int = signed long = **long** | 4 | 32 | -2 147 483 648 ⇒ +2 147 483 647
**unsigned long int** | 4 | 32 | 0 ⇒ +4 294 967 295
signed long long = **long long** (C99 only) | 8 | 64 | -9 223 372 036 854 775 808 ⇒ +9 223 372 036 854 775 807
**unsigned long long** (C99 only) | 8 | 64 | 0 ⇒ + 18 446 744 073 709 551 616

- if we need a firmly sized variable use `uint8_t`, `sint8_t`, `uint16_t`, `sint16_t`, `uint32_t`, `sint32_t`, `uint64_t`, `sint64_t`, etc

- suffixes:
	- `l`/`L` → `long int`
	- `LL` → `long long`
	- `u` - no sign number
- prefixes:
	- `0` - octal number
	- `0x`/`0X` - hexadecimal number
-  often don't warn when the lenght is exceeded!
	- if it overflows, it sets the variable value to the literal limit
		- `unsigned int i = -27` - `unsigned` cannot be negativ; `i` will be set to `4294967269`

- in `scanf`
	- `%d` - decimal, `%x` - hexa (in `prinf` if used `%X` prints upper case)


### `float`, `double`
- `double` - numbers with decimal point
- `float` - has to be declared with `f`/`F` at the end (suffix)
	- `205.F`
	- `%f` - float
	- `$.2f` - float with 2 points rounded
- science notation also possible
	- `1E2` = 1 * 10^2 =100
	- `1.45E4` = 1.45 * 10^4 = 14500
	- `45e-4` = 45 * 10^-4 = 0.0045
	- `.0e2` = 0
- `long double`

Type | Bytes | Bits
--- | ----- | ----
float | 4 | 32
double | 8 | 64
long double | 10 | 80


### `char`
- characters
- escape sequence
	- `' '` (space), `'\\'` (`\`), `'\"'` (single `"`), `'\''` (single `'`), `\n` (new line), `\r` (carriage return), `\b` (backspace), `\t` (horizontal TAB), `\f` (form feed), `\a` (buzzer/alarm), `\v` (vertical TAB), `\?` (question mark), `\nnn` (char with ocal code `nnn`), `\xhh` (hexa char `hh`)
- basic ASCII character table (first 128 chars) is same on all platforms  
- strings
	- defined with `char` and lenght
	- `char string[30] = "string o delce max 30";`


### Boolean values
- `false` or `true`
- can be reversed with `bool value = false; value = !value` → `true`