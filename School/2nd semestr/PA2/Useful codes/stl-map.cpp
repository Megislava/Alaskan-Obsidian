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
	map<CTest, int> map1;
	
	//adding elements
	
	map1.insert(make_pair(CTest("ahoj, jak se mas ty?"), 7));
	map1.insert(make_pair(CTest("ja se mam dobre"), 19));
	map1[CTest("mam se fajn")] = 128;
	//adding element to begin
	map1.insert(map1.begin(), make_pair(CTest("jabadabaduuu"), 457));
	
	//printing 
	//no sorting - set must be sorted, need to have operator<
	for (auto & i : map1) cout << i.first << " " << i.second << endl; LINE
 	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = map1.find(testString);
	if (it != map1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = map1.find(testString);
	if (it != map1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	map1.erase(it);
	map1.erase(CTest("ja se mam dobre"));
	for (auto & i : map1) cout << i.first << " " << i.second << endl; LINE
	
	return 0;
}