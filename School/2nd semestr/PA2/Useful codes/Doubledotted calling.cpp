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
}