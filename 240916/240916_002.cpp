/*
Scrivere un programma che, dato in input il raggio,
calcoli l’area e la circonferenza di un cerchio. 
*/
#include <iostream>
#include <cmath>
using namespace std;

const float PI=3.14;

int main(){
    float r,area, circonferenza;
    r=area=circonferenza=0;
    cout <<"Inserisci il raggio: ";
    cin >> r;
    area=pow(r,2)*PI;
    circonferenza=2*PI*r;
    cout << "Area: "<<area<<endl;
    cout << "Circonferenza: "<< circonferenza<<endl;
    return 0;
}