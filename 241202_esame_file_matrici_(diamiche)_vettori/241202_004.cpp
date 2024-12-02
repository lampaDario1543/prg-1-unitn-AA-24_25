/*
Es. 2 Appello Gennaio 2013

Scrivere un programma che, dati due interi in input (righe e colonne), crei
dinamicamente una matrice e la riempia con valori interi random (è concesso
l’uso della funzione rand() nella libreria <cstdlib>). In seguito, chiedere
all’utente le dimensioni della sottomatrice da stampare. Le dimensioni sono
fornite tramite quattro numeri, corrispondenti alle coordinate del primo
elemento (2 numeri) e alle dimensioni della sottomatrice (numero di righe e
colonne). Se le dimensioni fornite dall’utente eccedono quelle della matrice,
stampare la sottomatrice massima disponibile. Deallocare infine la matrice.

1 2 9 1
5 6 7 8     input: 2,1,2,3 => 5 7 2
9 5 7 2                       2 9 3
7 2 9 3
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void carica(int **, const int, const int);
void visualizza(int **, const int, const int);
void visualizza(int **, const int, const int, int *);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int ROW;
    int COL;
    int coords[4];
    do{
        cout << "<ROW> <COL>: ";
        cin >> ROW >> COL;
    } while (ROW <= 0 || COL <= 0);
    // alloc
    int **m = new int *[ROW];
    for (int i = 0; i < ROW; i++)
        m[i] = new int[COL];
    carica(m, ROW, COL);
    visualizza(m, ROW, COL);
    do{
        cout << "<ROW_FIRST_EL> <COL_FIRST_EL> <N_ROWS> <N_COLS>: ";
        cin >> coords[0] >> coords[1] >> coords[2] >> coords[3];
    } while (coords[0] < 0 || coords[0] >= ROW || coords[1] < 0 || coords[1] >= COL);
    visualizza(m, ROW, COL, coords);
    // dealloc
    for (int i = 0; i < ROW; i++)
        delete m[i];
    delete[] m;
    return 0;
}

void carica(int **m, const int ROW, const int COL){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            m[i][j] = rand() % 100;
    }
}
void visualizza(int **m, const int ROW, const int COL){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void visualizza(int **m, const int ROW, const int COL, int *coords){
    if (coords[2] >= ROW || coords[3] >= COL){
        visualizza(m, ROW, COL);
        return;
    }
    for (int i = 0; i < coords[2]; i++){
        for (int j = 0; j < coords[3]; j++)
            cout << m[coords[0] + i][coords[1] + j] << " ";
        cout << endl;
    }
    cout << endl;
}