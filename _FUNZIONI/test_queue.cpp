#include <iostream>

using namespace std;
struct _SNode {
  int val;
  struct _SNode * next;
};

struct Queue {
  _SNode * first;
  _SNode * last;
};

Queue * init() {
  Queue * res = new Queue;
  res->first = res->last = NULL;
  return res;
}

bool isEmpty(Queue * s) {
  return s->first == NULL;
}

void enqueue(Queue * s, int i) {
  _SNode * n = new _SNode {i, NULL};
  if (s->last != NULL) {
    s->last->next = n;
  }
  s->last = n;
  if (s->first == NULL) s->first = n;
}

int dequeue(Queue *s) {
  int r = s->first->val;
  _SNode * t = s->first;
  s->first = s->first->next;
  if (s->first == NULL) s->last = NULL;
  delete t;
  return r;
}

void quit(Queue * & s) {
  for(_SNode * l = s->first; l!=NULL;) {
    _SNode * t = l;
    l=l->next;
    delete t;
  }
  delete s;
  s = NULL;
}

void visualizza(Queue *s){
    if(isEmpty(s))
        cout << "Queue is empty."<<endl;
    for(_SNode *l = s->first; l!=NULL; l=l->next)
        cout << l->val << " ";
    cout << endl;
}

int first(Queue *s){
    return s->first->val;
}
void reverse(Queue *&q){
    if(isEmpty(q))
        return;
    int v = dequeue(q);
    reverse(q);
    enqueue(q, v);
}

int lenght_rec(Queue *&q, int ctr=0){
    if(isEmpty(q))
        return ctr;
    int v = dequeue(q);
    ctr++;
    int res = lenght_rec(q, ctr);
    enqueue(q, v);
    return res;
}

int length(Queue * q) {
  int res=lenght_rec(q);
  reverse(q);
  return res;
}

    void FrontToLast(Queue *& q, int qsize) {
        if (qsize <= 0)
            return;
        
        enqueue(q, first(q));
        dequeue(q);
        FrontToLast(q, qsize - 1);
    }

    void pushInQueue(Queue *& q, int temp, int qsize) {
        if (isEmpty(q) || qsize == 0) {
            enqueue(q, temp);
            return;
        } else if (temp <= first(q)) {
            enqueue(q, temp);
            FrontToLast(q, qsize);
        } else {
            enqueue(q, first(q));
            dequeue(q);
            pushInQueue(q, temp, qsize - 1);
        }
    }

    void sort(Queue *& q) {
        if (isEmpty(q))
            return;
        int temp = first(q);
        dequeue(q);
        sort(q);
        pushInQueue(q, temp, length(q));
    }
void getNth_aux(Queue *&q, int i, int &res)
    {
        if(isEmpty(q)) return;
        int n = dequeue(q);
        if (i == 0)
            res = n;
        getNth_aux(q, i - 1, res);
        enqueue(q, n);
    }
    int getNth(Queue * & q, int pos) {
        int res;
        getNth_aux(q, pos, res);
        reverse(q);
        return res;
    }


void removeNth_aux(Queue *&q, int i, int &res)
    {
        if(isEmpty(q)) return;
            int n = dequeue(q);
            if (i == 0)
                res = n;
            removeNth_aux(q, i - 1, res);
            if(i!=0)
                enqueue(q, n);
    }
    int removeNth(Queue * & q, int pos) {
        int res;
        removeNth_aux(q, pos, res);
        reverse(q);
        return res;
    }
void contains_aux(Queue *&q, const int n, bool &r){
    if(isEmpty(q)) return;

    if(first(q)==n)
        r=true;
    int value = dequeue(q);
    contains_aux(q,n,r);
    enqueue(q,value);
    return;
}

bool contains(Queue *&q, const int n){
    bool res=false;
    contains_aux(q,n, res);
    reverse(q);
    return res;
} 
int sumElementsWithDistance_aux(Queue *& q, int n, int i) {
        if (isEmpty(q)) {
            return 0;
        }
        int current = dequeue(q);
        if(i == 0) {
            i = n;
            int sum = sumElementsWithDistance_aux(q,n,i);
            enqueue(q, current);
            // std::cout << "CURRENT ELEMENT: " << current << std::endl;
            return sum+current;
        }
        if(i <= n) {
            i--;
            int sum = sumElementsWithDistance_aux(q,n,i);
            enqueue(q, current);
            return sum;
        }
    }

    int sumElementsWithDistance(Queue *& q, int n) {
        int ris = sumElementsWithDistance_aux(q,n,0);
        reverse(q);
        return ris;
    }

void insertAtIndex(Queue*& q, int value, int index) {
        if (index < 1 || index > length(q) + 1) {
            std::cerr << "insertAtIndex Error: index out of range" << std::endl;
            return;
        }
        if (index == 1) {
            enqueue(q, value);
            return;
        }

        int tempValue = dequeue(q);
        insertAtIndex(q, value, index - 1);
        enqueue(q, tempValue);
    }
    
int main(){
    Queue *q = init();
    for(int i = 0; i < 10; i++)
        enqueue(q, 10-i);
    dequeue(q);
    visualizza(q);
    //cout << sumElementsWithDistance(q,0)<<endl;
    sort(q);
    visualizza(q);
    quit(q);
    return 0;
}