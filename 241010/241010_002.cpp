/*
Scrivere un programma che prenda in input un numero e
stampi a video il numero invertito usando una procedura.
*/
#include <iostream>

using namespace std;

void inverti(int &);

int main(){
    int n=694201; //non funziona per le cifre che terminano con 0 (non ho voglia.)
    cout << "n= "<<n<<endl;
    inverti(n);
    cout << "n invertito= "<<n<<endl;
    return 0;
}

void inverti(int &n){
    int temp=n;
    n=0;
    while(temp>0){
        n*=10;
        n+=temp%10;
        temp/=10;
    }
}