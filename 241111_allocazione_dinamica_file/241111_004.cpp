/*
Si scriva la funzione append che concateni due array di numeri interi ordinati in senso
crescente. La funzione riceve come parametri i puntatori a due array di numeri interi pa e
pb e le loro dimensioni na e nb (due numeri interi) e restituisce come valore di ritorno il
puntatore a un array di numeri interi. Si suppone che gli array puntati da pa e pb siano
già ordinati in senso crescente. La funzione allocherà dinamicamente un array di (na +
nb) elementi e vi copierà gli elementi degli array puntati da pa e pb in modo tale che
l’array risultante sia a sua volta ordinato in senso crescente. La funzione restituirà infine il
puntatore all’array risultante. Sarà responsabilità del programma chiamante deallocare la
memoria allocata dalla funzione.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione. Il programma chiederà all’utente di immettere da tastiera le dimensioni nx e ny
di due array di numeri interi, allocherà dinamicamente gli array e chiederà all’utente di
inserire i valori per entrambi gli array. Il programma utilizzerà quindi l’algoritmo
BubbleSort per ordinare entrambi gli array, chiamerà la funzione append e stamperà a
video l’array concatenato risultante.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void carica(int *, const int);
void visualizza(int *, const int);
void swap(int &, int &);
void sort(int *, const int);
int *append(int *, const int, int *, const int);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int dim_a, dim_b;
    cout << "Inserire <dim_a> <dim_b>: ";
    cin >> dim_a >> dim_b;
    int *a = new int[dim_a];
    int *b = new int[dim_b];
    carica(a, dim_a);
    sort(a, dim_a);
    visualizza(a, dim_a);
    carica(b, dim_b);
    sort(b, dim_b);
    visualizza(b, dim_b);
    int *v = append(a, dim_a, b, dim_b);
    visualizza(v, dim_a + dim_b);
    delete[] a;
    delete[] b;
    delete[] v;
    return 0;
}
void carica(int *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % 100 + 1;
}
void visualizza(int *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}
void swap(int &a, int &b){
    int box = a;
    a = b;
    b = box;
}
void sort(int *v, const int DIM){
    for (int i = 0; i < DIM - 1; i++){
        for (int j = i + 1; j < DIM; j++)
            if (v[i] > v[j])
                swap(v[i], v[j]);
    }
}
int *append(int *a, const int DIM_A, int *b, const int DIM_B){
    int *v = new int[DIM_A + DIM_B];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < DIM_A && j < DIM_B){
        if (a[i] < b[j]){
            v[k] = a[i];
            ++i;
        }
        else{
            v[k] = b[j];
            ++j;
        }
        ++k;
    }
    if (i == DIM_A)
        for (i = j; i < DIM_B; i++, k++)
            v[k] = b[i];
    else
        for (j = i; j < DIM_A; j++, k++)
            v[k] = a[j];
    return v;
}