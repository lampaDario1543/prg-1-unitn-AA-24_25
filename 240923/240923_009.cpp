/*
Senza utilizzare funzioni di libreria o istruzioni if-else:
● Scrivere un programma che chiede all'utente di inserire un numero intero e
determina se il numero è pari o dispari 
*/
#include <iostream>

using namespace std;

int main(){
    int n=0;
    cout << "Numero> ";
    cin>>n;
    const char *ris= n%2==0 ? "pari" : "dispari"; //è un po' come usare un if
    cout << "Il numero e' "<< ris << endl;
    return 0;
}