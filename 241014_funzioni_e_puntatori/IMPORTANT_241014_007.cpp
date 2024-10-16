/*
Dati in input due interi (short), scrivere un programma che
con una procedura scambi gli 8 bit meno significativi dei
due numeri.
*/
#include <iostream>

using namespace std;

void swap(short &, short &);

int main(){
    short a=1855;
    short b=1048;
    cout << "a= " << a << " b= " << b << endl;
    swap(a,b);
    cout << "a= " << a << " b= " << b << endl;
    return 0;
}

void swap(short &a, short &b){
    short mask = 0xFF; //massimo (11111111...)
    //prendo gli ultimi 8 bit di ogni numero.
    short last_8_a= a & mask;
    short last_8_b= b & mask;
    //Tolgo gli ultimi 8 bit di ogni numero.
    a= a & ~(mask); 
    b= b & ~(mask);
    //scambio gli ultimi 8 bit.
    a= a | last_8_b; 
    b= b | last_8_a; 
}