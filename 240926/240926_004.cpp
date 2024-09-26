/*
Scrivere un programma C++ che, dati in input due numeri interi,
a e b, controlli se i due numeri sono uguali. Il programma deve
stampare a video il risultato del confronto tramite una variabile
booleana
(senza utilizzare funzioni di libreria o istruzioni if-else oppure “==”)*/

#include <iostream>

using namespace std;

int main(){
    int a,b;
    cout << "Inserisci a: ";
    cin >> a;
    cout << "Inserisci b: ";
    cin >> b;
    bool are_same=!(a-b);
    cout << "Sono lo stesso numero: " << are_same << endl;
    return 0;
}