/*
Scrivere una funzione ricorsiva che, dato in input un
numero intero, ritorni la somma delle cifre che
compongono il numero intero.
25 => 7
*/
#include <iostream>

using namespace std;

int somma(int);

int main(){
    const int n = 69;
    cout << "Somma delle cifre di " << n << "= " << somma(n) << endl;
    return 0;
}

int somma(int n)
{
    if (n == 0)
        return n;
    return n % 10 + somma(n / 10);
}