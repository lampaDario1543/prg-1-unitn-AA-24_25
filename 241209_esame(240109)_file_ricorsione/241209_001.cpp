#include <iostream>
#include <fstream>

using namespace std;

const int LEN = 128;

void elaborariga(char *, int *, int &);
int converti(int *, const int);
int pow(int, int);
int somma(int *);

int main()
{
    fstream in, out;
    in.open("inputdati.txt", ios::in);
    if (in.fail())
    {
        cerr << "Il file non esiste." << endl;
        exit(0);
    }
    out.open("outputcheck.txt", ios::out);
    if (out.fail())
    {
        cerr << "Errore apertura output" << endl;
        exit(0);
    }
    // lettura:
    char line[LEN];
    int v[13];
    int ris = 0;
    int g[4] = {1, 0, 1, 0};
    while (!in.eof())
    {
        in.getline(line, LEN);
        elaborariga(line, v, ris);
        if (ris == somma(v))
            out << ris << endl;
        else
            out << "Errore" << endl;
    }
    in.close();
    out.close();
    return 0;
}
void elaborariga(char *s, int *v, int &ris){
    for (int i = 0; i < 13; i++)
        v[i] = 0;
    int i = 0;
    int j = 0;
    int b[8];
    while (s[i] != '=')
    {
        int dim = 0;
        while (s[i] != '+' && s[i] != '=')
        {
            b[dim] = s[i] - '0';
            ++dim;
            ++i;
        }
        v[j] = converti(b, dim);
        ++j;
        if (s[i] != '=')
            ++i;
    }
    j = 0;
    for (i = i + 1; s[i] != ';'; i++, j++)
        b[j] = s[i] - '0';
    ris = converti(b, j);
}

int pow(int base, int exp){
    int ris = base;
    if (exp == 0)
        return 1;
    for (int i = 1; i < exp; i++)
        ris *= base;
    return ris;
}

int converti(int *v, const int DIM){
    int res = 0;
    for (int i = 0; i < DIM; i++)
        res += (pow(2, DIM - i - 1)) * v[i];
    return res;
}
int somma(int *v){
    int sum = 0;
    for (int i = 0; i < 13; i++)
        sum += v[i];
    return sum;
}