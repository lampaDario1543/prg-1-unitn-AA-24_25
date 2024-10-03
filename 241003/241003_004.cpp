/*
Scrivere un programma C++ che disegni sul terminale un triangolo le
cui righe devono essere composte da un numero dispari di asterischi.
L’altezza di questo triangolo viene data in input dall’utente
A = 4
   *
  ***
 *****
*******
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "n: ";
    cin >> n;
    if (n <= 0)
        cout << "Inserire n > 0" << endl;
    else{
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < ((n - i - 1)); j++)
                cout << " ";
            for (int j = 0; j < (i * 2) + 1; j++)
                cout << "*";
            cout << endl;
        }
    }
    return 0;
}