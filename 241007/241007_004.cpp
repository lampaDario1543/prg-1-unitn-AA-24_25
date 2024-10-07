/*
Scrivere un programma che utilizza un doppio ciclo
annidato per stampare una matrice identità di dimensione
n x n. L'utente inserisce il valore di n.
Esempio di output per n = 4:
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
*/
#include <iostream>

using namespace std;

void printIdentityMatrix(int);

int main(){
    int n=0;
    do{
        cout << "n: ";
        cin >> n;
    }while(n<=0);
    printIdentityMatrix(n);
    return 0;
}
void printIdentityMatrix(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)
                cout << "0 ";
            else
                cout << "1 ";
        }
        cout << endl;
    }
}