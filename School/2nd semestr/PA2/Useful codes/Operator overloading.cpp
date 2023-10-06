<<<<<<< HEAD
struct SNode {
	
	vector<string> data;
	SNode & operator=(const SNode &src) {
		this->data.clear();
		for (auto &i : src.data) this->data.push_back(i);
			
		return *this;
	}
	
	SNode operator+(const SNode &src) {
		SNode newnode;
		for (auto &i : this->data) {
			for (auto &j : src.data) {
				newnode.data.push_back(i + j);
			}
		}
		
		return newnode;
	}
	
	friend ostream & operator<<(ostream & os, SNode & src);
	
};

ostream & operator<<(ostream & os, SNode & src) {
		for (auto &i : src.data) os << i << ", ";
		os << endl;
		os << "---------" << endl;
		return os;
	}

int main(int argc, char** argv) {
	int size = 5;
	string base[] = {"a", "b", "c", "d", "e", "f"};
	SNode* array = new SNode[size];
	
	for (int i = 0; i < size; i++) {
		array[i].data.push_back(base[i]);
		array[i].data.push_back(base[i+1]);
		cout << array[i];
	}
	
	array[0] = array[1];
	array[0] = array[1] + array[2];
	cout << array[0];
	
	delete[] array;
	
	return 0;
=======
struct SNode {
	
	vector<string> data;
	SNode & operator=(const SNode &src) {
		this->data.clear();
		for (auto &i : src.data) this->data.push_back(i);
			
		return *this;
	}
	
	SNode operator+(const SNode &src) {
		SNode newnode;
		for (auto &i : this->data) {
			for (auto &j : src.data) {
				newnode.data.push_back(i + j);
			}
		}
		
		return newnode;
	}
	
	friend ostream & operator<<(ostream & os, SNode & src);
	
};

ostream & operator<<(ostream & os, SNode & src) {
		for (auto &i : src.data) os << i << ", ";
		os << endl;
		os << "---------" << endl;
		return os;
	}

int main(int argc, char** argv) {
	int size = 5;
	string base[] = {"a", "b", "c", "d", "e", "f"};
	SNode* array = new SNode[size];
	
	for (int i = 0; i < size; i++) {
		array[i].data.push_back(base[i]);
		array[i].data.push_back(base[i+1]);
		cout << array[i];
	}
	
	array[0] = array[1];
	array[0] = array[1] + array[2];
	cout << array[0];
	
	delete[] array;
	
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}