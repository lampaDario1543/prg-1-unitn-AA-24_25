/*scrivere una funzione che prenda come parametri 2 array di double
  della stessa dimensione e ne calcoli il prodotto scalare.
  a[0]*b[0] + ... + a[i]*b[i] + ... + a[dim-1]*b[dim-1]
  
  IN MODO RICORSIVO
  */
#include <iostream>

using namespace std;

const int DIM=3;

double prodotto_scalare(double *, double *, int);
double prodotto_scalare(double *, double *);

int main(){
    double a[DIM]={1.5,2.5,3.5};
    double b[DIM]={0.69,1.5,5.5};
    double ris= prodotto_scalare(a,b);
    cout << "Il prodotto scalare fa: "<<ris<<endl;
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