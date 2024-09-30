/*
Dati in input tre numeri interi, scrivere un programma C++
che ritorni a video il minimo tra questi tre numeri.
*/

#include <iostream>

using namespace std;

int main(){
    int min=0;
    int a,b,c;
    cout << "Inserire a b c: ";
    cin >> a >> b >> c;
    min=a;
    if(b<min)
        min=b;
    if(c<min)
        min=c;
    cout << "Il numero minore e': " << min << endl;
    return 0;
}