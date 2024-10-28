/*
Scrivere una funzione C++ che dati come parametri un array di interi e la
sua dimensione n, trovi il massimo dell’array in modo ricorsivo. Si
scriva un programma che testi il corretto funzionamento della funzione.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void carica(int *, const int);
void visualizza(int *, const int);
int max(int *, const int);
int max(int *, const int, int, int);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    const int DIM = 10;
    int v[DIM];
    carica(v, DIM);
    visualizza(v, DIM);
    cout << "Max= " << max(v, DIM) << endl;
    return 0;
}

void carica(int *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % 100 + 1;
}
void visualizza(int *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}
int max(int *v, const int DIM){
    return max(v, DIM, 1, v[0]);
}
int max(int *v, const int DIM, int i, int m){
    if (i == DIM)
        return m;
    if (v[i] > m)
        return max(v, DIM, i + 1, v[i]);
    return max(v, DIM, i + 1, m);
}
