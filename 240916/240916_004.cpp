/*
Dato in input il raggio di un cerchio, calcola il volume della sfera
corrispondente;
*/


#include <iostream>

using namespace std;

const float PI=3.14;

int main(){
    float r,volume;
    r=0;
    volume=((float)4/3)*PI;
    cout << "Raggio cerchio> ";
    cin >> r;
    volume*=r*r*r;
    cout << "Volume= "<<volume<<endl;
    return 0;
}