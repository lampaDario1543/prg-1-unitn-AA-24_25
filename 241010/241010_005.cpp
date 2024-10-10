/*
Scrivere un programma che simuli un attacco 2 contro 2 a RisiKo!. Tirare 2
dadi a 6 facce per l’attaccante e 2 dadi per il difensore. Confrontare il dado
più alto dell’attaccante contro il più alto del difensore, e il più basso
dell’attaccante contro il più basso del difensore. Dichiarare infine gli
scontri vinti dall’attaccante e quelli vinti dal difensore.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int lanciaDado();

int main(){
    time_t seed = time(NULL);
    srand(seed);
    cout << "Random seed generator: " << seed << endl
         << endl;
    int attaccante1 = lanciaDado();
    int attaccante2 = lanciaDado();
    int difensore1 = lanciaDado();
    int difensore2 = lanciaDado();
    int max_attaccante = max(attaccante1, attaccante2);
    int min_attaccante = min(attaccante1, attaccante2);
    int max_difensore = max(difensore1, difensore2);
    int min_difensore = min(difensore1, difensore2);
    if (max_attaccante > max_difensore)
        cout << "Attacante (" << max_attaccante << ") vince il primo scontro. (difensore [" << max_difensore << "])" << endl;
    else
        cout << "Difensore (" << max_difensore << ") vince. (attaccante [" << max_attaccante << "])" << endl;
    if (min_attaccante > min_difensore)
        cout << "Attacante (" << min_attaccante << ") vince il primo scontro. (difensore [" << min_difensore << "])" << endl;
    else
        cout << "Difensore (" << min_difensore << ") vince. (attaccante [" << min_attaccante << "])" << endl;
    return 0;
}

int lanciaDado()
{
    return (rand() % 6) + 1;
}