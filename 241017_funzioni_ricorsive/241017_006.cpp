/*
Scrivere un programma che prenda in input due caratteri e
stampi a video tutti i caratteri compresi tramite procedura
ricorsiva.
(a, g)=> “a,b,c,d,e,f,g”
*/
#include <iostream>

using namespace std;
void printChar(char,char);

int main(){
    const char start= 'a';
    const char end= 'g';
    printChar(start, end);
    cout << endl;
    return 0;
}

void printChar(char s,char e){
    if(s==e){
        cout << s << " ";
        return;
    }
    cout << s << " ";
    return printChar(s+1,e);
}