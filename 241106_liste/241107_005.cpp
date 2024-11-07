/*
* Scrivere una funzione che costruisca la lista risultante dalla
  concatenazione di due liste x e y.
  - Diverse soluzioni sono possibili:
    . Side effects sulla lista destinazione.
    . Nuova lista.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node{
    int dato;
    Node *next;
};

void visualizza(Node *);
void insertNode(Node *, Node *);
void delete_list(Node * & s);
void carica(Node *&);
void merge_list(Node *&, Node *);

int main(){
    time_t seed=time(NULL);
    cout << "Random seed generator: "<< seed<<endl<<endl;
    srand(seed);
    Node *x= new Node;
    Node *y= new Node;
    carica(x);
    carica(y);
    cout << "Lista x: ";
    visualizza(x);
    cout << "Lista y: ";
    visualizza(y);
    cout << "Liste concatenate: ";
    merge_list(x,y);
    visualizza(x);
    delete_list(x);
    delete_list(y);
    return 0;
}

void visualizza(Node *l){
    if(l==NULL)
        return;
    for(Node *s=l;s!=NULL;s=s->next)
        cout << s->dato << " ";
    cout << endl;
}

void insertNode(Node *l, Node *t){
    t->next=l->next;
    l->next=t;
}

// Dealloca la memoria della lista
void delete_list(Node * & s) {
  // Alla fine la lista e' vuota. Passaggio per riferimento.
  while(s != NULL) {
    // Salvo il valore del nodo corrente
    Node * t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}

void carica(Node *& x){
    x->dato=rand()%100+1;
    x->next=NULL;
    for(int i=0;i<9;i++){
        Node *t=new Node;
        t->dato=rand()%100+1;
        t->next=NULL;
        insertNode(x,t);
    }
}
void merge_list(Node *&x, Node *y){
    Node *q= x;
    while(q->next!=NULL)
        q=q->next;
    q->next=y;
}