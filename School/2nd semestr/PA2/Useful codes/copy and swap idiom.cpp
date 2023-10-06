#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <utility>
using namespace std;

class CTest {
public:
	CTest(const string & name, const int age, const bool student) : m_name(new string(name)), m_age(new int(age)), m_student(new bool(student)) {}
	~CTest() {
		delete m_name;
		delete m_age;
		delete m_student;

	}
	
	CTest(const CTest & src) {
		m_name = new string(*src.m_name);
		m_age = new int(*src.m_age);
		m_student = new bool(*src.m_student);
		
	}
	
	CTest & operator=(CTest src) {
		/*
		 * tricky one:
		 * 1) Don't pass object by const reference but by value. 
		 *    It need to be copied either way and it could be optimalised that way.
		 * 2) Call swap function, which will swap content in all variables
		 * 3) Return pointer to this object (left operand).
		 *    Because we used swap it now contents the right data and at the end of this function
		 *    the other object (with old data) is deleted.
		 * 4) So we called copy constructor and destructor and we don't need to write the code twice.
		 */
		
		mySwap(src);
		return *this;
		
	}
	
	friend ostream & operator<<(ostream & os, const CTest & src) {
		os << setw(20) << *src.m_name << " " << setw(5) << *src.m_age << " " << setw(10) << "student: ";
		*src.m_student ? os << "yes" : os << "no";
		return os << endl;
		
	}
private:
	
	void mySwap(CTest & src) {
		swap(*m_name, *src.m_name);
		swap(*m_age, *src.m_age);
		swap(*m_student, *src.m_student);
	}
	
	string* m_name;
	int* m_age;
	bool* m_student;
};


int main() {
#define LINE cout << "-----------------" << endl;
	CTest a("Pepa vocasek", 23, true);
	CTest b("Honza manasek", 34, false);
	CTest c("Vagner Verycvut", 39, false);
	cout << a << b << c; LINE
	
	CTest d(a);
	cout << d; LINE
	d = b;
	cout << d; LINE
	
	
	return 0;
	
}