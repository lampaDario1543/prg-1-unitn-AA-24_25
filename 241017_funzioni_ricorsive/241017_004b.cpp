/*
Scrivere un programma che, preso in input un numero
intero, controlli se il numero è un palindromo.
Scrivere una funzione ricorsiva che faccia il controllo.
*/
#include <iostream>

using namespace std;

bool isPalindromo(int);
int getReverse(int, int ris = 0);

int main(){
    const int n = 5;
    if (isPalindromo(n))
        cout << n << " e' palindromo" << endl;
    else
        cout << n << " non e' palindromo" << endl;
    return 0;
}

int getReverse(int n, int ris){
    if (n == 0)
        return ris;
    ris = (n % 10) + (ris * 10);
    return getReverse(n / 10, ris);
}

bool isPalindromo(int n){
    // trovo il reverse
    int reverse = getReverse(n);
    if (reverse == n)
        return true;
    return false;
}
