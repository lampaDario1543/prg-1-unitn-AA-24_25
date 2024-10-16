/*
Dati in input tre interi positivi in tre variabili (n1, n2, n3),
scrivere un programma che con una procedura “ri-ordini” i
numeri in ordine crescente usando il passaggio di
parametri per riferimento.
*/

#include <iostream>

using namespace std;

void sort(int &, int &, int &);

int main(){
    int n1, n2, n3;
    cout << "Inserisci tre numeri: ";
    cin >> n1 >> n2 >> n3;
    sort(n1, n2, n3);
    cout << n1 << " " << n2 << " " << n3 << endl;
    return 0;
}

void sort(int &a, int &b, int &c){
    int box=0;
    if(a>b){
        box=a;
        a=b;
        b=box;
    }
    if(a > c){
        box=a;
        a=c;
        c=box;
    }
    if(b > c){
        box=b;
        b=c;
        c=box;
    }
}