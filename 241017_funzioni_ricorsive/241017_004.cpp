/*
Scrivere un programma che, preso in input un numero
intero, controlli se il numero è un palindromo.
*/
#include <iostream>

using namespace std;

bool isPalindromo(int);

int main(){
    const int n = 696;
    if (isPalindromo(n))
        cout << n << " e' palindromo" << endl;
    else
        cout << n << " non e' palindromo" << endl;
    return 0;
}

bool isPalindromo(int n){
    int temp = n;
    // trovo il reverse
    int reverse = 0;
    while ((n / 10) > 0){
        reverse = (n % 10) + reverse * 10;
        n /= 10;
    }
    reverse = (n % 10) + reverse * 10;
    if (reverse == temp)
        return true;
    return false;
}
