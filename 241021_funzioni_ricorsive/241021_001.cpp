/*
Si scriva in C++ una funzione ricorsiva (NON tail recursive!) che, dati due numeri
interi m ed n ricevuti come parametri passati per valore, verifichi che n sia
positivo o nullo, calcoli e restituisca come valore di ritorno la potenza mn (un
numero intero).
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione.
Il programma chiederà all’utente di inserire da tastiera due numeri interi, se n è
negativo chiederà all’utente di inserire un numero valido. Il programma poi
chiamerà la funzione e stamperà a video il suo valore di ritorno.
Le operazioni si ripeteranno finché l’utente lo desidera
*/
#include <iostream>

using namespace std;

int pow(int, int);
int pow(int, int, int);

int main(){
    int n, esp;
    char opt = ' ';
    do{
        do{
            cout << "Inserire n esponente: ";
            cin >> n >> esp;
            if (esp < 0)
                cout << "Esponente >= 0" << endl
                     << endl;
        } while (esp < 0);
        cout << n << "^" << esp << "= " << pow(n, esp) << endl;
        cout << "Vuoi continuare (y/n)? ";
        cin >> opt;
    } while (opt == 'y');
    return 0;
}
int pow(int m, int n, int ctr){
    if (ctr != n)
        return m * pow(m, n, ctr + 1);
    return m;
}
int pow(int m, int n){
    if (n == 0)
        return 1;
    return pow(m, n, 1);
}