/*
Scrivere un programma C++ che, dati in input due numeri interi,
a e b, li salvi in due variabili distinte, max e min,
in cui la prima conterrà il numero maggiore tra i due e la seconda il
più piccolo.
(senza utilizzare funzioni di libreria o istruzioni if-else o operatore
ternario o cicli)
Stampare poi queste variabili a video.
*/
#include <iostream>

using namespace std;

int main(){
    int a,b;
    a=0;
    b=0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    int maggiore= (a>b)+1;
    int max,min=0;
    max=b*(maggiore%2)+a*(1-(maggiore%2));
    min=a*(maggiore%2)+b*(1-(maggiore%2));
    cout << "Max= " << max << " Min= " << min << endl;
    return 0;
}