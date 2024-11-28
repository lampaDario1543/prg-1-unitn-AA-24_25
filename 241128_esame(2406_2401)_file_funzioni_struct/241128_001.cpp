// input sample ./241128_001 Paziente1.txt 3 91 111
#include <iostream>
#include <fstream>

using namespace std;

const int ROW = 12;
const int COL = 31;

struct Paziente
{
    double weight;
    int age;
    int gli[ROW][COL];
};

void leggi(Paziente *&, fstream &);
// void visualizza(Paziente *); //[debug]
int monitora(Paziente *, int, int, int, int &, double &, double &);
double average(int *);
int sum(int *);

int main(int argc, char *argv[]){
    if (argc != 5){
        cerr << "Il numero di parametri e' diverso da 4. Errore!" << endl;
        exit(0);
    }
    int n, ipo, iper;
    char *filename;
    filename = argv[1];
    n = atoi(argv[2]);
    ipo = atoi(argv[3]);
    iper = atoi(argv[4]);
    if (ipo > iper || ipo < 80 || ipo > 95 || iper < 105 || iper > 120){
        cerr << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!" << endl;
        exit(0);
    }
    if (n < 1 || n > 12){
        cerr << "Il mese e' sbagliato. Errore!" << endl;
        exit(0);
    }
    fstream in;
    in.open(filename, ios::in);
    if (in.fail()){
        cerr << "Il file non esiste. Errore!" << endl;
        exit(0);
    }
    Paziente *p = new Paziente;
    leggi(p, in);
    // visualizza(p);
    int dd_iper, dd_ipo;
    double avg, sigma;
    dd_iper = monitora(p, n, ipo, iper, dd_ipo, avg, sigma);
    cout << "Il numero di giorni di iperglicemia e': " << dd_iper << endl;
    cout << "Il numero di giorni di ipoglicemia e': " << dd_ipo << endl;
    cout << "la media e': " << avg << endl;
    cout << "la varianza e': " << sigma << endl;
    delete p;
    in.close();
    return 0;
}
void leggi(Paziente *&p, fstream &in){
    in >> p->weight >> p->age;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            in >> p->gli[i][j];
}
int monitora(Paziente *p, int month, int ipo, int iper, int &dd_ipo, double &avg, double &sigma){
    int dd_iper = 0;
    dd_ipo = 0;
    int *v = p->gli[month - 1];
    for (int i = 0; i < COL; i++){
        if (v[i] > iper)
            ++dd_iper;
        if (v[i] < ipo)
            ++dd_ipo;
    }
    avg = average(v);
    sigma = (sum(v) - (COL * avg * avg)) / COL;
    return dd_iper;
}
double average(int *v){
    double s = 0;
    for (int i = 0; i < COL; i++)
        s += v[i];
    return (s / COL);
}

int sum(int *v){
    int s = 0;
    for (int i = 0; i < COL; i++)
        s += (v[i] * v[i]);
    return s;
}

/*
//[debug]
void visualizza(Paziente *p){
    cout << "Age: " << p->age<<endl;
    cout << "Weight: " << p->weight<<endl;
    for(int i=0;i< ROW;i++){
        for(int j=0;j<COL;j++)
            cout << p->gli[i][j] << " ";
        cout << endl;
    }
}
*/