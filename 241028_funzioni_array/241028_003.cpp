/*
Scrivere un programma C++ che, sfruttando le funzioni scritte per
l’esercizio 01, dichiari e poi inizializzi (con valori random tra 0 e 9)
un array di 10 numeri interi e lo stampi a video. Il programma
chiami poi una funzione che calcoli la media dei valori degli
elementi dell’array, il valore massimo e il valore minimo.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

void carica(int *);
void visualizza(int *);
double media(int *);
int max(int *);
int min(int *);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int v[DIM];
    carica(v);
    visualizza(v);
    cout << "Media= " << media(v) << endl;
    cout << "Max= " << max(v) << endl;
    cout << "Min= " << min(v) << endl;
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
double media(int *v){
    int s = 0;
    double m = 0;
    for (int i = 0; i < DIM; i++)
        s += v[i];
    m = (double)s / DIM;
    return m;
}
int max(int *v){
    int max = v[0];
    for (int i = 1; i < DIM; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

int min(int *v){
    int min = v[0];
    for (int i = 1; i < DIM; i++)
        if (v[i] < min)
            min = v[i];
    return min;
}