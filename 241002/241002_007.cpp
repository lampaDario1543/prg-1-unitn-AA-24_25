/*
calcolare fattoriale di n
*/

#include <iostream>

using namespace std;

int main(){
    const int n=5;
    int fact=1;
    for(int i=n;i>1;i--)
        fact*=i;
    cout << "Il fattoriale di " << n << " e' "<< fact <<endl;
    return 0;
}