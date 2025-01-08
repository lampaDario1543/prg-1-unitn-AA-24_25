#include <iostream>
#include "queue.h"
#include "tree.h"
using namespace std;

// Inserire qui sotto la dichiarazione della funzione treeSuccessor
Node *treeSuccessor(Node* root, Node* node);
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
Node* treeSuccessor(Node* root, Node* node) {
    if (root == nullptr || node == nullptr) {
        return nullptr;
    }

    // Inizializza la coda
    coda q = coda_init();

    Node* successor = nullptr;

    // Riempie la coda con i valori in ordine crescente
    fillQueueInOrder(root, q);

    // Cerca il successore
    bool found = false;
    int curr;
    while (coda_first(q, curr)) { // Ottiene il primo elemento della coda
        coda_dequeue(q);       // Rimuove l'elemento dalla coda

        if (found && successor == nullptr) {
            // Assegna il successore al primo valore trovato dopo il nodo
            successor = cercaNodo(root, curr);
        }

        if (curr == node->data) {
            found = true; // Nodo trovato, il successore è il prossimo elemento nella coda
        }
    }

    // Deinizializza la coda
    coda_deinit(q);

    // Ritorna il successore (può essere nullptr se non trovato)
    return successor;
}

// Inserire qui sopra la definizione della funzione treeSuccessor