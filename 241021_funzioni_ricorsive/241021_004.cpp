/*
Modificare il codice della funzione potenza dell’esercizio 1 cosi che la
funzione diventi tail recursive. 
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
    if (ctr == n)
        return m;
    return m * pow(m, n, ctr + 1);

}
int pow(int m, int n){
    if (n == 0)
        return 1;
    return pow(m, n, 1);
}