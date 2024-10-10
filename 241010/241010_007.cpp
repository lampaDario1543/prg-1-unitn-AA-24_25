/*
implementere bubblesort in modo completamente ricorsivo
*/
#include <iostream>

using namespace std;

const int DIM = 5;

void sort(int *);
void sort(int *, int, int); //ricorsivo
void visualizza(int *);

int main()
{
    int v[DIM] = {5, 4, 3, 2, 1};
    visualizza(v);
    sort(v);
    visualizza(v);
    return 0;
}

void visualizza(int *v)
{
    for (int i = 0; i < DIM; i++)
        cout << v[i] << " ";
    cout << endl;
}

void sort(int *v, int i, int j){
    if(i==DIM-1){
        return;
    }
    if(j==DIM-1){
        return sort(v,i+1,0);
    }
    if(v[j]>v[j+1]){
        int box = v[j];
        v[j] = v[j+1];
        v[j+1] = box;
        return sort(v,i,j+1);
    }
    return sort(v,i,j+1);
}

void sort(int *v){
    /*for (int i = 0; i < DIM-1; i++){
        for (int j = 0; j < DIM-1; j++){
            if (v[j] > v[j+1]){
                int box = v[j];
                v[j] = v[j+1];
                v[j+1] = box;
            }
        }
    }*/
   sort(v,0,0);
}