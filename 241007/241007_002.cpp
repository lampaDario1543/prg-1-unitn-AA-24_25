/*
Scrivere un programma che stampi a video i caratteri
compresi tra un intervallo di valori ASCII (quindi, interi)
a e b definito dall’utente in input.
Controllare anche che l’intervallo inserito dall’utente
sia valido (a < b, a >= 0, b <= 127), altrimenti
terminare il programma.
*/
#include <iostream>

using namespace std;

void printChar(int, int);

int main(){
    int a, b;
    cout << "a b: ";
    cin >> a >> b;
    if (a > b){
        int box = a;
        a = b;
        b = box;
    }
    if (a < 0 || b >= 127)
        cout << "Intervallo non valido." << endl;
    else
        printChar(a, b);
    return 0;
}

void printChar(int a, int b){
    char c;
    c = (char)a;
    for (c = a; c <= b; c++)
        cout << c << " --> " << (int)c << endl;
}