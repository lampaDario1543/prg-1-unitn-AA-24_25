/*
Dato in input due numeri interi, a ed n (dove n >= 1), scrivere
un programma che stampi a video la successione di potenze
di a da 1 ad n.
a = 2, n = 6
Output: 2, 4, 8, 16, 32, 64
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,n;
    long int ris=0;
    cout << "Inserisci a: ";
    cin >> a;
    do{
        cout << "Inserisci n: ";
        cin >> n;
        if(n<1)
            cout << "!! n deve essere >= 1 !!"<<endl<<endl;
    }while(n<1);
    for(int i=0;i<n-1;i++){
        ris=pow(a,(i+1));
        cout << ris << ", ";
    }
    //fuori dal ciclo solo per non mettere la virgola
    ris=pow(a,n);
    cout << ris << endl;
    return 0;
}