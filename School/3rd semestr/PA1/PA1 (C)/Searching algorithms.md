### Sequence search
- used in arrays and linear linked structures
- does not require sorted data
```c
/* vrať index prvku v poli, -1, pokud tam prvek není */
int hledej(int pole[], int delkaPole, int x) {
	int i = 0;
	while (i < delkaPole && pole[i] != x)
		i++;
	if (i < delkaPole)
		return i; /* hodnota nalezena */
	return -1; /* hodnota nenalezena */
}
```
- time complexity: $O(n)$
- we can also save the number we are searching for at the end of the structure and then check all data against it:
```c
int hledejSeZarazkou(int pole[], int volny, int x) {
	int i = 0;
	pole[volny] = x; /* uložení zarážky */
	while (pole[i] != x)
		i++;
	if (i < volny)
		return i; /* hodnota nalezena */
	return -1; /* hodnota nenalezena */
}
```

### Binary search
- searching for a value by splitting (halving) the data structure
- in increasing sorted array:
	- get value of `y` element in the middle of searched array
	- is `x=y` then the value we are searching is found
	- if `x<y` then we continue to search in left part of array
	- if `x>y` we continue to search in right part of array
- eg: `[-2, 4, 11, 28, 42, 68, 99]` searching for `42`
	- value of middle element is `28` -> `42>28` continue right
	- value of middle element of right part is `68` -> `42<68` continue to left
	- middle (and) only value is `42` -> `42=42` match found
- time complexity: $O(log⁡n)$
```c
int hledejPulenim(int pole[], int pocet, int x) {
	int dolni = 0, horni = pocet - 1;
	while (dolni <= horni) {
		int stred = (dolni + horni)/2;
		if (x < pole[stred])
			horni = stred - 1;
		else if (x > pole[stred])
			dolni = stred + 1;
		else
			return stred;
	}
	return -1; /* nenalezen */
}
```
#### Binsearch in C library
- `void * bsearch (const void * key, const void * base, size_t nitems, size_t size, int(*compar)(const void *, const void *));`
- together with `qsort`:
```c
void printPole(int * pole, int n) {
	for (int i = 0; i < n; i++)
		printf("%4d ", pole[i]);
	printf("\n");
}

int intCmp(const void * a, const void * b) {
	const int * ia = (const int *)a; /* přetypování */
	const int * ib = (const int *)b;

	return *ia - *ib; /* POZOR!! */
}

int main(void) {
	int pole[] = { 7, 3, 4, 1, -1, 23, -43, 2, -4, 5, -102, 544, 87, 4598, 9, 254 };
	int hledam;
	int * nalezeno;
	int velikostPole = sizeof(pole)/sizeof(pole[0]);

	printf("Razeni cisel: neserazene \n");
	printPole(pole, velikostPole);
	qsort(pole, velikostPole, sizeof(int), intCmp); /* razeni */
	hledam = -1;
	nalezeno = (int*)bsearch(&hledam, pole, velikostPole, sizeof(pole[0]), intCmp);
	printf("Razeni cisel: serazene \n");
	printPole(pole, velikostPole);
	if (nalezeno != NULL)
		printf("Prvek nalezen na indexu %d.\n", nalezeno - pole);
	else
		printf("Prvek nenalezen.\n");
	return 0;
}
```

### Interpol search
- more smart binary search
- time complexity: $O(log⁡(log⁡n))$

### Text search
- searched text `T`, length `n`, pattern we are searching for `P`, its length `m`
- naïve algorithm
	- goes one by one and checks
	- if the check fails the whole process starts again from previous start `+1`
	- time complexity: $O(m∗n)$
	- eg. `T="nessie_asi_neuneseme"`, `P="nese"`
		- first start on true start of `T` (`T[0]`) -> check fails on `s!=e`
		- starts again from `T[1]`
- opposite direction algorithms -> Bad Character Shift
	- starting with aligning `T[0]` and `P[0]` and checking for match
	- if match is not found for whole pattern then the pattern is moved until the bad check matches with something
	- then the rest of the pattern is checked against the template text