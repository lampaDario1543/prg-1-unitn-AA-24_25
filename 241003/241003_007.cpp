/*
Scrivere un programma C++ che calcoli il risultato della seguente serie
che approssima il valore (pi greco^2 / 6). Si ricavi il valore
approssimato di pi greco. Il limite superiore di questa serie (il valore N)
viene dato dall’utente in input.

sum(1/(i^2)) di i=1 a n

*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n = 0;
    long double sum = 0;
    do{
        cout << "n: ";
        cin >> n;
    } while (n < 1);
    for (int i = 1; i <= n; i++)
        sum += 1.0 / pow(i, 2);
    cout << "Somma= " << sum << endl;
    return 0;
}