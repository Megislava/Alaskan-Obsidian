<<<<<<< HEAD

int compareConstChar(const char* & a, const char* & b) {
	const char* selected;
	if (strlen(a) <= strlen(b)) selected = a;
	else selected = b;
	
	for (unsigned int i = 0; i < strlen(selected); i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
		//else is equeal, new cycle
	}
	
	if (strlen(a) == strlen(b)) return 0;
	else if (strlen(a) < strlen(b)) return -1;
	else return 1;
	
	//returned value: 
	//	-1 - left is less than right
	//   0 - they are equal
	//	 1 - left is bigger than right
}



int main() {
	const char* a = "mam se dobre.mas se ty?";
	const char* b = "mam se dobre.";
	int value = compareConstChar(a, b);
	cout << value;
	return 0;
=======

int compareConstChar(const char* & a, const char* & b) {
	const char* selected;
	if (strlen(a) <= strlen(b)) selected = a;
	else selected = b;
	
	for (unsigned int i = 0; i < strlen(selected); i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
		//else is equeal, new cycle
	}
	
	if (strlen(a) == strlen(b)) return 0;
	else if (strlen(a) < strlen(b)) return -1;
	else return 1;
	
	//returned value: 
	//	-1 - left is less than right
	//   0 - they are equal
	//	 1 - left is bigger than right
}



int main() {
	const char* a = "mam se dobre.mas se ty?";
	const char* b = "mam se dobre.";
	int value = compareConstChar(a, b);
	cout << value;
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}