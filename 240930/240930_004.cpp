/*
Scrivere un programma in C++ che chieda all’utente di immettere da tastiera
le coordinate (x, y) di un punto e le coordinate (a, b) e (c, d) dei vertici
rispettivamente in alto a sinistra e in basso a destra di un rettangolo e
stampi a video un messaggio per indicare all’utente se il punto si trova
all’interno del rettangolo.

In teoria il triangolo è formato

AB -------
|        |
-------- CD

*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int x, y;
    // Bisognerebbe fare le verifiche sul rettangolo, ma non ho voglia.
    cout << "Inserisici a b c d: ";
    cin >> a >> b >> c >> d;
    cout << "Inserire x y: ";
    cin >> x >> y;
    // ipotizzo che il rettangolo sia un rettangolo e che a,b,c,d vadano bene
    if (x >= a && x <= c && y >= b && y <= c)
        cout << "Il punto fa parte del rettangolo." << endl;
    else
        cout << "Il punto NON fa parte del rettangolo." << endl;
    return 0;
}