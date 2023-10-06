#### Arrays
- array can be of `int`, `bool` or `char` type
- initialization: `int age[4] = {23, 12, 15, 34};`
	- generally: `dataType name[arraySize] = {variable1, variable2, ..., variableN};`
	- can also be WITHOUT arraySize!!
- indexing from 0
- accessing value on index:
	- `arr[idx];`
- value on index modification:
	- `arr[idx] newValue;`
- size of
	- `int letn = sizeof(arr)/sizeof(arrType);`

#### Matrixes
- matrixes (multidimensional arrays)
	- `int mat[2][3] = {{1, 4, 5}, {3, 6, 2}};`
- `arrayType arrName[rowCount][columnCount];`

#### Strings
- initialization via *initialized array*:
	- `char str[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};`
	- has to end with `\0` = null terminating character
- initialize via *string literal*:
	- `char str[] = "Hello World";`
	- null terminating character is added implicitly
- print with `printf("%s", str);`
- print character on index: `printf("%c", str[index]);`
	- PRINTING C (char) not string!
- length of string: `strlen(str);`
- concatenation of string: `strcat(firstStr, secondStr);`
- string copy: `strcpy(targetStr, sourceStr);`