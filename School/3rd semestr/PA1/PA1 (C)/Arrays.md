- for saving more data of same type
- unbroken section of memory 
- indexed from 0

## One dimensional array
- array can be of `int`, `bool` or `char` type
- initialization: `int age[4] = {23, 12, 15, 34};`
	- generally: `dataType name[arraySize] = {variable1, variable2, ..., variableN};`
	- can also be WITHOUT arraySize!!
- accessing value on index:
	- `arr[idx];`
- value on index modification:
	- `arr[idx] newValue;`
- size of
	- `int letn = sizeof(arr)/sizeof(arrType);`
- eg: 
```c
void vypisPole(int pole[], int velikostPole) {
	for(int i=0; i<velikostPole;i++)
		printf("%5d", pole[i]); // all output with 5 "places", number in the middle, surounded by spaces
	printf("\n");
}

int * vratPoleNahodCisel(int velikostPole) {
	int * pole = (int*)malloc(velikostPole * sizeof(int));
	for(int i = 0; i < velikostPole; i++)
		pole[i] = rand()%100+1;
	return pole;
}

int main(void) {
	int * pole = vratPoleNahodCisel(100);
	vypisPole(pole, 100);
	return 0;
}
```

## Multidimensional array
- matrixes (2 dimensional arrays)
	- `int mat[2][3] = {{1, 4, 5}, {3, 6, 2}};`
- `arrayType arrName[rowCount][columnCount];`
- when using it as function parameter:
	- necessary to define all dimensions except first
	- `void ctiMatici(int mat[][DELKA_RADKU], int pocetRadku) { ... }`

## Dynamically allocated arrays
- `malloc`
- `calloc`
- `realloc`
	- dynamic memory reallocation 
	- `void *realloc(void *ptr, size_t size)`