/*
Realizzare una struttura dati "archivio di studenti" dove gli
   studenti siano ordinati sia per cognome sia per numero di
   matricola.
*/
#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 30;
const int DIM = 100;

struct studente
{
    char name[LEN];
    char sur[LEN];
    char mat[10];
};

struct archivio
{
    int n_studenti;
    studente studenti[DIM];
};

void init_arc(archivio &);
void leggi_studente(studente &);
void stampa_studente(const studente &);
void inserisci_studente(const studente &, archivio &);
void stampa_archivio(const archivio &);
void ordina(archivio &, const bool flag = false);
void swap(studente &a, studente &b);

int main(){
    archivio a;
    init_arc(a);
    studente c;
    char opt = ' ';
    bool flag = true;
    do{
        cout << "i - inserisci studente" << endl;
        cout << "v - visualizza archivio per cognome" << endl;
        cout << "m - visualizza archivio per matricola" << endl;
        cout << "e - esci" << endl;
        cout << endl;
        cout << "> ";
        cin >> opt;
        switch (opt){
        case 'i':
            leggi_studente(c);
            inserisci_studente(c, a);
            break;
        case 'v':
            cout << endl;
            ordina(a);
            stampa_archivio(a);
            break;
        case 'm':
            cout << endl;
            ordina(a, true);
            stampa_archivio(a);
            break;
        case 'e':
            flag = false;
            break;
        default:
            break;
        }
    } while (flag);
    return 0;
}

void stampa_studente(const studente &c){
    cout << "Nome: " << c.name << endl;
    cout << "Cognome: " << c.sur << endl;
    cout << "Matricola: " << c.mat << endl;
    cout << endl
         << endl;
}

void leggi_studente(studente &c){
    cout << "Nome: ";
    cin >> c.name;
    cout << "Cognome: ";
    cin >> c.sur;
    cout << "Matricola: ";
    cin >> c.mat;
    cout << endl;
}

void init_arc(archivio &a){
    a.n_studenti = 0;
}

void inserisci_studente(const studente &c, archivio &a){
    if (a.n_studenti == DIM - 1){
        cout << "Archivio piena." << endl;
        return;
    }
    a.studenti[a.n_studenti] = c;
    ++a.n_studenti;
}
void stampa_archivio(const archivio &a){
    if (a.n_studenti == 0){
        cout << "Non ci sono studenti in archivio." << endl
             << endl;
        return;
    }
    for (int i = 0; i < a.n_studenti; i++){
        cout << "Contatto " << (i + 1) << ":" << endl;
        stampa_studente(a.studenti[i]);
    }
}

void swap(studente &a, studente &b){
    studente box;
    box = a;
    a = b;
    b = box;
}

void ordina(archivio &a, const bool flag){
    if (flag){ // ordino per matricola
        for (int i = 0; i < a.n_studenti - 1; i++){
            for (int j = i + 1; j < a.n_studenti; j++)
                if (strcmp(a.studenti[i].mat, a.studenti[j].mat) > 0)
                    swap(a.studenti[i], a.studenti[j]);
        }
    }
    else{
        for (int i = 0; i < a.n_studenti - 1; i++){
            for (int j = i + 1; j < a.n_studenti; j++)
                if (strcmp(a.studenti[i].sur, a.studenti[j].sur) > 0)
                    swap(a.studenti[i], a.studenti[j]);
        }
    }
}