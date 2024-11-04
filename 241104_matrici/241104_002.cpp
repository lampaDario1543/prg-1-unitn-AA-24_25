/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) una matrice di interi e poi stampi a video tutti gli
elementi della matrice.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 10;

void carica(int[][DIM]);
void visualizza(int[][DIM]);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int m[DIM][DIM];
    carica(m);
    visualizza(m);
    return 0;
}

void carica(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            m[i][j] = rand() % 100 + 1;
    }
}
void visualizza(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}