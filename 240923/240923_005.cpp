/*
dato in input un carattere maiuscolo, ritorna lo
stesso carattere minuscolo… e viceversa SENZA costrutti
condizionali
VARIANTE: risolvere il problema SENZA usare espressioni
booleane (nessun operatore), o l’operatore ternario
SUPERSFIDA: implementare anche il controllo dell’input
sotto gli stessi vincoli
*/
#include <iostream>

using namespace std;

int main(){
    char c='A';
    c=c^('a'-'A');
    cout << c << endl;
    return 0;
}