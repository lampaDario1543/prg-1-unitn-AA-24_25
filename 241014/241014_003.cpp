/*
Dati in input tre interi in tre variabili (secondi, minuti, ore), scrivere un
programma che con una procedura converta un eventuale eccesso di
secondi in minuti e un eventuale eccesso di minuti in ore. Usare a
scelta passaggio di parametri per riferimento o puntatore.
*/
#include <iostream>

using namespace std;

void converti(int &, int &, int &);

int main(){
    int secondi=69;
    int minuti=69;
    int ore=13;
    cout << "Secondi= "<< secondi <<endl<<  "Minuti= "<< minuti << endl << "Ore= "<< ore<<endl;
    cout << "--------"<<endl;
    converti(secondi, minuti, ore);
    cout << "Conversione: "<<endl<<endl;
    cout << "Secondi= "<< secondi <<endl<<  "Minuti= "<< minuti << endl << "Ore= "<< ore<<endl;
    return 0;
}

void converti(int &secondi, int &minuti, int &ore){
    if(secondi > 59){
        minuti+=secondi/60;
        secondi=(secondi%60);
    }
    if(minuti > 59){
        ore+=minuti/60;
        minuti=(minuti%60);
    }
}
