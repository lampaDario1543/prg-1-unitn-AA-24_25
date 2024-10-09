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
*/
#include <iostream>

using namespace std;

const int DIM = 100;

bool add_element(int *, int &, int, int);
void visualizza(int *, int);

int main(){
    int v[DIM];
    int d = 1;
    int i = 0;
    int n = 0;
    // inizializzo vettore
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
    int box,box2;
    box=v[idx];
    for(int i =idx+1;i<d+1;i++){
        box2=v[i];
        v[i]=box;
        box=box2;
    }
    v[idx] = n;
    ++d;
    return true; // ritorno vero se l'elemento è stato aggiunto
}
void visualizza(int *v, int d){
    for (int i = 0; i < d; i++)
        cout << v[i] << " ";
    cout << endl;
}