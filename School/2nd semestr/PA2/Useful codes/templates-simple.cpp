#include <iostream>
#include <string>
using namespace std;

class CTest {
public:
	CTest(string name, int value) : m_name(name), m_value(value) {}

	friend ostream & operator<<(ostream & os, const CTest & src) {
		return os << src.m_name << " " << src.m_value;
	}
private:
	string m_name;
	int m_value;
};

//template<class T> - old way to write template typename, works same (in most cases)
template<typename T1, typename T2>
void printIt(T1 x, T2 y) {
	cout << x << " " << y << endl;
}


int main() {
	int val = 8;
	char charact = 'x';
	string str = "test";
	CTest cls("Miro Vana", 120);
	
	printIt(val, charact);
	printIt(charact, str);
	printIt(str, cls);
	printIt(cls, cls);
	
	return 0;
}