#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string str = "1 2 3";
	istringstream iss(str);
	int i, j, k;
	iss >> i >> j >> k;
	cout << i << " " << j << " " << k << endl;
	
	ostringstream oss;
	oss << "oss test";
	cout << oss.str() << endl;
	
	stringstream ss("ss test");
	int a = 5, b = 7;
	string outStr;
	ss >> outStr;
	ss << a << b;
	cout << outStr << endl;
	cout << ss.str() << endl;
	return 0;
}