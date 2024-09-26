/*● Scrivere un programma che determina se un numero è un multiplo di un altro
usando solo operatori aritmetici e logici (senza cicli o condizioni).
*/
#include <iostream>

using namespace std;

int main()
{
    int n=12;
    int n2=8;
    bool ris=n%n2==0;
    cout << n2 << (ris? " e' ": " non e' ")<< "multiplo di "<<n <<endl;
    return 0;
}