- declaration
	- `int *ptrInt`, `char *ptrChar`
- accessing a byte of memory
	- declared variable is in continuous block in memory
	- pointer points to first of the address of the block
- creating: `<dataType> *<nameOfPointer>`
	- the `*` can be at the end of `dataType` or `nameOfPointer` or between
	- `int *ptr = &x;`
		- pointer to an address of variable x
- `&` - reference operator
	- gets an address
```c
	int k = 2000;
	int* ptr = &k;
	printf("%i ", *ptr); // prints 2000
	*ptr = 961; // change value of 'k' to 961 though pointer
	printf("%i\n", k); // prints 961 
```

|Kód v C|Vysvětlení činnosti|
|------------|---|
|`char c;`|Deklarace proměnné `c` typu `char`.|
|`char * pc;`|Deklarace proměnné `pc`, její typ je ukazatel na `char`.|
|`pc = &c;`|Navázání proměnné `pc` na `c`. V `pc` je nyní adresa proměnné `c` v paměti programu.|
|`*pc = 'A';`|Na adresu `pc` je uložena hodnota odpovídající znaku `'A'`.|

- NULL - setting pointer to empty 

#### Void*
- pointer of unknown type 
- cannot be dereferenced
```c
int main(void) {
	int  i;
	void * pi = &i;
	*pi = 10; /* toto nelze */
	return 0;
}
```

#### Pointer arithmetic
|Operace|Typ výsledku|Popis|
|---|---|---|
|`T* + int`|`T*`|Přičtení `n` k ukazateli typu `T*` znamená jeho posun o n-násobek délky typu `T`|
|`T* - int`|`T*`|Odečtení `n` od ukazatele typu `T*` znamená jeho posun o n-násobek délky typu `T`  (obdobně fungují prefixové i postfixové operátory **++** a **--**)|
|`T* - T*`|`int`|Počet prvků typu `T`, které lze uložit mezi adresy specifikované operandy|
|`T* < T*`|`int`|Zjistí, zda první ukazatel ukazuje v paměti před druhý.  (Obdobně pro další relační operátory >, <=, >=, \==, !=. ; Zde **není požadován stejný doménový typ ukazatelů.**)|

## Pointers in array
- `int a[10], *pa, i;`

|Výraz|Ekvivalentní výraz|Komentář|
|---|---|---|
|pa = a|pa = &a[0]|Pole je vlastně adresa prvního prvku.|
|*(a + 2) = 3|a[2] = 3|Třetímu prvku nastaví hodnotu 3.|
|*(2 + a) = 3|2[a] = 3|Třetímu prvku nastaví hodnotu 3, nehezké byť funkční.|
|*(a + i) = 4|a[i] = 4|Zobecnění.|
|for (pa = a; pa < a + 10; *pa++ = 0);|for (i = 0; i < 10; i++)  <br>a[i] = 0;|Pole lze procházet pomocí ukazatele.|
|int sectiPrvky(int pole[])|int sectiPrvky(int * pole)|Pole jako parametr funkce.|
|int \* xy[];  <br>int \*(xy[]);| | `xy` je pole ukazatelů na `int`  <br>totéž, protože operátor `[]` má vyšší prioritu než `*`|
|int (\*xyz)[];| |`xyz` je ukazatel na pole `int`|
|int **x[10][5];| | `x` je deseti-prvkové pole pěti-prvkových polí ukazatelů na ukazatele na `int`|
|int \*(\*x[4])(int, char);| | x je čtyř-prvkové pole ukazatelů na funkce s parametry typu `int` a `char`,  <br>které vrací ukazatel na `int`|


#### Combination * and ++
|Výraz|Význam|
|---|---|
|*p++|Přistup k datům odkazovaným ukazatelem p a poté inkrementuj p (posuň jej na další prvek).|
|(*p)++|Přistup k datům odkazovaným ukazatelem p a poté inkrementuj tato data.|
|*++p|Nejprve inkrementuj p a pak přistup k datům odkazovaným ukazatelem p.|
|++*p|Nejprve inkrementuj data odkazovaná ukazatelem p a pak tato data použij.|

#### Using const
- when declaring array then the variable cannot be changed
	- `int a[10]; a++ // does not work`
- how to change specific variable to unchangeable

|Deklarace funkce|Význam|
|---|---|
|int xyz(const int * uk);|Nesmí se měnit data, na která ukazuje **uk**, ale **uk** je možné přesměrovat na jiná data.|
|int xyz(int * const uk);|Nesmí se přesměrovat ukazatel **uk**, ale jím referovaná data lze měnit.|
|int xyz(const int * const uk)|Nesmí se měnit **uk** ani data.|

