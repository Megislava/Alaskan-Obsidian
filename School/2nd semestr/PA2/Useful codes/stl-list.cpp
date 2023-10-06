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
	list<CTest> l1;
	
	//adding elements
	
	l1.push_back(CTest("ahoj, jak se mas ty?"));
	l1.push_back(CTest("ja se mam dobre"));
	l1.push_front(CTest("mam se fajn"));
	//adding element to third position (other elements are moved)
	l1.insert(l1.begin(), CTest("jabadabaduuu"));
	
	//printing
	for (auto &i : l1) cout << i << endl; LINE
	
	
	//sorting using algorithm function sort - need to have operator<
	l1.sort();
	for (auto &i : l1) cout << i << endl; LINE
	//sorting with using own function
	l1.sort(reversed);
	for (auto &i : l1) cout << i << endl; LINE
	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = find(l1.begin(), l1.end(), testString);
	if (it != l1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = find(l1.begin(), l1.end(), testString);
	if (it != l1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	l1.erase(it);
	for (auto &i : l1) cout << i << endl; LINE
	
	return 0;
}