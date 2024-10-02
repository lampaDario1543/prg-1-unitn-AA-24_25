/*
reimplementare l'esempio della serie sum 1/(2^i) implementando
esplicitamente la funzione double pow2(int) che calcola 2^i
(2*2*2*2.....*2)
*/
#include <iostream>

using namespace std;
const int MAX = 5;

double pow2(int);

int main()
{
    double sum = 0;
    for (int i = 1; i <= MAX; i++)
        sum += (1.0 / pow2(i));
    cout << "Somma= " << sum << ". Per la serie che arriva a " << MAX << ". " << endl;
    return 0;
}

double pow2(int pow)
{
    double res = 1;
    for (int i = 1; i <= pow; i++)
        res *= 2;
    return res;
}