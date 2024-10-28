/*
Scrivere un programma C++ che, sfruttando le funzioni scritte per
l’esercizio 01, dichiari e poi inizializzi (con valori random tra 0 e 9) un
array di 10 numeri interi e lo stampi a video. Il programma chiami una
terza funzione che inverta l’array. Tale array inverito venga poi stampato
dal programma.

[3, 4, 0, 8, 6] => [6, 8, 0, 4, 3]
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

void carica(int *);
void visualizza(int *);
void reverse(int *);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int v[DIM];
    carica(v);
    visualizza(v);
    reverse(v);
    cout << "Array invertito: ";
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
void reverse(int *v){
    for (int i = 0; i < DIM / 2; i++){
        int box = v[i];
        v[i] = v[DIM - i - 1];
        v[DIM - i - 1] = box;
    }
}