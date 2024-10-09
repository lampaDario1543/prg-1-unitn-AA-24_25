/*
scrivere una procedura che normalizzi un vettore, cioe' che
sostituisca un vettore con quello risultante dalla divisione di
tutti i suoi elementi per la sua norma.
*/
#include <iostream>
#include <cmath>

using namespace std;

const int DIM = 4;

double prodotto_scalare(double *, double *);
double calcola_norma(double *);
void normalizza_vet(double *);
void visualizza_vet(double *);
int main(){
    double vettore[DIM] = {1.0, 1.0, 1.0, 1.0};
    normalizza_vet(vettore);
    visualizza_vet(vettore);
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
void visualizza_vet(double *v){
    cout << "vettore={";
    for (int i = 0; i < DIM; i++){
        if (i != DIM - 1)
            cout << v[i] << ", ";
        else
            cout << v[i];
    }
    cout << "}" << endl;
}
void normalizza_vet(double *v){
    double norma = 0;
    norma = calcola_norma(v);
    for (int i = 0; i < DIM; i++)
        v[i] /= norma;
}