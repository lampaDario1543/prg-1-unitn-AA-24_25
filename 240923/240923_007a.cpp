/*
Date in input due variabili (scegliete voi il loro tipo), a e b,
scrivere un programma che scambi il valore di a al valore
di b e viceversa.
*/
#include <iostream>

using namespace std;

int main(){
    int a,b,box;
    a=5;
    b=6;
    cout << "a= " << a << " b= " << b<<endl;
    box=a;
    a=b;
    b=box;
    cout << "a= " << a << " b= " << b<<endl;
    return 0;
}