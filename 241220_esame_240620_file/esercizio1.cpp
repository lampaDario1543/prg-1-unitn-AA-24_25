// Allowed include
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter
using namespace std;

const int DAYS = 31;
const int MONTHS = 12;

struct Paziente
{
    double weight;
    int age;
    int glicemia[MONTHS][DAYS];
};

bool readFile(Paziente &p, fstream &in);
int Monitora(const Paziente &, const int, const int, const int, int &giorni_ipo, double &val_medio, double &varianza);
double getAvg(const int *);
double getVarianza(const int *, double);

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        cerr << "Il numero di parametri e’ diverso da 4. Errore!" << endl;
        exit(1);
    }
    char *filename = argv[1];
    int n = atoi(argv[2]);
    int ipo = atoi(argv[3]);
    int iper = atoi(argv[4]);
    if (ipo > iper || ipo > 95 || ipo < 80 || iper < 105 || iper > 120)
    {
        cerr << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!" << endl;
        exit(1);
    }
    if (n < 1 || n > 12)
    {
        cerr << "Il valore del mese non e' corretto. Errore!" << endl;
        exit(1);
    }
    fstream in(filename, ios::in);
    if (in.fail())
    {
        cerr << "Il file non esiste. Errore!" << endl;
        exit(1);
    }
    Paziente p;
    if (!readFile(p, in))
    {
        in.close();
        cerr << "Errore lettura file." << endl;
        exit(1);
    }
    in.close();
    int giorni_ipo;
    double val_medio;
    double varianza;
    const int giorni_iper = Monitora(p, n, ipo, iper, giorni_ipo, val_medio, varianza);
    cout << "Il numero di giorni di iperglicemia e': " << giorni_iper << endl;
    cout << "Il numero di giorni di ipoglicemia e': " << giorni_ipo << endl;
    cout << "la media e': " << val_medio << endl;
    cout << "la varianza e' : " << varianza << endl;
    return 0;
}

bool readFile(Paziente &p, fstream &in)
{
    if (in >> p.weight >> p.age)
    {
        for (int i = 0; i < MONTHS; i++)
        {
            for (int j = 0; j < DAYS; j++)
            {
                if (!(in >> p.glicemia[i][j]))
                    return false;
            }
        }
    }
    else
        return false; // il file è vuoto
    return true;
}

int Monitora(const Paziente &p, const int MONTH, const int IPO, const int IPER, int &giorni_ipo, double &val_medio, double &varianza)
{
    int giorni_iper = 0;
    giorni_ipo = 0;
    for (int i = 0; i < DAYS; i++)
    {
        const int VAL = p.glicemia[MONTH - 1][i];
        if (VAL > IPER)
            ++giorni_iper;
        if (VAL < IPO)
            ++giorni_ipo;
    }
    val_medio = getAvg(p.glicemia[MONTH - 1]);
    varianza = getVarianza(p.glicemia[MONTH - 1], val_medio);
    return giorni_iper;
}
double getAvg(const int *v)
{
    int s = 0;
    for (int i = 0; i < DAYS; i++)
        s += v[i];
    return (double)s / DAYS;
}
double getVarianza(const int *v, double val_medio)
{
    double varianza = 0;
    for (int i = 0; i < DAYS; i++)
        varianza += pow(v[i], 2);
    varianza -= DAYS * pow(val_medio, 2);
    varianza /= DAYS;
    return varianza;
}