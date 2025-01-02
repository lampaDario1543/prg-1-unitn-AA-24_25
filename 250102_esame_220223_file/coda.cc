// Inserisci qui il codice implementazione delle funzioni in coda.h
#include "coda.h"
#include <iostream>

const int DIM=11;
static int v[DIM];
static int idxQ2;
static int dimQ1;
static int dimQ2;


void init(){
    idxQ2=DIM-1;
    dimQ1=0;
    dimQ2=0;
}

bool enqueue(int n){
    bool res=true;
    if(dimQ1> DIM/2 && dimQ2 >= DIM/2) return !res;
    if(dimQ1<=dimQ2){
        v[dimQ1]=n;
        ++dimQ1;
    }else{
        v[idxQ2]=n;
        ++dimQ2;
        --idxQ2;
    }
    return res;
}

bool firstS1(int& n){
    if(dimQ1 == 0) return false;
    n=v[0];
    return true;
}
bool firstS2(int& n){
    if(dimQ2 == 0) return false;
    n=v[DIM-1];
    return true;
}

bool dequeueS1(){
    if(dimQ1==0) return false;
    for(int i=1;i< dimQ1;i++)
        v[i-1]=v[i];
    --dimQ1;
    return true;
}

// rimuove il primo elemento della sotto-coda del secondo sportello
bool dequeueS2(){
    if(dimQ2==0) return false;
    for(int i=0;i<dimQ2-1;i++)
        v[(DIM-1)-i]=v[(DIM-1)-i-1];
    --dimQ2;
    ++idxQ2;
    return true;
    return true;
}

void deinit(){
    idxQ2=DIM-1;
    dimQ1=0;
    dimQ2=0;
}

void print(){
    std::cout << "S1: ";
    for(int i=0;i< dimQ1;i++)
        std::cout << v[i]<< " ";
    std::cout <<std::endl;
    std::cout << "S2: ";
    for(int i=0;i<dimQ2;i++)
        std::cout << v[(DIM-1)-i]<< " ";
    std::cout <<std::endl;
}