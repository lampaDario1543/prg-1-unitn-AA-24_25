#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// DO NOT MODIFY CODE ABOVE THIS LINE
const int LEN=32; //con terminatore

struct Abbonamento{
    int numero;
    char nome[LEN];
    char cognome[LEN];
    char tipo;
    float costo;
};

float ricavo(Abbonamento *abb, const int N);
char elabora(Abbonamento *abb, const int N, float *r);

int main(int argc, char *argv[]){
    if(argc!=2){
        cerr << "Usage "<< argv[0]<< " <filename_abbonamenti>"<<endl;
        exit(1);
    }
    fstream in(argv[1], ios::in);
    if(in.fail()){
        cerr << "Il file " <<argv[1] << " non esiste." <<endl;
        exit(1);
    }
    int N=0;
    if(!(in >> N)){
        in.close();
        cerr << "Errore leggendo il file."<<endl;
        exit(1);
    }
    Abbonamento *abb = new Abbonamento[N];
    for(int i=0;i<N;i++){
        in >> abb[i].numero >> abb[i].nome >> abb[i].cognome >> abb[i].tipo;
        switch(abb[i].tipo){
            case 'a': //stagionale
                abb[i].costo=500;
                break;
            case 'm': //mensile
                abb[i].costo=150;
                break;
            case 's'://settimanale
                abb[i].costo=50;
                break;
            case 'g'://giornaliero
                abb[i].costo=10;
                break;
            default:
                cout << "Errore il file e' contiene un errore."<<endl;
                break;
        }
    }
    in.close();
    float ric_tot=ricavo(abb, N);
    cout << "Ricavo totale: "<< ric_tot<<endl;
    float r[4];
    char max=elabora(abb, N, r);
    fstream out("risultati.txt",ios::out);
    if(out.fail()){
        delete [] abb;
        cerr << "Errore creazione file risultati.txt"<<endl;
        exit(1);
    }
    for(int i=0;i<N;i++){
        if(abb[i].tipo==max){
            out << abb[i].numero <<" "<< abb[i].nome <<" "<< abb[i].cognome <<" "<< abb[i].tipo <<" "<< abb[i].costo<<endl;
        }
    }
    delete [] abb;
    out.close();
    return 0;
}

float ricavo(Abbonamento *abb, const int N){
    float tot=0;
    float spese=0;
    for(int i=0;i<N;i++){
        const float costo=abb[i].costo;
        tot+=costo;
        spese+=(10/100)*costo;
    }
    return (tot-spese);
}

char elabora(Abbonamento *abb, const int N, float *r){
    for(int i=0;i<4;i++) r[i]=0;
    for(int i=0;i< N;i++){
        switch(abb[i].tipo){
            case 'a':
                r[0]+=abb[i].costo;
                break;
            case 'm':
                r[1]+=abb[i].costo;
                break;
            case 's':
                r[2]+=abb[i].costo;
                break;
            case 'g':
                r[3]+=abb[i].costo;
                break;
            default:
                break;
        }
    }
    int max=0; //max_index
    for(int i=1;i<4;i++)
        if(r[i]>r[max]) max=i;
    char res;
    switch(max){
        case 0:
            res='a';
            break;
        case 1:
            res='m';
            break;
        case 2:
            res='s';
            break;
        case 3:
            res='g';
            break;
    }
    return res;
}