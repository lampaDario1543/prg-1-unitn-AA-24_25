/*
* Scrivere una funzione che cancella un elemento x da una lista
  doppiamente concatenata s.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int dato;
    Node *prev;
    Node *next;
};

void insertNode(Node *, Node *);
void carica(Node *);
void visualizza(Node *);
void delete_list(Node *&);
void remove_el(Node *&, int);

int main()
{
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    Node *l = new Node;
    carica(l);
    visualizza(l);
    int n=0;
    cin >> n;
    remove_el(l,n);
    visualizza(l);
    delete_list(l);
    return 0;
}

void visualizza(Node *l)
{
    for (Node *s = l; s != NULL; s = s->next)
        cout << s->dato << " ";
    cout << endl;
}

void insertNode(Node *l, Node *t)
{
    t->next = l->next;
    if (l->next != NULL)
        t->next->prev = t;
    t->prev = l;
    l->next = t;
}

void carica(Node *l)
{
    l->dato = rand() % 100 + 1;
    l->prev = NULL;
    l->next = NULL;
    for (int i = 0; i < 9; i++)
    {
        Node *t = new Node;
        t->dato = rand() % 100 + 1;
        t->prev = NULL;
        insertNode(l, t); // Inserisci t dopo il nodo corrente
    }
}
void delete_list(Node *&s)
{
    while (s != NULL)
    {
        Node *t = s;
        s = s->next;
        delete t;
    }
}
void remove_el(Node *&l, int n){
    if(l==NULL)
        return;
    Node *q=l;
    
    if(l->dato==n){
        l=l->next;
        l->next->prev=NULL;
        delete q;
        return;
    }
    while(q->next!=NULL){
        if(q->next->dato==n){
            Node *r=q->next;
            q->next=q->next->next;
            delete r;
            return;
        }
        q->next=q->next->next;
    }
}