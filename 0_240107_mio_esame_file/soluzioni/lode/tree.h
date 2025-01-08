#include "queue.h"
#ifndef TREE_H
#define TREE_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* creaNodo(int data);

Node* inserisciNodo(Node* root, int data);

void inorderTraversal(Node* root);

Node* cercaNodo(Node* root, int key);

// Funzione per riempire la coda con i valori in ordine crescente
void fillQueueInOrder(Node* root, coda& q);

#endif 
