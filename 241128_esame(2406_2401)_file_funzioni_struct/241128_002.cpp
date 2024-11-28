#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
const int MAX_LEN = 127;
const int DIM = 13;

void elaborariga(char *, int *, int &);
int converti(int *, int);
int somma(int *, const int);

int main(){
    char str[MAX_LEN];
    int num[DIM];
    int ris;
    fstream in, out;
    in.open("inputdati.txt", ios::in);
    if (in.fail()){
        cerr << "Errore inputdati.txt non esiste." << endl;
        exit(0);
    }
    out.open("outputcheck.txt", ios::out);
    if (out.fail()){
        cerr << "Errore outputcheck.txt." << endl;
        exit(0);
    }
    while (!in.eof()){
        in.getline(str, MAX_LEN);
        cout << str << endl;
        elaborariga(str, num, ris);
        int s = somma(num, DIM);
        if (s == ris)
            out << ris << endl;
        else
            out << "Errore" << endl;
    }
    in.close();
    out.close();
    return 0;
}
void elaborariga(char *str, int *num, int &ris){
    int i = 0;
    int num_idx = 0;
    int bin[8];
    int j = 0;
    while (str[i] != '='){
        j = 0;
        while (str[i] != '+' && str[i] != '='){
            bin[j] = (str[i] - '0');
            ++j;
            ++i;
        }
        num[num_idx] = converti(bin, j - 1);
        ++num_idx;
        if (str[i] != '=')
            ++i;
    }
    for (; num_idx < DIM; num_idx++)
        num[num_idx] = 0;
    for (i = i + 1, j = 0; str[i] != ';'; i++, j++)
        bin[j] = (str[i] - '0');
    ris = converti(bin, j - 1);
}
int converti(int *v, int len){
    int ris = 0;
    for (int i = 0; i <= len; i++)
        ris += v[i] * pow(2, (len - i));
    return ris;
}

int somma(int *v, const int dim){
    int s = 0;
    for (int i = 0; i < dim; i++)
        s += v[i];
    return s;
}