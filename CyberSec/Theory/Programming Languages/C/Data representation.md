- bite - two states in a memory cell - `0` (off) or `1` (on)
- 1 byte = 8 bites
	- compromise between speed (performance) and waisting


## Decadic 
- number with the base of 10
- `295.62` represented as:
	- `2*10^2 + 9*10^1 + 5*10^0 + 6*10^-1 + 2*10^-2`

## Binary
- binary to decimal transfer
	- `10110110` = `1*2^7 + 0*2^6 + 1*2^5 + 1*2^4 + 0*2^3 + 1*2^2 + 1*2^1 + 0*2^0` = `182`
- decimal to binary
	- `9` -> `9 % 2 = 1` -> `1`;  `9/2=4`; `4 % 2 = 0` -> `01` (is stacked from the end); `4 / 2 = 2`; `2 % 2 = 0` -> `001`; `2 / 2 = 1`; `1 % 2 = 1` -> `1001`

### Aritmetic operation on non-signed integers
- addition - 4 possibilities (0+0, 0+1, 1+0, 1+1) and overflow from lower position
	- can overflow to non existant bite
	```
	245 + 31 (dec) = 11110101 + 00011111 (bin)
	    1 1 1 1 0 1 0 1
	+   0 0 0 1 1 1 1 1
	(1) 0 0 0 1 0 1 0 0   =  20 (dec)
	```
- subtraction
	- actually adding negation of- second number plus one
	```
	 178 - 111 (dec) = 10110010 - 01101111 (bin)
                 = 10110010 + (-01101111)  (bin)
                 = 10110010 + 10010000 + 1 (bin)
		    1 0 1 1 0 0 1 0
		  + 1 0 0 1 0 0 0 0
		  +               1
		(1) 0 1 0 0 0 0 1 1   =  67 (dec)
	```
- multiplication
	- only one combination gives 1 (`1*1`) others give 0 (`0*0`, `1*0`, `0*1`)
	- can easilu overflow
	- multiple addition OR
	- something I cannot use words to describe
	```
	y *            x
	0 *            1 1 0 1 1 ->           0 0 0 0 0
	1 *          1 1 0 1 1   ->         1 1 0 1 1
	0 *        1 1 0 1 1     ->       0 0 0 0 0
	0 *      1 1 0 1 1       ->     0 0 0 0 0
	1 *    1 1 0 1 1         ->   1 1 0 1 1
                            --------------------
                              1 1 1 1 0 0 1 1 0
	```
- divination
	- not sure how to write it [more here](courses.fit.cvut.cz/BI-PA1/elearning/data_representation/unsigned-mul-div.html)


### Aritmetic operation on signed integers in 2's complement
- 2's complement is easy for arithmetic operations
- addition
	```
	 68 (dec) = 01000100 (bin)
	-73 (dec) = 10110111 (bin)
  			    --------
	      (0,0) 11111011 (bin) = -5 (dec)
	```
	- can overflow (when `-92 + (-57)`)
- subtraction
	- is changed to addition but the second number is negated and 1 is added
		```
		(-22)(dec) = 11101010 (bin)
		  82 (dec) = 01010010 (bin)
		22            11101010
		 negace 82   +10101101
		 horká 1            +1
		              --------
		        (1,1) 10011000 = -104 (dec)
		```

### Decimal representation
- rational
- `136.796875` to decimal/decadic
	- interger and decimal (rational) part is splitted
	- `136 = 10001000`
	- decimal part is multiplied by 2 and we get number from interval (^0, 2)
		```
		0.796875 * 2  = 1.59375
		0.59375  * 2  = 1.1875
		0.1875   * 2  = 0.375
		0.375    * 2  = 0.75
		0.75     * 2  = 1.5
		0.5      * 2  = 1.0
		0
		```
		- `0.796875` = `110011`
	- => `10001000.110011`
- transfer from the other side is simpler
	- each bit is multiplied by its corresponding `2^X`
	```
	1 * 2^6             = 64
	0 * 2^5             =  0
	0 * 2^4             =  0
	1 * 2^3             =  8
	1 * 2^2             =  4
	0 * 2^1             =  0
	1 * 2^0             =  1
	0 * 2^(-1)          =  0
	1 * 2^(-2)          =  0.25
	1 * 2^(-3)          =  0.125
	0 * 2^(-4)          =  0
	1 * 2^(-5)          =  0.03125
	1001101.01101 (bin) = 77.40625 (dec)
	```
- it is necessary to limit the accuracy
	- some numbers can easily get cycled (eg `0.45`)
		- the reminders (0.8, 0.6, 0.4, 0.2) repeat infinitely


#### Floating point
- representation of number with bigger size before/after decimal point or are approximated
	- will be inaccurate by design
	- eg approximation of the weight of electron `9.1 * 10^-31 kg`
- mantiss
	- 23+1 bit
	- small number bebore/after the decimal point
- exponent
	- 8 bits
- sign
	- `0` or `1`
- counted as = `x = (-1)s * m * 2e`

Type | Total size [bit] | Exponent [bit] | Mantiss [bit] | Sign [bit] | Accuracy | Range
---- | ----- | ---- | ------ | ------ | ----| ---- 
float | 32 | 8 | 23 | 1 | 7 | ~1038
double | 64 | 11 | 52 | 1 | 15 | ~10308

- arithmetics
	- addition
		- `x = 17.25`  + `y = 138.875`
		```
		In binary: 
		  x = 10001.01 (bin)
		  y = 10001010.111 (bin)
		Semilogarithmic (base 2):
		  x = 1.00010100000000000000000 (bin) * 2^4
		  y = 1.00010101110000000000000 (bin) * 2^7
		Transfer to same exponent:
		  x = 0.00100010100000000000000 (bin) * 2^7
		  y = 1.00010101110000000000000 (bin) * 2^7
		Adding mantisses:
		x+y = 1.00111000010000000000000 (bin) * 2^7
		    = 10011100.001 (bin) =
		    = 156.125 (dec)
		```
		- normalization = if addition of mantis is  `2` then we need to move mantiss one position to right and change exponent
	- multiplication
		- paradoxically more easier
		- mantisses are multiplicated and exponents are addited
			- `x = 8005` * `y = 4007`
		```
		Binary:
		  x = 1111101000101 (bin)
		  y = 111110100111 (bin)
		Semilogarithmic (base 2):
		  x = 1.11110100010100000000000 (bin) * 2^12
		  y = 1.11110100111000000000000 (bin) * 2^11
		Multiplication of mantisses, addition of exponents:
		x*y = 11.11010010111000100000011 (bin) * 2^23
		    = 1.111010010111000100000011 (bin) * 2^24
		Limit mantiss to 23 bits:
		x*y = 1.11101001011100010000001 (bin) * 2^24
		    = 1111010010111000100000010 (bin)
		    = 32076034 (dec)
		```
- special numbers
	- `0`
		- zero has mantiss 0 (special case)
		- lowest exponent value
	- `inf`
		- infinity, eg from divination by 0
		- highest exponent value and mantiss is ?
	- `NaN` 
		- Not a Number
		- result of operation is not defined in real numbers
		- highest exponent value and mantiss value is ? 
- accuracy is dicated by size of a mantiss


## Octal and Hexadecimal
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


## Transfer between all possible number bases
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

## Integers
- if number would be kept in memory in decimal base
	- there would have to stored the lenght/size of each number
	- processor would have to find out how much space each number takes
	- if the number would got bigger it could be bigger then the original space and would have to be moved
- compromise: having fixed size of memory cell for each number type no matter if the size is smaller
	- integers have 32-bits (`0 to 2^32 - 1`)
		- if higher positions are empty theh are filled with zeros
	- negative is that small number take same space as bigget (still int) numbers

### Integers without sign - in BCD and ASCII coding
- both close to decimal numbers

**1. BCD (binary coded decimal)**
- coding every decimal cifre with 4 bits
	- 4 * 4 = 16 - (decimal ~) 10 = 6 combinations not used
	- combination 1010 to 1111 are unused
- more memory needed then storing numbers in binary
- `x = 1658` => `0001` (1) + `0110` (6) + `0101` (5) + `1000` (8) => `001011001011000`
	- it is not the same as the same number but in decimal!!!!

Cifra | Code | Cifra | Code
----- | ---- | ---- | -----
0 | 0000 | 5 | 0101 | 
1 | 0001 | 6 | 0110 |
2 | 0010 | 7 | 0111 |
3 | 0011 | 8 | 1000 | 
4 | 0100 | 9 | 1001 |

**2. ASCII**
- even more memory "expensive"
- one decadic cifra as one byte
	- `2^8 = 256`
	- 256 possibilities, rest is unused (we are talking ONLY about numbers)
- information is kept only in the smallest 4 bits (lower nibble)
	- higher nibble is set for `0` to mean 0 and `1` to mean 1
- `x = 15` => `00110001` (1) + `00110101` (5) => `0011000100110101`
	- again not the same as the same number in 

Cifra | Code | Cifra | Code
----- | ---- | ---- | -----
0 | 00110000 | 5 | 00110101 | 
1 | 00110001 | 6 | 00110110 |
2 | 00110010 | 7 | 00110111 |
3 | 00110011 | 8 | 00111000 | 
4 | 00110100 | 9 | 00111001 |


Number of bytes | Number of bites | Min | Max in binary | Max in BCD | Max in ASCII
-------- | ----- | -------- | ------| ------- | ----
1 B | 8 b | 0 | 255 | 99 | 9
2 B | 16 b | 0 | 65 535 | 9 999 | 99 
4 B | 32 b | 0 | 4 294 967 295 | 99 999 999 | 9 999
8 B | 64 b | 0 | 18 446 744 073 709 551 615 | 9 999 999 999 999 999 | 99 999 999
16 B | 128 b | 0 | 340 282 366 920 938 463 463 374 607 431 768 211 455 | 


### Signed integers

**1. Signed bit** (primy kod)
- before the binary representation there is `0` for positive and `1` for negative numbers
- signed bit is the most significant bit (MSB) usually the highest position (most front)
- range is `-127` to `+127` (instead of `0 - 255`) ~ 256 possibilities

**2. 2's complement** (doplnkovy kod)
- most used for displaying signed integers
- fast arithmetic operations
- coding is not as direct as with signed bit option
- range: `-128` to `127`, only one null
- for positive number the representation is same as for signed bit representation
- negative numbers; two posibilities:
	- write an unsigned representation of `2^(n-x)` for -x in n-bit representation
	- write a representation on +X and take 2's complement
- `y = -53`
	```
	absolute value:     00110101
	negation:           11001010
							  +1
	binary image:       11001011
	```

**3. 1's complement, biased code**
- aditive code
- to coded values is added a value (usually `2^ (n-1)`)
- is not good for division and multiplying


## Characters
- computes are primary working with numbers
- each character has a correspondin number
- from the view of CPU there is no difference between number and character
- most difference is when displaying and loading
- characters are in strings
	- length of string is necessary for processing
	- length is stored/saved explicitely (integer with number if chars) or implicitely (special char at the end of the string)

### ASCII
- American Standart Code for Informaton Interchange
- standart of character coding
- originaly 128 characters, nowdays 256 possibilities
- different codings with some special characters
	- `ISO-8859-1`, `Win-1252` - USA, western Europe
	- `ISO-8859-2`, `Win-1250` - eastern Europe
	- `ISO-8859-5`, `Win-1251` - azbuka
	- ...

### UNICODE
- `0` to `1114111`
	- => at least 21 bits (~ 4 bytes)
- less "expensive" => `UTF-2`, `UTF-8`, ... (number is number of bites)
- `UTF-8`
	- chars coded with 1 to 4 bytes
	- from `0` to `127 ~0x7f`
		- chars from original ASCII
	- from `128 ~0x80` to `2047 ~0x7ff`
		- special characters (diacritics, greek alphabet, azbuka,...)
		- 2 bytes `110xxxxx 10xxxxxxx`
			- first: combination of highes bits on `110` = the character is made by two bytes
			- second: two highest bits on`10`
	- from `2048 ~0x800` to `65535 ~0xfff`
		- chinese, japanese, korean signs and idiograms
		- in 3 bytes: `1110xxxx 10xxxxxx 10xxxxxx`
			- similar reasoning
	- from `6536 ~0x10000` to `1114111 ~0x10fff`
		- rest of chinese characters and signs of dead languages


### Little-endien, Big-endien
- when saving byte value is it necessary to fill in neighbourgh values
- 2 possibilies how to sort the bytes
	- start with the highest byte = big-endien
	- srat with the lowest byte = little=endien
- coding is set by processor
	- Intel x86/x64, AMD, Atmel AVR and Dec Alpha – little-endien
	- Motorola, Sparc, IBM Power – big-endien
	- ARM, PowerPRM, new Spark CPUs – bi-endien
- each variant has its own advanatages and disadvantages
	- big-endien is easier to read by human
	- little-endien is easier for harware to convert
