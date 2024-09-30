/*
Scrivere un programma C++ che, ricevuti in input tre numeri interi a,
b, c, di cui b e c siano gli estremi di un intervallo, stampi a video un
numero, seguendo il comportamento della funzione rappresentata
sotto, a seconda della posizione di a nell’intervallo b, c

f(a,b,c):
= -1 per b<=a<=c
=1 a<b
=0 a>c
*/

#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    int ris=-1;
    cout << "Inserisci a b c: ";
    cin >> a >> b >> c;
    if(a>=b && a<=c){
        ris=-1;
    }else if(a<b){
        ris=1;
    }else if(a>c){
        ris=0;
    }
    cout << "Il risultato della funzione e': "<< ris << endl;
    return 0;
}