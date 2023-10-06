<<<<<<< HEAD
#include <iostream>
using namespace std;

struct CNode {
	CNode(int key) : m_value(key), m_left(NULL), m_right(NULL) {}
	int m_value;
	CNode* m_left;
	CNode* m_right;
};

class CTree {
public:
	CTree() : m_root(NULL) {}
	~CTree() {
		if (!m_root) return;
		else Delete(m_root);
	}
	bool Search(int key) {
		if (!m_root) return false;
		else if (key == m_root->m_value) return true;
		else return Search(key, m_root);
	}
	bool Insert(int key) {
		if (!m_root) {
			m_root = new CNode(key);
			return true;
		} else return Insert(key, m_root);
	}
	
	void PrintPreOrder() {
		if (!m_root) return;
		else PrintPreOrder(m_root);
	}
	
	void PrintInOrder() {
		if (!m_root) return;
		else PrintInOrder(m_root);
	}
	
	void PrintPostOrder() {
		if (!m_root) return;
		else PrintPostOrder(m_root);
	}
	
private:
	CNode* m_root;
	bool Search(int key, CNode* node) {
		if (key == node->m_value) return true;
		else if (key < node->m_value) {
			if (!node->m_left) return false;
			else return Search(key, node->m_left);
		} else {
			if (!node->m_right) return false;
			else return Search(key, node->m_right);
		}
	}
	
	bool Insert(int key, CNode* node) {
		if (key < node->m_value) {
			if (node->m_left) return Insert(key, node->m_left);
			else {
				node->m_left = new CNode(key);
				return true;
			}
		} else if (key > node->m_value) {
			if (node->m_right) return Insert(key, node->m_right);
			else {
				node->m_right = new CNode(key);
				return true;
			}
		} else return false;
	}
	
	void Delete(CNode* node) {
		if (node->m_left) Delete(node->m_left);
		if (node->m_right) Delete(node->m_right);
		delete node;
	}
	
	void PrintPreOrder(CNode* node) {
		cout << node->m_value << endl;
		if (node->m_left) PrintPreOrder(node->m_left);
		if (node->m_right) PrintPreOrder(node->m_right);
	}
	
	void PrintInOrder(CNode* node) {
		if (node->m_left) PrintInOrder(node->m_left);
		cout << node->m_value << endl;
		if (node->m_right) PrintInOrder(node->m_right);
	}
	
	void PrintPostOrder(CNode* node) {
		if (node->m_left) PrintPostOrder(node->m_left);
		if (node->m_right) PrintPostOrder(node->m_right);
		cout << node->m_value << endl;
	}
};


int main() {
#define LINE cout << "-------------------" << endl;
	CTree a;
	
	a.Insert(5);
	a.Insert(2);
	a.Insert(4);
	a.Insert(1); LINE
	cout << a.Search(2) << endl;
	cout << a.Search(10) << endl; LINE
	a.PrintPreOrder(); LINE
	a.PrintInOrder(); LINE
	a.PrintPostOrder(); LINE
	
	return 0;
=======
#include <iostream>
using namespace std;

struct CNode {
	CNode(int key) : m_value(key), m_left(NULL), m_right(NULL) {}
	int m_value;
	CNode* m_left;
	CNode* m_right;
};

class CTree {
public:
	CTree() : m_root(NULL) {}
	~CTree() {
		if (!m_root) return;
		else Delete(m_root);
	}
	bool Search(int key) {
		if (!m_root) return false;
		else if (key == m_root->m_value) return true;
		else return Search(key, m_root);
	}
	bool Insert(int key) {
		if (!m_root) {
			m_root = new CNode(key);
			return true;
		} else return Insert(key, m_root);
	}
	
	void PrintPreOrder() {
		if (!m_root) return;
		else PrintPreOrder(m_root);
	}
	
	void PrintInOrder() {
		if (!m_root) return;
		else PrintInOrder(m_root);
	}
	
	void PrintPostOrder() {
		if (!m_root) return;
		else PrintPostOrder(m_root);
	}
	
private:
	CNode* m_root;
	bool Search(int key, CNode* node) {
		if (key == node->m_value) return true;
		else if (key < node->m_value) {
			if (!node->m_left) return false;
			else return Search(key, node->m_left);
		} else {
			if (!node->m_right) return false;
			else return Search(key, node->m_right);
		}
	}
	
	bool Insert(int key, CNode* node) {
		if (key < node->m_value) {
			if (node->m_left) return Insert(key, node->m_left);
			else {
				node->m_left = new CNode(key);
				return true;
			}
		} else if (key > node->m_value) {
			if (node->m_right) return Insert(key, node->m_right);
			else {
				node->m_right = new CNode(key);
				return true;
			}
		} else return false;
	}
	
	void Delete(CNode* node) {
		if (node->m_left) Delete(node->m_left);
		if (node->m_right) Delete(node->m_right);
		delete node;
	}
	
	void PrintPreOrder(CNode* node) {
		cout << node->m_value << endl;
		if (node->m_left) PrintPreOrder(node->m_left);
		if (node->m_right) PrintPreOrder(node->m_right);
	}
	
	void PrintInOrder(CNode* node) {
		if (node->m_left) PrintInOrder(node->m_left);
		cout << node->m_value << endl;
		if (node->m_right) PrintInOrder(node->m_right);
	}
	
	void PrintPostOrder(CNode* node) {
		if (node->m_left) PrintPostOrder(node->m_left);
		if (node->m_right) PrintPostOrder(node->m_right);
		cout << node->m_value << endl;
	}
};


int main() {
#define LINE cout << "-------------------" << endl;
	CTree a;
	
	a.Insert(5);
	a.Insert(2);
	a.Insert(4);
	a.Insert(1); LINE
	cout << a.Search(2) << endl;
	cout << a.Search(10) << endl; LINE
	a.PrintPreOrder(); LINE
	a.PrintInOrder(); LINE
	a.PrintPostOrder(); LINE
	
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}