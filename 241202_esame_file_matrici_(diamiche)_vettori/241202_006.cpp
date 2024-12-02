/*
- Es. 1 Appello Gennaio 2011

Sia dato in input un file contenente una sequenza di stringhe formate da
(massimo 10) ripetizioni dell’unico carattere * e separate da uno o più
spazi e ritorni a capo. Le stringhe rappresentano una sequenza di interi
positivi codificati in codice unario. Scrivere un programma che calcoli la
media dei valori contenuti nel file e la appenda a fine file in codice unario
(arrotondato per difetto). Usare solo le librerie <fstream> e <iostream>
*/
#include <iostream>
#include <fstream>

using namespace std;
const int LEN = 255;

int getAvg(fstream &);

int main(){
    char filename[255];
    cout << "<filename>: ";
    cin >> filename;
    fstream in;
    in.open(filename, ios::in);
    if (in.fail()){
        cerr << "Il file non esiste." << endl;
        exit(0);
    }
    int avg = getAvg(in);
    in.close();
    in.open(filename, ios::app);
    if (in.fail()){
        cerr << "Errore apertura file append." << endl;
        exit(0);
    }
    in << endl;
    for (int i = 0; i < avg; i++)
        in << "*";
    cout << "La media e' " << avg << endl;
    in.close();
    return 0;
}

int getAvg(fstream &in){
    char line[LEN];
    int sum = 0;
    int el = 0;
    bool flag = false;
    while (!in.eof()){
        in.getline(line, LEN);
        int i = 0;
        while (line[i] != '\0'){
            while (line[i] != ' ' && (flag = (line[i] != '\0'))){
                ++sum;
                ++i;
            }
            if (flag)
                ++i;
            ++el;
        }
    }
    return (sum / el);
}