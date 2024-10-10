/*
Scrivere un programma che lanci 10 dadi a 6 facce utilizzando la funzione
presentata sotto. Chiedere poi all’utente di indovinare quanti dadi sono
risultati essere 1.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lanciaDado();
int lanciaNDadi(int); // ritorna quanti di questi hanno prodotto 1

int main(){
    time_t seed = time(NULL);
    srand(seed);
    cout << "Random seed generator: " << seed << endl
         << endl;
    int n = lanciaNDadi(10);
    int usr_n = 0;
    cout << "Quanti dati sono risultati 1? ";
    cin >> usr_n;
    if (n == usr_n)
        cout << "Hai indovinato i dadi risultati 1 sono stati " << n << endl;
    else
        cout << "Hai sbagliato, i dadi risultanti 1 sono stati " << n << endl;
    return 0;
}

int lanciaNDadi(int n){
    int ctr = 0;
    for (int i = 0; i < n; i++)
        if (lanciaDado() == 1)
            ++ctr;
    return ctr;
}

int lanciaDado(){
    return (rand() % 6) + 1;
}