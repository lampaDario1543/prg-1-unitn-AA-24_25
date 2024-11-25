/*
Partendo dall’implementazione di una Pila tramite liste concatenate
https://pastebin.com/BCyD0f4g (.cc), https://pastebin.com/Rj4UhUA0 (.h)
scrivere un programma che prenda in ingresso un file con un intero per
riga e lo copi su un altro file con le righe in ordine inverso
01 - Inverti Righe
*/
#include <iostream>
#include <fstream>
#include "pila.h"

using namespace std;

int main(){
    char filename[30];
    int n;
    cout << "Filename: ";
    cin >> filename;
    fstream in, out;
    in.open(filename, ios::in);
    out.open("out.txt", ios::out);
    if (in.fail()){
        cerr << "Il file " << filename << " non esiste." << endl;
        exit(0);
    }
    if (out.fail()){
        cerr << "Errore apertura file output" << endl;
        exit(0);
    }
    pila_init();
    while (!in.eof()){
        in >> n;
        pila_push(n);
    }
    while (pila_top(n)){
        pila_pop();
        out << n << endl;
    }
    cout << "File creato con successo." << endl;
    pila_deinit();
    return 0;
}