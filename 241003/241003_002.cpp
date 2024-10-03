/*
Si scriva un programma in linguaggio C++ che chieda all’utente di
immettere da tastiera un numero intero positivo e calcoli e stampi a video
di quante cifre il numero è composto. Se il numero inserito non è positivo,
il programma stamperà un messaggio di errore e chiederà di inserire un
nuovo numero.
*/
#include <iostream>

using namespace std;

int contaCifre(int);

int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    if (n < 0)
        cout << "Errore: n deve essere positivo" << endl;
    else
        cout << "Le cifre di " << n << " sono: " << contaCifre(n) << endl;
    return 0;
}

int contaCifre(int n)
{
    int cifre = 1;
    while ((n /= 10) > 0)
    {
        cifre++;
    }
    return cifre;
}