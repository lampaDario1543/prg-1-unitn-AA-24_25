/*
Il rompicapo consiste di tre pali A, B, C e un numero n di dischi forati
di diametro diverso. Inizialmente, tutti i dischi sono impilati sul palo
A. Scopo del gioco è reimpilare tutti i dischi sul palo C.
Regole:
• Si può spostare un disco per volta;
• Nessun disco può avere sopra di sé dischi di diametro più grande
• I dischi non possono essere «parcheggiati» fuori dai pali

Scrivere una funzione ricorsiva che risolva la Torre di Hanoi tramite procedura ricorsiva. La
funzione riceva come parametri il numero di dischi N e il nome dei tre pali. La funzione non
ritorna alcun valore.

Il problema generale consiste nello spostare n dischi da una torre ad un’altra, usando la terza
torre come parcheggio temporaneo. Per spostare n dischi da una torre all’altra supponiamo di
saper spostare n-1 dischi da una torre all’altra.
Il caso base si ha quando n = 1. Se n=1, possiamo spostare liberamente il disco da una torre
ad un’altra.
Procedura per spostare n dischi dalla torre A alla torre C:
• Passo 1: gli n-1 dischi in cima alla torre A vengono spostati sulla torre B, usando la torre C
come parcheggio temporaneo (si usa una chiamata ricorsiva, al termine della quale la torre
C è vuota)
• Passo 2: il disco rimasto nella torre A viene portato nella torre C
• Passo 3: gli n-1 dischi in cima alla torre B vengono spostati nella torre C, usando la torre A
come parcheggio temporaneo (si usa una chiamata ricorsiva, al termine della quale la torre
A è vuota)
*/
#include <iostream>

using namespace std;

void solve_hanoi(int, char, char, char);

int main(){
    const int n = 3;
    solve_hanoi(n, 'A', 'C', 'B');
    return 0;
}

void solve_hanoi(int n, char a, char b, char c){
    if (n == 1)
        cout << "Sposta il disco dal paletto " << a << " al paletto " << b << endl;
    else
    {
        solve_hanoi(n - 1, a, c, b);
        cout << "Sposta il disco dal paletto " << a << " al paletto " << b << endl;
        solve_hanoi(n - 1, c, b, a);
    }
    return;
}