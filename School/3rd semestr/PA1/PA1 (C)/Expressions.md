#### Operator Function calling `()`
- change of priority
- function calling
- overtyping

#### Operator Accessing field of array `[]`
- indexing in array
- works also with pointers

#### Operator Access to structures `.` and `->`
- `.`
	- direct access 
- `->`
	- access to pointer structure
- ```c
	typedef struct TComplex {
		double re, im;
	} TCOMPLEX;
	
	int main (void) {
		TCOMPLEX x, *y = &x;
	
		x.re = 10;
		x.im = 20;
	
		y->re = 10;
		y->im -= 20;
		return 0;
		}
- are interchangeable
	- ```c
	typedef struct TComplex {
		double re, im;
		} TCOMPLEX;
		
		int main (void) {
		TCOMPLEX x, *y = &x;
	
		(&x)->re = 10;  /* x.re  = 10; */
		(*y).im  = 20;  /* y->im = 20; */
		return 0;
	}

#### Increments and decrements `++` and `--`
- postfixed
	- immediate result is same with original value of variable
	- value of variable is changed after the line is run
- prefixed
	- immediate result is the new value of variable
	- value of variable is changed BEFORE the line is run

#### Logical and bit negation `!` and `~`
- `!`
	- logical negation
	- 0 -> 1; 1 -> 0
- `~`
	- changes binary representation
	- changes 0s to 1s and the other way round
	- used with operators for bit rotation and others

#### Operators `+` and `-`
- additive
	-  addition and subtraction
- unary
	- both operators are used for accenting or change of the sign
	- rather don't use

#### Reference and dereference operators `&` and `*`
- `&`
	- gets address of variable
	- can only get address of variable if it is stored in memory
- `*`
	- dereferences pointer
	- is similar to operator for accessing values in array

#### `sizeof`
- how many bytes is taken by an operand
- based on data type of operand
- is received during compilation
- does not work for getting length of string
- returns `size_t` (sized 64/32 bits according to platform)
	- printf by `%zd`

#### Operator for changing type
- while converting, things can happen:
	- spread out (elongate)
		- eg. `short int` to `long int`
		- new bits are filled to respect sign of original data type
	- spread in (shorten)
		- eg. `long int` to `short int`
		- higher bits are lost
		- precision can be lost (`double` to `float`)
	- keep number of bites
		- eg. `signed int` to `unsigned int`

#### Multiplicative operators `*`, `/` and `%`
- multiplication, division, modulo
- possible issues with the reminder:
- |Dělenec|Dělitel|Podíl|Zbytek|
|---|---|---|---|
|+|+|+|+|
|+|-|-|+|
|-|+|-|-|
|-|-|+|-|

#### Arithmetic shift `<<` and `>>`
- arithmetic shift left `<<` or right `>>`
	- basically multiplication/division by cube of 2 

#### Relation operators `<=`, `\<`, `>=`, `==`, `!=`
- value comparison
- result is true or false
- ```c
	int a = 10, b = 10, c = 1;
	if (a == b == c) { ... }
	 /* zde splněno. Výraz se chápe jako if ((a == b) == c) { }
		 should be */
	if (a == b && b == c) { ... }
- ```c
	int a = 10, b, c = 100;
	
	if (a < b < c) { ... }
	 /* tato podmínka je opět splněna i pro hodnoty b, pro které by to nebylo očekáváno.
	  * Protože se výraz vyhodnotí jako if ((a < b) < c)
	  * bude výsledkem první závorky buď 0 nebo 1. Ale obě tyto hodnoty jsou menší než 100,
	  * tedy podmínka bude splněná pro libovolnou hodnotu b.
	  *
	  * should be:
	  */
	if (a < b && b < c) { ... }
- when comparing different data types, types can change
	- especially problematic is comparing signed and unsigned data types

#### Bit operators `&`, `|` and `^`
- work with operands like with array of bits
- `&` AND, `|` OR, `^` XOR
- ```c
	unsigned char a = 12, b = 5, c;
	// a = 12 = 00001100; b =  5 = 00000101
	c = a & b; // c =  4 = 00000100	
	c = a | b; // c = 13 = 00001101	
	c = a ^ b; // c =  9 = 00001001 
- usually used for manipulation with bits in HW

#### Logical operators `&&` and `||`
- logical AND `&&` and logical OR `||`
- work in shortened evaluation
	- when AND operator and first operand is FALSE is does not continue

#### Ternary operator `?` and `:`
- one line if
- first part (before `?`) is evaluated and based on result then continues to `:`
	- `(expression) ? IF_TRUE : IF_FALSE`

#### Assigning operators `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `<<=`, `>>=`, `&=`, `|=` and `^=`
- modification of variable value

#### Comma `,`
- used in for cycle formation or matrix formation

#### Priority of operators
|Priorita|Asociativita|Operátor|Význam|
|---|---|---|---|
|1|L|`( )`  <br>`[ ]`  <br>`.`  <br>`->`  <br>`++`  <br>`--`|[Zvýšení priority podvýrazu a volání funkce](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/func-call.html)  <br>[Odkaz na prvek pole](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/array-index.html)  <br>[Přímý přístup k položce struktury](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/member-access.html)  <br>[Nepřímý přístup k položce struktury](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/member-access.html)  <br>[Postinkrement](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/inc-dec.html)  <br>[Postdekrement](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/inc-dec.html)|
|2|R|`++`  <br>`--`  <br>`!`  <br>`~`  <br>`+`  <br>`-`  <br>`*`  <br>`&`  <br>`sizeof`  <br>`(type)`|[Preinkrement](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/inc-dec.html)  <br>[Predekrement](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/inc-dec.html)  <br>[Logická negace](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/not.html)  <br>[Bitová negace](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/not.html)  <br>[Kladné znaménko operandu](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/neg.html)  <br>[Záporné znaménko operandu](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/neg.html)  <br>[Dereference ukazatele (zpřístupnění hodnoty)](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/ref-deref.html)  <br>[Reference (získání adresy)](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/ref-deref.html)  <br>[Zjištění velikosti operandu](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/sizeof.html)  <br>[Přetypování operandu](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/typecast.html)|
|3|L|`*`  <br>`/`  <br>`%`|[Násobení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/multiplicative.html)  <br>[Dělení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/multiplicative.html)  <br>[Zbytek po dělení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/multiplicative.html)|
|4|L|`+`  <br>`-`|[Sčítání](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/additive.html)  <br>[Odčítání](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/additive.html)|
|5|L|`<<`  <br>`>>`|[Bitový posun vlevo](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/bit-shift.html)  <br>[Bitový posun vpravo](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/bit-shift.html)|
|6|L|`<`  <br>`<=`  <br>`>`  <br>`>=`|[Porovnání - menší než](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/relational.html)  <br>[Porovnání - menší rovno](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/relational.html)  <br>[Porovnání - větší než](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/relational.html)  <br>[Porovnání - větší rovno](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/relational.html)|
|7|L|`==`  <br>`!=`|[Porovnání - rovnost](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/relational.html)  <br>[Porovnání - nerovnost](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/relational.html)|
|8|L|`&`|[Bitový součin - AND](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/bitwise.html)|
|9|L|`^`|[Bitová nonekvivalence - XOR](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/bitwise.html)|
|10|L|`\|`|[Bitový součet - OR](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/bitwise.html)|
|11|L|`&&`|[Logický součin - AND](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/logic.html)|
|12|L|`\|`|[Logický součet - OR](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/logic.html)|
|13|R|`?:`|[Ternární operáror - podmínka](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/ternary.html)|
|14|R|`=`  <br>`+=`  <br>`-=`  <br>`*=`  <br>`/=`  <br>`%=`  <br>`>>=`  <br>`<<=`  <br>`\|=`  <br>`^=`  <br>`&=`|[Přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Součet a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Rozdíl a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Součin a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Podíl a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Zbytek po dělení a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Bitový posun vpravo a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Bitový posun vlevo a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Bitový součet a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Bitová nonekvivalence a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)  <br>[Bitový součin a přiřazení](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/assign.html)|
|15|L|`,`|[Operátor zapomenutí](https://courses.fit.cvut.cz/BI-PA1/elearning/expressions/comma.html)|
- generally follows rules from normal life
