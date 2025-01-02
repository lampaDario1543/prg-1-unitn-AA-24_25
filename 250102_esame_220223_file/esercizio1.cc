// Inserisci qui il codice
/*
52 minuti totali:
    * es1: 19:59
    * es2: 08:24
    * es3: 23:54 
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int LEN=101;
const int DIM=100;

bool isLower(const char *);
void insert_in_arr(char v[][LEN],int *,  int &, char *);

int main(int argc, char * argv[]){
    if(argc!=3){
        cerr << "Usage "<< argv[0] << " <input_filename> <output_filename>"<<endl;
        exit(1);
    }
    fstream in(argv[1], ios::in);
    if(in.fail()){
        cerr << argv[1] << " dosen't exists."<<endl;
        exit(1);
    }
    fstream out(argv[2], ios::out);
    if(out.fail()){
        in.close();
        cerr << "Error opening "<<argv[2]<< "."<<endl;
        exit(1);
    }
    char word[LEN];
    int dim=0;
    char v[DIM][LEN];
    int occ[DIM];
    for(int i=0;i<DIM;i++) occ[i]=0; 
    while(in>>word){
        if(isLower(word))
            insert_in_arr(v,occ,dim, word);
    }
    for(int i=0;i< dim;i++)
        out << v[i]<<": "<<occ[i]<<endl;
    in.close();
    out.close();
    return 0;
}
bool isLower(const char *s){
    for(int i=0;s[i]!='\0';i++)
        if(!(s[i]>='a' && s[i]<='z')) return false;
    return true;
}
void insert_in_arr(char v[][LEN],int *occ, int &dim, char *word){
    for(int i=0;i< dim;i++){
        if(strcmp(v[i], word)==0){
            ++occ[i];
            return; //la parola è già nell'array
        }
    }
    if(dim<DIM){
        strcpy(v[dim],word);
        ++occ[dim];
        ++dim;
    }
}