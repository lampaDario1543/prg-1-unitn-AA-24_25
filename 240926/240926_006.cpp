/*
L’area di un triangolo di cui sono noti i lati a, b e c può essere calcolata,
utilizzando la formula di Erone, come:
sqrt(𝑝(𝑝 − 𝑎)(𝑝 − 𝑏)(𝑝 − 𝑐)) dove 𝑝 = (𝑎 + 𝑏 + 𝑐)/2
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere
da tastiera le lunghezze dei lati a, b e c (tre numeri reali positivi), calcoli
l’area A e ne stampi il valore a video. Per il calcolo della radice quadrata si
può usare la funzione di libreria sqrt, disponibile in <cmath>.
Per fare di più: verificate che a,b,c siano effettivamente positivi e che il
triangolo non sia degenere
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a,b,c;
    double p,ris;
    cout << "Inserisic a b c: ";
    cin >> a >> b >> c;
    if(a<0 || b < 0 || c < 0)
        cout << "I lati devono essere tutti positivi." << endl;
    else if(a==(b+c) || b==(a+c) || c==(a+b)){
        cout << "Triangolo degenere." << endl;
    }else{
        p=(a+b+c)/2.0;
        ris=p*(p-a)*(p-b)*(p-c);
        ris=sqrt(ris);
        cout << "L'area del triangolo e' " << ris << endl;
    }
    return 0;
}