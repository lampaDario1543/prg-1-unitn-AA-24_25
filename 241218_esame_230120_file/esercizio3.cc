#include <iostream>
#include "pila.h"

using namespace std;

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti);
int abs(int n);
int main() {
    
    // Potete modificare l'array di asteroidi (e la sua
    // dimensione) per testare la vostra soluzione
    int asteroidi [] = {-6,10,5,8,-9};
    int numeroAsteroidi = 5;


    int numeroAsteroidiRimasti;
    int * asteroidiRimasti = collidiAsteroidi(asteroidi, numeroAsteroidi, numeroAsteroidiRimasti);


    // La stampa dell'array dinamico degli
    // asteroidi rimasti avviene nel main
    for (int i = 0; i < numeroAsteroidiRimasti ; i++) {
        cout << asteroidiRimasti[i] << " ";
    }
    cout << endl;

    // La deallocazione dell'array dinamico 
    // degli asteroidi rimasti avviene nel main
    delete[] asteroidiRimasti;
}


// Implementare la funzione sottostante come da consegna:
// - ritornare un'array di interi allocato dinamicamente che 
//   contenga lo stato degli asteroidi dopo tutte le collisioni
// - assegnare a 'numeroAsteroidiRimasti' il numero di elementi 
//   nell'array ritornato
int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti) {
    //non va bene, io lo faccio per gli asteroidi uno dopo l'altro non per tutti.
   int *ret=nullptr;
   int i=0;
   init();
   while(i < numeroAsteroidi-1){
        if(!((asteroidi[i] > 0 && asteroidi[i+1]>0) || ((asteroidi[i]<0) && (asteroidi[i+1]<0)))){
            if(abs(asteroidi[i])>abs(asteroidi[i+1])){
                push(asteroidi[i]);
                ++i; //quello dopo esplode
            }else if(abs(asteroidi[i])==abs(asteroidi[i+1])){
                ++i; //quello dopo esplode
            }else{
                push(asteroidi[i+1]);
                pop(); //quello prima esplode
            }
        }else{
            push(asteroidi[i]);
        }
        ++i;
   }
   numeroAsteroidiRimasti=0;
   int n=0;
   while(top(n)){
    cout <<n <<" ";
    //++numeroAsteroidiRimasti;
    pop();
   }
   deinit();
   return ret;
}
int abs(int n){
    return (n>0? n : (-1*n));
}