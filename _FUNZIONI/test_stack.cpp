#include <iostream>
#include <cassert>

using namespace std;

typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;

typedef struct List
{
    int data;
    struct List *next;
} List;

struct Stack *initStack()
{
    return nullptr;
}

bool isEmpty(struct Stack *s)
{
    return (s == nullptr);
}

void push(struct Stack *&s, int value)
{
    struct Stack *newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack *s)
{
    if (isEmpty(s))
    {
        std::cerr << "top Error: stack is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->data;
}

int pop(struct Stack *&s)
{
    if (isEmpty(s))
    {
        std::cerr << "pop Error: stack is empty" << std::endl;
        assert(false);
        exit(1);
    }
    int value = s->data;
    struct Stack *temp = s;
    s = s->next;
    delete temp;
    return value;
}

/*int lenght(struct Stack *s)
{
    int count = 0;
    struct Stack *temp = s;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}*/
int lenght_rec(Stack *s, int ctr=0){
    if(s==nullptr)
        return ctr;
    return lenght_rec(s->next, ctr+1);
}

int lenght(Stack *s){
    Stack *temp = s;
    return lenght_rec(temp);
}



void deleteStack(struct Stack *&s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
}

void printStack(struct Stack *s, const char *message = "Stack: ")
{
    if (isEmpty(s))
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        struct Stack *temp = s;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void reverse(Stack *&);
void insertAtBottom(Stack *&, int);
int getNth(Stack *&s, int n);


int removeNth(Stack *&s, int n){
        if(n==0)
            return pop(s);
        int value = pop(s);
        int res = removeNth(s,n-1);
        push(s,value);
        return res;
    }
bool contains(Stack *&s, const int n){
        if(isEmpty(s))
            return false;
        else if(top(s)==n)
            return true;
        int value = pop(s);
        int res = contains(s,n);
        push(s,value);
        return res;
    }

int main(){
    Stack *s = initStack();
    for(int i=0;i<10;i++)
        push(s,i);
    printStack(s);
    reverse(s);
    pop(s);
    printStack(s);
    cout << contains(s, 1)<<endl;
    pop(s);
    printStack(s);
    cout << lenght_rec(s) << endl;
    deleteStack(s);
    return 0;
}

void insertAtBottom(Stack *&s, int x) {
    if (isEmpty(s)) {
        push(s,x);
        return;
    }
    int topElement = top(s);
    pop(s);
    insertAtBottom(s, x);  // Chiamata ricorsiva
    push(s,topElement);    // Ripristina l'elemento
}

// Funzione per invertire lo stack
void reverse(Stack *& s) {
    if (isEmpty(s)) {
        return;
    }
    int topElement = top(s);
    pop(s);
    reverse(s);           // Chiamata ricorsiva
    insertAtBottom(s, topElement);  // Inserisce l'elemento in fondo
}
//without modify the stack

int getNth(Stack *&s, int n){
    if(n==0){
        return top(s);
    }
    int value = pop(s);
    int res = getNth(s,n-1);
    push(s,value);
    return res;
}