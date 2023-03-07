#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string> //cannot use
using namespace std;

class CAccount {
public:
	
	CAccount() {}
	CAccount(const char* &accID, int initBalance) 
	: m_number(accID), m_initBalance(initBalance), m_balance(initBalance) {
//		cout << "konstruktor: " << accID << endl;
	}
	
	const char* m_number;
	int m_balance;
	int m_initBalance;
};

class CAccountSortedArray {
public:
	#define INIT_SIZE 2
	#define EXPAND_FACTOR 1.5
	CAccountSortedArray() : m_cnt(0), m_size(INIT_SIZE), m_data(new CAccount*[INIT_SIZE]) {}
	
	~CAccountSortedArray() {
		for (int i = 0; i < m_cnt; i++) delete m_data[i];
		delete[] m_data;
	}
	
	int length() {
		return m_cnt;
	}
	bool addAccount(const char* accID, const int initBalance) {
		cout << "accID before " << accID << endl;
		if (m_cnt >= m_size) expandArray();
		if (m_cnt == 0) {
//			cout << "vkladam: " << accID << endl;
			m_data[m_cnt] = new CAccount(accID, initBalance);
//			cout << "vlozeno: " << m_data[m_cnt]->m_number << endl;
//			cout << "wtf? " << accID << endl; 
			m_cnt++;
			cout << "accID after " << accID << endl;
			return true;
		}
//		cout << "tested: " << accID << endl;
//		cout << *this;
		int m;
		if (findAccount(accID, m)) return false;
		
		for (int i = m_cnt; i > m; i--) m_data[i] = m_data[i-1];
		
		m_data[m] = new CAccount(accID, initBalance);
		m_cnt++;
		
		cout << "accID after " << accID << endl;
		return true;
	}
	
	friend ostream & operator<<(ostream & os, const CAccountSortedArray & src) {
		for (int i = 0; i < src.m_cnt; i++)
			os << "account ID: " << src.m_data[i]->m_number << ", balance: " << src.m_data[i]->m_balance 
				 << ", init balance: " << src.m_data[i]->m_initBalance << endl;
		
		return os;
	}
	
private:
	bool findAccount(const char* &account, int &m) const {
		
		
		int l, r;
		l = 0;
		r = m_cnt - 1;

		while (l <= r) {
			m = (l + r) / 2;
			
			if (strcoll(account, m_data[m]->m_number) < 0) r = m - 1;
			else if (strcoll(account, m_data[m]->m_number) > 0) l = m + 1;
			else {
//				cout << "comparing: " << account << " and " << m_data[m]->m_number << endl;
				return true; //account found - in "m" is position of this element
			}
		}

		m = l; //number not found - save position where elements should be inserted to "m"
		return false;
	}
	
	void expandArray() {
		m_size *= EXPAND_FACTOR;
		CAccount** newArray = new CAccount*[m_size];
		
		for (int i = 0; i < m_cnt; i++) newArray[i] = m_data[i];
		
		delete[] m_data;
		m_data = newArray;
	}
	
	int compareConstChar(const char* & a, const char* & b) const{
	const char* selected;
	if (strlen(a) <= strlen(b)) selected = a;
	else selected = b;
	
	for (unsigned int i = 0; i < strlen(selected); i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
		//else is equeal, new cycle
	}
	
	if (strlen(a) == strlen(b)) {
		return 0;
		cout << "comparing: " << a << " is equal to " << b << endl;
	}
	else if (strlen(a) < strlen(b)) return -1;
	else return 1;
	
	//returned value: 
	//	-1 - left is less than right
	//   0 - they are equal
	//	 1 - left is bigger than right
}

	int m_cnt;
	int m_size;
	CAccount** m_data;
};

string randomStrGen(int minLength, int maxLength) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
	int length = rand()%maxLength;
	if (length < minLength) length = minLength;
    result.resize(length);

    for (int i = 0; i < length; i++) result[i] = charset[rand() % charset.length()];

    return result;
}

int main() {
	srand(time(NULL));
	CAccountSortedArray array;
	
	#define CNT 20
//	for (int i = 0; i < CNT; i++) cout << randomStrGen(5, 20).c_str() << " " << rand()%10000 << endl;
//	cout << "-----------------------" << endl;
	
	
		//not working with random generator. Dont know why
		array.addAccount("asdf564654687", 1234654);
		array.addAccount("gdfs5g4654687", 6875);
		array.addAccount("ert5644654687", 87978);
		array.addAccount("1zcx564654687", 32564);
		array.addAccount("awe6544654687", 987987);
		array.addAccount("3456as4654687", 5465);
		array.addAccount("65sdf64654687", 4879);
		array.addAccount("98sdf64654687", 321364);
		array.addAccount("asdf464654687", 9877546);
		array.addAccount("khj+984654687", 5465798);
		array.addAccount("khg6544654687", 64679);
		array.addAccount("kgh6544654687", 5456987);
		array.addAccount("jfg6544654687", 45654);
		array.addAccount("tyi6544654687", 8974);
		array.addAccount("987jhnb654687", 564987);
		array.addAccount("98ty7i4654687", 56465);
		array.addAccount("1234564654687", 12354);
		array.addAccount("gh+k984654687", 89798);
		array.addAccount("1234564654687", 98754);
		array.addAccount("k984sdf654687", 89798);
		array.addAccount("asdf564654687", 1234654);
		array.addAccount("gdfs5g4654687", 6875);
		array.addAccount("ert5644654687", 87978);
		array.addAccount("1zcx564654687", 32564);
		array.addAccount("awe6544654687", 987987);
		array.addAccount("3456as4654687", 5465);
		array.addAccount("65sdf64654687", 4879);
		array.addAccount("98sdf64654687", 321364);
		array.addAccount("asdf464654687", 9877546);
		array.addAccount("khj+984654687", 5465798);
		array.addAccount("khg6544654687", 64679);
		array.addAccount("kgh6544654687", 5456987);
		array.addAccount("jfg6544654687", 45654);
		array.addAccount("tyi6544654687", 8974);
		array.addAccount("987jhnb654687", 564987);
		array.addAccount("98ty7i4654687", 56465);
		array.addAccount("1234564654687", 12354);
		array.addAccount("gh+k984654687", 89798);
		array.addAccount("1234564654687", 98754);
		array.addAccount("k984sdf654687", 89798);
		array.addAccount("WER4564654687", 98754);
		array.addAccount("GHJFDdf654687", 89798);
		array.addAccount("QWERGF4654687", 1234654);
		array.addAccount("XCVBHg4654687", 6875);
		array.addAccount("WQERTDF654687", 87978);
		array.addAccount("POFGH64654687", 32564);
		array.addAccount("OYOYU44654687", 987987);
		array.addAccount("KJHGas4654687", 5465);
		array.addAccount("KGHGH64654687", 4879);
		array.addAccount("RUYRf64654687", 321364);
		array.addAccount("SDFGSD4654687", 9877546);
		array.addAccount("XCVBXVC654687", 5465798);
		array.addAccount("ASDFAS4654687", 64679);
		array.addAccount("QWERQEW654687", 5456987);
		array.addAccount("NCV6544654687", 45654);
		array.addAccount(",VNB544654687", 8974);
		array.addAccount(",POIhnb654687", 564987);
		array.addAccount(".UGHFi4654687", 56465);
		array.addAccount(".PERT64654687", 12354);
		array.addAccount("[FGHGF4654687", 89798);
		array.addAccount("]HFGG64654687", 98754);
		array.addAccount("/HFGHDF654687", 89798);
		
		
		

		cout << "------" << array.length() << endl;
		cout << array;
		cout << "------" << endl;
	
	
	

	return 0;
}

