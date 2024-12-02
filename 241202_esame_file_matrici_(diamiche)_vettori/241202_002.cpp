/*
Es. 2 Appello Febbraio 2011

Scrivere un programma che verifichi se un array di interi “pattern” è
contenuto in un altro array di interi “testo”. Generare randomicamente i
due array (è concesso l’uso della funzione rand() nella libreria
<cstdlib>) con una dimensione fissata a priori (massimo 100).

Non per forza ricorsivo? ~LD
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void carica(int *, const int);
void visualizza(int *, const int);
bool hasPattern(int *, const int, int *, const int);
int getFirst(int *, const int,const int, const int);

int main(){
    time_t seed= time(NULL);
    cout << "Random seed generator: "<< seed<<endl<<endl;
    srand(seed);
    const int DIM1=6;
    const int DIM2=3;
    //int v1[DIM1]={4,5,9,1,7,3};
    //int v2[DIM2]={9,1,7};
    int v1[DIM1];
    int v2[DIM2];
    carica(v1, DIM1);
    carica(v2, DIM2);
    cout << "v1: ";
    visualizza(v1,DIM1);
    cout << "v2: ";
    visualizza(v2,DIM2);
    cout << (!hasPattern(v1,DIM1, v2, DIM2) ? "Non " : "") << "c'e' un pattern"<<endl;
    return 0;
}

void carica(int *v, const int DIM){
    for(int i=0;i < DIM; i++)
        v[i]= rand()%10+1;
}
void visualizza(int *v, const int DIM){
    for(int i=0;i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}

int getFirst(int *v, const int DIM, const int start, const int n){
    int i=start;
    while(i<DIM){
        if(v[i]==n)
            return i;
        ++i;
    }
    return -1;
}

bool hasPattern(int *v1, const int DIM1, int *v2, const int DIM2){
    int first=0;
    int start=0;
    while(((first=getFirst(v1, DIM1,start, v2[0]))!=-1) && (first+(DIM2-1))<DIM1-1){
        start=first+1;
        int ctr=1;
        for(int i=start; i<start+(DIM2-1);i++){
            if(v1[i]==v2[(i-start)+1])
                ++ctr;
        }
        if(ctr==DIM2)
            return true;
    }
    return false;
}
