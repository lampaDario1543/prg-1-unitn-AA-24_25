#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto
const int LEN=256;

bool isInToFind(const char, const char *);
char toupper(const char);

int main(int argc, char * argv []) {
  
  // inserire qui il codice
  if(argc!=2){
    cerr << "Usage "<< argv[0]<< " <filename>"<<endl;
    exit(1);
  }
  fstream in(argv[1],ios::in);
  if(in.fail()){
    cerr <<argv[1]<< " doesn't exists."<<endl;
    exit(1);
  }
  char c;
  char toFind[LEN];
  cout << "Stringa da cercare: ";
  cin.getline(toFind,LEN);
  while(in.get(c)){
    if(isInToFind(c,toFind))
      cout << c;
  }
  cout << endl;
  in.close();
  return 0;
}
bool isInToFind(const char c, const char *s){
  for(int i=0;s[i]!='\0';i++)
    if(toupper(s[i])==toupper(c)) return true;
  return false;
}
char toupper(const char c){
  if(c>='a' && c<='z')
    return c-('a'-'A');
  return c;
}