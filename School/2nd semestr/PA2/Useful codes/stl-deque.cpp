<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

class CTest {
public:
	CTest(string str) : m_str(str) {}

	friend ostream & operator<<(ostream & os, CTest & src) {
		return os << src.m_str;
	}
	
	bool operator<(const CTest & second) const {
		if (m_str < second.m_str) return true;
		else return false;
	}
	
	friend bool reversed(const CTest & first, const CTest & second);
	
	bool operator==(string test) const {
		if (m_str == test) return true;
		else return false;
	}
	
 private:
	string m_str;

};

bool reversed(const CTest & first, const CTest & second) {
		if (first.m_str < second.m_str) return false;
		else return true;
	}


int main() {
#define LINE cout << "-------------" << endl;
	deque<CTest> deque1;
	
	//adding elements
	
	deque1.push_back(CTest("ahoj, jak se mas ty?"));
	deque1.push_back(CTest("ja se mam dobre"));
	deque1.push_front(CTest("mam se fajn"));
	//adding element to third position (other elements are moved)
	deque1.insert(deque1.begin(), CTest("jabadabaduuu"));
	
	cout << "3. prvek: " << deque1[2] << endl; LINE
	//printing
	for (auto &i : deque1) cout << i << endl; LINE
	
	
	//sorting using algorithm function sort - need to have operator<
	sort(deque1.begin(), deque1.end());
	for (auto &i : deque1) cout << i << endl; LINE
	//sorting with using own function
	sort(deque1.begin(), deque1.end(), reversed);
	for (auto &i : deque1) cout << i << endl; LINE
	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = find(deque1.begin(), deque1.end(), testString);
	if (it != deque1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = find(deque1.begin(), deque1.end(), testString);
	if (it != deque1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	deque1.erase(it);
	for (auto &i : deque1) cout << i << endl; LINE
	
	return 0;
=======
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

class CTest {
public:
	CTest(string str) : m_str(str) {}

	friend ostream & operator<<(ostream & os, CTest & src) {
		return os << src.m_str;
	}
	
	bool operator<(const CTest & second) const {
		if (m_str < second.m_str) return true;
		else return false;
	}
	
	friend bool reversed(const CTest & first, const CTest & second);
	
	bool operator==(string test) const {
		if (m_str == test) return true;
		else return false;
	}
	
 private:
	string m_str;

};

bool reversed(const CTest & first, const CTest & second) {
		if (first.m_str < second.m_str) return false;
		else return true;
	}


int main() {
#define LINE cout << "-------------" << endl;
	deque<CTest> deque1;
	
	//adding elements
	
	deque1.push_back(CTest("ahoj, jak se mas ty?"));
	deque1.push_back(CTest("ja se mam dobre"));
	deque1.push_front(CTest("mam se fajn"));
	//adding element to third position (other elements are moved)
	deque1.insert(deque1.begin(), CTest("jabadabaduuu"));
	
	cout << "3. prvek: " << deque1[2] << endl; LINE
	//printing
	for (auto &i : deque1) cout << i << endl; LINE
	
	
	//sorting using algorithm function sort - need to have operator<
	sort(deque1.begin(), deque1.end());
	for (auto &i : deque1) cout << i << endl; LINE
	//sorting with using own function
	sort(deque1.begin(), deque1.end(), reversed);
	for (auto &i : deque1) cout << i << endl; LINE
	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = find(deque1.begin(), deque1.end(), testString);
	if (it != deque1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = find(deque1.begin(), deque1.end(), testString);
	if (it != deque1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	deque1.erase(it);
	for (auto &i : deque1) cout << i << endl; LINE
	
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}