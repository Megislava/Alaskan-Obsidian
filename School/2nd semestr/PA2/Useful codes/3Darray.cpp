struct structure {
	string parameter;
};

int size = 10;
structure**** array3D = new structure***[size];

for (int i = 0; i < size; i++) {
	array3D[i] = new structure**[size];
	
	for (int j = 0; j < size; j++) {
		array3D[i][j] = new structure*[size];
		
		for (int k = 0; k < size; k++) {
			array3D[i][j][k]= new structure[size];
			array3D[i][j][k]->parameter = "sdf";
		
		}
	}
}

cout << array3D[1][2][5]->parameter << endl;