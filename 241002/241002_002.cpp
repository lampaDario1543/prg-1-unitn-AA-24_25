/*
Scrivere una funzione f:R-->R che restituisca:
-x^3 se x<=0
e^x-1 se x>0
e scrivere un programma main che calcoli la funzione f nei punti
-10,-9,...,-1,0,1,2,...,9,10
*/
#include <iostream>
#include <cmath>

using namespace std;

const double e = 2.71828182845904;

double f(double);

int main(){
    for (int i = -10; i < 11; i++)
        cout << "f(" << i << ")= " << f((double)i)<<endl;
    return 0;
}
double f(double x){
    double res = 0;
    if (x <= 0){
        x *= -1;
        res = pow(x, 3);
    }else{
        x -= 1;
        res = pow(e, x);
    }
    return res;
}