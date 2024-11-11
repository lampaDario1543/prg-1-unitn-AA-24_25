/*
int * generate_numbers(int N);
Scrivere un programma che, dato in input dall’utente da riga di
comando un numero intero N, ritorni a video una lista di N
numeri interi generati randomicamente nell’intervallo 0-99.
Questi numeri devono essere salvati in un array. Questo array
deve essere generato dinamicamente da una funzione con la
firma uguale a quella mostrata sopra.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int *generate_numbers(const int);
void visualizza(const int *, const int);

int main(int argc, char *argv[]){
    if (argc != 2){
        cerr << "Use <n_elments>" << endl;
        exit(0);
    }
    int N = 0;
    N = atoi(argv[1]);
    if (N <= 0){
        cerr << "N must be > 0" << endl;
        exit(0);
    }
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl;
    srand(seed);
    int *v = generate_numbers(N);
    visualizza(v, N);
    delete[] v;
    return 0;
}

int *generate_numbers(const int N){
    int *v = new int[N];
    for (int i = 0; i < N; i++)
        v[i] = rand() % 100;
    return v;
}

void visualizza(const int *v, const int N){
    for (int i = 0; i < N; i++)
        cout << v[i] << " ";
    cout << endl;
}