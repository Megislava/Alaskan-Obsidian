#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;
const string MESSAGE_INVALID_INPUT = "Invalid input";

struct date_t
{
	int year;
	int month;
	int day;
};

// TASK function date_scan
bool date_scan(date_t &date) {
    return (bool) (!(cin >> date.year >> "-" >> date.month >> "-" >> date.day));
}

// DONE? TASK function date_print
void date_print(date_t &date) {
    cout << date.year << endl;
    cout << date.month << endl;
    cout << date.day << endl;
}

bool date_compare ( const date_t & d1, const date_t & d2 )
{
	// DONE? TASK body of function date_compare
    return (d1.year > d2.year) - (d2.year > d1.year) || (d1.month > d2.month) - (d2.month > d1.month) || (d1.day > d2.day) - (d2.day > d1.day);
}

struct datelist_t
{
	size_t n;
	date_t * data;
};

void datelist_free ( datelist_t & dl )
{
	// DONE? TASK Deallocate memory (dl.data)
	delete [] dl.data;
    dl.n = 0;
	dl.data = nullptr;
}

bool datelist_scan ( datelist_t & dl )
{
	if ( !( cin >> dl.n ) || dl.n <= 0 )
		return false;

	// DONE? TASK Allocate memory (dl.data)
    dl.data = new date_t [dl.n];
	for ( size_t i = 0; i < dl.n; ++i ) {
		if ( !date_scan( dl.data[ i ] ) ) {
			datelist_free( dl );
			return false;
		}
	}

	return true;
}

void datelist_print ( const datelist_t & dl )
{
	for ( size_t i = 0; i < dl.n; ++i ) {
		date_print( dl.data[ i ] );
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

	if ( !datelist_scan( dl ) ) {
		// TASK constant MESSAGE_INVALID_INPUT
		cout << MESSAGE_INVALID_INPUT << endl;
		return 1;
	}

	datelist_print( dl );

	datelist_sort( dl );
	datelist_print( dl );

	datelist_free( dl );
	return 0;
}
