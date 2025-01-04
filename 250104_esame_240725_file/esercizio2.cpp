#include <iostream>
#include <cstdlib>
#include <cassert>

// Non modificare questa parte sotto del codice
typedef struct List {
    int data;
    struct List * next;
} List;

typedef struct Queue {
    List * head;
    List * tail;
} Queue;

Queue * initQueue() {
    return new Queue {nullptr, nullptr};
}

bool isEmpty(Queue * s) {
    return ((s != nullptr) && (s->head == s->tail) && (s->head == nullptr));
}

void enqueue(Queue * &s, int value) {
    if (s == nullptr) {
        std::cerr << "enqueue Error: the queue is nullptr" << std::endl;
        assert(false);
        exit(1);
    }
    List * newElement = new List {value, nullptr};
    if (isEmpty(s)) {
        s->tail = s->head = newElement;
    } else {
      s->tail->next = newElement;
      s->tail = newElement;
    }
}

int first(Queue * s) {
    if (isEmpty(s)) {
        std::cerr << "first Error: the queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->head->data;
}

int dequeue(Queue * &s) {
    if (isEmpty(s)) {
        std::cerr << "dequeue Error: queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    int value = s->head->data;
    List * temp = s->head;
    if (s->head == s->tail) {
        s->head = s->tail = nullptr;
    } else {
        s->head = s->head->next;
    }
    delete temp;
    return value;
}

int length(Queue * s) {
    int count = 0;
    List * temp = s->head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

    void reverse(Queue * & s) {
        if (!isEmpty(s)) {
            int v = dequeue(s);
            reverse(s);
            enqueue(s, v);
        }
    }

void deleteQueue(Queue * &s) {
    while (!isEmpty(s)) {
        dequeue(s);
    }
}

void printQueue(Queue * s, const char * message = "Queue: ") {
    if (isEmpty(s)) {
        std::cout << message << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        List * temp = s->head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
// Non modificare questa parte sopra del codice

// Inserire qui sotto la dichiarazione della funzione calcola
void calcola(Queue *&, Queue *&);
void calcola_aux(Queue *&q1,Queue *& q2,int N, int i=0);
void getEl(Queue *&q2, int,int &, int i=0);
// Inserire qui sopra la dichiarazione della funzione calcola

int main() {
    Queue *q1, *q2;
    unsigned int seed = (unsigned int)time(NULL);
    // seed = 60000
    seed = 1697033220;
    srand(seed);

    q1 = initQueue();
    q2 = initQueue();
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) enqueue(q1, 10-i);
        else enqueue(q2, 10-i);
    }
    printQueue(q1, "Q1: ");
    printQueue(q2, "Q2: ");
    calcola(q1, q2);
    printQueue(q1, "NQ1: ");
    printQueue(q2, "NQ2: ");
    deleteQueue(q1);
    deleteQueue(q2);
    
    q1 = initQueue();
    q2 = initQueue();
    for (int i = 0; i < 10; i++) {
        enqueue(q1, rand() % 10);
        enqueue(q2, rand() % 10);
    }
    printQueue(q1, "Q1: ");
    printQueue(q2, "Q2: ");
    calcola(q1, q2);
    printQueue(q1, "NQ1: ");
    printQueue(q2, "NQ2: ");
    deleteQueue(q1);
    deleteQueue(q2);

    q1 = initQueue();
    q2 = initQueue();
    printQueue(q1, "Q1: ");
    printQueue(q2, "Q2: ");
    calcola(q1, q2);
    printQueue(q1, "NQ1: ");
    printQueue(q2, "NQ2: ");
    deleteQueue(q1);
    deleteQueue(q2);

    return 0;
}
// Inserire qui sotto la definizione della funzione calcola

void getEl(Queue *&q, int DIM,int &res, int i){
    if(isEmpty(q)) return;
    int n= dequeue(q);
    if(i==DIM-1) res=n;
    getEl(q,DIM, res, i+1);
    enqueue(q,n);
}


void calcola_aux(Queue *&q1,Queue *& q2,int N, int i){
    if(i==N) return;
    int el=dequeue(q1);
    int el2=0;
    getEl(q2, N-i, el2);
    reverse(q2);
    calcola_aux(q1,q2,N,i+1);
    enqueue(q1, el+el2);
}

void calcola(Queue *&q1, Queue *&q2){
    if(isEmpty(q1) || isEmpty(q2)) return;
    const int N= length(q1);
    calcola_aux(q1,q2,N);
    reverse(q1);
}
// Inserire qui sopra la definizione della funzione calcola
