/*Scrivere un programma che scambia il valore di due variabili intere utilizzando solo
l'operatore XOR e senza usare variabili temporanee.*/

#include <iostream>

using namespace std;

int main(){
    int a=4;
    int b=5;
    cout << "a= " << a << " b= " << b<<endl;
    a^=b;
    b=a^b;
    a^=b;
    cout << "a= " << a << " b= " << b<<endl;
    return 0;
}