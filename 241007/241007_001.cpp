/*
Scrivere un programma che stampi a video il valore ASCII
di tutte le lettere dell’alfabeto minuscole e maiuscole.*/
#include <iostream>

using namespace std;

int main(){
    char c = 'A';
    for (int i = 0; i < 26; i++){
        cout << c << " --> " << (int)c << endl;
        ++c;
    }
    cout << "----------" << endl;
    c = 'a';
    for (int i = 0; i < 26; i++){
        cout << c << " --> " << (int)c << endl;
        ++c;
    }
    return 0;
}