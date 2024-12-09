#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int [][5], int, int);
bool hasNext(int m[][5],int,int, const int, const int, cella);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 0,3);
   
    return 0;
}
void risolviLabirinto(int m[5][5], int x, int y){
    init();
    int i=0;
    cella prev;
    prev.indiceColonna=
    
    
    
    -1;
    prev.indiceColonna=-1;
    hasNext(m,0,0,x,y,prev);
    while(!vuota()){
        cella cell;
        top(cell);
        cout << "["<<cell.indiceRiga<<","<<cell.indiceColonna<<"]";
        pop();
    }
    deinit();
    cout << endl;
}

bool hasNext(int m[5][5],int r,int c, const int X, const int Y, cella prev){
    cella cell;
    cell.indiceRiga=r;
    cell.indiceColonna=c;
    cout << "R= "<< r << " c= "<<c<<endl;
    if(r==X && c== Y && m[r][c]){
        push(cell);
        return true;
    }else if(r==X && c== Y && m[r][c]==0){
        return false;
    }
    if(m[r][c]){
        cella new_prev;
        new_prev.indiceColonna=c;
        new_prev.indiceRiga=r;
        if((c+1)<5 && prev.indiceColonna!= (c+1) && hasNext(m,r,c+1,X,Y,new_prev)){
            push(cell);
            return true;
        }
        if((r+1)<5 && prev.indiceRiga!= (r+1) && hasNext(m,r+1,c,X,Y,new_prev)){
            push(cell);
            return true;
        }

        if((c-1)>= 0 && prev.indiceColonna!= (c-1) && hasNext(m,r,c-1,X,Y,new_prev)){
            push(cell);
            return true;
        }
        if((r-1)>=0 && prev.indiceColonna!= (r-1) && hasNext(m,r-1,c,X,Y,new_prev)){
            push(cell);
            return true;
        }
    }
    pop();
    return false;
}