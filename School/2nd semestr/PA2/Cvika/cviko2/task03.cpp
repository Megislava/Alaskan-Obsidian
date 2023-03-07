#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct date_t
{
	int year;
	int month;
	int day;
};

// TASK function date_scan

// TASK function date_print

bool date_compare ( const date_t & d1, const date_t & d2 )
{
	// TASK body of function date_compare
}

struct datelist_t
{
	size_t n;
	date_t * data;
};

void datelist_free ( datelist_t & dl )
{
	// TASK Deallocate memory (dl.data)
	dl.n = 0;
	dl.data = nullptr;
}

bool datelist_scan ( datelist_t & dl )
{
	if ( !( cin >> dl.n ) || dl.n <= 0 )
		return false;

	// TASK Allocate memory (dl.data)
	for ( size_t i = 0; i < dl.n; ++i ) {
		if ( !dl.data[ i ].scan() ) {
			datelist_free( dl );
			return false;
		}
	}

	return true;
}

void datelist_print ( const datelist_t & dl )
{
	for ( size_t i = 0; i < dl.n; ++i ) {
		dl.data[ i ].print();
		cout << endl;
	}
}

void datelist_sort ( datelist_t & dl )
{
	sort( dl.data, dl.data + dl.n, date_compare );
}

int main ()
{
	datelist_t dl { 0, nullptr };

	if ( !dl.scan() ) {
		// TASK constant MESSAGE_INVALID_INPUT
		cout << MESSAGE_INVALID_INPUT << endl;
		return 1;
	}

	dl.print();
	cout << endl;

	dl.sort();
	dl.print();

	dl.free();
	return 0;
}
