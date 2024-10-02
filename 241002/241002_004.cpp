/*
scrivere una PROCEDURA (void) che calcoli l'area del cerchio dato
il raggio.*/
#include <iostream>
#include <cmath>
using namespace std;

void getCircleArea(double, double *);

int main(void){
    double area = 0, r = 0;
    r = 1;
    getCircleArea(r, &area);
    cout << "L'area del cerchio di raggio r= " << r << " e' " << area << endl;
    return 0;
}

void getCircleArea(double r, double *a){
    const double PI = 3.14159265358;
    *a = pow(r,2) * PI;
}