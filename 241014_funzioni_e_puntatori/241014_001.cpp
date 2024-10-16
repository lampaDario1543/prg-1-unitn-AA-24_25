/*
Dati in input due reali (double) in due variabili, scrivere un
programma che usi una procedura per scambiare i valori
delle due variabili usando il passaggio di parametri per
puntatore.
*/

#include <iostream>

using namespace std;

void swap(double *, double *);

int main(){
    double a = 5.3;
    double b = 3.2;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    swap(&a, &b);
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    return 0;
}

void swap(double *a, double *b){
    double box;
    box = *a;
    *a = *b;
    *b = box;
}