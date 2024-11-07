/*
Scrivere un programma che, dato in input da linea di
comando il nome di un file, ritorni a video il contenuto del
suddetto file. Implementare anche dei controlli che avvisino
l’utente in caso il numero di argomenti sia sbagliato (manca il
file di input) oppure nel caso in cui il file di input non esista.
*/
#include <iostream>
#include <fstream>

const int LEN = 80;

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 2){
        cerr << "Inserire il nome del file." << endl;
        exit(0);
    }
    fstream in;
    in.open(argv[1], ios::in);
    if (in.fail()){
        cerr << "Il file non esiste." << endl;
        exit(0);
    }
    char str[LEN];
    char c;
    while (!in.eof()){ // leggo char by char :<
        in.get(c);
        cout << c;
    }
    cout << endl;
    in.close();
    return 0;
}