/*
Scrivere un programma che definisca una struttura chiamata
Studente formata dai campi nome (array di 30 caratteri),
cognome (array di 30 caratteri), matricola (int) e media (float)
ponderata dei voti. Implementare poi le funzioni definite in basso: la
funzione stampa_studente stampa a video il contenuto di una
struttura Studente, mentre la funzione genera_studente genera una
struttura Studente dati in input il valore dei suoi campi.
Si può utilizzare la funzione strcpy della libreria cstring.

void stampa_studente (Studente * S);
Studente* genera_studente (char nome[], char cognome[], int matricola, float media_ponderata );

*/
#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 30;

struct Studente{
    char nome[LEN];
    char cognome[LEN];
    int matricola;
    float media;
};

void stampa_studente(Studente *);
void get_studente(char *, char *, int &, float &);
Studente *genera_studente(char *, char *, int, float);

int main(){
    char nome[LEN], cognome[LEN];
    int matricola;
    float media;
    get_studente(nome, cognome, matricola, media);
    Studente *s = genera_studente(nome, cognome, matricola, media);
    stampa_studente(s);
    delete s;
    return 0;
}

void get_studente(char *nome, char *cognome, int &matricola, float &media){
    cout << "Nome: ";
    cin >> nome;
    cout << "Cognome: ";
    cin >> cognome;
    cout << "Matricola: ";
    cin >> matricola;
    cout << "Media: ";
    cin >> media;
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
    cout << endl
         << endl;
    cout << "Studente: " << endl;
    cout << "Nome: " << s->nome << endl;
    cout << "Cognome: " << s->cognome << endl;
    cout << "Matricola: " << s->matricola << endl;
    cout << "Media: " << s->media << endl;
    cout << endl
         << endl;
}