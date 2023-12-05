- accessing a byte of memory
	- declared variable is in continuous block in memory
	- pointer points to first of the address of the block
- creating: `<dataType> *<nameOfPointer>`
	- the `*` can ve at the end of `dataType` or `nameOfPointer` or between
	- `int *ptr = &x;`
		- pointer to an address of variable x
- `&` reference operator
	- gets an address
- ```c
	int k = 2000;
	int* ptr = &k;
	printf("%i ", *ptr); // prints 2000
	*ptr = 961; // change value of 'k' to 961 though pointer
	printf("%i\n", k); // prints 961
	```