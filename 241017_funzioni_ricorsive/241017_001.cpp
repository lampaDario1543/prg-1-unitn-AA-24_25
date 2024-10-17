/*
Scrivere un programma che calcoli il fattoriale di un intero
positivo tramite funzione ricorsiva.
*/
#include <iostream>

using namespace std;

int fattoriale(int);

int main(){
    const int n = 5;
    int ris = fattoriale(n);
    cout << "Il fattoriale di " << n << " e' " << ris << endl;
    return 0;
}
int fattoriale(int n){
    if (n == 0)
        return 1;
    else
        return n * fattoriale(n - 1);
}