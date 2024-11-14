/*
Utilizzando le funzioni scritte precedentemente, scrivere un programma
che, dato in input un file contenente i dati di alcuni studenti e il numero di
righe del file, generi un array dinamico che contenga tutti questi studenti. E’
consigliato raggruppare questa logica all’interno di una funzione separata.
Utilizzare la libreria fstream.

Studente **database = new Studente*[N];
*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int LEN = 30;

struct Studente{
    char nome[LEN];
    char cognome[LEN];
    int matricola;
    float media;
};

void stampa_studente(Studente *);
Studente *genera_studente(char *, char *, int, float);
void carica(Studente **, fstream &);
void delete_database(Studente **&, const int);

int main(){
    char filename[LEN];
    int N;
    fstream in;
    cout << "Inserisci <nome file> <n_studenti>: ";
    cin >> filename >> N;
    if (N <= 0){
        cerr << "Il numero di studenti deve essere > 0" << endl;
        exit(0);
    }
    in.open(filename, ios::in);
    if (in.fail()){
        cerr << "Il file " << filename << " non esiste" << endl;
        exit(0);
    }
    Studente **database = new Studente *[N];
    carica(database, in);
    for (int i = 0; i < N; i++)
        stampa_studente(database[i]);
    delete_database(database, N);
    in.close();
    return 0;
}

Studente *genera_studente(char nome[], char cognome[], int matricola, float media){
    Studente *s = new Studente;
    strcpy(s->nome, nome);
    strcpy(s->cognome, cognome);
    s->matricola = matricola;
    s->media = media;
    return s;
}

void stampa_studente(Studente *s){
    cout << "Studente: " << endl;
    cout << "Nome: " << s->nome << endl;
    cout << "Cognome: " << s->cognome << endl;
    cout << "Matricola: " << s->matricola << endl;
    cout << "Media: " << s->media << endl;
    cout << endl
         << endl;
}
void carica(Studente **database, fstream &in){
    int i = 0;
    char nome[LEN], cognome[LEN];
    int matricola;
    float media;
    while (!in.eof()){
        in >> nome >> cognome >> matricola >> media;
        database[i] = genera_studente(nome, cognome, matricola, media);
        ++i;
    }
}
void delete_database(Studente **&db, const int N){
    for (int i = 0; i < N; i++){
        delete db[i];
        db[i] = nullptr;
    }
    delete[] db;
}