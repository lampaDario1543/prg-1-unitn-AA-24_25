#include <iostream>
#include "tree.h"
#include "queue.h"


Node* creaNodo(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


Node* inserisciNodo(Node* root, int data){
    //caso base: albero vuoto
    if (root == nullptr) { 
        return creaNodo(data);
    }

    if (data < root->data) {
        root->left = inserisciNodo(root->left, data);
    }
    else if (data > root->data) {
        root->right = inserisciNodo(root->right, data);
    }
    return root;
}


Node* cercaNodo(Node* root, int key){
    // la radice è nulla o il nodo da cercare è la radice
    if (root == nullptr || root->data == key) {
        return root;
    }
    // il nodo da cercare è nel ramo di destra
    if (root->data < key) {
        return cercaNodo(root->right, key);
    }
    // il nodo da cercare è nel ramo di sinistra
    return cercaNodo(root->left, key);
}


void fillQueueInOrder(Node* root, coda& q) {
    if (root == nullptr) {
        return;
    }

    // Visita in ordine: sinistra -> radice -> destra
    fillQueueInOrder(root->left, q);
    coda_enqueue(q, root->data); // Inserisce il valore del nodo nella coda
    fillQueueInOrder(root->right, q);
}

