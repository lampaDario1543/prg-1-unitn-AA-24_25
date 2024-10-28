/*
scrivere un programma che prenda due file
- uno di testo
- l'altro con una mappa iniettiva tra caratteri
  e riscriva su un nuovo file il testo criptato secondo la mappa di caratteri.
*/

/*
mi aspetto che la mappa sia di tipo:
a: b
b: c
...
A: 2
B: 1
...
0: F
1: G
...
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
const int LEN = 256;
const int CAR = 2 + ('z' - 'a') + ('Z' - 'A') + 10; // 10 sono i numeri.

void cifra(char *msg, char[2][CAR]);

int main(int argc, char *argv[]){
    if (argc < 2){
        cerr << "Inserisci il nome di un file" << endl;
        exit(0);
    }
    fstream in;
    fstream map;
    char msg[LEN];
    char cifrario[2][CAR];
    // creo il file di output:
    fstream out("output.txt", ios::out);
    if (out.fail()){
        cerr << "Errore creazione file output.txt" << endl;
        exit(0);
    }
    map.open("mappa.txt", ios::in);
    if (map.fail()){
        cerr << "Il file di mappa non esiste." << endl;
        exit(0);
    }

    in.open(argv[1], ios::in);
    if (in.fail()){
        cerr << "Il file " << argv[1] << " non esiste." << endl;
        exit(0);
    }
    // salvo il file di input col messaggio nella stringa msg
    in.getline(msg, LEN);
    // leggo il file di mappa e lo salvo in un cifrario
    int i = 0;
    while (i < CAR && !map.eof()){
        char temp;
        map >> cifrario[0][i] >> temp >> cifrario[1][i]; // solo un temp perché a quanto apre ignora gli spazi
        ++i;
    }
    cifra(msg, cifrario);
    cout << "Messaggio cifrato con successo." << endl;
    cout << "[DEBUG] Salvo il messaggio sul file" << endl;
    out << msg;
    cout << "[DEBUG] file output.txt creato con successo." << endl;
    in.close();
    map.close();
    out.close();
    return 0;
}
void cifra(char *msg, char cifrario[2][CAR]){
    for (int i = 0; msg[i] != '\0'; i++){
        for (int j = 0; j < CAR; j++){
            if (msg[i] == cifrario[0][j]){
                msg[i] = cifrario[1][j];
                break;
            }
        }
    }
}