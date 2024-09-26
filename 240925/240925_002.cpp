/*
2) Scrivere un programma che risolva un'equazione di 2 grado, dando
   anche le soluzioni complesse

     ax^2 + b*x + c = 0

     se b^2 - 4ac >= 0
     x1 = (-b + sqrt(b^2 - 4ac)) / 2a
     x2 = (-b - sqrt(b^2 - 4ac)) / 2a

     se b^2 - 4ac < 0

     x1 = -b/2a "+"  sqrt(-(b^2 - 4ac))) / 2a "i"
     x2 = -b/2a "-"  sqrt(-(b^2 - 4ac))) / 2a "i"

     e.g.   3.0 + 4.0i e 3.0 - 4.0i

*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,b,c;
    double x1,x2;
    x1=x2=a=b=c=0;
    cout << "a> ";
    cin>> a;
    cout << "b> ";
    cin>> b;
    cout << "c> ";
    cin>> c;
    double delta=0;
    delta=(b*b)-4.0*(a*c);
    if(delta<0){
        x1=(-b + delta)/(2.0*a);
        x2=(-b - delta)/(2.0*a);
        cout << "L'equazione non e' definta in R."<<endl;
    }else{
        x1=(-b + sqrt(delta))/(2.0*a);
        x2=(-b - sqrt(delta))/(2.0*a);
        cout << "x1= "<< x1 << endl << "x2= " << x2 << endl; 
    }
    return 0;
}