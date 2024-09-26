/*Scrivere un programma C++ che, dati in input due numeri interi,
a e b, calcoli il risultato, in valore assoluto,
dell’operazione (a-b).
(senza utilizzare funzioni di libreria o istruzioni if-else o l’operatore
ternario)*/

#include <iostream>

using namespace std;

int main(){
    int a,b;
    int ris=0;
    a=0;
    b=0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    int maggiore=a>b;
    cout << maggiore<<endl;
    ris=(a-b)*maggiore;
    ris+=(b-a)*!(maggiore);
    cout<< "Risultato: " << ris << endl;
    return 0;
}