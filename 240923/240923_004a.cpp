/*
Dati in input due numeri reali “prezzo” e “iva”,
scrivere due programmi che calcolino rispettivamente:
● il prezzo lordo considerando gli input come prezzo
netto e percentuale d’iva
● il prezzo netto considerando gli input come prezzo
lordo e percentuale d’iva
PrezzoLordo = PrezzoNetto + PrezzoNetto*(PercentualeIVA/100)
VARIANTE: valutare la fattibilità ed eventualmente implementare in un unico
programma entrambe le funzionalità SENZA usare costrutti condizionali e
chiedendo in input all’utente quale calcolo si desidera effettuare
*/
#include <iostream>

using namespace std;

int main(){
    float prezzo, iva;
    prezzo=iva=0;
    float prezzo_lordo=0;
    cout << "Prezzo> ";
    cin>> prezzo;
    cout << "Iva> ";
    cin>> iva;
    prezzo_lordo=prezzo+((float)prezzo*((float)(iva/100)));
    cout << "Prezzo lordo= "<<prezzo_lordo << endl;
    return 0;
}