/*
stampare i numeri da 0 a n
*/
#include <iostream>

using namespace std;

void stampa (int);

int main() 
{
    int n;
    cout << "n? ";
    cin >> n;
    cout << "stampanumeri(" << n << ") = \n";
    stampa(n);
    return 0;
}

void stampa (int n){
    for(int i=0;i<=n;i++)
        cout << i << " ";
    cout << endl;
}