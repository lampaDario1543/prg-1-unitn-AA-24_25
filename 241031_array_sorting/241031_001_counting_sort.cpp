/*
Scrivere un programma C++ per realizzare l’ordinamento di un array attraverso l’algoritmo di counting
sort. A tale fine, il programma definisca un array a di 10 elementi e lo inizializzi tramite un’opportuna
funzione inizializza_array con valori casuali nell’intervallo [0,100]. L’array così generato venga
stampato a video invocando una funzione stampa_array. Per effettuare l’ordinamento dell’array,
successivamente venga chiamata una funzione counting_sort che realizza i passi dell’algoritmo. Si abbia
cura di calcolare il massimo dell’array attraverso una funzione max che verrà invocata dalla funzione
counting_sort. La funzione counting_sort realizza come ultimo passo una copia dell’array out nell’array
a. Il programma stamperà il vettore a ordinato.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

int max(int *v);
void counting_sort(int *);
void carica(int *, int);
void visualizza(int *, int);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator= " << seed << endl
         << endl;
    srand(seed);
    int v[DIM];
    carica(v, 100);
    visualizza(v, DIM);
    counting_sort(v);
    visualizza(v, DIM);
    return 0;
}

int max(int *v){
    int max = v[0];
    for (int i = 1; i < DIM; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

void counting_sort(int *v){
    int m = max(v);
    const int COUNT_DIM = m + 1;
    int *count;
    int *out = new int[DIM];
    count = new int[COUNT_DIM](); //() inizializza tutto a 0
    for (int i = 0; i < DIM; i++)
        ++count[v[i]];
    for (int i = 1; i < COUNT_DIM; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < DIM; i++)
        out[--(count[v[i]])] = v[i];
    for (int i = 0; i < DIM; i++)
        v[i] = out[i];
    delete[] count;
    delete[] out;
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