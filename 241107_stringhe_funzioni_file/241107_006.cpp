/*
Scrivere un programma che, dati in input due file A e B da
riga di comando, generi un terzo file C che contenga tutte le
parole presenti in entrambi i file A e B.
E’ consentito l’uso delle funzioni strcmp(), strcpy() della
libreria <cstring>. Assumete inoltre che i file contengano al
massimo 1000 parole e che la lunghezza massima delle singole
parole sia 100. E’ consentito aprire al massimo un unico
stream per file.
*/
#include <iostream>
#include <fstream>
#include <cstring>

const int LEN = 100;
const int DIM = 1000;

using namespace std;

void interseca(char *, char *);

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Inserire i nomi dei file." << endl;
        exit(0);
    }
    interseca(argv[1], argv[2]);
    return 0;
}

void interseca(char *a_name, char *b_name){
    fstream a;
    a.open(a_name, ios::in);
    if (a.fail()){
        cerr << "Il file " << a_name << " non esiste" << endl;
        exit(0);
    }
    fstream b;
    b.open(b_name, ios::in);
    if (b.fail()){
        cerr << "Il file " << b_name << " non esiste" << endl;
        exit(0);
    }
    fstream c;
    c.open("intersezione.txt", ios::out);
    if (c.fail()){
        cerr << "Errore creazione file intersezione.txt" << endl;
        exit(0);
    }
    char parole[DIM][LEN];
    int i = 0;
    while (!a.eof()){
        a >> parole[i];
        ++i;
    }
    const int dim = i;
    char s[LEN];
    while (!b.eof()){
        b >> s;
        for (i = 0; i < dim; i++){
            if (strcmp(parole[i], s) == 0){
                c << s << endl;
                break;
            }
        }
    }
    cout << "Intersezione creata con successo." << endl;
    a.close();
    b.close();
    c.close();
}