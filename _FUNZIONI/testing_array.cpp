#include <iostream>
#include <cstdlib>

using namespace std;
void visualizza(int *v, const int DIM)
{
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}

// scambio di due numeri
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// sorting di un array
void sort(int *v, const int DIM)
{
    for (int i = 0; i < DIM - 1; i++)
    {
        for (int j = i + 1; j < DIM; j++)
        {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}
int ricercaDicotomica(int v[], const int DIM, int target)
{
    sort(v, DIM);
    int inizio = 0;
    int fine = DIM - 1;

    while (inizio <= fine)
    {
        int medio = inizio + (fine - inizio) / 2;

        if (v[medio] == target)
        {
            return medio; // Elemento trovato, ritorna l'indice
        }
        if (v[medio] < target)
        {
            inizio = medio + 1; // Cerca nella parte destra
        }
        else
        {
            fine = medio - 1; // Cerca nella parte sinistra
        }
    }
    return -1; // Elemento non trovato
}
int getOcc(int *v, const int DIM, int target)
{
    int ctr = 0;
    for (int i = 0; i < DIM; i++)
        if (v[i] == target)
            ++ctr;
    return ctr;
}
int dec2bin(int n)
{
    if (n == 0)
        return 0;
    int val = n % 2;
    return val + (10 * dec2bin(n / 2));
}
int pow(int base, int exp)
{
    if (exp == 0)
        return 1;
    else
        return pow(base, exp - 1) * base;
}
int converti(int *v, const int DIM)
{
    int ris = 0;
    for (int i = 0; i < DIM; i++)
    {
        ris += v[i] * pow(2, (DIM - i - 1));
    }
    return ris;
}
int convert2dec(int n)
{
    int res = 0;
    int cifre = 0;
    int cifra = 0;
    while ((n / 10) != 0)
    {
        cifra = n % 10;
        res += cifra * pow(2, cifre);
        ++cifre;
        n /= 10;
    }
    cifra = n % 10;
    res += (cifra)*pow(2, cifre);
    return res;
}
void right_shift(int *v, const int DIM, int n)
{
    n = (n % DIM);
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        int prev = v[0];
        v[0] = v[DIM - 1];
        for (int j = 1; j < DIM; j++)
        {
            int prev2 = v[j];
            v[j] = prev;
            prev = prev2;
        }
    }
}
void left_shift(int *v, const int DIM, int n)
{
    n = (n % DIM);
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        int prev = v[DIM - 1];
        v[DIM - 1] = v[0];
        for (int j = DIM - 2; j >= 0; j--)
        {
            int prev2 = v[j];
            v[j] = prev;
            prev = prev2;
        }
    }
}

int main()
{
    srand(67);
    const int DIM = 10;
    int v[DIM];
    v[0] = 69;
    for (int i = 1; i < DIM; i++)
        v[i] = rand() % 90;
    visualizza(v, DIM);
    sort(v, DIM);
    visualizza(v, DIM);
    right_shift(v, DIM, 0);
    visualizza(v, DIM);
    return 0;
}