/*
Scrivere un programma che, dato un intero positivo N, crei
dinamicamente e stampi un array contenente i primi N numeri
esagonali, partendo da 0.
L’i-esimo numero esagonale è uguale a
Nota: non si possono usare cicli
*/
#include <iostream>

using namespace std;

void getHex(int *, const int);
void getHex(int *, int ,const int);
void visualizza(int *, const int);
int main(){
    int N=0;
    do{
        cout << "Inserisci dimensione: ";
        cin >> N;
    }while(N<=0);
    int *v=new int[N];
    getHex(v,N);
    visualizza(v,N);
    delete []v;
    return 0;
}
void getHex(int *v, const int DIM){
    return getHex(v, 0, DIM);
}

void getHex(int *v, int i,const int DIM){
    if(i==DIM)
        return;
    v[i]=i*((2*i)-1);
    getHex(v,i+1,DIM);
}

void visualizza(int *v, const int DIM){
    for(int i=0;i< DIM;i++)
        cout << v[i]<< " ";
    cout << endl;
}