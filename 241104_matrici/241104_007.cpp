/*
Scrivere un programma che dichiari e poi inizializzi (con valori
random) una matrice di 10x10 interi con valore 0 oppure 1.
Scrivere poi una funzione che torni il numero di “isole”,
definite come elementi della matrice con valore 1 circondati da
soli zeri.
*/

/*
Rappresentiamo una palude con una matrice che contiene solo 0 e 1, in cui 1 rappresenta
terraferma, mentre 0 rappresenta sabbie mobili in cui si sprofonda. Scrivere un programma
che, data la mappa di una palude (ovvero una matrice di 0 e 1), cerca un percorso per
attraversarla su terraferma e, se tale percorso esiste, lo visualizza tramite un array che
contiene i passi fatti su terraferma e una matrice che codifica terraferma con ‘*’ e sabbie mobili
con ‘-’.
Più specificatamente:
• Si cerchi un percorso da sinistra a destra, cioè dalla colonna 0 alla colonna (colonna-1);
• Sono possibili solo movimenti in avanti, cioè partendo dalla posizione (riga, colonna) ci si
può spostare in:
(riga-1, colonna+1) (solo se la riga non è la prima)
(riga, colonna+1)
(riga+1, colonna+1) (solo se la riga non è l’ultima)
• Si memorizzi l’eventuale percorso di attraversamento in un array i cui elementi sono gli
indici delle righe corrispondenti ad ogni passo del percorso.

https://imgur.com/a/t4k5bva
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 4;

void carica(int[][DIM]);
int get_islands(int[][DIM]);
void visualizza(int[][DIM]);
bool isIsland(int[][DIM], int, int);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    /*int m[DIM][DIM]={
        {1,0,1,0},
        {0,0,0,1},
        {0,1,0,0},
        {1,0,0,1},
    };
    //carica(m);*/
    int m[DIM][DIM];
    carica(m);
    visualizza(m);
    cout << "Isole trovate: " << get_islands(m) << endl;
    return 0;
}

void carica(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            m[i][j] = rand() % 2;
}
void visualizza(int m[DIM][DIM]){
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int get_islands(int m[DIM][DIM]){
    int ctr = 0;
    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++)
            if (m[i][j] == 1 && isIsland(m, i, j))
                ++ctr;
    }
    return ctr;
}
bool isIsland(int m[DIM][DIM], int r, int c){
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, 
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}};

    for (int i = 0; i < 8; ++i){
        int newR = r + directions[i][0];
        int newC = c + directions[i][1];
        if (newR >= 0 && newR < DIM && newC >= 0 && newC < DIM)
            if (m[newR][newC])
                return false;
    }
    return true;
}
