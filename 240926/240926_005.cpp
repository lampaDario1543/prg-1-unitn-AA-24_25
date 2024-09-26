/*
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera le dimensioni di una tabella espresse come numero di righe e
numero di colonne (due numeri interi) e stampi a video 0 se la tabella ha una
sola riga oppure una sola colonna oppure un solo elemento.
Attenzione: si usino solo gli operatori di confronto.
*/
#include <iostream>

using namespace std;

int main(){
    int row,col;
    cout << "Inserisci righe colonne: ";
    cin >> row >> col;
    bool ris;
    ris= (row==1) || (col==1) || ((row*col)==1);
    ris=!ris;
    cout << "Risultato: " << ris << endl; 
    return 0;
}