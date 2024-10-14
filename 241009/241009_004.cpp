/*
scrivere una funzione che dica se due vettori della stessa
dimensione sono ortogonali (due vettori sono ortogonali se il loro
prodotto scalare e' nullo).
*/
#include <iostream>

using namespace std;

const int DIM = 3;

double prodotto_scalare(double *, double *);
bool isOrtogonale(double *, double *);

int main(){
    // esempio vettori ortogonali:
    /*
    double a[DIM] = {1.0, 2.0, 3.0};
    double b[DIM] = {4.0, -8.0, 4.0};
    */
    // esempio vettori non ortogonali:
    double a[DIM] = {2.0, 2.0, 2.0};
    double b[DIM] = {1.0, 1.0, 1.0};
    if (isOrtogonale(a, b))
        cout << "I due vettori sono ortogonali." << endl;
    else
        cout << "I due vettori non sono ortogonali." << endl;
    return 0;
}

double prodotto_scalare(double *a, double *b){
    double ris = 0;
    for (int i = 0; i < DIM; i++)
        ris += a[i] * b[i];
    return ris;
}
bool isOrtogonale(double *a, double *b){
    return prodotto_scalare(a, b) == 0;
}