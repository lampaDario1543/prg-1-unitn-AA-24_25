/*
Scrivere un programma C++ per realizzare l’ordinamento di un array attraverso l’algoritmo di shell sort.
A tale fine, il programma definisca un array a di 10 elementi e lo inizializzi tramite un’opportuna
funzione inizializza_array con valori casuali nell’intervallo [0,100]. L’array così generato venga
stampato a video invocando una funzione stampa_array. Per effettuare l’ordinamento dell’array a,
successivamente venga chiamata una funzione shell_sort che realizza i passi dell’algoritmo. Il
programma stamperà infine il vettore a ordinato.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int DIM = 10;

void shell_sort(int *);
void carica(int *, int);
void visualizza(int *, int);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator= " << seed << endl
         << endl;
    //srand(1730723539);
    srand(seed);
    int v[DIM];
    carica(v, 100);
    visualizza(v, DIM);
    shell_sort(v);
    visualizza(v, DIM);
    return 0;
}

void shell_sort(int *v){
    int temp = DIM;
    int ctr = 1;
    while (temp != 1){
        temp /= pow(2, ctr);
        ++ctr;
    }
    for (int i = 0; i < ctr; i++){
        const int len = DIM / pow(2, (i + 1));
        cout << len<<endl;
        for (int j = 0; j < DIM - len; j++){
            if (v[j] > v[j + len]){
                int box = v[j];
                v[j] = v[j + len];
                v[j + len] = box;
            }
        }
    }
}
void carica(int *v, int k){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % (k + 1);
}
void visualizza(int *v, int dim){
    for (int i = 0; i < dim; i++)
        cout << v[i] << " ";
    cout << endl;
}