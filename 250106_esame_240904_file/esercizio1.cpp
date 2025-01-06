#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

// Insert solution hereafter
//p cnf <numero clausole> <numero variabili>

using namespace std;

bool checkHeader(fstream &, int &,int & );
void print_clauses(int **v);
int main(int argc, char * argv[]){
    if(argc!=2){
        cerr << "Usage "<< argv[0] << " <filename>"<<endl;
        exit(1);
    }
    fstream in(argv[1], ios::in);
    if(in.fail()){
        cerr << "Errore "<< argv[1]<< " non esiste"<<endl;
        exit(1);
    }
    int clausole=0;
    int variabili=0;
    if(!checkHeader(in, clausole, variabili)){
        in.close();
        cerr << "Error reading header of file \""<<argv[1]<<"\""<<endl;
        exit(1);
    }
    int **claus= new int *[clausole+1];
    int lit=0;
    for(int i =0 ; i< clausole;i++){
        in >> lit;
        if(in.eof()){
            cerr << "Error reading file \""<< argv[1]<<"\": eof or clause out of bound, or 0 encountered, or more clauses encount"<<endl;
            exit(1);
        }
        claus[i]= new int[lit+1];
        for(int j=0;j<lit;j++){
            in >> claus[i][j];
            if(claus[i][j]>variabili || claus[i][j]==0){
                cerr << "Error reading file \""<< argv[1]<<"\": eof or clause out of bound, or 0 encountered, or more clauses encount"<<endl;
                exit(1);
            }
        }
        claus[lit]=0;
    }
    claus[clausole]=nullptr;
    for(int i=0;i< clausole+1;i++)
        delete [] claus[i];
    delete [] claus;
    in.close();
    return 0;
}

bool checkHeader(fstream &in, int &clausole ,int &variabili){
    char prefix[100];
    char cnf[100];
    cout << "aaa"<<endl;
    if(!(in >> prefix >> cnf >> clausole >> variabili)) return false;
    if (strcmp(prefix, "p") != 0 || strcmp(cnf, "cnf") != 0 || clausole <= 0 || variabili <= 0) return false;
    return true;
}
void print_clauses(int **v){
    int max=v[0][0];
    for(int i=0;v[i]!=nullptr;i++){
        for(int j=0;v[i][j]!=0;j++){
            if(v[i][j]>max)
                max=v[i][j];
        }
    }
    for(int i=0;v[i]!=nullptr;i++){
        for(int j=0;v[i][j]!=0;j++){
            cout << v[i][j] << " ";
        }
        cout <<"0"<< endl;
    }
}