

- bite - two states in a memory cell - `0` (off) or `1` (on)
- 1 byte = 8 bites
	- compromise between speed (performance) and waisting


### Decadic 
- number with the base of 10
- `295.62` represented as:
	- `2*10^2 + 9*10^1 + 5*10^0 + 6*10^-1 + 2*10^-2`

### Binary
- binary to decimal transfer
	- `10110110` = `1*2^7 + 0*2^6 + 1*2^5 + 1*2^4 + 0*2^3 + 1*2^2 + 1*2^1 + 0*2^0` = `182`
- decimal to binary
	- `9` -> `9 % 2 = 1` -> `1`;  `9/2=4`; `4 % 2 = 0` -> `01` (is stacked from the end); `4 / 2 = 2`; `2 % 2 = 0` -> `001`; `2 / 2 = 1`; `1 % 2 = 1` -> `1001`

### Octal and Hexadecimal
- grouping ones and zeros by four

Transfer from binary to | octal(0-7)/hexa(0-f)
---------- | -----
0000 | 0
0001 | 1
0010 | 2
0011 | 3
0100 | 4
0101 | 5
0110 | 6
0111 | 7
1000 | 8
1001 | 9
1010 | a
1011 | b
1100 | c
1101 | d
1110 | e
1111 | f
- in programming languages hexadecimal code is prefixed by `0x`
- octal is prefixes as `0`
- hexa is used in files and memory, in debugger, binary file display, binary editor


### Transfer between all possible number bases
- `[0-9,a-z]` possibilities
	- 10 + 26 = 36
- to decimal is relatively easy
	- `x = 1gj` with 21 base to decimal
			- g = 16; j = 19
			- `1 * 21 ^2 + 16 * 21^1 + 19 * 21^0 = 796`
- from decimal to any other
	- modulos/reminders after dividing with number of desired base
	- `x = 1234` from decimal to base 25
		- `1234 : 25 = 49 (reminder 9)`, `49 :  25 = 1 (reminder 24=o)`, `1 : 25 = 0 (reminder 1)` => `1o9`

### Integers
- if number would be kept in memory in decimal base
	- there would have to stored the lenght/size of each number
	- processor would have to find out how much space each number takes
	- if the number would got bigger it could be bigger then the original space and would have to be moved
- kompromise: having fixed size of memory cell no matter the size of the number
	- 