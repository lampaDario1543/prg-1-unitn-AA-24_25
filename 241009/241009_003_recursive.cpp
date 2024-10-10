/*
scrivere una procedura che normalizzi un vettore, cioe' che
sostituisca un vettore con quello risultante dalla divisione di
tutti i suoi elementi per la sua norma.

IN MODO RICORSIVO
*/
#include <iostream>
#include <cmath>

using namespace std;

const int DIM = 4;

double prodotto_scalare(double *, double *, int);
double prodotto_scalare(double *, double *);
double calcola_norma(double *);
void normalizza_vet(double *);
void normalizza_vet(double *, int, int); //normalizza ricorsivo
void visualizza_vet(double *, int); //visualizza ricorsivo
void visualizza_vet(double *);
int main(){
    double vettore[DIM] = {1.0, 1.0, 1.0, 1.0};
    visualizza_vet(vettore);
    normalizza_vet(vettore);
    visualizza_vet(vettore);
    return 0;
}

double prodotto_scalare(double *a, double *b, int i){
    if(i==(DIM-1))
        return a[i]*b[i];
    else
        return (a[i]*b[i])+prodotto_scalare(a,b,i+1);
}

double prodotto_scalare(double *a, double *b){
    return prodotto_scalare(a,b,0);
}

double calcola_norma(double *v){
    double ps = prodotto_scalare(v, v);
    return sqrt(ps);
}

void visualizza_vet(double *v, int i){
    if(i==(DIM-1)){
        cout << v[i];
    }else{
        cout << v[i]<< ", ";
        return visualizza_vet(v,i+1);
    }
}

void visualizza_vet(double *v){
    cout << "vettore={";
    visualizza_vet(v,0);
    cout << "}" << endl;
}

void normalizza_vet(double *v, int i, int norma){
    if(i==(DIM-1)){
        v[i]/=norma;
        return;
    }else{
        v[i]/=norma;
        return normalizza_vet(v,i+1,norma);
    }
}

void normalizza_vet(double *v){
    double norma = 0;
    norma = calcola_norma(v);
    return normalizza_vet(v,0,norma);
}