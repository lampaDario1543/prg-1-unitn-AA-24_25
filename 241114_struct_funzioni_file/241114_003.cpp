/*
Modificare il programma scritto precedentemente implementando le funzioni
definite sotto: la funzione cerca_matricola permette di cercare uno studente
tramite il numero di matricola, la funzione cerca_nome_e_cognome permette di
cercare uno studente per nome e cognome, mentre la funzione
studente_top_media ritorna lo studente con la più alta media ponderata. Tutte le
funzioni ritornano l’indice del database corrispondente.
Si può utilizzare la funzione strcmp della libreria cstring.

● int cerca_matricola(Studente ** database, int matricola, int DIM);
● int cerca_nome_e_cognome(Studente ** database, char * nome, char *
cognome, int DIM);
● int studente_top_media(Studente ** database, int DIM);
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
int cerca_matricola(Studente **, int, int);
int cerca_nome_e_cognome(Studente **, char *, char *, int);
int studente_top_media(Studente **, int);

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
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;

    // cerco per matricola
    int res_matricola = -1;
    const int mat = 46592;

    if ((res_matricola = cerca_matricola(database, mat, N)) != -1){
        cout << "Studente con matricola " << mat << " trovato." << endl;
        stampa_studente(database[res_matricola]);
    }
    else
        cout << "Studente con matricola " << mat << " non trovato." << endl;

    char nome[LEN] = "Aida";
    char cognome[LEN] = "Scott";
    // cerco per nome e cognome
    if ((res_matricola = cerca_nome_e_cognome(database, nome, cognome, N)) != -1){
        cout << "Studente " << nome << " " << cognome << " trovato." << endl;
        stampa_studente(database[res_matricola]);
    }
    else
        cout << "Studente " << nome << " " << cognome << " non trovato." << endl;
    cout << "Studente con la media piu' alta: " << endl;
    stampa_studente(database[studente_top_media(database, N)]);
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
    while (!in.eof()){ // forse meglio usare for
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

int cerca_matricola(Studente **database, int matricola, int DIM){
    int idx = -1;
    int i = 0;
    bool flag = false;
    while (i < DIM && !flag){
        flag = database[i]->matricola == matricola;
        if (flag)
            idx = i;
        ++i;
    }
    return idx;
}
int cerca_nome_e_cognome(Studente **database, char *nome, char *cognome, int DIM){
    int idx = -1;
    int i = 0;
    bool flag = false;
    while (i < DIM && !flag){
        flag = strcmp(nome, database[i]->nome) == 0 && strcmp(cognome, database[i]->cognome) == 0;
        if (flag)
            idx = i;
        ++i;
    }
    return idx;
}
int studente_top_media(Studente **database, int DIM){
    int idx = 0;
    for (int i = 1; i < DIM; i++)
        if (database[i]->media > database[idx]->media)
            idx = i;
    return idx;
}