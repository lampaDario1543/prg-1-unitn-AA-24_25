/*Scrivere una funzione che sposti l'elemento più piccolo di una lista
  concatenata nel primo nodo della lista.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int dato;
    Node * next;
};

void visualizza(Node *);
void insert_node(Node *, Node *);
void insert_head(Node *, Node *);
int get_min(Node *);
void sub_min(Node *);

int main(){
    time_t seed= time(NULL);
    cout << "Random seed generator: "<< seed<<endl<<endl;
    srand(seed);
    Node *l=new Node;
    l->dato=rand()%100+1;
    l->next=NULL;
    for(int i=0;i< 9;i++){
        Node *t=new Node;
        t->dato=rand()%100+1;
        t->next=NULL;
        insert_node(l,t);
    }
    visualizza(l);
    sub_min(l);
    visualizza(l);
    delete l;
    return 0;
}

void visualizza(Node *l){
    for(Node *s=l;s!=NULL;s=s->next)
        cout << s->dato << " ";
    cout << endl;
}
void insert_node(Node *l, Node *t){
    t->next=l->next;
    l->next=t;
}

int get_min(Node *l){
    int min=l->dato;
    for(Node *s=l;s!=NULL; s=s->next)
        if(s->dato<min)
            min=s->dato;
    return min;
}
void insert_head(Node *l, Node *t){
    if(l==NULL){
        return;
    }
    Node *tmp= new Node;
    tmp->dato=l->dato;
    tmp->next=l->next;
    l->dato=t->dato;
    l->next=tmp;
}
void sub_min(Node * l){
    int min=get_min(l);
    Node *q=l;
    if(l->dato==min)
        return;
    while(q->next!=NULL){
        if(q->next->dato==min){
            Node *r = q->next;
            q->next = q->next->next;
            delete r;
            break;
        }
        q=q->next;
    }
    Node *tmp= new Node;
    tmp->dato=l->dato;
    tmp->next=l->next;
    Node *min_node= new Node;
    min_node->dato=min;
    min_node->next=NULL;
    l->dato=min;
    l->next=tmp;
    delete min_node;
}