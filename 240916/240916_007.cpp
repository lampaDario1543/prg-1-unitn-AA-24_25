/*
Dato in input un carattere maiuscolo, ritorna lo stesso carattere
minuscolo;
*/
#include <iostream>

using namespace std;

int main(){
    char c;
    cout << "Carattere> ";
    cin >> c;
    if(c>='A' && c<='Z')
        c+=('a'-'A');
    cout << c <<endl;    
    return 0;
}