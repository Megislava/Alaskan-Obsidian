#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	ifstream in("testIn3.txt");
	ofstream out("testOut.txt");
	
	if (in.fail()) return 1;
	if (out.fail()) return 1;
	
	string line;

	
	vector<string> names;
	while(getline(in, line)) {
		//there can be problems with windows line endings (CR is left on the end, which causes unwanted behavior)
		//if (line[line.size()-1] == '\r') line = line.substr(0, line.size()-1);
		cout << "-----------------------------------------------------------" << endl;
		cout << line << endl;
		cout << "-----------------------------------------------------------" << endl;
		int it1 = 0, it2 = 0;
		while(1) {
			if (it2 == -1) break;
			it2 = line.find_first_of(',', it1);
			
			string parse = line.substr(it1, it2-it1);
			cout << "\"" << parse << "\"";
			names.push_back(parse);
			it1 = it2+2;
		} cout << endl;
		
		
	}
	
	
	for (auto &i : names) {
		cout << i << "/";
	} cout << endl;
	return 0;
}