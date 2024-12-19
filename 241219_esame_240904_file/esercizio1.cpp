#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

// Insert solution hereafter
using namespace std;

bool checkHeader(fstream &in, int &, int &);
int abs(int);
void print_clauses(int **); 

int main(int argc, char *argv[]){
    if(argc!=2){
        cerr << "usage ./a.out <filename>"<<endl;
        exit(0);
    }
    char *filename;
    filename=argv[1];
    fstream in;
    in.open(filename, ios::in);
    if(in.fail()){
        cerr << filename << " doesn't exists."<<endl;
        exit(0);
    }
    int nClausole;
    int nVar;
    if(!checkHeader(in, nClausole, nVar)){
        in.close();
        cerr << "Error reading header of file \""<<filename<< "\""<<endl;
        exit(0);
    }
    int **v= new int *[nClausole+1];
    int n_lit_in_cla;
    int ctr=0;
    bool flag=true;
    int i;
    for(i=0; flag && i< nClausole;i++){
        if(!(in >> n_lit_in_cla)){
            flag=false;
            break;
        }
        v[i]=new int [n_lit_in_cla+1];
        for(int j=0;j< n_lit_in_cla;j++){
            if(!(in >> v[i][j]) || v[i][j]==0 || abs(v[i][j])>nVar){
                flag=false;
                break;
            }
        }
        v[i][n_lit_in_cla+1]=0;
    }
    v[i]=nullptr;
    char c;
    if(in >> c){
        flag=false;
    }
    if(!flag){
        cerr << "Error reading file \""<< filename << "\": eof or clause out of bound, or 0 encountered, or more clauses encountered"<<endl;
        for(int i=0; i< nClausole+1;i++)
            delete []v[i];
        delete []v;
        return 1;
    }

    print_clauses(v);
    
    for(int i=0; i< nClausole+1;i++)
        delete []v[i];
    delete []v;
    in.close();
    return 0;
}

bool checkHeader(fstream &in , int &nClausole, int &nVar){
    char c;
    char buf[255];
    if(in >> c){
        if(c!='p')
            return false;
        if(in >> buf){
            if(strcmp(buf,"cnf")!=0) return false;
            if(in >> nClausole){
                if(in >> nVar) return true;
                else return false;
            }else return false;
        }
    }
    return false;
}
int abs(int n){
    return (n>0)? n : (-1*n);
}
void print_clauses(int **v){
    int nClausole=0;
    int nVar=0;
    int m=v[0][0];
    for(int i=0;v[i]!=nullptr;i++){
        ++nClausole;
        for(int j=0;v[i][j]!=0;j++){
            m=std::max(m,v[i][j]);
            cout << v[i][j]<< " ";
        }
        cout << "0 " << endl;
    }
    cout << "p cnf "<< nClausole << " "<< m<< endl;
}