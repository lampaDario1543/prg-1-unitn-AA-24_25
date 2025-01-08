#include <iostream>
#include "queue.h"
#include "tree.h"
using namespace std;

// Inserire qui sotto la dichiarazione della funzione treeSuccessor
Node *treeSuccessor(Node *, Node *);
bool getNext(coda &, const int, int &successor);
// Inserire qui sopra la dichiarazione della funzione treeSuccessor

int main()
{
    Node* root = nullptr;
    // create a BST
    root = inserisciNodo(root, 15);
    root = inserisciNodo(root, 10);
    root = inserisciNodo(root, 20);
    root = inserisciNodo(root, 8);
    root = inserisciNodo(root, 12);
    root = inserisciNodo(root, 25);


    Node *nodo, *successore;
    //esempio 1
    nodo = cercaNodo(root, 10); 
    successore = treeSuccessor(root, nodo);
    if (successore) {
        cout << "Il successore di " << nodo->data << " e' " << successore->data << std::endl;
    } else {
        cout << "Il nodo " << nodo->data << " non ha un successore." << std::endl;
    }

    //esempio 2
    nodo = cercaNodo(root, 12); 
    successore = treeSuccessor(root, nodo);
    if (successore) {
        cout << "Il successore di " << nodo->data << " e' " << successore->data << std::endl;
    } else {
        cout << "Il nodo " << nodo->data << " non ha un successore." << std::endl;
    }

    //esempio 3
    nodo = cercaNodo(root, 15); 
    successore = treeSuccessor(root, nodo);
    if (successore) {
        cout << "Il successore di " << nodo->data << " e' " << successore->data << std::endl;
    } else {
        cout << "Il nodo " << nodo->data << " non ha un successore." << std::endl;
    }

    return 0;
}

// Inserire qui sotto la definizione della funzione treeSuccessor
Node *treeSuccessor(Node *t, Node *toFind){
    Node *res=nullptr;
    if(toFind==nullptr) return res;
    if(cercaNodo(t, toFind->data)==nullptr) return res; //il numero dato non c'è nell'albero
    coda q=coda_init();
    fillQueueInOrder(t,q);
    //coda_print(q);
    int successor=0;
    bool res_next=getNext(q, toFind->data, successor);
    if(!res_next){
        coda_deinit(q);
        return res;
    }
    res=cercaNodo(t,successor);
    coda_deinit(q);
    return res;
}
bool getNext(coda &q, const int N, int &successor){
    int first=0;
    if(!coda_first(q,first)) return false;
    coda_dequeue(q);
    if(first==N){
        if(!coda_first(q,first)) return false;
        else{
            successor=first;
            return true;
        }
    }
    return getNext(q,N,successor);
}
// Inserire qui sopra la definizione della funzione treeSuccessor