/*
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera un numero intero e stampi a video il numero immediatamente
precedente ed il numero immediatamente successivo.
Attenzione: si utilizzino solo gli operatori di incremento e decremento.
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Inserisci n: ";
    cin >> n;
    cout << "Numero precedente: "<< --n << endl;
    n++;
    cout << "Numero successivo: "<< ++n << endl;
    return 0;
}