#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// E' possibile avere delle funzioni di appoggio per la codifica delle parole in numeri e viceversa.
// Ad esempio:
// int encode(char * decoded);
// void decode(int coded, char * decoded);


int countDigit(int);
int decode(char *);
void encode(int n, char *);

int main(int argc, char * argv []) {
  // inserire qui il codice
  if(argc!=3){
    cerr << "Usage ./a.out <filename_in> <filename_out>"<<endl;
    exit(0);
  }
  char *fileIn= argv[1];
  char *fileOut= argv[2];
  fstream in;
  in.open(fileIn,ios::in);
  if(in.fail()){
    cerr << fileIn << " doesn't exists."<<endl;
    exit(0);
  }
  fstream out;
  out.open(fileOut, ios::out);
  if(out.fail()){
    in.close();
    cerr << "Error opening " <<fileOut<<endl;
    exit(0);
  }
  int key;
  bool flag=true;
  do{
    cout << "chiave: ";
    cin >> key;
    flag=countDigit(key)>7;
    if(flag)
      cout << "Max 7 cifre."<<endl<<endl;
  }while(flag);
  char word[255];
  while(in >> word){
    int decoded=decode(word);
    //cout << word << ": "<< n<<endl;
    decoded+=key;
    char encoded[5],res[5];
    encode(decoded, encoded);
    const int LEN=strlen(encoded);
    for(int i=0;i<LEN;i++)
      res[LEN-i-1]=encoded[i];
    out << res<< " ";
  }
  in.close();
  out.close();
  return 0;
}

int countDigit(int n){
  int ctr=0;
  while(n!=0){
    n/=10;
    ++ctr;
  }
  return ctr;
}
int decode(char *s){
  int res=0;
  const int shift_char='a'-10;
  if(strlen(s)<=4){
    for(int i=0;s[i]!='\0';i++){
      if(s[i]>='a' && s[i]<='z'){
        res+=(int)(s[i]-shift_char)*pow(36,strlen(s)-i-1);
      }else if(s[i]>='0' && s[i]<='9'){
        res+=(int)(s[i]-'0')*pow(36,strlen(s)-i-1);
      }
    }
  }else{
    for(int i=0;i<4;i++){
      if(s[i]>='a' && s[i]<='z'){
        res+=(int)(s[i]-shift_char)*pow(36,4-i-1);
      }else if(s[i]>='0' && s[i]<='9'){
        res+=(int)(s[i]-'0')*pow(36,4-i-1);
      }
    }
  }
  return res;
}

void encode(int n, char *s){
  int r=0;
  int i=0;
  while((r=(n%36))!=0){
    char c=' ';
    if(r>=10)
      c='a'+r-10;
    else
      c='0'+r;
    s[i]=c;
    n-=r;
    n/=36;
    ++i;
  }
  s[i]='\0';
}