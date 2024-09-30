/*
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera i coefficienti a, b e c (tre numeri reali) di una equazione di secondo
grado nella forma ax2 + bx + c = 0 e ne calcoli le soluzioni x1 e x2. Prima di
effettuare il calcolo, il programma verificherà che l’equazione non sia
degenere e che abbia soluzioni reali. In tal caso, il programma stamperà a
video le soluzioni calcolate, altrimenti stamperà a video opportuni messaggi
per l’utente.
Attenzione! Dovete gestire TUTTI i casi possibili
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    double x1, x2;
    double delta = 0;
    cout << "Inserisci a b c: ";
    cin >> a >> b >> c;
    delta = (b * b) - (4 * a * c);
    if (delta < 0)
        cout << "L'equazione non ha soluzioni reali." << endl;
    else
    {
        x1 = (b * (-1) + sqrt(delta)) / (2 * a);
        x2 = (b * (-1) - sqrt(delta)) / (2 * a);
        if (0 == delta)
            cout << "La soluzione e' " << x1 << endl;
        else
            cout << "x1= " << x1 << endl
                 << "x2= " << x2 << endl;
    }
    return 0;
}