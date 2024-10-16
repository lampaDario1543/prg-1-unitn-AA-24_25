/*
Scrivere un programma che simuli un attacco 3 contro 3 a RisiKo!. Tirare 3 dadi
a 6 facce per l’attaccante e 3 per il difensore. Confrontare il dado più alto
dell’attaccante contro il più alto del difensore, il medio dell’attaccante contro il
medio del difensore e il più basso dell’attaccante contro il più basso del
difensore. Dichiarare infine gli scontri vinti dall’attaccante e dal difensore
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LANCI = 3;

int lanciaDado();
void sort(int *);
void printDices(int *);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generatore= " << seed << endl;
    srand(1728901612);
    int dadi_p1[LANCI];
    int dadi_p2[LANCI];
    for (int i = 0; i < LANCI; i++){
        dadi_p1[i] = lanciaDado();
        dadi_p2[i] = lanciaDado();
    }
    cout << "Dadi p1: ";
    printDices(dadi_p1);
    cout << "Dadi p2: ";
    printDices(dadi_p2);
    sort(dadi_p1);
    sort(dadi_p2);
    cout << endl << endl;
    for (int i = 0; i < LANCI; i++){
        if (dadi_p1[i] > dadi_p2[i])
            cout << "Ha vinto l'attaccante (" << dadi_p1[i] << ") sul difensore (" << dadi_p2[i] << ")." << endl;
        else
            cout << "Ha vinto il difensore (" << dadi_p2[i] << ") sull' attaccante (" << dadi_p1[i] << ")." << endl;
    }
    return 0;
}
int lanciaDado(){
    return (rand() % 6) + 1;
}

void sort(int *v){
    for (int i = 0; i < LANCI - 1; i++){
        for (int j = i + 1; j < LANCI; j++){
            if (v[i] > v[j]){
                int box = v[i];
                v[i] = v[j];
                v[j] = box;
            }
        }
    }
}

void printDices(int *v){
    for (int i = 0; i < LANCI; i++)
        cout << v[i] << " ";
    cout << endl;
}