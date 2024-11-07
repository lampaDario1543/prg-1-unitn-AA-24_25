/*
Scrivere un programma che, dati in input da linea di comando
i nomi di due file, A e B, copi il contenuto di A all’interno di B.
Implementare anche dei controlli che avvisino l’utente in caso
il numero di argomenti sia sbagliato (manca il file di input)
oppure nel caso in cui il file di input non esista.
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void copy_file(char *, char *);

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Inserire il nome dei file." << endl;
        exit(0);
    }
    if (strcmp(argv[1], argv[2]) == 0){
        cerr << "I file non possono avere lo stesso nome." << endl;
        exit(0);
    }
    copy_file(argv[1], argv[2]);
    return 0;
}

void copy_file(char *in_name, char *out_name){
    fstream in;
    in.open(in_name, ios::in);
    if (in.fail()){
        cerr << "Il file " << in_name << " non esiste." << endl;
        exit(0);
    }
    fstream out;
    out.open(out_name, ios::out);
    if (out.fail()){
        cerr << "Errore apertura file " << out_name << endl;
        exit(0);
    }
    char c;
    while (!in.eof()){
        in.get(c);
        out << c;
    }
    cout << "File copiato con successo." << endl;
    in.close();
    out.close();
}