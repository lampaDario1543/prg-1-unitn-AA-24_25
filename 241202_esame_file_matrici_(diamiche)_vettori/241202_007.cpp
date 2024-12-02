/*
Es. 1 Appello Settembre 2011

Scrivere un programma che, presi i nomi di due file da linea di
comando, copi il primo file nel secondo correggendone la sintassi.
Affinché un testo possa essere considerato corretto, la prima parola del
testo e tutte le parole dopo i caratteri “.”, “?” e “!” devono iniziare con
una lettera maiuscola.
Potete usare la libreria <fstream>.
Inoltre potete scrivere “input >> noskipws;” per impedire
all’operatore “>>” di skippare spazi bianchi e nuove linee
*/
#include <iostream>
#include <fstream>

using namespace std;
const int LEN = 255;

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Usage ./a.out <input_file> <output_file>" << endl;
        exit(0);
    }
    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if (in.fail()){
        cerr << "Il file non esiste." << endl;
        exit(0);
    }
    if (out.fail()){
        cerr << "Errore apertura output." << endl;
        exit(0);
    }
    char prev;
    char line[LEN];
    if (!in.eof()){
        in.getline(line, LEN);
        if (line[0] >= 'a' && line[0] <= 'z')
            line[0] -= ('a' - 'A');
        prev = line[0];
        for (int i = 1; line[i] != '\0'; i++){
            if (prev == '.' || prev == '!' || prev == '?' && (line[i] >= 'a' && line[i] <= 'z'))
                line[i] -= ('a' - 'A');
            prev = line[i];
        }
        out << line << endl;
    }
    while (!in.eof()){
        in.getline(line, LEN);
        for (int i = 0; line[i] != '\0'; i++){
            if (prev == '.' || prev == '!' || prev == '?' && (line[i] >= 'a' && line[i] <= 'z'))
                line[i] -= ('a' - 'A');
            prev = line[i];
        }
        out << line << endl;
    }
    in.close();
    out.close();
    return 0;
}