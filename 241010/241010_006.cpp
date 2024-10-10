/*
* implementare la linear search in modo ricorsivo
*/
#include <iostream>

using namespace std;

const int DIM = 5;

bool search(int *,int);
bool search(int *, int, int ); //ricorsivo

int main(){
    int v[DIM]={1,2,3,4,5};
    int n=3;
    if(search(v,n)){
        cout << "Elemento trovato."<<endl;
    }else{
        cout << "Elemento NON trovato."<<endl;
    }
    return 0;
}

bool search(int *v, int i, int n){
    if(i==DIM)
        return false;
    else if(v[i]==n)
        return true;
    else
        return search(v,i+1,n);
}

bool search(int *v,int n){
    return search(v,0,n);
}