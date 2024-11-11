/*
Scrivere un programma che, dato in input da riga di comando il
nome di un file F, ritorni a video il conteggio di tutte le lettere
presenti all’interno del file. Il conteggio è case insensitive (quindi
non c’è differenza tra maiuscole e minuscole)
“Ciao come stai?”
a = 2
b = 0
c = 2
...
*/
#include <iostream>
#include <fstream>

using namespace std;

const int DIM=26;

void visualizza(int *);
void occ(int *, fstream &);
void init(int *v);

int main(int argc, char *argv[]){
    if(argc!=2){
        cerr << "use <filename>"<<endl;
        exit(0);
    }
    fstream in;
    in.open(argv[1],ios::in);
    if(in.fail()){
        cerr << argv[1] << " doesn't exists."<<endl;
        exit(0);
    }
    int v[DIM];
    init(v);
    occ(v,in);
    visualizza(v);
    return 0;
}

void init(int *v){
    for(int i=0;i< DIM;i++)
        v[i]=0;
}

void occ(int *v, fstream &in){
    char c=' ';
    while(!in.eof()){
        in >> c;
        if(!in.eof()){
            if(c>='A' && c<='Z')
                v[c-'A']++;
            else if(c>='a' && c<='z')
                v[c-'a']++;
        }
    }
}
void visualizza(int *v){
    cout << "Occorrenze: "<<endl <<endl;
    char c='a';
    for(int i=0;i<DIM;i++, c++)
        cout << c << ": "<< v[i]<<endl;
    cout << endl;
}