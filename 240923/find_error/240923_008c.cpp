//VIENE FATTA UNA DIVISIONE PER 0 (IMPOSSIBILE) (floating point exception)
#include <iostream>
using namespace std;
int main() {
 int numeratore = 10;
 int denominatore = 0;
 int risultato = numeratore / denominatore;
 cout << "Il risultato è: " << risultato << endl;
 return 0;
}