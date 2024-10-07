/*
Scrivere un programma che genera e stampa il Triangolo di Tartaglia fino a
n righe, dove n è fornito dall'utente. È possibile utilizzare solo variabili e
cicli, anche annidati.
*/
#include <iostream>

using namespace std;

void printTriangle(int);

int main(){
    int n=0;
    do{
        cout << "n: ";
        cin >> n;
    }while(n<=0);
    printTriangle(n);
    return 0;
}

void printTriangle(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i-1);j++){
            cout << " ";
        }
        int valore=1;
        for(int j=0;j<=i;j++){
            cout << valore << " ";
            valore=valore*(i-j)/(j+1);
        }
        cout << endl;
    }
}