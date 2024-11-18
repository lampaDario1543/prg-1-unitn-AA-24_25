/*
Scrivere un programma che simuli il gioco del Tris.
L'utente giocherà contro il pc, ogni volta che sarà il suo turno sceglierà la
cella in cui vorrà giocare, le celle sono numerate dall'alto al basso, da
sinistra a destra. Verrà fatto un controllo per verificare che la mossa sia
possibile.
Il computer invece sceglie un numero casuale tra 1 e 9 e giocherà nella
cella se libera.
Il programma dovrà essere organizzato in file multipli: main.cc gioco.cc
gioco.h.

void inizializzaMatrice (char matrice[DIM][DIM]);
void stampaMatrice(const char matrice[DIM][DIM]);
bool gioca(char matrice[DIM][DIM], bool turnoUtente, char
simboloUtente, char simboloComputer);
bool controllaVincita (const char matrice[DIM][DIM], char
simbolo, bool &pareggio);
void iniziaGioco(); //da richiamare nel main
*/
#include <iostream>
#include "gioco.h"

using namespace std;

int main(){
    iniziaGioco();
    return 0;
}