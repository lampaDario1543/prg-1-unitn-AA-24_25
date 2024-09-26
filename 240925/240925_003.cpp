/*
Scrivere un programma che chieda un carattere che identifica una
   lingua (es: 'i'= italiano, 'e'=inglese, ecc.) e scriva "buon
   giorno" nella lingua prescelta. Usare l'istruzione switch.
*/

#include <iostream>

using namespace std;

int main(){
    char c=' ';
    cout << "Inserisci una lingua> ";
    cin >> c;
    switch(c){
        case 'i':
            //italiano
            cout << "Buon giorno" << endl;
            break;
        case 'f':
            //francese
            cout << "Bon jour" << endl;
            break;
        case 'e':
            //inglese
            cout << "Good morning" << endl;
            break;
        case 's':
            //Spagnolo
            cout << "Hola." << endl;
            break;
        default:
            cout << "La lingua non e' ancora riconosciuta." << endl;
            break;
    }
    return 0;
}