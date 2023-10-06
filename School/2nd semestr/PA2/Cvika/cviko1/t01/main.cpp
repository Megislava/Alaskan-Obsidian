#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const int N_MIN = 5;

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

void array_print ( const arrayCpp &arr ) {
    for(size_t i = 0; i < arr.val; i++) {
        if(i != 0) cout << " ";
        cout << arr.data[i];
    }
    cout << endl;
}

bool array_save(const arrayCpp &arr, string const filename) {
    ofstream fout(filename, ios::app);

    if(!fout.is_open()){
        cout << "Nepodarilo se otevrit " << endl;
        return false;
    }

    if(fout.fail()) {
        cout << "Nevalidni prace s dokumentem " << endl;
        return false;
    }

    fout << arr.val << endl;
    for(size_t i = 0; i < arr.val; i++) {
        fout << arr.data[i] << " ";
    }
    fout << endl;
    return true;
}

bool array_write(arrayCpp &arr, string const filename) {
    ofstream fout(filename, ios::binary);

    if(!fout.is_open()){
        cout << "Nepodarilo se otevrit " << endl;
        return false;
    }

    if(fout.fail()) {
        cout << "Nevalidni prace s dokumentem " << endl;
        return false;
    }

    fout.write((const char *)&arr.val, sizeof(arr.val));

    for(size_t i = 0; i < arr.val; i++) {
        fout.write((const char *)(arr.data + i), sizeof(arr.data[i]));
    }
    fout << endl;
    return true;
}

bool array_load(arrayCpp &arr, string const filename) {
    int i = 0, j = 0;
    double num;

    ifstream in(filename, ios::in);

    while(in >> num) {
        if(i == 0) {
            arr.val = num;
            arr.data = new double[arr.val];
        } else {
            arr.data[j] = num;
            j++;
        }
        i++;
    }

    getchar();

    return true;
}

bool array_read(arrayCpp &arr, string const filename) {
    int i = 0, j = 0;
    double num;

    ifstream in(filename, ios::in);

    while(in >> num) {
        if(i == 0) {
            arr.val = num;
            arr.data = new double[arr.val];
        } else {
            arr.data[j] = num;
            j++;
        }
        i++;
    }

    getchar();

    return true;
}

int main ()
{
    arrayCpp arrCpp;
    /*if(! (array_fill(arrCpp))){
        cout << "Nespravny vstup." << endl;
        return 0;
    }*/
    //array_load(arrCpp, "input.txt");

    array_read(arrCpp, "inputBin.txt");

    array_print(arrCpp);
    std::sort(arrCpp.data, arrCpp.data+arrCpp.val);
    array_print(arrCpp);

    /*if(!array_save(arrCpp, "outputApp.txt")){
        cout << "Nepodarilo se zapsat do souboru " << endl;
    }*/

    array_write(arrCpp, "outputBin.txt")){
        cout << "Nepodarilo se zapsat do souboru " << endl;
    }

    array_free(arrCpp);
    return 1;
}
