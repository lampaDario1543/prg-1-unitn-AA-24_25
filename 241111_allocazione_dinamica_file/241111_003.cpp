/*
Scrivere un programma che, dato un file in input da linea di comando
contenente diverse temperature. Il file è costituito da una sola colonna
e le temperature sono rappresentate come numeri reali. Il programma
salvi queste temperature in un array dinamico e stampi a video le
prime N temperature più alte. Il valore N viene specificato dall’utente
da linea di comando. Il programma accetta anche un intero M che
indica quante temperature al massimo sono presenti nel file.

27.5
34.3
13.2
...
*/
#include <iostream>
#include <fstream>

using namespace std;

void sort(double *, const int);
void visualizza(double *, const int);
void swap(double &, double &);

int main(int argc, char *argv[]){
    if (argc != 4){
        cerr << "Use <filename> <N> <M>" << endl;
        exit(0);
    }
    const int N = atoi(argv[2]);
    const int M = atoi(argv[3]);
    if (M <= 0){
        cerr << "M must be > 0" << endl;
        exit(0);
    }
    if (N <= 0){
        cerr << "M must be > 0" << endl;
        exit(0);
    }
    double *v = new double[M];
    fstream in;
    in.open(argv[1], ios::in);
    if (in.fail()){
        cerr << argv[1] << " doesn't exists." << endl;
        exit(0);
    }
    int i = 0;
    while (!in.eof())
        in >> v[i++];
    visualizza(v, M);
    sort(v, M);
    visualizza(v, N);
    in.close();
    delete[] v;
    return 0;
}

void visualizza(double *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}

void sort(double *v, const int DIM){
    for (int i = 0; i < DIM - 1; i++){
        for (int j = i + 1; j < DIM; j++)
            if (v[i] < v[j])
                swap(v[i], v[j]);
    }
}
void swap(double &a, double &b){
    double box;
    box = a;
    a = b;
    b = box;
}