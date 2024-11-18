#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gioco.h"

using namespace std;

const int DIM = 3;

void printDashes(const int N){
    for(int i=0;i<N;i++)
        cout << "-";
}


void inizializzaMatrice (char m[DIM][DIM]){
    for(int i=0; i< DIM;i++)
        for(int j=0; j< DIM;j++)
            m[i][j]=' ';
}
void stampaMatrice(const char m[DIM][DIM]){
    for(int i=0; i< DIM;i++){
        for(int j=0; j< DIM;j++){
            if(j!=DIM-1)
                cout << m[i][j] << " | ";
            else
                cout << m[i][j];
        }
        cout << endl;
        if(i!=DIM-1)
            printDashes(10);
        cout << endl;
    }
            /*
            O | X | O
            ---------
            O | X | O
            ---------
            O | X | O
            */
}


bool controllaVincita (const char m[DIM][DIM], char simbolo, bool &pareggio){
    pareggio=false;
    int ctr=0;
    int ctr2=0;
    int ctr3=0;
    int ctr4=0;
    for(int i=0;i<DIM;i++){
        ctr=ctr2=0;
        for(int j=0; j<DIM;j++){
            if(m[i][j]==simbolo)
                ++ctr;
            if(m[j][i]==simbolo)
                ++ctr2;
            if(i==j && m[i][j]==simbolo)
                ++ctr3;
            if((i+j)==DIM-1 && m[i][j]==simbolo)
                ++ctr4;
        }
        if(ctr==DIM || ctr2==DIM || ctr3==DIM || ctr4==DIM)
            return true;
    }
    ctr=0;
    for(int i=0;i<DIM;i++){
        for(int j=0; j<DIM;j++){
            if(m[i][j]!=' ')
                ++ctr;
        }
    }
        
    if(ctr==(DIM*DIM)){
        pareggio=true;
        return true;
    }
    return false;
}

bool gioca(char m[DIM][DIM], bool turnoUtente, char simboloUtente, char simboloComputer){
    char simbolo= turnoUtente ? simboloUtente : simboloComputer;
    bool pareggio= false;
    if(turnoUtente){
        int r,c;
        do{
            cout << "Inserire <riga> <colonna>: ";
            cin >> r >> c;
            if((r<1 || r>3) || (c<1 || c>3))
                cout << "Inserire una riga e una colonna nell'intervallo [1,3]"<<endl;
            else
                if(m[r-1][c-1]!=' ')
                cout << "La cella gia' occupata "<<endl;
        }while(r<1 || r>3 || c<1 || c>3 || m[r-1][c-1]!=' ');
        m[r-1][c-1]=simboloUtente;
    }else{
        cout << "Computer> e' il mio turno" << endl;
        int r=rand()%3;
        int c=rand()%3;
        while(m[r][c]!=' '){
            r=rand()%3;
            c=rand()%3;
        }
        m[r][c]=simboloComputer;
        cout << "Computer> ho messo '"<<simboloComputer<< "'"<<" in "<< (r+1) << " " << (c+1)<< endl;
    }
    stampaMatrice(m);
    bool checkWin=controllaVincita(m,simbolo, pareggio);
    if(pareggio)
        cout << "Il gioco e' terminato, avete pareggiato." << endl;
    else if(checkWin)
        cout << "Il gioco e' terminato: " << (turnoUtente? "utente": "computer") <<" ("<<simbolo<< ") ha vinto."<<endl;
    return checkWin;
}
void iniziaGioco(){
    time_t seed=time(NULL);
    cout << "Random seed generator: "<< seed<<endl<<endl;
    srand(seed);
    char m[DIM][DIM];
    inizializzaMatrice(m);
    stampaMatrice(m);
    bool turnoUtente=rand()%2; //true inizia user, false inizia pc
    if(turnoUtente)
        cout << "Utente (X) inizia a giocare." <<endl;
    else
        cout << "Computer (O) inizia a giocare." <<endl;
    int i=0;
    while(i<(DIM*DIM) && !gioca(m,turnoUtente,'X', 'O')){
        turnoUtente=!turnoUtente;
        ++i;
        if(i<(DIM*DIM))
            cout << "Tocca a " << (turnoUtente ? "utente" : "computer") <<endl;
    }
}