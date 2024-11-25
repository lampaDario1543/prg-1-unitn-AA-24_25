/*
coda (int): https://pastebin.com/SdxreBUc (.cc) https://pastebin.com/z0J4t7YY (.h)
pila (int): https://pastebin.com/BCyD0f4g (.cc) https://pastebin.com/Rj4UhUA0 (.h)

Scrivere un programma che inverta gli elementi di una pila usando una
coda.
*/
#include <iostream>
#include "coda.h"
#include "pila.h"

using namespace std;

void reverse();

int main(){
    pila_init();
    pila_push(1);
    pila_push(2);
    pila_push(3);
    pila_push(4);
    cout << "Pila: "<<endl;
    pila_print();
    reverse();
    cout << "Pila reverse: "<<endl;
    pila_print();
    pila_deinit();
    return 0;
}

void reverse(){
    coda_init();
    int n;
    while(pila_top(n)){
        pila_pop();
        coda_enqueue(n);
    }
    while(coda_first(n)){
        coda_dequeue();
        pila_push(n);
    }
    coda_deinit();
}