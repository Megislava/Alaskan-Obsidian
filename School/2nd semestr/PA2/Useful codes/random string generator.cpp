<<<<<<< HEAD
#include <cstdlib>
#include <iostream>
#include <string>
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


int main() {
	#define CNT 20
	srand(time(NULL)); //init seed (different between runs)
	for (int i = 0; i < CNT; i++) cout << randomStrGen(5, 23) << endl; //random string
	for (int i = 0; i < CNT; i++) cout << rand()%10000 << endl; //random number
	return 0;
=======
#include <cstdlib>
#include <iostream>
#include <string>
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


int main() {
	#define CNT 20
	srand(time(NULL)); //init seed (different between runs)
	for (int i = 0; i < CNT; i++) cout << randomStrGen(5, 23) << endl; //random string
	for (int i = 0; i < CNT; i++) cout << rand()%10000 << endl; //random number
	return 0;
>>>>>>> ed86870e047cc27b656f2f20735dd248c5953b5d
}