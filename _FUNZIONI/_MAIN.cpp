#include <iostream>

using namespace std;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*
####################
#######LISTE########
####################
*/
//liste del tipo 
    struct list
    {
        int num;
        list *next;
    };


//lunghezza lista
    int length (list * s) {
        int l = 0;
        for( ; s != nullptr; s = s->next) l++;
        return l;
    }


//visualizza lista:
    void visualizza(list *l){
        if(l==nullptr)
            cout << "List is empty."<<endl;
        for (list *s = l; s != nullptr; s = s->next)
            cout << s->num << " ";
        cout << endl;
    }


//inserisci nodo in testa
    void insert_first(list*&s, int v) {
        list * n = new list;
        n->num = v;
        n->next = s;
        s = n;
    }


//inserimento in posizione n:
    void insert_at(list*& head, int value, int n) {
        if (n < 0){
            cout << "La posizione non può essere negativa." << endl;
            return;
        }
        list* new_node = new list{value, nullptr};
        if (n == 0){
            new_node->next = head;
            head = new_node;
            return;
        }
        list* current = head;
        int pos = 0;
        while (current != nullptr && pos < n - 1){
            current = current->next;
            pos++;
        }
        if (current == nullptr) {
            cout << "La posizione è fuori dai limiti della lista." << endl;
            delete new_node;
            return;
        }
        new_node->next = current->next;
        current->next = new_node;
    }


//inserimento in ordine lista ordinata (ordine crescente) (serve anche insert_first)
    void insert_order(list * &p, int inform){
        if ((p==nullptr) || (p->num >= inform))
            insert_first(p, inform);
        else {
            list* q=p;
            while ((q->next != nullptr) && q->next->num <= inform) {
                q=q->next;
            }
            list* r = new list;
            r->num = inform;
            r->next = q->next;
            q->next = r;
        }
    }


//inserimento lista in coda:
    void insert_last(list * & p, int n){
        list * r = new list;
        r->num = n;
        r->next = nullptr;
        if (p != nullptr) {
            list * q = p;
            while(q->next != nullptr)
                q = q->next;
            q->next = r;
        }
        else 
            p = r;
    }


//rimuovi il secondo elemento in lista:
    /*
    Usage:
        list *t=remove_element(l);
        delete t;
    */
    list * remove_element(list *x) {
        list * y = x->next;
        x->next = y->next;
        y->next = nullptr;
        return y;
    }


//rimuovi primo elemento di una lista
    void remove_first(list * & s) {
        list * n = s;
        if (s != nullptr) {
            s = s->next;
            delete n;
        }
    }


//rimuovi elemento <val> da una lista (ATTENZIONE: ne rimuove solo uno (il primo che incontra))
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


//rimuovi ultimo elemento:
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


//rimuovi elemento in posizione n:
    void remove_at(list*& head, int n) {
        if (head == nullptr) {
            cout << "La posizione è fuori dai limiti della lista." << endl;
            return;
        }
        if (n < 0) {
            cout << "La posizione non può essere negativa." << endl;
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

    
//lista reverse:
    /*
    Usage:
        l=reverse(l);
    */
    list * reverse(list * x) {
        list * t;
        list * y = x;
        list * r = nullptr;
        while (y != nullptr ) {
            t = y->next;
            y->next = r;
            r = y;
            y = t;
        }
        return r;
    }


//sorting su lista
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
//elimina lista 
    void delete_list(list *&l)
    {
        while (l != nullptr)
        {
            list *t = l;
            l = l->next;
            delete t;
        }
    }


/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*
####################
##LISTE RICORSIVE###
####################
*/

//lunghezza lista ricorsivo
    int length(list* s) {
        if (s == nullptr)
            return 0;
        return 1 + length(s->next);
    }


//visualizza lista ricorsivo:
    void visualizza(list* l) {
        if (l == nullptr) {
            std::cout << std::endl;
            return;
        }
        std::cout << l->num << " ";
        visualizza(l->next);
    }


//inserimento elemento in lista in posizione n:
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


//inserimento in ordine ricorsivo (ordine decrescente)
    void insert_inorder(list * & res, int v) {
        if (res == nullptr)
            res = new list{v, nullptr};
        else {
            if (res->num < v) {
                res = new list{v, res};
            }
            else
            {
                insert_inorder(res->next, v);
            }
        }
    }



//rimuovi elemento in posizione n ricorsivo
    void remove_at(list*& head, int n) {
        if (head == nullptr) {
            cout << "La posizione è fuori dai limiti della lista." << endl;
            return;
        }
        if (n < 0) {
            cout << "La posizione non può essere negativa." << endl;
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



//lista reverse ricorsivo:
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


//elimina lista ricorsivo
    void delete_list(list*& l) {
        if (l == nullptr)
            return;
        list* next_node = l->next;
        delete l;
        l = nullptr;
        delete_list(next_node);
    }
/*---------------------------------------------------------------------------------------------------------------------------------------*/


/*
####################
##LISTE CIRCOLARI###
####################
*/
//lunghezza lista circolare:
int length (list * s, list * x) { //x primo elemento
    int l = 0;
    if (s != nullptr) {
        l = 1;
        for( s = s->next; s != x; s = s->next) l++;
    }
    return l;
}



/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*
####################
########STACK#######
####################
*/

//reverse stack
    void insertAtBottom(Stack *&s, int x) {
        if (isEmpty(s)) {
            push(s,x);
            return;
        }
        int topElement = top(s);
        pop(s);
        insertAtBottom(s, x);
        push(s,topElement);
    }
    void reverse(Stack *& s) {
        if (isEmpty(s))
            return;
        int topElement = top(s);
        pop(s);
        reverse(s);
        insertAtBottom(s, topElement);
    }



//lunghezza stack:
    int length(Stack *s, int ctr=0){
        if(s==nullptr)
            return ctr;
        return length(s->next, ctr+1);
    }



//stack vuoto:
    bool isEmpty(Stack *s)
    {
        return (s == nullptr);
    }



//ottieni elemento in posizione n:
//va da 0 a length-1
    int getNth(Stack *&s, int n){
        if(n==0)
            return top(s);
        int value = pop(s);
        int res = getNth(s,n-1);
        push(s,value);
        return res;
    }



// Elimina un elemento in posizione n in uno Stack:
    int removeNth(Stack *&s, int n){
        if(n==0)
            return pop(s);
        int value = pop(s);
        int res = removeNth(s,n-1);
        push(s,value);
        return res;
    }



//controlla se uno stack contiene un elemento:
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
/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*
####################
#######QUEUE########
####################
*/

// reverse coda:
    void reverse(Queue *&q){
        if(isEmpty(q))
            return;
        int v = dequeue(q);
        reverse_rec(q);
        enqueue(q, v);
    }



//lunghezza coda:
//ATTENZIONE: IMPLEMENTARE ENTRAMBE LE FUNZIONI E ANCHE REVERSE.
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



//ottieni elemento in posizione n:
//va da 0 a length-1
//ATTENZIONE: necessita di reverse e isEmpty
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


//rimuove un elemento in posizione N:
//va da 0 a length-1
//ATTENZIONE: necessita di reverse e isEmpty
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



//controlla se una coda contiene un elemento:
//ATTENZIONE: necessita di reverse e isEmpty
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
/*---------------------------------------------------------------------------------------------------------------------------------------*/


/*
####################
#####RICORSIONE#####
####################
*/

//somma delle cifre di un numero.
    int sum(int n)
    {
        if (n == 0)
            return n % 10;
        return sum(n / 10) + n % 10;
    }


//lunghezza stringa
    int len(char *s, int i){
        if(s[i]=='\0')
            return 0;
        return len(s,i+1)+1;
    }



/*---------------------------------------------------------------------------------------------------------------------------------------*/



/*
####################
#####ALGORITMI######
####################
*/

//scambio di due numeri
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }


//visualizza array
    void visualizza(int *v, const int DIM){
        for(int i=0;i< DIM;i++)
            cout << v[i] << " ";
        cout <<endl;
    }


//sorting di un array
    void sort(int *v, const int DIM){
        for(int i=0;i< DIM-1; i++){
            for(int j=i+1;j<DIM;j++){
                if(v[i]>v[j])
                    swap(v[i],v[j]);
            }
        }
    }


//ricerca dicotomica
//ATTENZIONE l'array deve essere ordinato in modo crescente
    int ricercaDicotomica(int v[], const int DIM, int target) {
        sort(v,DIM);
        int inizio = 0;
        int fine = DIM - 1;

        while (inizio <= fine) {
            int medio = inizio + (fine - inizio) / 2;

            if (v[medio] == target) {
                return medio; // Elemento trovato, ritorna l'indice
            }
            if (v[medio] < target) {
                inizio = medio + 1; // Cerca nella parte destra
            } else {
                fine = medio - 1; // Cerca nella parte sinistra
            }
        }
        return -1; // Elemento non trovato
    }


//conta occorrenze in array
    int getOcc(int *v, const int DIM, int target) {
        int ctr=0;
        for(int i=0;i<DIM;i++)
            if(v[i]==target)
                ++ctr;
        return ctr;
    }


//converti decimale in binario:
    int dec2bin(int n){
        if(n==0)
            return 0;
        int val=n%2;
        return val+(10*dec2bin(n/2));
    }


//potenza di un numero
    int pow(int base, int exp){
        if(exp==0)
            return 1;
        else
            return pow(base, exp-1)*base;
    }


//array binario a decimale
    int bin2dec(int *v, const int DIM){
        int ris = 0;
        for (int i = 0; i < DIM; i++){
            ris += v[i] * pow(2, (DIM - i - 1));
        }
        return ris;
    }


//conversione binario a decimale di un int
    int convert2dec(int n){
        int res=0;
        int cifre=0;
        int cifra=0;
        while((n/10)!=0){
            cifra=n%10;
            res+=cifra*pow(2,cifre);
            ++cifre;
            n/=10;
        }
        cifra=n%10;
        res+=(cifra)*pow(2,cifre);
        return res;
    }



//convertitore da qualsiasi base a decimale.
    int convert(char *s, const int base){
        int res=0;
        const int len=strlen(s);
        for(int i=0;s[i]!='\0';i++){
            int digit = s[i] - '0';
            if(s[i]>='A' && s[i]<='Z')
                digit = s[i] - 'A' + 10;
            res += digit * pow(base, len-i-1);
        }
        return res;
    }



//right shift circolare
    void right_shift(int *v, const int DIM, int n)
    {
        n = (n % DIM);
        if (n == 0)
            return;
        for (int i = 0; i < n; i++)
        {
            int prev = v[0];
            v[0] = v[DIM - 1];
            for (int j = 1; j < DIM; j++)
            {
                int prev2 = v[j];
                v[j] = prev;
                prev = prev2;
            }
        }
    }


//left shift circolare su array
    void left_shift(int *v, const int DIM, int n){
        n = (n % DIM);
        if (n == 0)
            return;
        for (int i = 0; i < n; i++)
        {
            int prev = v[DIM - 1];
            v[DIM - 1] = v[0];
            for (int j = DIM - 2; j >= 0; j--)
            {
                int prev2 = v[j];
                v[j] = prev;
                prev = prev2;
            }
        }
    }



//conta cifre
    int count_digits(int n){
        if(n==0)
            return 0;
        return 1+count_digits(n/10);
    }



//conta sottostringhe (substring):
//ATTENZIONE NECESSITA' DI CSTRING
    int subStringOcc(char *word, char *toFind){
        int occ=0;
        char *newWord=word;
        while((newWord=strstr(newWord, toFind))!=nullptr){
            (newWord)++;
            ++occ;
        }
        return occ;
    }