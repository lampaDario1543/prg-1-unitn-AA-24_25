/*
Scrivere un programma che stampi a video la tabella di
verità dell’operatore AND (&&) e dell’operatore OR (||).
*/
#include <iostream>

using namespace std;

int main(){
    bool a,b;
    a=false;
    b=false;
    cout << "A\tB\tA && B\tA || B"<<endl;
    cout << a << "\t" << b << "\t" << (a&&b) << "\t" << (a || b) <<endl;
    a=true;
    cout << a << "\t" << b << "\t" << (a&&b) << "\t" << (a || b) <<endl;
    a=false;
    b=true;
    cout << a << "\t" << b << "\t" << (a&&b) << "\t" << (a || b) <<endl;
    a=true;
    cout << a << "\t" << b << "\t" << (a&&b) << "\t" << (a || b) <<endl;
    return 0;
}