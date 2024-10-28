/*
Scrivere un programma C++, che sfruttando le funzioni scritte negli esercizi
precedenti, dichiari e poi inizializzi (con valori random) un array di 10 numeri
interi. Il programma chiamerà poi una funzione che prende in input un nuovo
elemento x e un indice i, e aggiunge l'elemento x in posizione i nell’array,
traslando gli elementi successivi. Il programma controlli che l’indice i inserito
sia nel range opportuno, e, se non lo fosse, visualizzi un messaggio di errore e
richieda un nuovo inserimento. Infine, si stampi l’array modificato.
[3, 4, 0, 8, 6] => [3, 4, 7, 0, 8]
Inserisci 7 in posizione 2

*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

void carica(int *);
void visualizza(int *);
void insert(int *, int, int);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    int v[DIM], x, i;
    carica(v);
    visualizza(v);
    do{
        cout << "Inserisci un numero e un indice: ";
        cin >> x >> i;
        if (i < 0 || i >= DIM)
            cout << "L'indice deve essere maggiore di 0 e minore di " << DIM << endl;
    } while (i < 0 || i >= DIM);
    insert(v, x, i);
    visualizza(v);
    return 0;
}

void carica(int *v){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % 10;
}

void visualizza(int *v){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}
void insert(int *v, int x, int idx){
    int box = v[idx];
    for (int i = idx; i < DIM - 1; i++){
        int box2 = v[i + 1];
        v[i + 1] = box;
        box = box2;
    }
    v[idx] = x;
}