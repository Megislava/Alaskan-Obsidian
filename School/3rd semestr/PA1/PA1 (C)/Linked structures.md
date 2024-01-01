- solves issue with unchangeable length of C arrays
- linked lists:
	- one-sided
	- both-sided
	- cyclical
- binary tree
- N-ary tree

### One-way linked list
- build on a structure that has a value and a reference to next element
```c
typedef struct prvek {
	int hodnota;
	struct prvek * dalsi;
} Prvek;
```
- to initialize start of linked list: `Prvek * zacatek = NULL;`
- to create a new structure element and add it to start of linked list:
	- using dynamic allocation
```c
Prvek * vytvorPrvek(int hodn, Prvek * dalsi) {
	Prvek * pom = (Prvek*)malloc(sizeof(Prvek));
	pom->hodn = hodn;
	pom->dalsi = dalsi;
	return pom;
}

int main(void) {
	Prvek * zacatek = NULL, * p;
	int cislo;
	printf("zadej posloupnost cisel zakoncenou nulou\n");
	scanf("%d", &cislo); /* osetreni vstupu */
	while (cislo) {
		zacatek = vytvorPrvek(cislo, zacatek);
		scanf("%d", &cislo); /* osetreni vstupu */
	}
	printf("vypis cisel v opacnem poradi\n");
	p = zacatek;
	while (p) {
		printf("%d ", p->hodn);
		p = p->dalsi;
	}
	printf("\n");
	return 0;
}
```

### Both-way linked list
- list keeps information about what is in from of element and what is behind
	- = pointers that point both-ways 
- positives: can move both ways
- negatives: working with it is more difficult, uses more memory

### Cyclical one-way linked list
- end elements points not to `NULL` but to start - creates a cycle

### Binary tree
- has one root (starting point) and each node has exactly one "parent" and at least two "children"
- in programming can be represented two ways:
	- by dynamic structure
		- routes are pointers (similar to linked list)
	- by array
		- element with index has "children" saved on positions with indexes `2i+1` and `2i+2`
		- this representation is also in `heapsort` algorithm
		- dominant structure used in PA1
- structure definition:
```c
typedef struct MUzel {
	char znak;
	struct MUzel * tecka, * carka;
} MUzel;
```
- create a new node
```c
#define MAXDELKA 100

MUzel * novyMUzel1(char z) {
	MUzel * p = (MUzel*)malloc(sizeof(MUzel));
	p->znak = z;
	p->tecka = NULL;
	p->carka = NULL;
	return p;
}

MUzel * novyMUzel(char z, MUzel *t, MUzel *c) {
	MUzel * p = (MUzel*)malloc(sizeof(MUzel));
	p->znak = z;
	p->tecka = t;
	p->carka = c;
	return p;
}

MUzel * koren;

void dekoduj(char odkud[], char kam[]) {
	MUzel * aktualni = koren;
	int i = 0, j = 0, delka = strlen(odkud);
	while (i < delka) {
		char z = odkud[i];
		if (aktualni != NULL) {
			if (z == '.')
				aktualni = aktualni->tecka;
			else if (z == '-')
				aktualni = aktualni->carka;
			else {
				kam[j++] = aktualni->znak;
				aktualni = koren;
			}
			i++;
		}
		else {
			kam[j++] = '?';
			while (odkud[i] == '.' || odkud[i] == '-')
				i++;
			aktualni = koren;
		}
	}
	kam[j] = 0;
}

int main() {
	koren = strom();
	char morse[MAXDELKA]; /* = ".../---/.../ " */
	char text[MAXDELKA]; /*  ..-./../- */
	fgets(morse, MAXDELKA, stdin);
	dekoduj(morse, text);
	fprintf(stdout, "%s\n", text);
	return 0;
}
```
- binary search tree
	- one of possible usages
	- representation by linked structure or array
	- typical operations: search for elements, insert element, remove element
	- time complexity: $O(logn)$

### N-ary tree 
- for more the two "children" in each node
	- eg. for DNA, alphabet, ASCII, Unicode,...
- representation:
	- linked structure
		- each node keeps pointers to children
		- array of children - sorter or unsorted
		- or pointer to first child and second pointer to neighbour node
	- table
		- for each node is in table one line
			- line has: constant length correlating with number of symbols, length dependant on number of children