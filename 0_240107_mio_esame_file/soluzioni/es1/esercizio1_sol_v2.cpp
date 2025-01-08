#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// DO NOT MODIFY CODE ABOVE THIS LINE

struct Abbonamento
{
    int numero;
    char nome[32];
    char cognome[32];
    char tipo;
    double costo;
};

double ricavo(Abbonamento *abb, int N)
{
    double ricavo = 0;
    for (int i = 0; i < N; i++)
    {
        ricavo += abb[i].costo;
    }
    return ricavo;
}

char elabora(Abbonamento *abb, int N, double *parziali)
{
    for (int i = 0; i < 4; i++)
    {
        parziali[i] = 0;
    }
    double max = 0.0;
    char res = 'a';
    for (int i = 0; i < N; i++)
    {
        switch (abb[i].tipo)
        {
        case 'a':
            parziali[0] += abb[i].costo;
            if (parziali[0] > max)
            {
                max = parziali[0];
                res = 'a';
            }
            break;
        case 'm':
            parziali[1] += abb[i].costo;
            if (parziali[1] > max)
            {
                max = parziali[1];
                res = 'm';
            }
            break;
        case 's':
            parziali[2] += abb[i].costo;
            if (parziali[2] > max)
            {
                max = parziali[2];
                res = 's';
            }
            break;
        case 'g':
            parziali[3] += abb[i].costo;
            if (parziali[3] > max)
            {
                max = parziali[3];
                res = 'g';
            }
            break;
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        exit(1);
    }

    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (ifs.fail())
    {
        cerr << "Cannot open the input file " << argv[1] << endl;
        exit(2);
    }

    int N;
    ifs >> N;

    Abbonamento *abb = new Abbonamento[N];
    for (int i = 0; !ifs.eof() && !ifs.fail() && i < N; i++)
    {
        ifs >> abb[i].numero >> abb[i].nome >> abb[i].cognome >> abb[i].tipo;
        switch (abb[i].tipo)
        {
        case 'a':
            abb[i].costo = 500.00;
            break;
        case 'm':
            abb[i].costo = 150.00;
            break;
        case 's':
            abb[i].costo = 50.00;
            break;
        case 'g':
            abb[i].costo = 10.00;
            break;
        default:
            cerr << "Tipo abbonamento non valido" << endl;
            ifs.close();
            delete[] abb;
            exit(1);
        }
    }
    ifs.close();

    double ricavototale = ricavo(abb, N);

    cout << "Ricavo totale: " << ricavototale << endl;

    double ricaviparziali[4];

    char tipo = elabora(abb, N, ricaviparziali);

    ofstream ofs;
    ofs.open("risultati.txt", ios::out);
    if (ofs.fail())
    {
        cerr << "Cannot open the output file risultati.txt" << endl;
        delete[] abb;
        exit(3);
    }

    for (int i = 0; i < N; i++)
    {
        // cout << abb[i].numero << " " << abb[i].nome << " " << abb[i].cognome << " " << abb[i].tipo << " " << abb[i].costo << endl;
        if (abb[i].tipo == tipo)
        {
            ofs << abb[i].numero << " " << abb[i].nome << " " << abb[i].cognome << " " << abb[i].tipo << " " << abb[i].costo << endl;
        }
    }
    ofs.close();

    delete[] abb;
}