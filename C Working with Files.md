- input/output from `stdin` to `stdout` is standard
- I/O from/to files:  (soubor = file; test = program)

|Deklarace|Význam|Přesměrování|
|---|---|---|
|FILE * stdin;|Standardní vstup (typicky klávesnice)|program < soubor|
|FILE * stdout;|Standardní výstup (typicky obrazovka)|program > soubor|
|FILE * stderr;|Standardní chybový výstup (typicky obrazovka)|program 2> soubor|

- add to the end of the file with `>>` instead of `>`

#### Error handling
```c
#include <errno.h> /* obsahuje definici globální proměnné errno, pro ukládání kódů */
                   /* chyby v případě neúspěchu některých standardních funkcí */
#include <stdio.h>
#include <string.h> /* obsahuje deklaraci funkce strerror(), vrací */
                    /* řetězec odpovídající kódu chyby v errno */

int main (void) {
    char * jmSouboru = "neco.txt";
    FILE * soubor = fopen(jmSouboru,"r");
    if (soubor != NULL) {
        fclose(soubor);
        printf("Soubor %s se podarilo otevrit.\n", jmSouboru);
    } else {
        int chyba = errno; /* aby nám ji nepřepsala další chyba */
        fprintf(stderr, "Soubor %s se nepodarilo otevrit. Chyba:%s\n", jmSouboru, strerror(chyba));
    }
    return 0;
}
```

#### End of input
- `scanf` until EOF
	- defined in `stdio.h` like `#define EOF (-1)`

## Direct and sequence approach
1. Sequence approach
	- data are read in sequence (as are naturally read and written)
	- defined by ANCI C (and POSIX)
	- implemented by `stdio.h`
	- file system is approached with the structure `FILE`:
	```c
	/* Definition of the control structure for streams */
	
	typedef struct  {
		int level;     /* fill/empty level of buffer */
		unsigned flags;     /* File status flags          */
		char fd;        /* File descriptor            */
		unsigned char hold;      /* Ungetc char if no buffer   */
		int bsize;     /* Buffer size                */
		unsigned char *buffer;  /* Data transfer buffer       */
		unsigned char *curp;    /* Current active pointer     */
		unsigned istemp;    /* Temporary file indicator   */
		short token;     /* Used for validity checking */
	} FILE;                       /* This is the FILE object    */	
	/* Bufferisation type to be used as 3rd argument for "setvbuf" function */
	
	#define _IOFBF  0
	#define _IOLBF  1
	#define _IONBF  2
	
	/*  "flags" bits definitions */
	#define _F_RDWR 0x0003     /* Read/write flag       */
	#define _F_READ 0x0001     /* Read only file        */
	#define _F_WRIT 0x0002     /* Write only file       */
	#define _F_BUF  0x0004     /* Malloc'ed Buffer data */
	#define _F_LBUF 0x0008     /* line-buffered file    */
	#define _F_ERR  0x0010     /* Error indicator       */
	#define _F_EOF  0x0020     /* EOF indicator         */
	#define _F_BIN  0x0040     /* Binary file indicator */
	#define _F_IN   0x0080     /* Data is incoming      */
	#define _F_OUT  0x0100     /* Data is outgoing      */
	#define _F_TERM 0x0200     /* File is a terminal    */
	```
2. Direct approach
	- is not part of ANSI norm; defined by POSIX
	- thanks to close relation to platform gives:
		- higher speed
		- implementation dependence
	- libraries: `sys/stat.h`, `fcntl.h`

## Text and binary files
- OS guesses the type of file from the postfix
- text file
	- file is structured
	- when reading, the character `\n` are automatically converted to new line, the same for write
	- number is saved as string
	- keeping a copy is more readable (using any text editor to view) and has better transferability between platforms
	- to read and write: `fscanf`, `fprintf`
- binary file
	- file unstructured - the assumption is that user/programmer knows what is the meaning of each byte in the file
	- no conversion
	- number is saved as number (`int`)
	- keeping a saved copy is less space consuming
	- uses hexa editor to view
	- to read and write: `fread`, `fwrite`

#### File opening
- different regimes of file open with `fopen`:
	- `FILE *fopen(char *jmeno, char *mod);`

|Mód otevření|Význam|
|---|---|
|r|otevření na začátku (čtení)|
|w|existující obsah vymazán (psaní)|
|a|otevření na konci (zápis na konec)|
|b|binární soubor (jinak textový)|
|+|update, přepisování|

- different regimes can be combined:
	- `r`, `a` -> text file
	- `rb`, `rw`, `ab` -> binary file
	- `r+`, `w+`, `a+` -> text file, update
	- `rb+` = `r+b`, `wb+` = `w+b`, `ab+` = `a+b` -> binary file, append, update

#### File close
- `int fclose(FILE *soubor);`

## Accessing random position in the file
- if it's required to not read data sequentially but "jump":
	- `int fseek(FILE * soubor, long offset, int odkud);`
	- `long ftell(FILE * soubor);`