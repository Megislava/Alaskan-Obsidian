<<<<<<< HEAD
#include <cstdio>
#include <string>
using namespace std;

class CBank {
public:
	class CAccount {
	public:
		CAccount(string accNum) : m_balance(185) {}
		int Balance() {return m_balance;}
	private:
		string m_accNum;
		int m_balance;
	};
	
	CAccount Account(const string accNum) {
		return CAccount(accNum);
	}
};

int main() {
	int balance;
	CBank a;
	balance = a . Account ( "123456" ).Balance();
	cout << balance << endl;
	return 0;
=======
#include <cstdio>
#include <string>
using namespace std;

class CBank {
public:
	class CAccount {
	public:
		CAccount(string accNum) : m_balance(185) {}
		int Balance() {return m_balance;}
	private:
		string m_accNum;
		int m_balance;
	};
	
	CAccount Account(const string accNum) {
		return CAccount(accNum);
	}
};

int main() {
	int balance;
	CBank a;
	balance = a . Account ( "123456" ).Balance();
	cout << balance << endl;
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}