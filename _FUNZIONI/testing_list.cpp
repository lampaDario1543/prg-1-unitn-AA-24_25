#include <iostream>
#include <cstdlib>

using namespace std;

struct list{
    int num;
    list *next;
};

void insert_first(list*&s, int v) {
    list * n = new list;
    n->num = v;
    n->next = s;
    s = n;
}
void visualizza(list* l) {
    if (l == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << l->num << " ";
    visualizza(l->next);
}
void delete_list(list*& l) {
    if (l == nullptr)
        return;
    list* next_node = l->next;
    delete l;
    l = nullptr;
    delete_list(next_node);
}

void insert_order(list * &p, int inform){
    if ((p==NULL) || (p->num >= inform))
        insert_first(p, inform);
    else {
        list* q=p;
        while ((q->next != NULL) && q->next->num <= inform) {
            q=q->next;
        }
        list* r = new list;
        r->num = inform;
        r->next = q->next;
        q->next = r;
    }
}

void insert_last(list * & p, int n) {
    list * r = new list;
    r->num = n;
    r->next = NULL;
    if (p != NULL) {
        list * q = p;
        while(q->next != NULL)
            q = q->next;
        q->next = r;
    }
    else 
        p = r;
}
list * remove_element(list *x) {
    list * y = x->next;
    x->next = y->next;
    y->next = NULL;
    return y;
}
void remove_first(list * & s) {
    list * n = s;
    if (s != NULL) {
        s = s->next;
        delete n;
    }
}
void search_remove(list* &p, int val){
        if (p != nullptr) {
            list* q = p;
            if (q->num == val) {
                p = p->next;
                delete q;
            }
            else {
                while(q->next != nullptr) {
                    if (q->next->num == val) {
                        list* r = q->next;
                        q->next = q->next->next;
                        delete r;
                        return;
                    }
                    if (q->next != nullptr)
                        q=q->next;
                }
            }
        }
    }
void remove_last(list * & s) {
    if (s != nullptr) {
        if (s->next == nullptr) {
            delete s;
            s = nullptr;
        } else {
            list *p = s;
            while (p->next->next != nullptr)
                p = p->next;
            delete p->next;
            p->next = nullptr;
        }
    }
}
//reverse ricorsivo
void reverse_list(list*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    list* rest = head->next; 
    reverse_list(rest);
    head->next->next = head;
    head->next = nullptr;    
    head = rest;             
}

int length(list* s) {
    if (s == nullptr) {
        return 0; // Caso base: lista vuota, lunghezza 0
    }
    return 1 + length(s->next); // Passo ricorsivo: somma 1 e passa al nodo successivo
}

void insert_at(list*& head, int value, int n) {
    if (n < 0) {
        std::cout << "La posizione non può essere negativa." << std::endl;
        return;
    }
    if (n == 0) {
        list* new_node = new list{value, head};
        head = new_node;
        return;
    }
    if (head == nullptr) {
        cout << "La posizione è fuori dai limiti della lista." << std::endl;
        return;
    }
    insert_at(head->next, value, n - 1);
}

void remove_at(list*& head, int n) {
    if (head == nullptr) {
        std::cout << "La posizione è fuori dai limiti della lista." << std::endl;
        return;
    }

    if (n < 0) {
        std::cout << "La posizione non può essere negativa." << std::endl;
        return;
    }

    if (n == 0) {
        list* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    remove_at(head->next, n - 1);
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(list* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        list* current = head;
        while (current->next != nullptr) {
            if (current->num > current->next->num) {
                swap(current->num, current->next->num);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

int count_digits(int n){
        if(n==0)
            return 0;
        return 1+count_digits(n/10);
    }
void insert_inorder(list * & res, int v) {
        if (res == nullptr)
            res = new list{v, nullptr};
        else {
            if (res->num > v) {
                res = new list{v, res};
            }
            else
            {
                insert_inorder(res->next, v);
            }
        }
    }
int main(){
    list *l=nullptr;
    /*for(int i=0;i< 10;i++)
        insert_inorder(l, rand()%80);*/
    insert_first(l,1);
    insert_first(l,2);
    visualizza(l);
    insert_at(l,669,1);
    visualizza(l);
    cout << "Len= "<< length(l);
    delete_list(l);
    return 0;
}