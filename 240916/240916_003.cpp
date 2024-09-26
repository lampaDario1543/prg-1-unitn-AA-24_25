/*
Scrivere un programma che, data in input una
temperatura in Fahrenheit, ritorni a video il corretto 
*/


#include <iostream>

using namespace std;

int main(){
    float f=0;
    float c=0;
    cout << "Temperatura (°F)> ";
    cin >> f;
    c=(f-32)/1.8;
    cout << "Temperatura "<<c<<"°C"<<endl;
    return 0;
}