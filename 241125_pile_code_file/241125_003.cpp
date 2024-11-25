/*
Partendo dall’implementazione di una Coda tramite liste concatenate
con tipo di dato char*
https://pastebin.com/yuqZUM5j (.cc), https://pastebin.com/TNvTjBDU (.h)
Scrivere un programma che simuli l'arrivo e lo smaltimento di una coda
all'ufficio postale. Gli elementi della coda sono i nomi delle persone. Il
main sarà un menù con tre opzioni: (1) aggiungi persona, (2) smaltisci
persona, (3) stampa situazione corrente.
Non sono ammessi omonimi nella coda.
Potete usare la funzione strcmp della libreria <cstring>
*/
#include <iostream>
#include <cstring>
#include "coda.h"

using namespace std;

void inserisci(char *);
bool isOnonimo(char *, char *, bool &);
void smaltisci();
void stampa();

int main(){
    int opt;
    bool flag = true;
    char nome[30];
    char *n;
    bool res;
    init();
    while (flag){
        cout << "0 - Esci" << endl;
        cout << "1 - Inserisci persona" << endl;
        cout << "2 - Smaltisci persona" << endl;
        cout << "3 - Stampa situazione corrente" << endl;
        cout << "> ";
        cin >> opt;
        switch (opt){
        case 0:
            flag = !flag;
            break;
        case 1:
            res = false;
            do{
                cout << "Nome: ";
                cin >> nome;
            } while (isOnonimo(nome, n, res));
            inserisci(nome);
            break;
        case 2:
            smaltisci();
            break;
        case 3:
            cout << endl
                 << "Persone in coda: " << endl;
            stampa();
            cout << endl;
            break;
        default:
            cout << "Opzione non valido.";
            break;
        }
    }
    deinit();
    return 0;
}

void inserisci(char *n){
    enqueue(n);
}

bool isOnonimo(char *nome, char *n, bool &res){
    if (!first(n)){
        res = false;
        return false;
    }
    if (strcmp(n, nome) == 0){
        res = true;
        return true;
    }
    else{
        char *tmp = n;
        dequeue();
        isOnonimo(nome, n, res);
        enqueue(tmp);
        return res;
    }
}
void smaltisci(){
    char *nome;
    first(nome);
    cout << endl
         << "Servo " << nome << endl;
    dequeue();
    cout << endl
         << "Ho servito " << nome << endl;
}
void stampa(){
    print();
}