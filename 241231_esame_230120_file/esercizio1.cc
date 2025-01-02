#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// E' possibile avere delle funzioni di appoggio per la codifica delle parole in numeri e viceversa.
// Ad esempio:
// int encode(char * decoded);
// void decode(int coded, char * decoded);
const int LEN=256;
char *encode(int decoded);

int decode(char *);
void reverse(char *);

int main(int argc, char * argv []) {
  // inserire qui il codice
  if(argc!=3){
    cerr << "Usage "<< argv[0] << " <filename_input> <filename_output>"<<endl;
    exit(1);
  }
  fstream in(argv[1],ios::in);
  fstream out(argv[2],ios::out);
  if(in.fail()){
    cerr << "Error "<< argv[1] << "doesn't exists" <<endl;
    exit(1);
  }
  if(out.fail()){
    in.close();
    cerr << "Error opening "<< argv[2] <<endl;
    exit(1);
  }
  int key;
  do{
    cout << "Chiave (max 7 cifre): ";
    cin >> key;
  }while(key<0 || key> 9999999);
  char word[LEN];
  while(in >> word){
    int decoded=decode(word);
    char *encoded= encode(decoded+key);
    out << encoded << " ";
    delete [] encoded;
  }
  in.close();
  out.close();
  return 0;

}
int decode(char *s){
  int res=0;
  const int dim= strlen(s)<4? strlen(s) : 4;
  for(int i=0;i<dim;i++){
    int n=0;
    if(s[i]>='a' && s[i]<='z'){
      n=(int)(s[i]-'a')+10;

    }else if(s[i]>='0' && s[i]<='9')
      n=s[i]-'0';
    res+=n*pow(36,dim-i-1);
  }
  return res;
}
char *encode(int n){
  int tmp;
  char *res= new char [5];
  int i=0;
  while((tmp=n%36)!=0){
    res[i]= tmp>=10? ('a'+tmp-10) : ('0'+tmp);
    n-=tmp;
    n/=36;
    ++i;
  }
  res[i]='\0';
  reverse(res);
  return res;
}
void reverse(char *s){
  const int DIM=strlen(s);
  for(int i=0;i<DIM/2;i++){
    char box=s[i];
    s[i]=s[DIM-i-1];
    s[DIM-i-1]=box;
  }
}