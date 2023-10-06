<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;

int main() {
#define LINE cout << "-------------" << endl;

	vector<int> vec1;
	
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	
	//c++11 for each
	for (const auto & i : vec1) cout << i << endl; LINE
	//c++11 using auto
	for (auto i = vec1.cbegin(); i != vec1.cend(); ++i) cout << *i << endl; LINE
	//old way with manually written iterator
	for (vector<int>::const_iterator i = vec1.begin(); i != vec1.end(); ++i) cout << *i << endl; LINE
	
	return 0;
=======
#include <iostream>
#include <vector>
using namespace std;

int main() {
#define LINE cout << "-------------" << endl;

	vector<int> vec1;
	
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	
	//c++11 for each
	for (const auto & i : vec1) cout << i << endl; LINE
	//c++11 using auto
	for (auto i = vec1.cbegin(); i != vec1.cend(); ++i) cout << *i << endl; LINE
	//old way with manually written iterator
	for (vector<int>::const_iterator i = vec1.begin(); i != vec1.end(); ++i) cout << *i << endl; LINE
	
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}