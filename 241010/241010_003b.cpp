/*
Scrivere un programma che lanci 10 dadi a 6 facce utilizzando la funzione
presentata sotto. Chiedere poi all’utente di indovinare quanti dadi sono
risultati essere 1.


Variante: chiamare “n” il numero dei dadi (1<=n<=10) e considerare un’altra variabile “m” (0<=m<n) entrambi da leggere
in input come prima azione. Effettuare poi un lancio di “n” dadi mostrandone “m” a video e chiedendo poi di indovinare
quanti in totale sono pari a “1”. Valutare empiricamente se si ritiene che la probabilità di successo vari al variare di “m”.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lanciaDado();
int lanciaNDadi(int, int); // ritorna quanti di questi hanno prodotto 1

int main(){
    int n,m;
    time_t seed = time(NULL);
    srand(seed);
    cout << "Random seed generator: " << seed << endl
         << endl;
    do{
        cout << "n: ";
        cin >> n;
    }while(n<=0 || n>10);
    do{
        cout << "m: ";
        cin >> m;
    }while(m<0 || m>=n);
    int ris=lanciaNDadi(n,m);
    int usr_n = 0;
    cout << "Quanti dati sono risultati 1? ";
    cin >> usr_n;
    if (ris == usr_n)
        cout << "Hai indovinato i dadi risultati 1 sono stati " << ris << endl;
    else
        cout << "Hai sbagliato, i dadi risultanti 1 sono stati " << ris << endl;
    return 0;
}

int lanciaNDadi(int n, int m){
    int ctr = 0;
    int dado = 0;
    for (int i = 0; i < m; i++)
    {
        dado = lanciaDado();
        cout << (i + 1) << " dado= " << dado << endl;
        if (dado == 1)
            ++ctr;
    }
    cout << endl;
    for (int i = m; i < n; i++)
        if (lanciaDado() == 1)
            ++ctr;
    return ctr;
}

int lanciaDado(){
    return (rand() % 6) + 1;
}