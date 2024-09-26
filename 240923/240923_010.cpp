/*
Senza utilizzare funzioni di libreria o istruzioni if-else:
Scrivere un programma che prende un numero intero a tre cifre e calcola la somma
delle sue cifre senza usare cicli
*/
#include <iostream>

using namespace std;

int main(){
    int n=0;
    int s=0;
    cout << "Numero (a tre cifre)> ";
    cin>>n;
    s+=n/100;
    s+=(n/10)%10;
    s+=n%10;
    cout<<"Somma: "<< s << endl;
    return 0;
}