#include <iostream>
#include <fstream>

// Inserire qui sotto la soluzione all'esercizio
const int LEN=128;
const int BIN_DIM=8;
const int MAX_NUM=13;

using namespace std;

void elaborariga(char *, int *, int &);
int converti(int *, const int);
int pow(int b, int e);
int somma(int *, const int);

int main(){
    fstream in("inputdati.txt", ios::in);
    fstream out("outputcheck.txt", ios::out);
    if(in.fail()){
        cerr << "inputdati.txt doesn't exists."<<endl;
        exit(1);
    }
    if(out.fail()){
        in.close();
        cerr << "Error opening outputcheck.txt."<<endl;
        exit(1);
    }
    char line[LEN];
    while(in.getline(line, LEN)){
        int num[MAX_NUM];
        int ris=0;
        elaborariga(line, num, ris);
        if(somma(num,MAX_NUM)==ris)
            out << ris<<endl;
        else
            out << "Errore"<<endl;
    }
    cout << "outputcheck.txt creato con successo."<<endl;
    in.close();
    out.close();
    return 0;
}

void elaborariga(char *s, int *num, int &ris){
    for(int i=0;i<MAX_NUM;i++) num[i]=0;
    int i=0;
    int j=0;
    bool flag=s[i]!='=';
    int byte[BIN_DIM];
    while(flag){
        int dim=0;
        while(s[i]!='+' && (flag=s[i]!='=')){
            byte[dim]=s[i]-'0';
            ++dim;
            ++i;
        }
        num[j]=converti(byte, dim);
        ++j;
        ++i;
    }
    //ottengo il risultato:
    for(j=0;s[i]!=';';i++,j++)
        byte[j]=s[i]-'0';
    ris=converti(byte,j);
}
int converti(int *v, const int DIM){
    int res=0;
    for(int i=0;i<DIM;i++)
        res+=v[i]*pow(2,DIM-1-i);
    return res;
}
int pow(int b, int e){
    int ris=1;
    for(int i=0;i<e;i++){
        ris*=b;
    }
    return ris;
}

int somma(int *v, const int DIM){
    int s=0;
    for(int i=0;i<DIM;i++)
        s+=v[i];
    return s;
}