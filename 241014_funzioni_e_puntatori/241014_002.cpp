/*
Dati in input due interi, scrivere un programma che faccia la divisione
tramite una funzione; la funzione restituisce tramite valore di ritorno il
quoziente e tramite parametro per riferimento il resto.
In questo programma non si può usare il simbolo ‘/’ per la divisione
*/
#include <iostream>

using namespace std;

double dividi(double, double, int &);

int main(){
    double dividendo = (69 * 7) + 1;
    double divisore = 69;
    int resto = 0;
    double ris = 0;
    ris = dividi(dividendo, divisore, resto);
    cout << dividendo << "/" << divisore << "= " << ris << " con resto " << resto << endl;
    return 0;
}

double dividi(double dividendo, double divisore, int &resto){
    int ris = 0;
    if (0 == divisore)
        return ris;
    while ((dividendo - divisore) >= 0){
        dividendo -= divisore;
        ris++;
    }
    resto = dividendo;
    return ris;
}