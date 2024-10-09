/*
scrivere una procedura che prenda un vettore v e la sua dimensione
  d, un elemento x, ed elimina tutte le occorrenze di x (diminuemdo la
  dimensione d del vettore)

Esempio:
v = [4 1 3 6 8 4 2]
d = 7
x = 4
===>
v = [1 3 6 8 2]
d = 5
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 10;

void carica(int *);
void visualizza(int *, int);
int remove_occ(int *, int, int &); // int perché voglio stampare il numero di occorrenze trovate.
void left_shift(int *, int, int);

int main(){
    time_t seed = time(NULL);
    cout << "Seed random numbers generator= " << seed << endl
         << endl;
    srand(seed);
    int v[DIM];
    int d = DIM;
    carica(v);
    visualizza(v, d);
    remove_occ(v, 5, d);
    visualizza(v, d);
    cout << "d= " << d << endl;
    return 0;
}
void visualizza(int *v, int d){
    for (int i = 0; i < d; i++)
        cout << v[i] << " ";
    cout << endl;
}
void carica(int *v){
    for (int i = 0; i < DIM; i++)
        v[i] = (rand() % 10) + 1;
}

void left_shift(int *v, int idx, int d){
    int box, box2;
    box = v[d - 1];
    v[d - 1] = v[idx];
    for (int i = d - 2; i >= idx; i--){
        box2 = v[i];
        v[i] = box;
        box = box2;
    }
}

int remove_occ(int *v, int n, int &d){
    int ctr = 0;
    const int dim = d;
    for (int i = 0; i < d; i++){
        if (v[i] == n){
            left_shift(v, i, d);
            --d;
        }
    }
    return ctr;
}