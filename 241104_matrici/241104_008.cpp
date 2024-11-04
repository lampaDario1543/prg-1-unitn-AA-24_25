/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) una matrice di 3x3 interi. Scrivere poi una funzione
che calcoli il prodotto dei valori di una determinata diagonale.
Usare infine questa funzione per calcolare il determinante
della matrice tramite la regola di Sarrus.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 3;

void carica(int[][DIM]);
int determinante(int[][DIM]);
void visualizza(int[][DIM]);
int diagonale_principale(int [][DIM], int,int);
int diagonale_inversa(int [][DIM], int,int);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int m[DIM][DIM];
    carica(m);
    visualizza(m);
    cout << "Determinante matrice: " << determinante(m) << endl;
    return 0;
}

void carica(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            m[i][j] = rand() % 10;
}
void visualizza(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int determinante(int m[DIM][DIM]){
    int det = 0;
    for (int i = 0; i < DIM; i++){
        det += diagonale_principale(m,0,i);
        det-=diagonale_inversa(m,i,0);
    }
    return det;
}
int diagonale_principale(int m[DIM][DIM],int r,int c){
    int prodotto=1;
    for (int i = 0; i < DIM; i++){
        if ((c + i) == DIM)
            c = (-i);
        prodotto *= m[r + i][c + i];
    }
    return prodotto;
}
int diagonale_inversa(int m[DIM][DIM],int r,int c){
    int prodotto=1;
    for (int i = 0; i < DIM; i++){
            if ((r - i) == -1)
                r = (DIM - 1) + i;
            prodotto *= m[r - i][c + i];
        }
    return prodotto;
}