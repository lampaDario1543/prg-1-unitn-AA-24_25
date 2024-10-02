/*
scrivere una procedura che ruoti tre elementi a,b,c
   e si scriva un main di prova.
es:
  a=1;
  b=2;
  c=3;
  ruota(a,b,c); // a=2;b=3;c=1;
*/
#include <iostream>

using namespace std;

void ruota(int *, int *, int *);

int main(){
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
    cout << "a= "<< a <<endl <<"b= "<<b <<endl<< "c= "<<c<<endl<<endl;
    ruota(&a,&b,&c);
    cout << "ROTAZIONE: "<<endl;
    cout << "a= "<< a <<endl <<"b= "<<b <<endl<< "c= "<<c<<endl<<endl;
    return 0;
}

void ruota(int *a, int *b, int *c){
    int box=*c;
    *c=*a;
    *a=*b;
    *b=box;
    return;
}
