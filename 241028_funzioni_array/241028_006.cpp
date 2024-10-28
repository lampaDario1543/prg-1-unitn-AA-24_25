/*
Si scriva una funzione in C++ che riceva come parametro un array a di
numeri reali, la sua dimensione n e due ulteriori numeri reali x e y. Dopo
avere verificato che sia x < y, la funzione assegnerà 0 a tutti gli elementi
dell’array a che non appartengano all’intervallo [x, y]. Inoltre la funzione
restituirà come valore di ritorno il numero di assegnamenti effettuati
(cioè il numero di elementi non appartenenti all’intervallo
[x, y]). Se la condizione x < y non è verificata, la funzione restituirà -1.
Si scriva quindi un programma per verificare il corretto funzionamento
della funzione.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void carica(double *, const int);
void visualizza(double *, const int);
int interval(double *, const int, const double, const double);

int main(){
    time_t seed = time(NULL);
    cout << "[DEBUG] Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    const int DIM = 10;
    double v[DIM], x, y;
    x = 65;
    y = 85;
    carica(v, DIM);
    visualizza(v, DIM);
    int assigment = interval(v, DIM, x, y);
    cout << "Assegnamenti= " << assigment << endl;
    visualizza(v, DIM);
    return 0;
}

void carica(double *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        v[i] = rand() % 100 + 1;
}
void visualizza(double *v, const int DIM){
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}
int interval(double *a, const int DIM, const double x, const double y){
    if (x > y)
        return -1;
    int ctr = 0;
    for (int i = 0; i < DIM; i++){
        if (a[i] < x || a[i] > y){
            ++ctr;
            a[i] = 0;
        }
    }
    return ctr;
}