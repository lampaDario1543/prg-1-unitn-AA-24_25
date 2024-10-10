/*
Scrivere un programma che simuli un attacco 1 contro 1 a RisiKo!. Tirare 1
dado a 6 facce per l’attaccante e 1 dado per il difensore. Dichiarare infine il
numero più alto come il vincitore.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lanciaDado();

int main(){
    time_t seed = time(NULL);
    srand(seed);
    cout << "Random seed generator: " << seed << endl
         << endl;
    int attaccante = lanciaDado();
    int difensore = lanciaDado();
    if (attaccante > difensore)
        cout << "Attacante (" << attaccante << ") vince. (difensore [" << difensore << "])" << endl;
    else
        cout << "Difensore (" << difensore << ") vince. (attaccante [" << attaccante << "])" << endl;
    return 0;
}

int lanciaDado(){
    return (rand() % 6) + 1;
}