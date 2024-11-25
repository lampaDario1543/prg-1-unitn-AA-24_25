/*
Scrivere un programma che, data una parola in input (massimo 100
caratteri), dica se è palindroma oppure no usando una pila e/o una coda.
Nota: non potete sfruttare la conoscenza della lunghezza della parola
(non potete nemmeno calcolarla)
*/
#include <iostream>
#include "pila.h"
#include "coda.h"

const int LEN = 100;
using namespace std;

bool isPalindrom(char *);

int main(){
    char s[LEN];
    cout << "Stringa: ";
    cin.getline(s, LEN);
    cout << s << " " << (!isPalindrom(s) ? "non " : " ") << "e' palindromo" << endl;
    coda_deinit();
    pila_deinit();
    return 0;
}

bool isPalindrom(char *s){
    coda_init();
    pila_init();
    for (int i = 0; s[i] != '\0'; i++){
        coda_enqueue(s[i]);
        pila_push(s[i]);
    }
    int n1 = 0;
    int n2 = 0;
    while (pila_top(n1) && coda_first(n2)){
        if (n1 != n2)
            return false;
        pila_pop();
        coda_dequeue();
    }
    return true;
}