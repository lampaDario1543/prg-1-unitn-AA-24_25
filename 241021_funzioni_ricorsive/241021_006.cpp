/*
Un cliente di una banca investe un ammontare α > 0 di denaro in un fondo di investimento, il quale
rende nel seguente modo: ogni mese il capitale aumenta di una percentuale fissa γ > 0
dell’ammontare di denaro presente al mese precedente e diminuisce a causa delle spese fisse di
gestione per una somma pari a σ≥ 0. Il capitale del cliente dopo n mesi può essere, cioè, espresso
attraverso la seguente successione definita per ricorrenza:

https://imgur.com/a/COWDWLL

Si scriva in linguaggio C++ la funzione ricorsiva capitale_maturato che riceva in ingresso (ovvero
come parametro) l’ammontare α del capitale inizialmente investito (un numero reale), il numero n di
mesi trascorsi (un numero intero), la percentuale di rendimento mensile γ (un numero reale) e
l’ammontare σ delle spese di gestione (un numero reale), calcoli e restituisca come valore di ritorno il
capitale maturato dopo n mesi (un numero reale), applicando la formula sopra riportata.

Si scriva, quindi, un programma C++ che chieda all’utente di inserire da tastiera il numero k di mesi
corrispondenti alla durata di un investimento, verifichi che k sia maggiore o uguale a 6 (durata
minima dell’investimento) e chiami la funzione ricorsiva capitale_maturato passando k come
parametro attuale per il numero di mesi n e i seguenti valori per gli altri parametri: 25000.00 per alpha,
0.0015 per gamma e 1.0 per sigma. Il programma stampa a video il valore di ritorno della funzione,
ovvero il capitale maturato dopo n mesi, avendo investito 25000.00 Euro con un tasso di rendimento
mensile dello 0.15% e costi mensili di gestione pari a 1.0 Euro. Nel caso in cui l’utente immetta un
numero minore di 6, il programma stampa a video un messaggio di errore e termina.
Esempio: se l'utente inserisce il valore k = 36, il programma stampa a video 26349.1, cioè dopo 36
mesi il capitale passa da 25000 Euro a 26349.10 Euro.
*/
#include <iostream>

using namespace std;

const double GAMMA = 0.0015;
const double SIGMA = 1.0;

double capitale_maturato(double, int);

int main(){
    double alfa = 25000;
    int n = 7;
    cout << "Insereire il numero di mesi: ";
    cin >> n;
    if (n < 6){
        cout << "I mesi devono essere almeno 6" << endl;
        exit(0);
    }
    cout << "Capitale maturato= " << capitale_maturato(alfa, n) << " euro" << endl;
    return 0;
}

double capitale_maturato(double alfa, int n){
    if (n == 0)
        return alfa;
    return (1 + GAMMA) * capitale_maturato(alfa, n - 1) - SIGMA;
}