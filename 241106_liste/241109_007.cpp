/*
Scrivere una funzione che inserisce un elemento x in una lista
doppiamente concatenata s.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node{
    int dato;
    Node *prev;
    Node *next;
};

void carica(Node *);
void insertNode(Node *, Node *);
void visualizza(Node *);
void delete_list(Node *&);

int main(){
    time_t seed= time(NULL);
    cout << "Random seed generator: "<< seed<<endl;
    srand(seed);
    Node *l = new Node;
    carica(l);
    visualizza(l);
    delete_list(l);
    return 0;
}

void carica(Node *l){
    l->dato=rand()%100+1;
    l->next=NULL;
    l->prev=NULL;
    for(int i=0;i<9;i++){
        Node *t=new Node;
        t->dato=rand()%100+1;
        t->prev=NULL;
        insertNode(l,t);
    }
}

void insertNode(Node *l, Node *t){
    t->next=l->next;
    if (l->next != NULL)
        t->next->prev = t;
    t->prev=l;
    l->next=t;
}
void visualizza(Node *l){
    for(Node *s=l; s!=NULL;s=s->next)
        cout << s->dato << " ";
    cout << endl;
}
void delete_list(Node *&l){
    while(l!=NULL){
        Node *q=l;
        l=l->next;
        delete q;
    }
}