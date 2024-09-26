/*
Scrivere un programma che, dati in input i secondi da
mezzanotte, li salvi in una variabile e ritorni a video
l’equivalente orario in ore, minuti e secondi.
(mezzanotte => 0; 86399 => 23:59:59)
*/
#include <iostream>

using namespace std;
const int MAX_SS = 86399;

int main()
{
    int in_ss = 0;
    int hh=0,mm=0,ss=0;
    int tmp=0;
    do
    {
        cout << "> ";
        cin >> in_ss;
        if(in_ss>MAX_SS)
            cerr << "Errore: input non valido, max secondi = "<< MAX_SS<<endl;
        else if (in_ss<0)
            cerr << "Errore: input non valido, secondi > 0"<<endl;
    }while(in_ss>MAX_SS || in_ss<0);
    tmp=in_ss;
    while(tmp-(60*60)>0){
        ++hh;
        tmp-=(60*60);
    }
    while(tmp-60>0){
        ++mm;
        tmp-=60;
    }
    ss=tmp;
    cout << "Mezzanotte => 0; " << in_ss << " => " << hh << ":" << mm << ":" << ss << endl;
    return 0;
}