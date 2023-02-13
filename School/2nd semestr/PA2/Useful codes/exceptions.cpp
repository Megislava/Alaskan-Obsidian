#include <iostream>
using namespace std;



class CIntException {
public:
	CIntException(int x) : value(x){
	}

	friend ostream & operator<<(ostream & os, CIntException & src) {
		return os << "Nefunguje cislo: " << src.value << endl;
	}
private:
	int value;
};

void makeError() {
	if (1 != 0) throw CIntException(1);
	else return;
}

int main() {

	try {
		makeError();
	} catch (CIntException e) {
		cout << e << endl;
	}
	
	return 0;
}
