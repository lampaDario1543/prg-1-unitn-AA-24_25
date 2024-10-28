/*
Si scriva in C++ una nuova funzione ricorsiva (NON tail recursive!) che estenda il
comportamento della funzione dell’esercizio precedente cosi da permettere di ricevere
un esponente negativo. In tal caso, la funzione restituirà il valore M(-N) = 1 / MN.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione.
Il programma chiederà all’utente di inserire da tastiera due numeri interi, chiamerà la
funzione e stamperà a video il suo valore di ritorno. Le operazioni si ripeteranno finché
l’utente lo desidera.
*/
#include <iostream>

using namespace std;

long double pow(int, int);
long double pow(int, int, int, bool);

int main(){
    int n, esp;
    char opt = ' ';
    do{
        cout << "Inserire n esponente: ";
        cin >> n >> esp;
        cout << n << "^" << esp << "= " << pow(n, esp) << endl;
        cout << "Vuoi continuare (y/n)? ";
        cin >> opt;
    } while (opt == 'y');
    return 0;
}
long double pow(int m, int n, int ctr, bool isNeg){
    if (ctr != n){
        if (isNeg)
            return (long double)(1.0 / m) * (pow(m, n, ctr - 1, isNeg));
        return m * pow(m, n, ctr + 1, isNeg);
    }
    if (isNeg)
        return (long double)(1.0 / m);
    return m;
}
long double pow(int m, int n){
    if (n == 0)
        return 1;
    bool isNeg = n > 0;
    if (isNeg)
        return pow(m, n, 1, isNeg);
    return pow(m, n, -1, isNeg);
}