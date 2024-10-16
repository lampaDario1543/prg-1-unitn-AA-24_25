/*
Dati in input da 1 a 5 interi, scrivere una funzione che
ritorni il valore massimo. Usare argomenti di default per il
secondo, terzo, quarto e quinto input.
*/

#include <iostream>
#include <climits>

using namespace std;

int max(int n1, int n2 = INT_MIN, int n3 = INT_MIN, int n4 = INT_MIN, int n5 = INT_MIN);

int main(){
    int args = 0;
    int n1, n2, n3, n4, n5;

    do{
        cout << "Quant numeri vuoi inserire: ";
        cin >> args;
    } while (args < 1 || args > 5);
    switch (args){
        case 1:
            cout << "Inserisci un numero: ";
            cin >> n1;
            cout << "Max= " << max(n1) << endl;
            break;
        case 2:
            cout << "Inserisci due numeri: ";
            cin >> n1 >> n2;
            cout << "Max= " << max(n1, n2) << endl;
            break;
        case 3:
            cout << "Inserisci tre numeri: ";
            cin >> n1 >> n2 >> n3;
            cout << "Max= " << max(n1, n2, n3) << endl;
            break;
        case 4:
            cout << "Inserisci quattro numeri: ";
            cin >> n1 >> n2 >> n3 >> n4;
            cout << "Max= " << max(n1, n2, n3, n4) << endl;
            break;
        case 5:
            cout << "Inserisci cinque numeri: ";
            cin >> n1 >> n2 >> n3 >> n4 >> n5;
            cout << "Max= " << max(n1, n2, n3, n4, n5) << endl;
            break;
        default:
            cout << "Errrore: troppi argomenti." << endl;
            break;
    }
    return 0;
}

int max(int n1, int n2, int n3, int n4, int n5){
    int max = n1;
    if (n2 > max)
        max = n2;
    if (n3 > max)
        max = n3;
    if (n4 > max)
        max = n4;
    if (n5 > max)
        max = n5;
    return max;
}