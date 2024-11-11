/*
Scrivere una funzione che costruisca una copia di una data lista
  (cioe', una nuova lista che contiene le stesse informazioni nello
  stesso ordine).
*/
#include <iostream>

using namespace std;

struct Node{
    int dato;
    Node *next;
};

void visualizza(Node *);
void insertNode(Node *, Node *);
void copy_list(Node *, Node *);
void delete_list(Node * & s);

int main(){
    Node *l = new (Node);
    Node *l2 = new (Node);
    l->dato = 10;
    l2->next = NULL;
    l->next = NULL;
    for (int i = 0; i < 9; i++){
        Node *t = new (Node);
        t->dato = i + 1;
        t->next = NULL;
        insertNode(l, t);
    }
    copy_list(l, l2);
    cout << "Copia fatta." << endl;
    cout << "Lista 1: ";
    visualizza(l);
    cout << "Imposto a null il next->next di l." << endl;
    l->next->next = nullptr;
    cout << "Lista 1: ";
    visualizza(l);
    cout << "Lista 2: ";
    visualizza(l2);
    delete_list(l);
    delete_list(l2);
    return 0;
}

void visualizza(Node *l){
    for (Node *s = l; s != NULL; s = s->next)
        cout << s->dato << " ";
    cout << endl;
}

void insertNode(Node *l, Node *n){
    n->next = l->next;
    l->next = n;
}
void copy_list(Node *l, Node *l2){
    l2->dato = l->dato;
    l2->next = NULL;
    while (l->next != NULL)
    {
        l = l->next;
        Node *t = new Node;
        t->dato = l->dato;
        t->next = NULL;
        l2->next = t;
        l2 = l2->next;
    }
}
void delete_list(Node * & s) {
  while(s != NULL) {
    Node * t = s;
    s = s->next;
    delete t;
  }
}