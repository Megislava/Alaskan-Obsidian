<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


bool binarySearch(int searchedVal, int & position, deque<int> & array, int size) {
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
	deque<int> deque1;
	
	bool found;
	int position;
	
	for (int i = 0; i < 9; i++) deque1.push_back(i*2);
	
	for (int i = 0; i < 9; i++) cout << deque1[i] << endl; LINE
	
	
	found = binarySearch(4, position, deque1, deque1.size());
	cout << found << endl;
	found = binarySearch(3, position, deque1, deque1.size());
	auto it = deque1.begin() + position;
	cout << found << " number should be inserted at position: " << position << endl;
	deque1.insert(it, 3);
	for (auto &i : deque1) cout << i << endl; LINE
	found = binarySearch(22, position, deque1, deque1.size());
	cout << found << " number should be inserted at position: " << position << endl;
	it = deque1.begin() + position;
	deque1.insert(it, 22);
	for (auto &i : deque1) cout << i << endl; LINE
	return 0;
=======
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


bool binarySearch(int searchedVal, int & position, deque<int> & array, int size) {
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
	deque<int> deque1;
	
	bool found;
	int position;
	
	for (int i = 0; i < 9; i++) deque1.push_back(i*2);
	
	for (int i = 0; i < 9; i++) cout << deque1[i] << endl; LINE
	
	
	found = binarySearch(4, position, deque1, deque1.size());
	cout << found << endl;
	found = binarySearch(3, position, deque1, deque1.size());
	auto it = deque1.begin() + position;
	cout << found << " number should be inserted at position: " << position << endl;
	deque1.insert(it, 3);
	for (auto &i : deque1) cout << i << endl; LINE
	found = binarySearch(22, position, deque1, deque1.size());
	cout << found << " number should be inserted at position: " << position << endl;
	it = deque1.begin() + position;
	deque1.insert(it, 22);
	for (auto &i : deque1) cout << i << endl; LINE
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}