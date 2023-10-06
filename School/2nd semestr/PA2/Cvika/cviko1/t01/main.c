#include <stdio.h>
#include <stdlib.h>

/** Defines minimum size of arrayCpp. */
#define N_MIN 5

/**
 * Struct represents arrayCpp.
 */
typedef struct arrayCpp {
	/** Number of elements in arrayCpp. */
	size_t n;
	/** Pointer to memory with numbers. */
	double * data;
} array_t;

/**
 * Free arrayCpp allocated memory.
 * @param[in] arr Pointer to arrayCpp (to be freed).
 */
void array_free ( array_t * arr ) { 
	free(arr->data);
	arr->data = NULL;
	arr->n = 0;
}

/**
 * Scans numbers from standard input into arrayCpp.
 * @param[out] arr Pointer to arrayCpp, which is used for reading numbers from input.
 * @returns 0 for error during reading standard input, 1 if everything is OK
 */
int array_scan ( array_t * arr )
{
	if ( scanf( "%zu", &( arr->n ) ) != 1 || arr->n < N_MIN ) {
		return 0;
	}

	arr->data = (double *) malloc( arr->n * sizeof( double ) );
	for ( size_t i = 0; i < arr->n; ++i ) {
		if ( scanf( "%lf", arr->data + i ) != 1 ) {
			array_free(arr);
			return 0;
		}
	}

	return 1;
}

/**
 * Prints numbers from arrayCpp to standard output.
 * @param[in] arr Pointer to arrayCpp with numbers.
 */
void array_print ( const array_t * arr ) {
	for(size_t i = 0; i < arr->n; i++) {
		if(i != 0) printf(" ");
		printf("%g", arr->data[i]);
	}
	printf("\n");
}

int double_compare(double * a, double * b) {
	return (*a > *b) - (*b > *a); 
}

/**
 * Sorts numbers in the passed arrayCpp.
 * @param[in] arr Pointer to arrayCpp (to be sorted).
 */
void array_sort ( array_t * arr ) {
	qsort(arr->data, arr->n, sizeof(double), (int (*) ( const void *, const void * )) double_compare);
}

int main ( void )
{
	// TASK: Implement main using functions defined above.
	array_t array;
	if(!array_scan(&array)) {
		printf("Nespravny vstup.\n");
		return 1;
	}
	array_print(&array);
	array_sort(&array);
	array_print(&array);
	array_free(&array);
	return 0;
}

/*****************************************************************************/

/*int array_scan ( array_t * arr )
{
	if ( scanf( "%zu", &( arr->n ) ) != 1 || arr->n < N_MIN ) {
		return 0;
	}

	arr->data = (double *) malloc( arr->n * sizeof( double ) );
	for ( size_t i = 0; i < arr->n; ++i ) {
		if ( scanf( "%lf", arr->data + i ) != 1 ) {
			array_free( arr );
			return 0;
		}
	}

	return 1;

}

void array_print ( const array_t * arr )
{
	for ( size_t i = 0; i < arr->n; ++i ) {
		if ( i != 0 )
			printf( " " );
		printf( "%g", arr->data[ i ] );
	}
}

int double_compare ( const double * a, const double * b )
{
	return ( *a > *b ) - ( *a < *b );
}

void array_sort ( array_t * arr )
{
  qsort( arr->data, arr->n, sizeof( double ),
		(int (*) ( const void *, const void * )) double_compare
  );
}

void array_free ( array_t * arr )
{
	free( arr->data );
	arr->n = 0;
	arr->data = NULL;
}
*/