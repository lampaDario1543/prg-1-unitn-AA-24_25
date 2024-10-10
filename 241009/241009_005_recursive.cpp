/*
scrivere una procedura che prenda in ingresso un vettore v e la sua
dimensione d, un nuovo elemento x e un indice i, e aggiunga
l'elemento x in posizione i nel vettore, e incrementi d di uno.  Il
vettore passato deve avere almeno d+1 elementi.

Esempio:
v = [4 1 3 6 8]
d = 5
x = 7
i = 2
===>
v = [4 1 7 3 6 8]
d = 6

IN MODO RICORSIVO
*/
#include <iostream>

using namespace std;

const int DIM = 100;

bool add_element(int *, int &, int, int);
void shift(int *, int, int,int);
void visualizza(int *, int);
void visualizza(int *, int, int); //visualizza ricorsivo

int main(){
    int v[DIM];
    int d = 1;
    int i = 0;
    int n = 0;
    // inizializzo vettore

    //queste due non sono ricorsive perché non avevo voglia (poi l'esercizio non richiede di inizializzarlo.)
    for (int j = 0; j < 4; j++){
        v[j] = j + 1;
        ++d;
    }
    for (int j = 4; j < DIM; j++)
        v[j] = 0;
    visualizza(v, d - 1);
    cout << "Inserisci elementi (0 per uscire):" << endl
         << endl;
    do{
        cout << "i n (d=" << d << "): ";
        cin >> i >> n;
        if (n != 0)
            if (add_element(v, d, i, n))
                visualizza(v, d - 1);
        // altrimenti interrompe il programma
    } while (d + 1 < DIM && n != 0);
    cout << endl
         << endl
         << endl;
    visualizza(v, d - 1);
    return 0;
}
void shift(int *v, int dim, int i, int box){
    if(i==dim){
        v[i]=box;
        return; 
    }else{
        int box2=v[i];
        v[i]=box;
        return shift(v,dim,i+1,box2);
    }
}
bool add_element(int *v, int &d, int idx, int n)
{
    if (idx >= d){
        cout << "i deve essere < d" << endl;
        return false; // ritorno falso se l'elemento non è stato aggiunto
    }
    if ((d + 1) > DIM - 1){
        cout << "Dimensione massima raggiunta." << endl;
        return false;
    }
    if (idx < 0){
        cout << "L'indice i deve essere >= 0" << endl;
        return false;
    }
    //shifto il vettore
    shift(v,d+1,idx+1,v[idx]);
    v[idx] = n;
    ++d;
    return true; // ritorno vero se l'elemento è stato aggiunto
}
void visualizza(int *v, int i, int d){
    if(i==(d-1)){
        cout << v[i];
        return;
    }else{
        cout << v[i] << " ";
        return visualizza(v,i+1,d);
    }
}
void visualizza(int *v, int d){
    visualizza(v,0,d);
    cout << endl;
}