/*Scrivere un programma che chiede all'utente di inserire tre numeri e i rispettivi pesi,
e poi calcola la media ponderata.*/

#include <iostream>

using namespace std;

int main(){
    int n1,n2,n3;
    n1=n2=n3=0;
    float media,p1,p2,p3;
    cout << "n1> ";
    cin >> n1;
    cout << "peso 1> ";
    cin >> p1;
    cout << "n2> ";
    cin >> n2;
    cout << "peso 2> ";
    cin >> p2;
    cout << "n3> ";
    cin >> n3;
    cout << "peso 3> ";
    cin >> p3;
    media=(float)((n1*p1)+(n2*p2)+(n3*p3))/p1+p2+p3;
    cout << "Media= " << media << endl;
    return 0;
}