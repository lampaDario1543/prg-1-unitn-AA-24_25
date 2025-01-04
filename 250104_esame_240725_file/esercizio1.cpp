/*
53:30 minuti totali
    * es1: 18:24
    * es2: 11:59
    * es3: 23:04

*/
// Allowed include 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#define DIM 5000

using namespace std;

// Add your code hereafter
void getWords(char *text, char **pwords, const int dim);
int ContaParole(char **);
void GeneraParole(char **, const int, char *);
int main(int argc, char *argv[]){
    if(argc!=2){
        cerr << "usage "<< argv[0]<< " <input_filename>"<<endl;
        exit(1);
    }
    time_t seed=time(NULL);
    cout << "Random seed generator: "<< seed<<endl;
    srand(seed);
    fstream in(argv[1], ios::in);
    if(in.fail()){
        cerr << "Error opening "<< argv[1]<<endl;
        exit(1);
    }
    char text[DIM];
    char **pwords= new char *[DIM];
    for(int i=0;i< DIM;i++) pwords[i]=nullptr;
    int i;
    for(i=0;in.get(text[i]) && i<5000;i++);
    getWords(text, pwords,i);
    char res[7];
    const int dim=ContaParole(pwords);
    GeneraParole(pwords, dim, res);
    cout << "Text: "<< text << endl<< endl;
    cout << "Number of words: "<< dim << endl;
    cout << "Initials: ";
    for(i=0;pwords[i]!=nullptr;i++) cout << *pwords[i];
    cout << endl;
    cout << "Generated word: "<< res << endl;
    delete []pwords;
    in.close();
    return 0;
}
void getWords(char *text, char **pwords, const int dim){
    int j=0;
    if(dim>0) pwords[j]=&text[0];
    ++j;
    for(int i=1;i<dim;i++){
        if(text[i-1]==' ' || text[i-1]=='\n' && ((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z'))){
            pwords[j]=&text[i];
            ++j;
        }
    }
}
int ContaParole(char **pwords){
    int i=0;
    for(i=0;pwords[i]!=nullptr;i++);
    return i;
}
void GeneraParole(char **pwords, const int dim, char *res){
    for(int i=0;i<6;i++) res[i]=*pwords[rand()%dim];
    res[6]='\0';
}