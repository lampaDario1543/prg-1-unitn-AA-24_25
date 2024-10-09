/*
scrivere una procedura che calcoli la norma di un vettore di double
  (la radice quadrata del prodotto scalare con se' stesso).
*/
#include <iostream>
#include <cmath>

using namespace std;

const int DIM = 2;

double prodotto_scalare(double *, double *);
double calcola_norma(double *);

int main(){
    double norma = 0;
    double vettore[DIM] = {35.0, 60.0};
    norma = calcola_norma(vettore);
    cout << "La norma del vettore e' uguale a " << norma << endl;
    return 0;
}

double prodotto_scalare(double *a, double *b){
    double ris = 0;
    for (int i = 0; i < DIM; i++)
        ris += a[i] * b[i];
    return ris;
}
double calcola_norma(double *v){
    double ps = prodotto_scalare(v, v);
    return sqrt(ps);
}
