/*
Dato in input un carattere, scrivere un programma che
controlli con una funzione se il carattere fornito in input sia
una lettera dell’alfabeto minuscola. In caso affermativo, il
programma deve stampare a video il carattere in
maiuscolo, usando una funzione per la conversione.

La funzione di conversione non deve ritornare alcun
valore.
*/
#include <iostream>

using namespace std;

bool isLowerAlphabetic(char);
void upChar(char &);

int main(){
    char c;
    do{
        cout << "c: ";
        cin >> c;
        if (!isLowerAlphabetic(c))
            cout << "Inserisci una lettera minuscola dell'alfabeto!" << endl
                 << endl;
    } while (!isLowerAlphabetic(c));
    upChar(c);
    cout << c << endl;
    return 0;
}

void upChar(char &c){
    c -= 'a' - 'A';
    return;
}

bool isLowerAlphabetic(char c){
    return (c >= 'a' && c <= 'z');
}