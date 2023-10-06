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
	vector<CTest> v1;
	
	//adding elements
	v1.push_back(CTest("mam se fajn"));
	v1.push_back(CTest("ahoj, jak se mas ty?"));
	v1.push_back(CTest("ja se mam dobre"));
	//adding element to third position (other elements are moved)
	v1.insert(v1.begin()+2, CTest("jabadabaduuu"));
	
	//printing
	for (auto &i : v1) cout << i << endl; LINE
	
	cout << "3. PRVEK: " << v1[2] << endl; LINE
	
	//sorting using algorithm function sort - need to have operator<
	sort(v1.begin(), v1.end());
	for (auto &i : v1) cout << i << endl; LINE
	//sorting with using own function
	sort(v1.begin(), v1.end(), reversed);
	for (auto &i : v1) cout << i << endl; LINE
	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = find(v1.begin(), v1.end(), testString);
	if (it != v1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = find(v1.begin(), v1.end(), testString);
	if (it != v1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	v1.erase(it);
	for (auto &i : v1) cout << i << endl; LINE
	
	
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
	vector<CTest> v1;
	
	//adding elements
	v1.push_back(CTest("mam se fajn"));
	v1.push_back(CTest("ahoj, jak se mas ty?"));
	v1.push_back(CTest("ja se mam dobre"));
	//adding element to third position (other elements are moved)
	v1.insert(v1.begin()+2, CTest("jabadabaduuu"));
	
	//printing
	for (auto &i : v1) cout << i << endl; LINE
	
	cout << "3. PRVEK: " << v1[2] << endl; LINE
	
	//sorting using algorithm function sort - need to have operator<
	sort(v1.begin(), v1.end());
	for (auto &i : v1) cout << i << endl; LINE
	//sorting with using own function
	sort(v1.begin(), v1.end(), reversed);
	for (auto &i : v1) cout << i << endl; LINE
	
	//searching for string using algorithm function find
	string testString = "mam se blbe";
	auto it = find(v1.begin(), v1.end(), testString);
	if (it != v1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	
	testString = "mam se fajn";
	it = find(v1.begin(), v1.end(), testString);
	if (it != v1.end()) cout << "testString: \"" << testString << "\" found" << endl;
	else cout << "testString: \"" << testString << "\" not found" << endl;
	LINE
			
	//erasing elements
	v1.erase(it);
	for (auto &i : v1) cout << i << endl; LINE
	
	
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}