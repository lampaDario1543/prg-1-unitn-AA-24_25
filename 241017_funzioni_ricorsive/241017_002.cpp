/*
Scrivere un programma che calcoli la divisione di un intero
tramite funzione ricorsiva.
*/
#include <iostream>

using namespace std;

int dividi(int, int);

int main(){
    const int dividendo = 3;
    const int divisore = 15;
    if (divisore == 0)
    {
        cerr << "Il divisore deve essere > 0" << endl;
        exit(0);
    }
    int ris = dividi(dividendo, divisore);
    cout << dividendo << "/" << divisore << "= " << ris << endl;
    return 0;
}

int dividi(int dividendo, int divisore){
    if ((dividendo - divisore) == 0)
        return 1;
    else if ((dividendo - divisore) < 0)
        return 0;
    return 1 + dividi((dividendo - divisore), divisore);
}