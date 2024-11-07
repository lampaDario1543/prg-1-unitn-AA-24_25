/*
2) Realizzare una rubrica telefonica.
*/
#include <iostream>

using namespace std;

const int LEN = 30;
const int DIM = 100;

struct studente{
    char name[LEN];
    char sur[LEN];
    char tel[10];
};

struct rubrica{
    int n_contatti;
    studente persone[DIM];
};

void init_rub(rubrica &);
void leggi_contatto(studente &);
void stampa_contatto(const studente &);
void inserisci_contatto(const studente &, rubrica &);
void stampa_rubrica(const rubrica &r);

int main(){
    rubrica r;
    init_rub(r);
    studente c;
    char opt = ' ';
    bool flag = true;
    do{
        cout << "i - inserisci studente" << endl;
        cout << "v - visualizza rubrica" << endl;
        cout << "e - esci" << endl;
        cout << endl;
        cout << "> ";
        cin >> opt;
        switch (opt){
        case 'i':
            leggi_contatto(c);
            inserisci_contatto(c, r);
            break;
        case 'v':
            cout << endl;
            stampa_rubrica(r);
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

void stampa_contatto(const studente &c){
    cout << "Nome: " << c.name << endl;
    cout << "Cognome: " << c.sur << endl;
    cout << "Telefono: " << c.tel << endl;
    cout << endl
         << endl;
}

void leggi_contatto(studente &c){
    cout << "Nome: ";
    cin >> c.name;
    cout << "Cognome: ";
    cin >> c.sur;
    cout << "Telefono: ";
    cin >> c.tel;
    cout << endl;
}

void init_rub(rubrica &r){
    r.n_contatti = 0;
}

void inserisci_contatto(const studente &c, rubrica &r){
    if (r.n_contatti == DIM - 1){
        cout << "Rubrica piena." << endl;
        return;
    }
    r.persone[r.n_contatti] = c;
    ++r.n_contatti;
}
void stampa_rubrica(const rubrica &r){
    if (r.n_contatti == 0){
        cout << "Non ci sono contatti in rubrica." << endl
             << endl;
        return;
    }
    for (int i = 0; i < r.n_contatti; i++){
        cout << "Contatto " << (i + 1) << ":" << endl;
        stampa_contatto(r.persone[i]);
    }
}