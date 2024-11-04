/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) un array di 10 interi e poi stampi a video tutti gli elementi
dell’array tramite una funzione, passando l’array come puntatore.
(i.e., potete usare i caratteri ‘[‘ e ‘]’ solo quando dichiarate l’array)
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 10;

void carica(int *);
void visualizza(int *);

int main(){
    int v[DIM];
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    carica(&v[0]);
    visualizza(&v[0]);
    return 0;
}

void carica(int *v){
    for (int i = 0; i < DIM; i++)
        *(v + i) = rand() % 10 + 1;
}

void visualizza(int *v){
    for (int i = 0; i < DIM; i++)
        cout << *(v + i) << " ";
    cout << endl;
}