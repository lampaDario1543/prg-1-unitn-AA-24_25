/*
Scrivere un programma che, preso in input un file, legga le parole in esso
contenute (massimo 255 lettere) e stampi a video le parole che possono
essere potenzialmente un indirizzo email.
Utilizzare le funzioni della libreria fstream
Definire la funzione che controlla se una parola è potenzialmente un
indirizzo email in un file separato

1. Deve contenere un solo simbolo @, che divida la parola in due parti,
nella forma: <utente>@<dominio>
2. Entrambe le parole <utente> e <dominio> devono:
a. Avere lunghezza >= 1;
b. Essere formate solo da:
i. lettere minuscole (a-z)
ii. lettere maiuscole (A-Z)
iii. cifre (0-9)
iv. i simboli . (punto) e _ (underscore)
3. Non avere il simbolo . (punto) come prima o ultima lettera;
*/

#include <iostream>
#include <fstream>
#include "fun003.h"

using namespace std;

const int LEN=256;

int main(){
    char filename[30];
    cout << "Filename: ";
    cin >> filename;
    fstream in;
    in.open(filename, ios::in);
    if(in.fail()){
        cerr << "Il file "<< filename << " non esiste."<<endl;
        exit(0);
    }
    char parola[LEN];
    while(!in.eof()){
        in >> parola;
        if(isEmail(parola))
            cout << "Mail trovata: "<<parola<<endl;
    }
    in.close();
    return 0;
}