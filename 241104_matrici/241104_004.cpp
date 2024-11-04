/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) una matrice quadrata di interi, la stampi a video,
calcoli la somma degli elementi nel triangolo superiore della
matrice e la stampi a video.
*/
/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) una matrice di interi, la stampi a video, calcoli la
matrice trasposta e la stampi a video.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 3;

void carica(int[][DIM]);
int somma_sup(int[][DIM]);
void visualizza(int[][DIM]);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int m[DIM][DIM];
    carica(m);
    visualizza(m);
    cout << "Somma superiore= " << somma_sup(m) << endl;
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
int somma_sup(int m[DIM][DIM]){
    int s = 0;
    for (int i = 0; i < DIM; i++){
        for (int j = i; j < DIM; j++)
            s += m[i][j];
    }
    return s;
}