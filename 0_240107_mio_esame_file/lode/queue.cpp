#include <iostream>
#include "queue.h"

using namespace std;



static bool coda_vuota(const coda & q) {
  return (q.head == NULL);
}


coda coda_init() {
  coda Q;
  Q.head = NULL;
  Q.tail = NULL;
  return Q;
}


bool coda_enqueue(coda & Q, int n) {
  
    bool risultatoOperazione;
    listaCoda nuovoNodo = new (nothrow) nodoCoda;
    if (nuovoNodo==NULL) {
        risultatoOperazione = false;
    }
    else {
        nuovoNodo->value=n;
        nuovoNodo->next=NULL;
        if (coda_vuota(Q)) {
            Q.head=nuovoNodo;
        }
        else { 
            Q.tail->next=nuovoNodo;
        }
        Q.tail=nuovoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}


bool coda_first(coda & Q, int &n) { 
    bool risultatoOperazione;
    if (coda_vuota(Q)) {
        risultatoOperazione = false;
    }
    else {
        n = Q.head->value;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}


bool coda_dequeue(coda & Q) { 
    bool risultatoOperazione;
    if (coda_vuota(Q)) {
        risultatoOperazione = false;
    }
    else {
        listaCoda primoNodo;
        primoNodo = Q.head;
        Q.head = Q.head->next;
        delete primoNodo; 
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}

void coda_deinit(coda & Q) {
    int tmp;
	while(coda_first(Q, tmp)) {
		coda_dequeue(Q);
	}
}

void coda_print(const coda & Q) {

  if (!coda_vuota(Q)) {
    listaCoda nodoCorrente=Q.head;
    do {
      cout << nodoCorrente->value << endl;
      nodoCorrente = nodoCorrente->next;
    } while (nodoCorrente != NULL);
  }
}
