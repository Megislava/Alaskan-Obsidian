<<<<<<< HEAD
#include <iostream>
using namespace std;


bool binarySearch(int searchedVal, int & position, int * array, int size) {
	int l, r, m;
	l = 0;
	r = size - 1;
	
	while (l <= r) {
		m = (l + r) / 2;
		if (searchedVal < array[m]) r = m - 1;
		else if (searchedVal > array[m]) l = m + 1;
		else return true;
	}
	
	position = l;
	return false;
}


int main() {
#define LINE cout << "-------------" << endl;
#define SIZE 10
	int array[SIZE];
	
	for (int i = 0; i < 9; i++) array[i] = i*2;
	
	for (int i = 0; i < 9; i++) cout << array[i] << endl; LINE
	
	bool found;
	int position;
	found = binarySearch(4, position, array, SIZE);
	cout << found << endl;
	found = binarySearch(3, position, array, SIZE);
	cout << found << " number should be inserted at position: " << position << endl;
	found = binarySearch(22, position, array, SIZE);
	cout << found << " number should be inserted at position: " << position << endl;
	return 0;
=======
#include <iostream>
using namespace std;


bool binarySearch(int searchedVal, int & position, int * array, int size) {
	int l, r, m;
	l = 0;
	r = size - 1;
	
	while (l <= r) {
		m = (l + r) / 2;
		if (searchedVal < array[m]) r = m - 1;
		else if (searchedVal > array[m]) l = m + 1;
		else return true;
	}
	
	position = l;
	return false;
}


int main() {
#define LINE cout << "-------------" << endl;
#define SIZE 10
	int array[SIZE];
	
	for (int i = 0; i < 9; i++) array[i] = i*2;
	
	for (int i = 0; i < 9; i++) cout << array[i] << endl; LINE
	
	bool found;
	int position;
	found = binarySearch(4, position, array, SIZE);
	cout << found << endl;
	found = binarySearch(3, position, array, SIZE);
	cout << found << " number should be inserted at position: " << position << endl;
	found = binarySearch(22, position, array, SIZE);
	cout << found << " number should be inserted at position: " << position << endl;
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}