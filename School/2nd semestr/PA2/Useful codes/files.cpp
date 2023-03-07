#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string line;
	ifstream in("testIn.txt");
	ofstream out("testOut.txt");
	
	if (in.fail()) return 1;
	if (out.fail()) return 1;
	
	while(getline(in, line)) {
		cout << line << endl;
		out << line << endl;
	}
	
	out << "tohle jde taky na vystup" << endl;
	
	in.close();
	out.close();
	
	return 0;
}