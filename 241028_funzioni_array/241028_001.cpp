/*
Scrivere una funzione C++ che inizializzi un array di 10 numeri interi
i cui elementi abbiano valori randomici compresi tra 0 e 9 inclusi.
Scrivere un’altra funzione C++ che stampi a video tutti gli elementi
di un array di numeri interi. Scrivere un programma C++ che testi il
buon funzionamento delle funzioni suddette.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

void carica(int *);
void visualizza(int *);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int v[DIM];
    carica(v);
    visualizza(v);
    return 0;
}

void carica(int *v){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % 10;
}

void visualizza(int *v){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}