/*
Scrivere la dichiarazione e definizione di una funzione ricorsiva estrai
che, data una stringa lunga al massimo 80 caratteri senza spazi, estragga
tutte le lettere maiuscole contenute e restituisca un’altra stringa contenente
solo le lettere maiuscole.
Definire la funzione di estrazione in un file separato
“MarcoStefanoAndreaEnricoGiovannaMatteo”
=
“MSAEGM”
*/
#include <iostream>
#include <fstream>
#include "fun002.h"

using namespace std;

const int LEN=80;

int main(){
    char s[LEN]="MarcoStefanoAndreaEnricoGiovannaMatte";
    char *res=estrai(s);
    cout << res<<endl;
    delete []res;
    return 0;
}