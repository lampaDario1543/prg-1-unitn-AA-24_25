/*
Scrivere un programma C++ che dato in input un numero binario,
stampi a video il suo corrispondente valore decimale.
Input: 10010 => 18
*/
#include <iostream>
#include <cmath>

using namespace std;

int convert2dec(int);

int main(){
    const int n=110111; //numero binario
    cout << n << " equivale a " << convert2dec(n) << endl;
    return 0;
}
int convert2dec(int n){
    int res=0;
    int cifre=0;
    int cifra=0;
    while((n/10)!=0){
        cifra=n%10;
        res+=cifra*pow(2,cifre);
        ++cifre;
        n/=10;
    }
    cifra=n%10;
    res+=(cifra)*pow(2,cifre);
    return res;
}