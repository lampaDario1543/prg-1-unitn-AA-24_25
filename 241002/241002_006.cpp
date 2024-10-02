/*
scrivere un programmino che simuli un attacco 3 contro 3 a RISIKO
Ovvero: ogni giocatore lancia 3 dadi e vince chi dei due ha
ottenuto dalla somma dei dadi un valore piu' alto.*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUMERO_GIOCATORI_SQUADRA = 3;
const int NUMERO_TIRI_A_TESTA = 3;

int lanciaDado();
int tiraDadi();

int main(){
    int somma_s1 = 0;
    int somma_s2 = 0;
    time_t seed = time(NULL);
    srand(seed);
    cout << "Seed random generator: " << seed << endl
         << endl
         << endl;
    for (int i = 0; i < NUMERO_GIOCATORI_SQUADRA; i++)
    {
        for (int j = 0; j < NUMERO_TIRI_A_TESTA; j++)
        {
            somma_s1 += tiraDadi();
            somma_s2 += tiraDadi();
        }
    }
    cout << "La squadra 1 ha fatto " << somma_s1 << endl
         << endl;
    cout << "La squadra 2 ha fatto " << somma_s2 << endl
         << endl;
    if (somma_s1 == somma_s2)
        cout << "Le due squadre hanno pareggiato!!!" << endl;
    else if (somma_s1 > somma_s2)
        cout << "Ha vinto la squadra 1 (" << somma_s1 << ")!!!" << endl;
    else
        cout << "Ha vinto la squadra 2 (" << somma_s2 << ")!!!" << endl;
    return 0;
}

int lanciaDado(){
    return (rand() % 6) + 1;
}
int tiraDadi(){
    return lanciaDado()+lanciaDado();
}