/*
Aggiungere una quarta e ultima funzione al programma:
void primizzaLista(lista listaDiNumeri);
che scorre la lista e rimuove tutti i numeri che non sono primi.
*/

#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

void carica(Node *&, fstream &);
void visualizza(Node *);
void insert(Node *, int);
void deleteList(Node *&);
void printReverse(Node *);
bool isPrime(int);
void primizzaLista(Node *&);
Node *removeNode(Node *&);

int main(){
    char filename[30];
    cout << "Filename: ";
    cin >> filename;
    fstream in;
    in.open(filename, ios::in);
    if (in.fail()){
        cerr << "Il file " << filename << " non esiste." << endl;
        exit(0);
    }
    Node *l = new Node;
    l->val = 0;
    l->next = nullptr;
    carica(l, in);
    cout << "Lista normale: ";
    visualizza(l);
    cout << "Lista reverse: ";
    printReverse(l);
    cout << endl;
    primizzaLista(l);
    cout << "No primi: ";
    visualizza(l);
    deleteList(l);
    return 0;
}

void visualizza(Node *l){
    for (Node *s = l; s != nullptr; s = s->next)
        cout << s->val << " ";
    cout << endl;
}

void carica(Node *&l, fstream &in){
    int n = 0;
    bool flag = true;
    while (!in.eof()){
        in >> n;
        if (flag){
            l->val = n;
            flag = !flag;
        }
        else
            insert(l, n);
    }
}

void insert(Node *l, int n){
    Node *t = new Node;
    t->val = n;
    t->next = l->next;
    l->next = t;
}

void deleteList(Node *&l){
    if (l->next == nullptr)
        delete l;
    else{
        deleteList(l->next);
        delete l;
    }
}

void printReverse(Node *l){
    if (l->next == nullptr)
        cout << l->val << " ";
    else{
        printReverse(l->next);
        cout << l->val << " ";
    }
}

Node *removeNode(Node *&l){
    Node *y = l->next;
    l->next = y->next;
    y->next = nullptr;
    return y;
}

void primizzaLista(Node *&l){
    while (l != nullptr && !isPrime(l->val)){ // controllo sul primo nodo
        Node *n = l;
        l = l->next;
        delete n;
    }

    if (l == nullptr)
        return;
    
    Node *curr = l;
    
    while (curr->next != nullptr){
        if (!isPrime(curr->next->val)){
            Node *t = removeNode(curr);
            delete t;
        }
        else
            curr = curr->next;
    }
}

bool isPrime(int n){
    for (int i = 2; i < n; i++)
        if ((n % i) == 0)
            return false;
    return true;
}