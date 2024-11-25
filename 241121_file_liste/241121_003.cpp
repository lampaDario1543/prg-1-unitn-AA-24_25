/*
Aggiungere una terza funzione al programma:
void stampaListaInvertita(lista listaDiNumeri);
che stampa la lista in maniera invertita.
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
    if(l->next==nullptr)
        cout << l->val << " ";
    else{
        printReverse(l->next);
        cout << l->val << " ";
    }
} 