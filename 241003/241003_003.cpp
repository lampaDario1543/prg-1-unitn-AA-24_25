/*
Scrivere un programma C++ che, dato in input un numero
intero (compreso tra 0 e 1000), ritorni a video se il numero
inserito è primo.
Nota: un numero viene definito primo quando è divisibile solo
per se stesso e per il numero 1
*/
#include <iostream>

using namespace std;

bool isPrime(int n);

int main(){
    int n=0;
    cout << "n: ";
    cin >> n;
    if(n<0 || n > 1000)
        cout << "Inserire 0 <= n <= 1000"<<endl;
    else
        cout << "Il numero "<< n << (isPrime(n) ? " e' " : " non e' ")<< "primo"<<endl;
    
    return 0;
}

bool isPrime(int n){
    for(int i=2;i<n;i++){
        if((n%i)==0)
            return false;
    }
    return true;
}