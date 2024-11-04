/*
Una tecnica che spesso si applica ai dati contenuti in una matrice consiste nel sostituire a
ciascun elemento della matrice la media degli elementi che lo circondano. Tale tecnica è detta
filtro medio. In un filtro medio, ciascun elemento della matrice è sostituito dalla media dei
quattro elementi che si trovano sopra, sotto, a destra e a sinistra dell’elemento specificato. Ad
esempio, data la matrice A qui sotto, la matrice B è il risultato dell’applicazione del filtro
mediano semplificato alla matrice A:

https://imgur.com/a/xtLoKdu

Si scriva una funzione che riceva in input una matrice di numeri reali A di 10 righe e 10 colonne e
una matrice di numeri reali B delle stesse dimensioni di A. La funzione assegnerà a ogni elemento
della matrice B la media degli elementi che si trovano sopra, sotto, a destra e a sinistra
dell’elemento corrispondente della matrice A. Si testi la funzione tramite un main opportuno, che
inizializza A con numeri random compresi tra 0 e 9.


*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 10;

void carica(double[][DIM]);
void filtro_medio(double[][DIM], double [][DIM]);
void visualizza(double[][DIM]);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    double a[DIM][DIM];
    double b[DIM][DIM];
    carica(a);
    visualizza(a);
    filtro_medio(a,b);
    visualizza(b);
    return 0;
}

void carica(double m[DIM][DIM]){
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            m[i][j] = rand() % 10;
}
void visualizza(double m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}
void filtro_medio(double a[DIM][DIM], double b[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            int fact=0;
            double media=0;
            //soluzione un po' stupida, ma non ho voglia di ragionare di più.
            if((i+1) < DIM){
                media+=a[i+1][j];
                ++fact;
            }
            if((j+1) < DIM){
                media+=a[i][j+1];
                ++fact;
            }
            if((i-1) >= 0){
                media+=a[i-1][j];
                ++fact;
            }
            if((j-1) >= 0){
                media+=a[i][j-1];
                ++fact;
            }
            b[i][j]=(double)(media/(double)fact);
        }
    }
}