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

	friend ostream & operator<<(ostream & os, const CTest & src) {
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
	set<CTest> set1;
	
	//adding elements
	
	set1.insert(CTest("ahoj, jak se mas ty?"));
	set1.insert(CTest("ja se mam dobre"));
	set1.insert(CTest("mam se fajn"));
	//adding element to begin
	set1.insert(set1.begin(), CTest("jabadabaduuu"));
	
	//printing
	//no sorting - set must be sorted, need to have operator<
	for (const auto & i : set1) cout << i << endl; LINE
	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = set1.find(testString);
	if (it != set1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = set1.find(testString);
	if (it != set1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	set1.erase(it);
	set1.erase(CTest("ja se mam dobre"));
	for (const auto & i : set1) cout << i << endl; LINE
	
	return 0;
}