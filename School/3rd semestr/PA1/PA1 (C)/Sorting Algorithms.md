- non smart sorting algorithms
	- random sorting,...

### Bubble sort
- compare two neighbouring numbers and switch if they aren't in wanted order
- in first run, the biggest value gets to right (bubbles up), etc
```c
void vymena(int * p, int * q) {
	int pom;
	pom = *p;
	*p = *q;
	*q = pom;
}

void bubbleSort(int a[], int n) {
	do {
		int vymeneno = 0;
		for (int i = 1; i < n; i++)
			if (a[i-1]>a[i]) {
				vymena(&a[i-1], &a[i]);
				vymeneno = 1;
			}
		n--;
	} while (vymeneno);
}
```
- positives: easy to program, can end before end of all cycles if the arrays is already sorted, stable
- negatives: quadratic complexity, not effective for smaller numbers (turtles)
- best case scenario time complexity: $O(n)$; worst case: $O(n^2)$
- space complexity: no additional memory needed

### Shaker sort, cocktail sort
- removes issue with slow moving of smaller numbers (turtles)
- starts as bubble sort, but second run is not again from start but is from end
	- after two runs the array is sorted from left and right
- positives: easy to program, effective for both big and small numbers, can end sooner if the arrays is already sorted, stable
- negatives: quadratic for best and worst case 
- time complexity: best case $O(n)$; worst case $O(n^2)$$
- space complexity: no additional memory needed

### Select sort
- repetitively searches for the smallest number
- first run goes thought the whole unsorted array and finds a global minimum and switches it up with first number in array
- second run searches array with length `-1`, finds minimum and puts it to second position
```c
void vymena(int * p, int * q) {
	int pom = *p;
	*p = *q;
	*q = pom;
}

void selectSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int imin = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[imin])
				imin = j;
		if (imin != i)
			vymena(&a[imin], &a[i]);
	}
}
```
- algorithm does not know if the rest of the array is already sorted - will always run all possibilities
- positives: easy to program, stable
- negatives: quadratic complexity in best, average and worst case
- time complexity: $O(n^2)$
- space complexity: no additional memory needed

### Insert sort
- uses partially sorted array and inserts additional numbers by gradually comparing them starting from the highest numbers, if the inserted number is smaller is swaps them and continues to next number
```c
void vloz(int a[], int n, int x) {
	int i = n - 1;
	for (; i >= 0 && a[i] > x; i--)
		a[i+1] = a[i]; /* odsun */
	a[i+1] = x; /* vlozeni */
}

void insertSort(int a[], int n) {
	for (int k = 1; k < n; k++)
		vloz(a, k, a[k]);
}
```
- positives: easy to program, it recognizes if array is already sorted, stable
- negatives: quadratic complexity for worst and average case
- time complexity: worst $O(n^2)$, best $O(n)$
- space complexity: no additional memory needed

### Merge sort
- uses repeated merging of sorted subarrays
- merging two sorted subarrays:
	- `[1, 4, 5, 5, 8, 11, 102]` and `[-8, 0, 5, 11, 91]`
	- first numbers are compared (`-8` and `1`) and smaller is put to new SORTED array, ...
- the end array is the concatenated length of both arrays
- recursive version:
```c
void merge(int a[], int b[], int levy, int pravy, int poslPravy) {
	int poslLevy = pravy - 1, i = levy, prvniLevy = levy;

	while (levy <= poslLevy && pravy <= poslPravy)
		b[i++] = (a[levy] < a[pravy]) ? a[levy++] : a[pravy++];

	while (levy <= poslLevy)
		b[i++] = a[levy++];
	while (pravy <= poslPravy)
		b[i++] = a[pravy++];
}

void mergeSortRek(int a[], int pom[], int prvni, int posl) {
	if (prvni < posl) {
		int stred = (prvni + posl)/2;
		mergeSortRek(a, pom, prvni, stred);
		mergeSortRek(a, pom, stred + 1, posl);
		merge(a, pom, prvni, stred + 1, posl);
		for (int i = prvni; i <= posl; i++)
			a[i] = pom[i];
	}
}

void mergeSort(int a[], int n) {
	int * pom = (int*)malloc(n * sizeof(int));
	mergeSortRek(a, pom, 0, n - 1);
	free(pom);
}
```
- non-recursive version:
```c
void merge(int a[], int b[], int levy, int pravy, int poslPravy) {
	int poslLevy = pravy - 1, i = levy, prvniLevy = levy;

	while (levy <= poslLevy && pravy <= poslPravy)
		b[i++] = (a[levy] < a[pravy]) ? a[levy++] : a[pravy++];

	while (levy <= poslLevy)
		b[i++] = a[levy++];
	while (pravy <= poslPravy)
		b[i++] = a[pravy++];
}

int min(int x, int y) {
	if (x < y)
		return x;
	return y;
}

void mergeSort(int a[], int n) {
	int * pom = (int*)malloc(n*sizeof(int)), *odkud = a, *kam = pom;
	int delkaUseku = 1, posl = n - 1;
	while (delkaUseku<n) {
		int levy = 0;
		while (levy <= posl) {
			int pravy = levy + delkaUseku;
			merge(odkud, kam, levy, min(pravy, n), min(pravy + delkaUseku - 1, posl));
			levy = levy + 2 * delkaUseku;
		}
		delkaUseku = 2 * delkaUseku;
		int *p = odkud;
		odkud = kam;
		kam = p;
	}
	if (odkud != a)
		for (int i = 0; i < n; i++)
			a[i] = pom[i];
}
```
- positives: very fast, stable
- negatives: needs additional space for the end arrays
- time complexity: worst and best case $O(n⋅log⁡n)$
- space complexity: needs additional memory of same size (or at least 50%) as the original arrays

### Quicksort
- has numbers from start, end and pivot
	- pivot = estimate of median
- starts with not sorted arrays, chooses pivot and creates a array where numbers smaller then pivot are on left and bigger are on right side
- eg: `[8, 2, 1, -4, 5, 9, 0, 7, 3, 11, 2, 18, 5]`, use two pointers to numbers in array
	- choose median from first, last name middle position (from `8, 5, 0`) -> `5`
	- switch `5` with number on first position -> `[5, 2, 1, -4, 5, 9, 0, 7, 3, 11, 2, 18, 8]` (`[8, ..., 5]` to `[5, ..., 8]`)
	- first goes though array from left, second goes from right
	- both are searching for number that does not belong to their part of array
		- aka on left from pivot is bigger then pivot, on right from pivot smaller then pivot
		- `[5, 2, 1, -4, 5, **9**, 0, 7, 3, 11, **2**, 18, 8]`
	- switch them -> `[5, 2, 1, -4, 5, 2, 0, 7, 3, 11, 9, 18, 8]`
	- continue with searching and swapping
		- `[5, 2, 1, -4, 5, 2, 0, **7**, **3**, 11, 9, 18, 8]` -> `[5, 2, 1, -4, 5, 2, 0, 3, 7, 11, 9, 18, 8]`
	- until the pointers will meet then swap current pivot with there the pointers have met
		-  -> `[**3**, 2, 1, -4, 5, 2, 0, **5**, 7, 11, 9, 18, 8]`
	- now left from the pivot are numbers less or same then the pivot and on right side bigger or same then pivot
	- choose start, end and pivot points from the "split" arrays
		- `[**3**, 2, 1, **-4**, 5, 2, **0**, **5**, **7**, 11, **9**, 18, **8**]`
		- and start sorting again
	- in the end: `[-4, 0, 1, 2, 2, 3, 5, 5, 7, 8, 9, 11, 18]`
- choosing pivot is crucial - does influence time complexity
	- any fixed position is not ideal
	- random number - often used
	- median 3, 5, 7
- positives: in reality fast (average speed $O(1,39⋅n⋅logn)$), does not need additional memory
- negatives: unstable (can change position of number that are equivalent), is not appropriate for sorting in outside memory, if pivot is badly chosen and data are bad it can be up to quadratic complexity
- time complexity: best case $O(n⋅log⁡n)$, worst case $O(n^2)$
- space complexity: does not need additional space
- is implemented in library `stdlib.h`
	- `void qsort(void * base, size_t num, size_t size, int(*comparator)(const void *, const void *))`
```c
int porovnejInt(const void * a, const void * b) {
	int aa = *(int*)a;
	int bb = *(int*)b;
	if (aa < bb)
		return -1;
	if (aa > bb)
		return 1;
	return 0;
}
int main(int argc, char * argv[]) {
	int pole[9] = {1,5,9,3,6,4,89,23,11};
	qsort((void*)pole,9,sizeof(int),porovnejInt);
	for (int i = 0; i < 9; i++)
		printf("%3d, ", pole[i]);
	printf("\n");
	return 0;
}
```
- more complex code:
```C
typedef struct student {
	char jmeno[MAXDELKA];
	char prijmeni[MAXDELKA];
	float prumer;
} Student;

 /*vrací int, jestliže je první prvek menší, pak záporné èíslo
 jestliže je vìtší, pak kladné číslo pokud jsou stejné, nulu */

int porovnejPodleProspechu(const void * a, const void * b) {
	Student aa = *(Student*)a;
	Student bb = *(Student*)b;
	if (aa.prumer < bb.prumer)
		return -1;
	if (aa.prumer > bb.prumer)
		return 1;
	return 0;
}
int porovnejPodleJmena(const void * a, const void * b) {
	Student aa = *(Student*)a;
	Student bb = *(Student*)b;
	int podlePrijmeni = strcmp(aa.prijmeni,bb.prijmeni);
	if (podlePrijmeni)
		return podlePrijmeni;

	/* prijmeni se shoduji, rozdel podle jmena */
	return strcmp(aa.jmeno,bb.jmeno);
}
int main(int argc, char * argv[]) {
	Student studenti[]= {{"Pepa","Novak",1.2},
						 {"Petr","Prochazka",1.8},
						 {"Chuck","Norris",0.99},
						 {"Pepa","Zdepa",3.8},
						 {"Petr","Novak",1.1}
						};

	qsort((void*)studenti, 5, sizeof(Student), porovnejPodleProspechu);
	// qsort((void*)studenti,5,sizeof(Student),porovnejPodleJmena);

	for (int i = 0; i < 5; i++)
		printf("%10s, %10s, %5g \n",
			studenti[i].prijmeni, studenti[i].jmeno, studenti[i].prumer);
	printf("\n");
	return 0;
}
```

## Implementation in C libraries
```c
void qsort(void * base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))

void qsort_r (void * base, size_t nmemb, size_t size, void * thunk, int(*compar)(void *, const void *, const void *))

int heapsort (void * base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))

int mergesort(void * base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
```
- generally goes: 
	- `qsort` is faster then `mergesort` and that is faster then `heapsort`
	- `qsort` and `heapsort`
	- `mergesort` is stable
