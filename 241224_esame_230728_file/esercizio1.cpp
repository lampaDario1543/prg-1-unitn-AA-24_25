#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>

using namespace std;

// è possibile definire funzioni di supporto
const int LEN=256;

bool check(char *, char *);

int main(int argc, char * argv []) {
  // inserire qui il codice
  if(argc!=2){
    cerr << "Usage "<< argv[0] << " <filename>"<<endl;
    exit(1);
  }
  fstream in(argv[1], ios::in);
  if(in.fail()){
    cerr << argv[1]<< " doesn't exists."<<endl;
    exit(1);
  }
  char toFind[LEN];
  char word[LEN];
  cout << "Stringa da trovare: ";
  cin >> toFind;
  while(in >> word){
    if(check(toFind, word))
      cout << word << endl;
  }
  in.close();
  return 0;
}

bool check(char *toFind, char *s){
  if(strlen(s)!=strlen(toFind)) return false;
  for(int i=0;s[i]!='\0';i++)
    if (s[i]!=toFind[i] && toFind[i]!='*') return false;
  return true;
}