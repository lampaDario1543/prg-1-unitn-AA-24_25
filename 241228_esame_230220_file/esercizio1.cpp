#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire proprie funzioni
const int LEN = 256;

void shift(char *, const int); //left shift circolare
char * getWordNoHead(char *);
int getLen(char *);
char * toLow(char *);

int main(int argc, char * argv []) {
  // inserire qui il codice
  if(argc!=3){
    cerr << "usage "<< argv[0] << " <filename input> <filename output>"<<endl;
    exit(1);
  }
  fstream in(argv[1],ios::in);
  if(in.fail()){
    cerr << "Errore: "<<argv[1] << " non esiste."<<endl;
    exit(1);
  }
  fstream out(argv[2],ios::out);
  if(out.fail()){
    in.close();
    cerr << "Errore: file "<<argv[2] <<endl;
    exit(1);
  }
  int pos=0;
  do{
    cout << "Numero di shift: ";
    cin >> pos;
  }while(pos<0);
  char word[LEN];
  while(in >> word){
    shift(word, pos);
    out << toLow(word)<< " ";
  }
  in.close();
  out.close();
  return 0;
}

char * getWordNoHead(char *s){
  char *res=s;
  int i=0;
  for(i=0;s[i]!='\0' && !(s[i]>='a' && s[i]<='z') && !(s[i]>='A' && s[i]<='Z');i++);
  if(s[i]!='\0')
    res=&s[i];
  return res;
}

void shift(char *word, const int N){
  char *s = getWordNoHead(word);
  const int len=getLen(s);
  const int iter=N%len;
  for(int i=0;i<iter;i++){
    char box=s[len-1];
    s[len-1]=s[0];
    for(int j=len-2;j>=0;j--){
      char box2=s[j];
      s[j]=box;
      box=box2;
    }
  }
}

int getLen(char *s){
  int res=0;
  int i=0;
  bool isTail=false;
  for(i=0;i<strlen(s);i++){
    if(!(s[i]>='a' && s[i]<='z') && !(s[i]>='A' && s[i]<='Z')){
      res=i;
      isTail=true;
      int j=i+1;
      while(s[j]!='\0' && isTail){
        if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')) isTail=false;
        ++j;
      }
      if(isTail){
        return res;
      }
      isTail=true;
      i=j-1;
    }
  }
  res=strlen(s);
  return res;
}
char * toLow(char *s){
  for(int i=0;s[i]!='\0';i++)
    if(s[i]>='A' && s[i]<='Z') s[i]+= 'a'-'A';
  return s;
}