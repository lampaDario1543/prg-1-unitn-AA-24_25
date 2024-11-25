/*
Partendo dall’implementazione di una Pila tramite liste concatenate
https://pastebin.com/BCyD0f4g (.cc), https://pastebin.com/Rj4UhUA0 (.h)
scrivere un programma che legge una sequenza di caratteri in input
dall’utente e determina se le parentesi sono “bilanciate”:
*/

/*
I/O sample:
((()())) --> true
()()(() --> false
((())) --> true
((() --> false
())( --> false
()(()()) --> true
*/
#include <iostream>
#include "pila.h"

const int LEN = 30;
using namespace std;

bool isBalanced();

int main(){
    char s[LEN];
    cout << "> "; //())(
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
        pila_push(s[i]);
    cout << "Le parentesi " << (isBalanced() ? "sono " : "non sono ") << "bilanciate" << endl;
    pila_deinit();
    return 0;
}

bool isBalanced(){
    bool flag = false;
    int ctr = 0;
    int n = 0;
    while (pila_top(n)){
        pila_pop();
        if (n == ')' && ctr >= 0)
            ++ctr;
        else if (n == '(')
            --ctr;
    }
    return ctr == 0;
}