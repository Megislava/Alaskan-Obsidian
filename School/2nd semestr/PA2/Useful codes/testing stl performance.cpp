#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string randomStrGen(int minLength, int maxLength) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
	int length = rand()%maxLength;
	if (length < minLength) length = minLength;
    result.resize(length);

    
    for (int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];

    return result;
}

class CMail {
public:
	CMail(string from, string to, string date, string letter, string attach) 
		: m_from(from), m_to(to), m_date(date), m_letter(letter), m_attach(attach) {
	}
		
	bool operator<(const CMail & src) const {
		if (m_date < src.m_date) return true;
		else return false;
	}
		
	friend ostream & operator<<(ostream & os, CMail & src) {
		os << "Email:\n"
		   << "from: " << src.m_from << "\n"
		   << "to: " << src.m_to << "\n"
		   << "date: " << src.m_date << "\n"
		   << "letter: " << src.m_letter << "\n"
		   << "attach: " << src.m_attach << "\n"
		   << "------------------" << endl;
		return os;
	}
	
	string getDate() {return m_date;}
private:
	string m_from;
	string m_to;
	string m_date;
	string m_letter;
	string m_attach;
};


int main() {
	#define CNT 3000
	#define RAND randomStrGen
//	srand(time(NULL)); //init seed (different between runs)
	
	list<CMail> emails;
	multimap<string, CMail*> emailmap;
	set<CMail*> emailset;
//	vector<CMail*> emails;
	
	for (int i = 0; i < CNT; i++) {
		CMail* newMail = new CMail(RAND(5, 20), RAND(5, 20), RAND(10, 10), RAND(1000, 5000), RAND(10000, 50000));
//		emailmap.insert(make_pair(newMail->getDate(), newMail));
		emailset.insert(CMail*);
//		sort(emails.begin(), emails.end());
//		emails.sort();
		}
	
	
	
	
	
//	for (auto & i : emails) {
//		cout << i;
//	}
	return 0;
}