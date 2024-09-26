/*
Date in input due variabili (scegliete voi il loro tipo), a e b,
scrivere un programma che scambi il valore di a al valore
di b e viceversa.
(senza utilizzare una variabile temporanea)
*/
#include <iostream>

using namespace std;

int main(){
    int a,b;
    a=5;
    b=6;
    cout << "a= " << a << " b= " << b<<endl;
    a=a+b;
    b=a-b;
    a-=b;
    cout << "a= " << a << " b= " << b<<endl;
    return 0;
}