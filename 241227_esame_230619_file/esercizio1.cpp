#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>

using namespace std;

// è possibile definire funzioni di supporto
const int LEN=256;
void toLow(char *);
void shift(char *, const int);

int main(int argc, char * argv []) {
  // inserire qui il codice
  if(argc!=2){
    cerr << "usage "<< argv[0]<< " <filename>"<<endl;
    exit(1);
  }
  fstream in(argv[1],ios::in);
  if(in.fail()){
    cerr << argv[1] << " not found."<< endl;
    exit(1);
  }
  char toFind[LEN];
  int n;
  cout << "Stringa da cercare: ";
  cin >> toFind;
  do{
    cout << "Shift: ";
    cin >> n;
  }while(n<0);
  toLow(toFind);
  shift(toFind, n);
  char word[LEN];
  int occ=0;
  while(in >> word){
    if(strcmp(word, toFind)==0)
      ++occ;
    char *newPos=word;
    while((newPos=strstr(newPos, toFind))!=nullptr){
      (newPos)++;
      ++occ;
    }
  }
  cout << occ<<endl;
  in.close();
  return 0;
}

void toLow(char *s){
  for(int i=0;s[i]!='\0';i++)
    if(s[i]>='A' && s[i]<='Z')
      s[i]+='a'-'A';
}

void shift(char *s, const int pos){
  const int s_len=strlen(s);
  const int ITER=pos%s_len;
  for(int i=0;i<ITER;i++){
    char box=s[0];
    s[0]=s[s_len-1];
    char box2;
    for(int j=1;j<s_len;j++){
      box2=s[j];
      s[j]=box;
      box=box2;
    }
  }
}