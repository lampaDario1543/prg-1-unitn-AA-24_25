#include <iostream>
#include "queue.h"
#include "tree.h"
using namespace std;

// Inserire qui sotto la dichiarazione della funzione treeSuccessor

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

// Inserire qui sopra la definizione della funzione treeSuccessor