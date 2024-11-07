/*
Scrivere una funzione che sposti l’elemento più grande di una
  lista concatenata nell'ultimo nodo della lista.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int dato;
    Node *next;
};

void visualizza(Node *);
void insertNode(Node *, Node *);
void insertInTail(Node *, Node *);
int find_max(Node *);
void sub_max(Node *&);

int main(){
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    Node *l = new Node;
    l->dato = rand()%100+1;
    l->next = NULL;
    for (int i = 1; i < 10; i++){
        Node *t = new Node;
        // t-> dato=i;
        t->dato = rand() % 100 + 1;
        t->next = NULL;
        insertNode(l, t);
    }
    visualizza(l);
    sub_max(l);
    visualizza(l);
    delete l;
    return 0;
}

void visualizza(Node *l){
    for (Node *s = l; s != NULL; s = s->next)
        cout << s->dato << " ";
    cout << endl;
}

void insertNode(Node *l, Node *t){
    t->next = l->next;
    l->next = t;
}
void insertInTail(Node *l, Node *t){
    while (l->next != NULL)
        l = l->next;
    l->next = t;
}

void sub_max(Node *&p){
    if(p==NULL)
        return;
    int max;
    max = find_max(p);
    if (p != NULL){
        Node *q = p;
        if (q->dato == max){
            p = p->next;
            delete q;
        }
        else{
            while (q->next != NULL){
                if (q->next->dato == max){
                    Node *r = q->next;
                    q->next = q->next->next;
                    delete r;
                    break;
                }
                if (q->next != NULL){
                    q = q->next;
                }
            }
        }
    }
    Node *max_node = new Node;
    max_node->dato = max;
    max_node->next = NULL;
    insertInTail(p, max_node);
}

int find_max(Node *l){
    int max;
    max = l->dato;
    for (Node *s = l; s != NULL; s = s->next){
        if (s->dato > max)
            max = s->dato;
    }
    return max;
}