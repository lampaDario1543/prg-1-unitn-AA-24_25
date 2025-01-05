/*
01:18:09 ore totali
    * es1: 23:05
    * es2: 10:00
    * es3: 45:01 PD.
*/

// Allowed include 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter

using namespace std;

const int MONTHS=12;
const int DAYS=31;

struct Paziente{
    float weight;
    int age;
    int glicemia[MONTHS][DAYS];
};

int Monitora(Paziente p, const int n, const int ipo, const int iper, int &ipoDays, float & avg, float &varianza);
float getAvg(int *, const int);

int main(int argc, char * argv[]){
    if(argc!=5){
        cerr << "Il numero di parametri e' diverso da 4. Errore!"<<endl;
        exit(1);
    }
    int n= atoi(argv[2]);
    int ipo= atoi(argv[3]);
    int iper= atoi(argv[4]);
    if(ipo> iper || ipo < 80 || ipo >95 || iper <105 || iper >120){
        cerr << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!"<<endl;
        exit(1);
    }
    if(n<1 || n> 12){
        cerr << "Il valore di mese non e' corretto. Errore!"<<endl;
        exit(1);
    }
    fstream in(argv[1],ios::in);
    if(in.fail()){
        cerr << "Il file non esiste. Errore!"<<endl;
        exit(1);
    }
    Paziente p;
    in >> p.weight >> p.age;
    for(int i=0;i<MONTHS;i++)
        for(int j=0;j<DAYS;j++)
            in >> p.glicemia[i][j];
    in.close();
    int ipoDays;
    int iperDays;
    float avg;
    float varianza;
    iperDays=Monitora(p,n,ipo,iper, ipoDays, avg, varianza);
    cout << "Il numero di giorni di iperglicemia e': " << iperDays<<endl;
    cout << "Il numero di giorni di ipoglicemia e': " << ipoDays<<endl;
    cout << "La media e': " << avg<<endl;
    cout << "La varianza e': " << varianza<<endl;
    return 0;
}

int Monitora(Paziente p, const int n, const int ipo, const int iper, int &ipoDays, float & avg, float &varianza){
    int iperDays=0;
    ipoDays=0;
    const int MONTH=n-1;
    for(int i=0;i< DAYS;i++){
        if(p.glicemia[MONTH][i]>iper) ++iperDays;
        if(p.glicemia[MONTH][i]<ipo) ++ipoDays;
    }
    avg=getAvg(p.glicemia[MONTH],DAYS);
    for(int i=0;i<DAYS;i++)
        varianza+=pow(p.glicemia[MONTH][i],2);
    varianza-=(DAYS*pow(avg,2));
    varianza/=DAYS;
    return iperDays;
}
float getAvg(int *v, const int DIM){
    float avg=0;
    for(int i=0;i<DIM;i++) avg+=v[i];
    return avg/DIM;
}