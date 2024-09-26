/*
Dati in input due numeri, dividendo e divisore, calcolate il quoziente e
resto dell’operazione di divisione;
*/
#include <iostream>

using namespace std;

int main(){
    int dividendo, divisore;
    float quoziente=0;
    int resto=0;
    cout << "Dividendo> ";
    cin >> dividendo;
    do{
        cout << "Divisore> ";
        cin >> divisore;
        if(divisore<=0)
            cout << "Inserire divisore maggiore di 0"<<endl;
    }while(divisore<=0);
    quoziente=(float)dividendo/divisore;
    resto=dividendo%divisore;
    if(resto==0)
        cout << dividendo<< "/"<<divisore<<"= "<<quoziente<<endl;
    else
        cout << dividendo<< "/"<<divisore<<"= "<<quoziente<< " resto "<< resto<<endl;
    return 0;
}