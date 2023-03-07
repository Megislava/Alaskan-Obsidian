#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CRec {
public:
	CRec(string name) : m_name(name) {}
	virtual string Type() const = 0;
	virtual CRec* Clone() const = 0;
	virtual void Print() const = 0;
	string m_name;

	friend ostream & operator<<(ostream & os, CRec & src) {
		src.Print();
		return os;
	}
};

class CRecA : public CRec {
public:
	CRecA(string name) : CRec(name), m_type("A") {}
	string Type() const {return m_type;}
	void Print() const {
		cout << m_name << " " << m_type << endl;
	}
	CRec* Clone() const {
		CRecA* newRecord = new CRecA(m_name);
		CRec* tmp = newRecord;
		return tmp;
	}

	string m_type;
};

class CRecB : public CRec {
public:
	CRecB(string name, string justB) : CRec(name), m_type("B"), m_onlyB(justB) {}
	string Type() const {
		return m_type;
	}
	void Print() const {
		cout << m_name << " " << m_type << " " << m_onlyB << endl;
	}
	CRec* Clone() const {
		CRecB* newRecord = new CRecB(m_name, m_onlyB);
		CRec* tmp = newRecord;
		return tmp;
	}

	string m_type;
	string m_onlyB;
};

class CZone {
public:
	bool Add(const CRec& record) {
		m_records.push_back(record.Clone());		
		return true;
	}
	
	
	friend ostream & operator<<(ostream & os, CZone & src) {
		for (auto &i : src.m_records) {
//			os << i->Type() << endl;
//			i->Print();
			os << *i;
		}
		return os;
	}
private:
	vector<CRec*> m_records;
};

int main () {
	CZone z1;
	z1.Add(CRecA("phase"));
	z1.Add(CRecA("volej"));
	z1.Add(CRecB("number", "onlyOne"));
	z1.Add(CRecB("yahoo", "onlyTwo"));
	cout << z1;
	
	
	
	
	return 0;
}

