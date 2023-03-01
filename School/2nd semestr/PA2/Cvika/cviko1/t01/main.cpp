#include <iostream>
#include <algorithm>
#define N_MIN 5
using namespace std;

struct arrayCpp {
    size_t val;
    double *data;
};

void array_free(arrayCpp &arr) {
    delete [] arr.data;
    arr.data = nullptr;
    arr.val = 0;
}

bool array_fill (arrayCpp &arr) {
    if (!(cin >> arr.val) || arr.val < N_MIN ) {
        return false;
    }

    arr.data = new double[arr.val];
    for ( size_t i = 0; i < arr.val; ++i ) {
        if ( !(cin >> *(arr.data + i))) {
            array_free(arr);
            return false;
        }
    }
    return true;
}

void arr_sort(const arrayCpp &arr) {
  std::sort(arr.data, arr.data+arr.val);
}

void array_print ( const arrayCpp &arr ) {
    for(size_t i = 0; i < arr.val; i++) {
        if(i != 0) cout << " ";
        cout << arr.data[i];
    }
    cout << endl;
}

int main ()
{
	arrayCpp arrCpp;
    if(! (array_fill(arrCpp))){
        cout << "Nespravny vstup." << endl;
        return 0;
    }
    array_print(arrCpp);
    arr_sort(arrCpp);
    array_print(arrCpp);
    array_free(arrCpp);
	return 1;
}
