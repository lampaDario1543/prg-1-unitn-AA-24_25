#include <iostream>
#include <cstdlib>
#include <cassert>

// Non modificare questa parte sotto del codice
typedef struct Stack {
    int data;
    struct Stack * next;
} Stack;

struct Stack * initStack() {
    return nullptr;
}

bool isEmpty(struct Stack * s) {
    return (s == nullptr);
}

void push(struct Stack * &s, int value) {
    struct Stack * newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack * s) {
    if (isEmpty(s)) {
        std::cerr << "Error: stack is empty" << std::endl;
        exit(1);
    }
    return s->data;
}

int pop(struct Stack * &s) {
    if (isEmpty(s)) {
        std::cerr << "Error: stack is empty" << std::endl;
        exit(1);
    }
    int value = s->data;
    struct Stack * temp = s;
    s = s->next;
    delete temp;
    return value;
}

void deleteStack(struct Stack * &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(struct Stack * s, const char * message = "Stack: ") {
    if (isEmpty(s)) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << message;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
// Non modificare questa parte sopra del codice

// Inserire qui sotto la dichiarazione della funzione calcola
Stack * calcola(Stack *&);
int lenght(struct Stack *s)
{
    int count = 0;
    struct Stack *temp = s;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void calcola_aux(Stack *&s, Stack *&res, int, const int );
int getOcc(Stack *&s,int i,const int DIM, const int N,  bool toSkip);
// Inserire qui sopra la dichiarazione della funzione calcola


int main() {
    struct Stack *s, *result;
    unsigned int seed = (unsigned int)time(NULL);
    // seed = 60000
    seed = 1697033220;
    srand(seed);

    s = initStack();
    for (int i = 0; i < 5; i++) {
        if (i != 2) push(s, 5-i);
    }
    printStack(s, "Original before: ");
    result = calcola(s);
    printStack(result, "Result of calcola: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    s = initStack();
    for (int i = 0; i < 10; i++) {
        push(s, rand() % 10);
    }
    printStack(s, "Original before: ");
    result = calcola(s);
    printStack(result, "Result of calcola: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    s = initStack();
    result = calcola(s);
    printStack(result, "Result of calcola: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    return 0;
}

// Inserire qui sotto la definizione della funzione calcola
Stack * calcola(Stack *&s){
    Stack *res=initStack();
    if(isEmpty(s))
        return res;
    const int DIM=lenght(s);
    calcola_aux(s, res, 0, DIM);
    return res;
}
void calcola_aux(Stack *&s, Stack *&res, int i, const int DIM){
    if(i==DIM)
        return;
    int n=pop(s);
    calcola_aux(s,res,i+1, DIM);
    int occ=getOcc(res, 0,lenght(res),n,false);
    push(res, occ+1);
    push(res, n);
    push(s,n);
}
int getOcc(Stack *&s,int i,const int DIM, const int N,  bool toSkip){
    if(isEmpty(s))
        return 0;
    if(i==DIM-1){
        int n=top(s);
        if(n==N && !toSkip) return 1;
        else return 0;
    }
    int n=pop(s);
    int res=0;
    if(!toSkip && n==N){
        res= 1+getOcc(s,i+1, DIM, N, !toSkip);
    }else
        res=getOcc(s,i+1,DIM, N,!toSkip);
    push(s, n);
    return res;
}
// Inserire qui sopra la definizione della funzione stackOperator
