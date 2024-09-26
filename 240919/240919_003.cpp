/*
Scrivere un programma che, dati tre input da tastiera (ore,
minuti e secondi), li memorizzi in tre variabili distinte e
calcoli i secondi da mezzanotte.
(mezzanotte => 0; 23:59:59 => 86399)
*/
#include <iostream>

using namespace std;

int main(){
    int hh,mm,ss;
    char c; //to get colon (':')
    int seconds_to_midnight=0;
    hh=0;
    mm=0;
    ss=0;
    do{
        cout << "> ";
        cin >> hh >> c >> mm >> c >> ss;
        if(hh>23 || mm > 59 || ss > 59 || ss<0 || hh < 0 || mm<0){
            cerr << "Errore: input non valido"<<endl;
        }
    }while(hh>23 || mm > 59 || ss > 59 || ss<0 || hh < 0 || mm<0);
    seconds_to_midnight=(hh*60*60)+(mm*60)+ss;
    cout << "Mezzanotte => 0; "<< hh << ":" << mm << ":" << ss << " => "<< seconds_to_midnight<<endl;
    return 0;
}