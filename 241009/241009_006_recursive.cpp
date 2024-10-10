/*
scrivere una procedura che prenda un vettore v e la sua dimensione
  d, un elemento x, ed elimina tutte le occorrenze di x (diminuemdo la
  dimensione d del vettore)

Esempio:
v = [4 1 3 6 8 4 2]
d = 7
x = 4
===>
v = [1 3 6 8 2]
d = 5

IN MODO RICORSIVO
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 10;

void carica(int *);
void carica(int *, int); //carica ricosivo
void visualizza(int *, int);
void visualizza(int *, int, int); //visualizza ricorsivo
void remove_occ(int *, int, int &);
void remove_occ(int *, int,int, int &); //ricorsivo
void left_shift(int *, int, int);
void left_shift(int *,int,int,int); //left_shift ricorsivo

int main(){
    time_t seed = time(NULL);
    cout << "Seed random numbers generator= " << seed << endl
         << endl;
    srand(seed);
    int v[DIM];
    int d = DIM;
    carica(v);
    visualizza(v, d);
    remove_occ(v, 5, d);
    visualizza(v, d);
    cout << "d= " << d << endl;
    return 0;
}

void visualizza(int *v, int i, int dim){
    if(i==(dim-1)){
        cout << v[i] << endl;
        return;
    }else{
        cout << v[i]<<" ";
        return visualizza(v,i+1,dim);
    }
}

void visualizza(int *v, int d){
    return visualizza(v,0,d);
}
void carica(int *v, int i){
    if(i==DIM){
        return;
    }else{
        v[i]=(rand()%10)+1;
        return carica(v,i+1);
    }
}
void carica(int *v){
    return carica(v,0);
}
void left_shift(int *v, int i, int dim, int box){
    if(i==dim){
        v[i]=box;
        return;
    }else{
        int box2=v[i];
        v[i]=box;
        return left_shift(v,i-1,dim,box2);
    }
}
void left_shift(int *v, int idx, int d){
    if(d-2>=idx){
        left_shift(v,d-2,idx,v[d-1]);
    }
    return;
}
void remove_occ(int *v, int i,int n, int &d){
    if(i==d){
        return;
    }else{
        if(v[i]==n){
            left_shift(v,i,d);
            i-=1; //non andrebbe fatto, è terribile.
            --d;
        }
        return remove_occ(v,i+1,n,d);
    }
}
void remove_occ(int *v, int n, int &d){
   return remove_occ(v,0,n,d);
}