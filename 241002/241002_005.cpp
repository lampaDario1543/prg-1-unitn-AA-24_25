/*
scrivere una funzione (int) che calcoli sia l'area del cerchio sia
il suo perimetro e che la restituisca tramite la lista dei
parametri, e che restituisca un valore booleano 1 se ha potuto
calcolarlo (raggio >=0), 0 altrimenti.
*/
#include <iostream>
#include <cmath>

using namespace std;

int getCircleData(double, double *, double *);

int main()
{
    double area = 0, r = 0, perimetro = 0;
    r = 0;
    int res = 0;
    res = getCircleData(r, &area, &perimetro);
    if (!res)
        cout << "Il raggio e' < 0" << endl;
    else
        cout << "L'area del cerchio di raggio r= " << r << " e' " << area << endl
             << "Il perimetro vale: " << perimetro << endl;

    return 0;
}

int getCircleData(double r, double *a, double *p)
{
    const double PI = 3.14159265358;
    if (r >= 0)
    {
        *a = pow(r,2) * PI;
        *p = 2 * r * PI;
        return 1;
    }
    return 0;
}