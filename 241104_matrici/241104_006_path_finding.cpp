/*
Rappresentiamo una palude con una matrice che contiene solo 0 e 1, in cui 1 rappresenta
terraferma, mentre 0 rappresenta sabbie mobili in cui si sprofonda. Scrivere un programma
che, data la mappa di una palude (ovvero una matrice di 0 e 1), cerca un percorso per
attraversarla su terraferma e, se tale percorso esiste, lo visualizza tramite un array che
contiene i passi fatti su terraferma e una matrice che codifica terraferma con ‘*’ e sabbie mobili
con ‘-’.
Più specificatamente:
• Si cerchi un percorso da sinistra a destra, cioè dalla colonna 0 alla colonna (colonna-1);
• Sono possibili solo movimenti in avanti, cioè partendo dalla posizione (riga, colonna) ci si
può spostare in:
(riga-1, colonna+1) (solo se la riga non è la prima)
(riga, colonna+1)
(riga+1, colonna+1) (solo se la riga non è l’ultima)
• Si memorizzi l’eventuale percorso di attraversamento in un array i cui elementi sono gli
indici delle righe corrispondenti ad ogni passo del percorso.

https://imgur.com/a/t4k5bva
*/
#include <iostream>

using namespace std;

const int ROW = 5;
const int COL = 6;

void find_path(int[][COL], char[][COL], int *);
void visualizza(int[][COL]);
void visualizza(char[][COL]);
void visualizza(int *);
void init(char[][COL]);
bool checkNext(int m[ROW][COL], int r, int c, int[]);

int main(){

    int m[ROW][COL] = {
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
    };
    /*int m[ROW][COL]={
        {1,0,0,1,0,0},
        {1,1,1,0,1,0},
        {0,1,0,0,0,1},
        {0,0,1,0,1,0},
        {0,1,0,0,0,0},
    };

    */
    /*
     int m[ROW][COL] = {
         {1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 1},
         {0, 0, 1, 1, 0, 0},
         {0, 1, 0, 0, 0, 0},
     };
     */
    int res[COL];
    char path[ROW][COL];
    init(path);
    visualizza(m);
    find_path(m, path, res);
    if (res[0] == -1)
        cout << "Non ci sono percorsi" << endl;
    else{
        visualizza(res);
        visualizza(path);
    }
    return 0;
}

void visualizza(int v[COL]){
    for (int i = 0; i < COL; i++)
        cout << v[i] << " ";
    cout << endl;
}

void visualizza(int m[ROW][COL]){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}
void visualizza(char m[ROW][COL]){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}
void find_path(int m[ROW][COL], char path[ROW][COL], int res[COL]){
    int i = 0;
    for (i = 0; i < COL; i++)
        res[i] = -1;
    bool flag = false;
    i = 0;
    while (i < ROW && m[i][0] && !(flag = checkNext(m, i, 0, res)))
        i++;
    if (!flag)
        return;
    for (i = 0; i < COL; i++)
        path[res[i]][i] = '*';
}

bool checkNext(int m[ROW][COL], int r, int c, int res[COL]){
    if (c == COL - 1 && m[r][c]){
        res[c] = r;
        return true;
    }
    if (m[r][c]){
        if ((r - 1) >= 0 && checkNext(m, r - 1, c + 1, res)){
            res[c] = r;
            return true;
        }
        if (checkNext(m, r, c + 1, res)){
            res[c] = r;
            return true;
        }
        if ((r + 1) < ROW && checkNext(m, r + 1, c + 1, res)){
            res[c] = r;
            return true;
        }
    }
    return false;
}
void init(char m[ROW][COL]){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            m[i][j] = '-';
}