/*
Dati in input tre numeri reali, a, b e c, scrivere
un programma che calcoli le soluzioni dell’equazione di
secondo grado (assumete che il delta sia positivo).
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float a,b,c;
    float x1,x2;
    x1=x2=0;
    cout << "a> ";
    cin >> a;
    cout << "b> ";
    cin >> b;
    cout << "c> ";
    cin >> c;
    x1= (float)((-b)+sqrt(((b*b)-(4*a*c))))/(float)(2*a);
    x2= (float)((-b)-sqrt(((b*b)-(4*a*c))))/(float)(2*a);
    cout << "x1= "<< x1 << "\t" << "x2= "<< x2 <<endl;
    return 0;
}