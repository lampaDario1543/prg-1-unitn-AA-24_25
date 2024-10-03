/*
Scrivere un programma C++ che, dato in input un valore intero
n, stampi a video la successione di fibonacci fino all’n-esima
cifra.
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    int f0 = 0;
    int f1 = 1;
    int box;
    cout << "n: ";
    cin >> n;
    if (n > 1)
    {
        cout << f0 << ", " << f1 << ", ";
        for (int i = 0; i < n; i++)
        {
            box = f1;
            f1 = f1 + f0;
            f0 = box;
            cout << f1 << ", ";
        }
        cout << "\b\b";
    }
    else
        cout << "n deve essere > 1" << endl;
    return 0;
}