/*
Si scriva in C++ una funzione ricorsiva che, ricevuto come parametro un numero reale x, calcoli
il valore di sin(x) utilizzando lo sviluppo di Taylor fino al termine n-esimo. Ovvero:

https://imgur.com/a/pQ53CQB

Si scriva quindi un programma per verificare il corretto funzionamento della funzione.
Il programma chiederà all’utente di inserire i valori di x (un numero reale) e di n (un numero intero),
chiamerà la funzione e stamperà a video il suo valore di ritorno. Tali operazioni potranno essere
ripetute finché l’utente lo desidera.
Nota: anche il fattoriale può essere implementato mediante una funzione ricorsiva.
Per fare di più: quale è il valore di n oltre il quale la funzione inizia a restituire valori non validi?
Per quale ragione questo accade?
*/
#include <iostream>
#include <cmath>
using namespace std;

//non so se funzione, andrebbe testato.

long long int fact(int);
long double sin(double, int, int k=0);

int main(){
    double x=5;
    int n=11;
    cout << sin(x,n)<<endl;
    return 0;
}

long long int fact(int n){
    long long int res=1;
    for(int i=2;i<=n;i++)
        res*=i;
    return res;
}

long double sin(double x, int n, int k){
    if(k==n)
        return pow(-1,k) * (double)pow(x,((2*k)+1))/fact((2*k)+1);
    return (pow(-1,k) * (double)pow(x,((2*k)+1))/fact((2*k)+1)) + sin(x,n,k+1);
}