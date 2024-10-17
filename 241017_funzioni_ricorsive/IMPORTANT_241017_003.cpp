/*
Scrivere un programma che prenda in input un numero e
ne stampi a video la rappresentazione binaria tramite
procedura ricorsiva.
*/
#include <iostream>

using namespace std;

int dec2bin(int);

int main(){
    const int n=345;
    int ris=dec2bin(n);
    cout << n << " => " << ris << endl;
    return 0;
}

int dec2bin(int n){
    if(n==0)
        return 0;
    int val=n%2;
    return val+(10*dec2bin(n/2)); //ricompongo il numero
}