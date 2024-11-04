/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) una matrice di interi, la stampi a video, calcoli la
matrice trasposta e la stampi a video.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 4;

void carica(int[][DIM]);
void trasposta(int[][DIM]);
void visualizza(int[][DIM]);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int m[DIM][DIM];
    carica(m);
    visualizza(m);
    trasposta(m);
    visualizza(m);
    return 0;
}

void carica(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            m[i][j] = rand() % 100 + 1;
}
void visualizza(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}
void trasposta(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        int box;
        for (int j = i + 1; j < DIM; j++){
            box = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = box;
        }
    }
}