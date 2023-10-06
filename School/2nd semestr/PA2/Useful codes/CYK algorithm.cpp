             struct SCell { //this represents one cell in exact row and column
	vector<string> data; //this is vector of all elements in one cell made in CYK while iterating
	
	SCell & operator=(const SCell &src) { 
		// used for iterating in CYK. Pushes new element created in adding 
		// two CYK cells to the end of already existing (so iterating can go on)
		this->data.insert(this->data.end(), src.data.begin(), src.data.end());

	return *this;
	}
	
	SCell operator+(const SCell &src) { 
		//adding two cells together. It iterates for all combinations between these two and
		//pushing it in newly created node
		SCell newnode;
		for (auto &i : this->data) {
			for (auto &j : src.data) {
				string tmp1 = "(" + i;
				string tmp2 = j + ")";
				newnode.data.push_back(tmp1 + tmp2);
			}
		}
		
		return newnode;
	}
	
	friend ostream & operator<<(ostream & os, SCell & src);
	
};

ostream & operator<<(ostream & os, SCell & src) {
	//print what exact cell contains
		for (auto &i : src.data) os << i << ", ";
		os << endl;
		os << "---------" << endl;
		return os;
	}

 int main() {
	int size = 5;
	SCell** treeArray = new SCell*[size];
	//2D array of cells which contains vector of combinations in exac cell
	for (int row = 0; row < size; row++) {
		treeArray[row] = new SCell[size];
	}
	
	string baseStr[] = {"a", "b", "c", "d", "e"};
	
	for (int col = 0; col < size; col++) { //filling base string
				treeArray[0][col].data.push_back(baseStr[col]);
			}
	
	 for (int row = 1; row < size; row++) { 
		 //0 is base string, so starting from 1
		 //CYK is always as high as wide
		for (int col = 0; col < size; col++) {
		//because this is modulo CYK (not triangle but square) I can use full width
		//so iterate through all of columns
				int rowIt1 = 0; //first row iterator which is going from 0 in the same column as final cell
				int rowIt2 = row-1; //second row iterator which is going diagonally from up to down
				int colIt = col+1; //second column iterator which is going diagonally from left to right
				
			for (int number = 0; number < row; number++) {
				//there is as much combinations as the actually used row (for final cell)
				treeArray[row][col] =  treeArray[rowIt1][col] + treeArray[rowIt2][colIt%size];
				
				rowIt1++;
				rowIt2--;
				colIt++;
			}

		}
		
	}
	
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout << treeArray[row][col];
		}
	}
		
	 return 0;
 }