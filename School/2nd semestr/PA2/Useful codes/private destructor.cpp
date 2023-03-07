#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class CTest {
public:
	CTest(int x) : m_X(new int(x)) {}
	void release() {delete this;}
	void print() {cout << *m_X << endl;}
	
private:
	~CTest() {delete m_X;}
	int* m_X;
};


int main() {
	CTest *a = new CTest(5);
	CTest *b = new CTest(7);
	a->print();
	b->print();
	a->release();
	b->release();
	return 0;
}
