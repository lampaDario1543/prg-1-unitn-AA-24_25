/*
Scrivere un programma che generi un numero compreso tra 1 e 10
utilizzando la funzione presentata sotto. Chiedere poi all’utente
ripetutamente di inserire un numero e terminare il programma
quando si sarà indovinato.
*/
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main(){
    time_t seed = time(NULL);
    srand(seed);
    cout << "Random seed generator: " << seed << endl
         << endl;
    int rand_int = 0, n;
    rand_int = rand() % 10 + 1;
    //cout << "[DEBUG] rand_int= " << rand_int << endl << endl;
    do{
        cout << "n> ";
        cin >> n;
    } while (n != rand_int);
    cout << "Hai indovinato il numero, complimenti!!! [" << n << "]" << endl;
    return 0;
}