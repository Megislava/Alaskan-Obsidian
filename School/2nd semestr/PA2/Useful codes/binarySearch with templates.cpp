<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class CTest {
public:
	CTest(string name, int value) : m_name(name), m_value(value) {}

	bool operator<(const CTest & src) const {
		return m_name < src.m_name;
	}
	
	bool operator>(const CTest & src) const {
		return m_name > src.m_name;
	}
	
	friend ostream & operator<<(ostream & os, const CTest & src) {
		return os << src.m_name << " " << src.m_value;
	}
private:
	string m_name;
	int m_value;
};

template<typename T>
bool binarySearch(T searchedVal, int & position, deque<T> & array, int size) {
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

template<typename T>
bool binarySearchPointer(T* searchedVal, int & position, deque<T*> & array, int size) {
	int l, r, m;
	l = 0;
	r = size - 1;
	
	while (l <= r) {
		m = (l + r) / 2;
		if (*searchedVal < *array[m]) r = m - 1;
		else if (*searchedVal > *array[m]) l = m + 1;
		else return true;
	}
	
	position = l;
	return false;
}

template<typename T>
void printIt(T array) {
	cout << "============" << endl;
	for (auto & i : array) cout << i << endl;
	cout << "============" << endl;
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
	
	deque<string> deque2;
	deque2.push_back("hello");
	deque2.push_back("how are you");
	deque2.push_back("make money");
	deque2.push_back("yahoo");
	
	found = binarySearch((string)"yahoo", position, deque2, deque2.size());
	cout << found << endl;
	found = binarySearch((string)"yahooooo", position, deque2, deque2.size());
	cout << found << endl; LINE
	
	
	deque<CTest> deque3;
	deque3.push_back(CTest("hello", 5));
	deque3.push_back(CTest("how are you", 7));
	deque3.push_back(CTest("make money", 50));
	deque3.push_back(CTest("yahoo", 124));
	
	found = binarySearch(CTest("yahoo", 124), position, deque3, deque3.size());
	cout << found << endl;
	found = binarySearch(CTest("yahooooo", 55), position, deque3, deque3.size());
	cout << found << endl;
	
	
	deque<CTest*> deque4;
	deque4.push_back(new CTest("hello", 5));
	deque4.push_back(new CTest("how are you", 7));
	deque4.push_back(new CTest("make money", 50));
	deque4.push_back(new CTest("yahoo", 124));
	LINE LINE
	found = binarySearchPointer(new CTest("yahoo", 124), position, deque4, deque4.size());
	cout << found << endl;
	found = binarySearchPointer(new CTest("yahooooo", 55), position, deque4, deque4.size());
	cout << found << endl;
	
	
	
	printIt(deque1);
	printIt(deque2);
	printIt(deque3);
	
	return 0;
=======
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class CTest {
public:
	CTest(string name, int value) : m_name(name), m_value(value) {}

	bool operator<(const CTest & src) const {
		return m_name < src.m_name;
	}
	
	bool operator>(const CTest & src) const {
		return m_name > src.m_name;
	}
	
	friend ostream & operator<<(ostream & os, const CTest & src) {
		return os << src.m_name << " " << src.m_value;
	}
private:
	string m_name;
	int m_value;
};

template<typename T>
bool binarySearch(T searchedVal, int & position, deque<T> & array, int size) {
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

template<typename T>
bool binarySearchPointer(T* searchedVal, int & position, deque<T*> & array, int size) {
	int l, r, m;
	l = 0;
	r = size - 1;
	
	while (l <= r) {
		m = (l + r) / 2;
		if (*searchedVal < *array[m]) r = m - 1;
		else if (*searchedVal > *array[m]) l = m + 1;
		else return true;
	}
	
	position = l;
	return false;
}

template<typename T>
void printIt(T array) {
	cout << "============" << endl;
	for (auto & i : array) cout << i << endl;
	cout << "============" << endl;
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
	
	deque<string> deque2;
	deque2.push_back("hello");
	deque2.push_back("how are you");
	deque2.push_back("make money");
	deque2.push_back("yahoo");
	
	found = binarySearch((string)"yahoo", position, deque2, deque2.size());
	cout << found << endl;
	found = binarySearch((string)"yahooooo", position, deque2, deque2.size());
	cout << found << endl; LINE
	
	
	deque<CTest> deque3;
	deque3.push_back(CTest("hello", 5));
	deque3.push_back(CTest("how are you", 7));
	deque3.push_back(CTest("make money", 50));
	deque3.push_back(CTest("yahoo", 124));
	
	found = binarySearch(CTest("yahoo", 124), position, deque3, deque3.size());
	cout << found << endl;
	found = binarySearch(CTest("yahooooo", 55), position, deque3, deque3.size());
	cout << found << endl;
	
	
	deque<CTest*> deque4;
	deque4.push_back(new CTest("hello", 5));
	deque4.push_back(new CTest("how are you", 7));
	deque4.push_back(new CTest("make money", 50));
	deque4.push_back(new CTest("yahoo", 124));
	LINE LINE
	found = binarySearchPointer(new CTest("yahoo", 124), position, deque4, deque4.size());
	cout << found << endl;
	found = binarySearchPointer(new CTest("yahooooo", 55), position, deque4, deque4.size());
	cout << found << endl;
	
	
	
	printIt(deque1);
	printIt(deque2);
	printIt(deque3);
	
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}