<<<<<<< HEAD
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<pair<int, int> > myVector1;
	vector<pair<int, int> > myVector2;
	map<string, vector<pair<int, int> > > myMap;
	
	myVector1.push_back(make_pair(1, 2));
	myVector1.push_back(make_pair(3, 4));
	myVector2.push_back(make_pair(5, 6));
	myVector2.push_back(make_pair(7, 8));
	
	myMap.insert(make_pair("hole", myVector1));
	myMap.insert(make_pair("vole", myVector2));
	
	for (auto & i : myMap) {
		cout << i.first << " - ";
		for (auto & j : i.second) cout << j.first << " " << j.second << " | ";
		cout << endl;
	}
	
	
	return 0;
}
=======
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<pair<int, int> > myVector1;
	vector<pair<int, int> > myVector2;
	map<string, vector<pair<int, int> > > myMap;
	
	myVector1.push_back(make_pair(1, 2));
	myVector1.push_back(make_pair(3, 4));
	myVector2.push_back(make_pair(5, 6));
	myVector2.push_back(make_pair(7, 8));
	
	myMap.insert(make_pair("hole", myVector1));
	myMap.insert(make_pair("vole", myVector2));
	
	for (auto & i : myMap) {
		cout << i.first << " - ";
		for (auto & j : i.second) cout << j.first << " " << j.second << " | ";
		cout << endl;
	}
	
	
	return 0;
}
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
