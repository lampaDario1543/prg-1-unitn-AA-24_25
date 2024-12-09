#include <iostream>
#include "lista.h"

using namespace std;

const int POS_AL_SECONDO = 2;
const int DIM_COLORI = 4;
const int MAX_BAMBINI = 10;

const char* nomi[18] = {"Marco", "Luca", "Anna", "Sabrina", "Veronica", "Simone", "Mario", "Luigi", "Antonio", "Francesca", "Giovanni", "Letizia", "Lucrezia", "Carolina", "Luca", "Annalisa", "Susanna", "Licia"};
const color colori[DIM_COLORI] = {rosso, verde, blu, giallo};

// Inserire QUI sotto la dichirazione delle funzioni coloraPartecipante e cerca.
lista cerca(lista , char *);
lista coloraPartecipante(lista , int, int);
// Inserire QUI sopra la dichirazione delle funzioni coloraPartecipante e cerca.

int main() {
    lista cerchio = NULL;
    
    unsigned int seed = time(NULL);
    // Commentare la riga sotto per non avere sempre lo stesso seed
    seed = 1703945587;
    std::cout << "Seed: " << seed << std::endl;
    srand(seed);
  

    int numero_bambini = rand() % MAX_BAMBINI + 2;
    for (int i = 0; i < numero_bambini; i++) {
        char* nome = (char*)nomi[rand() % 18];
        if (cerca(cerchio, nome) == NULL) {
            insert_in(cerchio, nome, 0);
        } else {
            i--;
        }
    }

    cout << "Ci sono " << size(cerchio) << " bambini nella lista." << endl;
    print(cerchio);

    int i = 0;
    int durata;
    bool finished = false;
    while (!empty(cerchio) && !finished) {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Giro numero " << ++i << endl;
        
        cout << "La canzone durerà per " << (durata = rand() % 60 + 10) << " secondi." << endl;

        int sedia_rimossa = rand() % size(cerchio);
        cout << "Fermo il bambino alla sedia numero " << sedia_rimossa << "." << endl;

        lista eliminato = coloraPartecipante(cerchio, durata, sedia_rimossa);

        if (eliminato != NULL) {
            cout << eliminato->nome << " ha ricevuto il colore " << eliminato->colore << endl;
        } else {
            cout << "Tutti i bambini hanno un colore. Ho finito." << endl;
            finished = true;
        }
        print(cerchio);
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "Tutti i bambini hanno un colore. Ho finito." << endl;

    return 0;
}

// Inserire QUI la definizione delle funzioni coloraPartecipante e cerca.
lista cerca(lista l, char *nome){
    if(empty(l))
        return NULL;
    lista p = l;
    do {
        if(strcmp(p->nome, nome)==0)
            return p;
        p = p->next;
    } while (p != l);
    return NULL;
}
lista coloraPartecipante(lista l, int durata, int i){
    if(empty(l))
        return NULL;
    lista p = l;
    color prev=p->colore;
    durata=(durata*POS_AL_SECONDO+i)%size(l);
    for(int j=0;j<durata;j++){
        prev=p->colore;
        p=p->next;
    }
    lista last=p;
    while(p->colore != nero){
        prev=p->colore;
        p=p->next;
        if(p==last){
            return NULL;
        }
    }
    color next=p->next->colore;
    color newColor=nero;
    do{
        newColor=colori[rand()%DIM_COLORI];
        p->colore=newColor;
    }while(newColor==next || newColor==prev);
    return p;
}