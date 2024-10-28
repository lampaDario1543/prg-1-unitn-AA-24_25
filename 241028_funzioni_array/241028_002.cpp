/*
Scrivere una funzione C++ che inizializzi (con valori random, il cui
massimo sia inserito dall’utente) un array di numeri interi. Scrivere poi
una funzione C++ che stampi a video tutti gli elementi di un array di
numeri interi. Scrivere una terza funzione C++ che permetta di contare
quanti numeri interi uguali sono allo stesso indice in due array di
interi. Si scriva un programma che testi le funzioni suddette.
02 - Uguaglianza
[3, 4, 0, 8, 6]
[4, 9, 0, 3, 6]

=> 2
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

void carica(int *, int);
void visualizza(int *);
int getSame(int *, int *);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int v[DIM], v1[DIM], max;
    do{
        cout << "Inserire valore massimo: ";
        cin >> max;
    } while (max < 0);
    carica(v, max);
    carica(v1, max);
    cout << "Arr1: ";
    visualizza(v);
    cout << "Arr2: ";
    visualizza(v1);
    cout << "Numeri uguali nello stesso indice " << getSame(v, v1) << endl;
    return 0;
}

void carica(int *v, int max){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % max;
}

void visualizza(int *v){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}
int getSame(int *v, int *v1){
    int ctr = 0;
    for (int i = 0; i < DIM; i++)
        if (v[i] == v1[i])
            ++ctr;
    return ctr;
}