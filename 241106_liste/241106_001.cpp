/*
Scrivere una funzione che ritorni true se un elemento x occorre
nella lista, false se l'elemento non occorre.
*/
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *next;
};

void insert_node(nodo *, nodo *);
void visualizza(nodo *);
bool isInList(nodo *,int);

int main(){
    nodo *l;
    l=new (nodo);
    l->dato=10;
    l->next=NULL;
    nodo *x = new (nodo);
    for(int i=0;i<9;i++){
        nodo *t = new nodo;
        t->dato=i+1;
        t->next=NULL;
        insert_node(l,t);
    }
    const int n=7;
    visualizza(l);
    if(isInList(l,n))
        cout << "L'elemento "<< n << " e' presente nella lista."<<endl;
    else
        cout << "L'elemento "<< n << " NON e' presente nella lista."<<endl;
    delete l; 
    return 0;
}


void visualizza(nodo *l){
    for(nodo *s=l; s!=NULL; s=s->next)
        cout << s-> dato<<" ";
    cout <<endl;
}
void insert_node(nodo * x, nodo *t) {
    t -> next = x -> next;
    x -> next = t;
}

bool isInList(nodo *l,int n){
    for(nodo *s=l; s!=NULL; s=s->next)
        if(n==s->dato)
            return true;
    return false;
}