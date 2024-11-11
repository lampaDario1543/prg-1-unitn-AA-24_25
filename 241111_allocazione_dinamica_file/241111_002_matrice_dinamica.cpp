/*
int ** generate_matrix(int R, int C);

Scrivere un programma che, dati in input dall’utente da riga di
comando due numeri interi R e C, crei dinamicamente una
matrice con R righe ed C colonne. Popolate poi questa matrice
con dei numeri random.
Infine, stampate questa matrice a video.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int **generate_matrix(int R, int C);
void visualizza(int **, const int, const int);

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Use <R> <C>" << endl;
        exit(0);
    }
    int R, C;
    R = atoi(argv[1]);
    C = atoi(argv[2]);
    if (R <= 0){
        cerr << "<R> must be > 0";
        exit(0);
    }
    if (C <= 0){
        cerr << "<C> must be > 0";
        exit(0);
    }
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int **m;
    m = generate_matrix(R, C);
    visualizza(m, R, C);
    // dealloco la matrice:
    for (int i = 0; i < R; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}

int **generate_matrix(int R, int C){
    int **m = new int *[R];
    for (int i = 0; i < R; i++)
        m[i] = new int[C];
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            m[i][j] = rand() % 100 + 1;
    }
    return m;
}

void visualizza(int **m, const int R, const int C){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}