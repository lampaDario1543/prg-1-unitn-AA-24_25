/*
Scrivere una funzione tail recursive C++ che riceva come parametri due
numeri interi e calcoli il Massimo Comune Divisore (MCD) usando
l’algoritmo di Euclide.
Algoritmo di Euclide
Siano a e b due numeri interi, tali che 0 < b < a:
1) Se b = 0, allora MCD (a,b) = a;
2) Se b ≠ 0, calcolare la divisione di a e b, chiamando q il quoziente e r il resto della divisione;
3) Porre a = b e b =r ;
4) Ripartire dal punto 1
Convertire poi la soluzione ricorsiva in una soluzione iterativa.
*/
#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int MCD = 0;
    do{
        cout << "Inserisci a b: ";
        cin >> a >> b;
    }while(b<0 || a<=b);
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    MCD = a;
    cout << "MCD= " << MCD << endl;
    return 0;
}