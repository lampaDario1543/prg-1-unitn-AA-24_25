/*
Scrivere un programma C++ che, dato in input un carattere
alfabetico, stampa a video se il carattere è una consonante
o una vocale
*/
#include <iostream>

using namespace std;

int main()
{
    char c = ' ';
    do
    {
        cout << "Inserisci una lettera: ";
        cin >> c;
        if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
            cout << "!! Devi inserire una LETTERA!!" << endl
                 << endl;
    } while (c < 'A' || (c > 'Z' && c < 'a') || c > 'z');
    if ('A' == c || 'a' == c || 'E' == c || 'e' == c || 'I' == c || 'i' == c || 'O' == c || 'o' == c || 'U' == c || 'u' == c)
        cout << c << " e' una vocale." << endl;
    else
        cout << c << " e' una consonante." << endl;
    return 0;
}