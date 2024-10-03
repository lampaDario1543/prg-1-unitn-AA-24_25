/*
Dire se un numero è pari o dispari
*/
#include <iostream>

using namespace std;

int main(){
    const int n = 98;
    if (n % 2 == 0)
        cout << n << " e' pari" << endl;
    else
        cout << n << " e' dispari" << endl;
    return 0;
}