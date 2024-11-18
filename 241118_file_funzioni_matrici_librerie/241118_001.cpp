/*Scrivere un programma che implementi il Cifrario di Cesare. Il programma dovrà
prendere in input il file contenente il messaggio da cifrare (assumete che il file
contenga solo lettere minuscole e spazi fino ad un massimo di 255 lettere), il
nome di un file in cui verrà salvato l’output e la chiave di cifratura. All’utente verrà
inoltre chiesto se intende cifrare o decifrare il messaggio.
Utilizzare le funzioni della libreria fstream
Definire la funzione di cifratura e di decifratura in un file separato.
void crypt(char parola [], int chiave);
void decrypt(char parola [], int chiave);*/

#include <iostream>
#include <fstream>

using namespace std;

const int LEN = 30;
const int MAX_LEN = 256;

void leggi(fstream &, fstream &, bool, int);
void crypt(char parola [], int chiave);
void decrypt(char parola [], int chiave);
void lowCase(char *);


int main(){
    char out_filename[LEN], in_filename[LEN];
    int key;
    char opt;
    cout << "Input filename: ";
    cin >> in_filename;
    fstream in,out;
    in.open(in_filename,ios::in);
    if(in.fail()){
        cerr << "Il file "<< in_filename << " non esiste."<<endl;
        exit(0);
    }
    cout << "Output filename: ";
    cin >> out_filename;
    out.open(out_filename,ios::out);
    if(out.fail()){
        cerr << "Errore file "<< out_filename <<endl;
        exit(0);
    }
    cout << "Chiave: ";
    cin >> key;
    cout << "Cripta/decripta (c/d): ";
    cin >> opt;
    if(opt!='c' && opt!='d'){
        cerr << "Inserire c/d"<<endl;
        exit(0);
    }
    leggi(in, out, opt=='c', key);
    cout << "File "<< out_filename << " creato con successo."<<endl;
    in.close();
    out.close();
    return 0;
}

void leggi(fstream &in, fstream &out, bool flag, int key){
    char msg[MAX_LEN];
    while(!in.eof()){
        in.getline(msg,MAX_LEN);
        lowCase(msg);
        if(flag)
            crypt(msg, key);
        else
            decrypt(msg, key);
        out << msg <<endl;
    }
}

void crypt(char *s, int key){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]>='a' && s[i]<='z')
            s[i] = ((s[i] - 'a' + key) % 26 + 'a');
}
void decrypt(char *s, int key){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]>='a' && s[i]<='z')
            s[i] = ((s[i] - 'a' - key + 26) % 26 + 'a');
}
void lowCase(char *s){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i]+='a'-'A';
}