#include <iostream>
#include <fstream>

// Inserire qui sotto la soluzione all'esercizio
using namespace std;

double Percentuale(const int , const int);
int getLenght(fstream &, char *);
void getData(double *, fstream &);
int getE1gtE2(const double *, const double *, const int);

int main(int argc, char *argv[]){
    if(argc!=3){
        cerr << "Usage "<< argv[0] << " <filename1> <filename2>"<<endl;
        exit(1);
    }
    fstream m1(argv[1], ios::in);
    if(m1.fail()){
        cerr << argv[1] << " doesn't exists."<<endl;
        exit(1);
    }
    fstream m2(argv[2], ios::in);
    if(m2.fail()){
        m1.close();
        cerr << argv[2] << " doesn't exists."<<endl;
        exit(1);
    }
    const int MISURAZIONI=getLenght(m1, argv[1]);
    if(MISURAZIONI==0){
        cout << "Il numero delle misurazioni e' uguale a 0, per cui non posso calcolare la percentuale."<<endl;
        exit(1);
    }
    double *engine1= new double[MISURAZIONI]; 
    double *engine2= new double[MISURAZIONI];
    getData(engine1, m1);
    getData(engine2, m2);
    double p=Percentuale(getE1gtE2(engine1, engine2, MISURAZIONI), MISURAZIONI);
    cout << "La percentuale di misurazioni in cui la temperature del motore1 ha superato quella del motore2 e' del "<< p <<"%"<<endl;
    delete []engine1;
    delete []engine2;
    m1.close();
    m2.close();
    return 0;
}

double Percentuale(const int volte, const int DIM){
    return ((double)volte/DIM)*100;
}

int getLenght(fstream &f, char *filename){
    double n;
    int ctr=0;
    while(f >> n) ++ctr;
    f.close();
    f.open(filename, ios::in);
    return ctr;
}
void getData(double *v, fstream &f){
    int i=0;
    while(f >> v[i]) ++i;
}

int getE1gtE2(const double *e1, const double *e2, const int DIM){
    int ctr=0;
    for(int i=0;i<DIM;i++)
        if(e1[i]>e2[i]) ++ctr;
    return ctr;
}