<<<<<<< HEAD
#include <iostream>
using namespace std;

struct CInt {
	CInt(int x) : m_refCnt(1), m_data(new int(x)) {}
	~CInt() {delete m_data;}
	void setData(int x) {*m_data = x;}
	int m_refCnt;
	int* m_data;
};

class CTest {
public:
	CTest(int x) : m_data(new CInt(x)) {}
	CTest(CTest & src) {
		m_data = src.m_data;
		m_data->m_refCnt++;
	}
	
	~CTest() {
		m_data->m_refCnt--;
		if (m_data->m_refCnt == 0) delete m_data;
	}
	
	void setData(int x) {
		if (m_data->m_refCnt == 1) m_data->setData(x);
		else {
			m_data->m_refCnt--;
			m_data = new CInt(x);
		}
		
	}
	
	friend ostream & operator<<(ostream & os, CTest & src) {
		return os << *src.m_data->m_data << endl;
	}
	
	CInt* m_data;
};

int main() {
	CTest *a = new CTest(7);
	cout << "a " <<  *a;
	CTest *b = new CTest(*a);
	CTest *c = new CTest(*b);
	b->setData(6);
	cout << " a " << *a << *b << *c;
	delete a;
	cout << " b " << *b << *c;
	delete b;
	delete c;
	return 0;
}
=======
#include <iostream>
using namespace std;

struct CInt {
	CInt(int x) : m_refCnt(1), m_data(new int(x)) {}
	~CInt() {delete m_data;}
	void setData(int x) {*m_data = x;}
	int m_refCnt;
	int* m_data;
};

class CTest {
public:
	CTest(int x) : m_data(new CInt(x)) {}
	CTest(CTest & src) {
		m_data = src.m_data;
		m_data->m_refCnt++;
	}
	
	~CTest() {
		m_data->m_refCnt--;
		if (m_data->m_refCnt == 0) delete m_data;
	}
	
	void setData(int x) {
		if (m_data->m_refCnt == 1) m_data->setData(x);
		else {
			m_data->m_refCnt--;
			m_data = new CInt(x);
		}
		
	}
	
	friend ostream & operator<<(ostream & os, CTest & src) {
		return os << *src.m_data->m_data << endl;
	}
	
	CInt* m_data;
};

int main() {
	CTest *a = new CTest(7);
	cout << "a " <<  *a;
	CTest *b = new CTest(*a);
	CTest *c = new CTest(*b);
	b->setData(6);
	cout << " a " << *a << *b << *c;
	delete a;
	cout << " b " << *b << *c;
	delete b;
	delete c;
	return 0;
}
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
