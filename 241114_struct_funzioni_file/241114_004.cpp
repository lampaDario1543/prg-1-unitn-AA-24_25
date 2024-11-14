/*
Scrivere un programma che utilizzi tutte le funzioni definite nei precedenti
esercizi per fornire delle funzionalità molto semplici di database per
memorizzare i dati degli studenti. La dimensione del database è fissata a priori a
100. Il programma dovrà permettere all’utente di eseguire le seguenti azioni:
● Aggiungere un utente al sistema (se si raggiunge la dimensione massima
notificare l’utente);
● Cercare un utente per matricola, nome/cognome e stamparlo a video (se
l’utente non esiste, notificare l’utente);
● Ritornare l’utente con la media ponderata più alta;
● Caricare gli studenti da un file esterno.
*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int LEN = 30;
const int DIM = 100;

struct Studente{
    char nome[LEN];
    char cognome[LEN];
    int matricola;
    float media;
};

void stampa_studente(Studente *);
void get_studente(char *, char *, int &, float &);
Studente *genera_studente(char *, char *, int, float);
void carica(Studente **, fstream &, int &);
int cerca_matricola(Studente **, int, int);
int cerca_nome_e_cognome(Studente **, char *, char *, int);
int studente_top_media(Studente **, int);
void add_student(Studente **, Studente *, int &, char *);
void delete_db(Studente **, const int);

int main(){
    char filename[LEN];
    int N;
    int current = 0;
    char opt = ' ';
    bool flag = true;
    char nome[LEN];
    char cognome[LEN];
    float media;
    int res_search = -1;
    int matricola = 0;
    // apertura del file e numero studenti + vari controlli.
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

    // inizializzo db, caricandolo:
    Studente *database[DIM];
    carica(database, in, current);
    in.close(); // chiudo in, non mi serve più
    while (flag){
        cout << "e - Esci" << endl;
        cout << "v - visualizza studenti nel db" << endl;
        cout << "m - cerca per matricola" << endl;
        cout << "n - cerca per nome e cognome" << endl;
        cout << "t - studente con media piu' alta" << endl;
        cout << "a - aggiungi studente" << endl;
        cout << "> ";
        cin >> opt;
        switch (opt){
        case 'e':
            flag = false;
            delete_db(database, current);
            break;
        case 'v':
            for (int i = 0; i < current; i++)
                stampa_studente(database[i]);
            cout << endl
                 << endl;
            break;
        case 'm':
            cout << "Matricola da cercare: ";
            cin >> matricola;
            if ((res_search = cerca_matricola(database, matricola, current)) != -1){
                cout << "Studente con matricola " << matricola << " trovato." << endl;
                stampa_studente(database[res_search]);
            }
            else
                cout << "Studente con matricola " << matricola << " non trovato." << endl;
            cout << endl
                 << endl;
            break;
        case 'n':
            // cerco per nome e cognome
            cout << "Nome cognome: ";
            cin >> nome >> cognome;
            if ((res_search = cerca_nome_e_cognome(database, nome, cognome, current)) != -1){
                cout << "Studente " << nome << " " << cognome << " trovato." << endl;
                stampa_studente(database[res_search]);
            }
            else
                cout << "Studente " << nome << " " << cognome << " non trovato." << endl;
            break;
        case 'a':
            get_studente(nome, cognome, matricola, media);
            add_student(database, genera_studente(nome, cognome, matricola, media), current, filename);
            break;
        case 't':
            cout << "Studente con la media piu' alta: " << endl;
            stampa_studente(database[studente_top_media(database, current)]);
            cout << endl
                 << endl;
            break;
        default:
            cout << "Opzione non riconosciuta." << endl
                 << endl;
            break;
        }
    }
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
    cout << "Studente: " << endl;
    cout << "Nome: " << s->nome << endl;
    cout << "Cognome: " << s->cognome << endl;
    cout << "Matricola: " << s->matricola << endl;
    cout << "Media: " << s->media << endl;
    cout << endl
         << endl;
}
void carica(Studente **database, fstream &in, int &cur){
    char nome[LEN], cognome[LEN];
    int matricola;
    float media;
    while (!in.eof()){ // forse meglio usare for
        in >> nome >> cognome >> matricola >> media;
        database[cur++] = genera_studente(nome, cognome, matricola, media);
    }
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
void add_student(Studente **db, Studente *s, int &cur, char *filename){
    if (cur == DIM){
        cout << "Non puoi inserire altri studenti. " << endl
             << endl;
        return;
    }
    fstream out;
    db[cur] = s;
    out.open(filename, ios::app);
    if (out.fail()){
        cerr << "Il file " << filename << " non esiste" << endl;
        exit(0);
    }
    out << endl
        << s->nome << " " << s->cognome << " " << s->matricola << " " << s->media;
    out.close();
    ++cur;
}
void delete_db(Studente **db, const int cur){
    for (int i = 0; i < cur; i++)
        delete db[i];
}