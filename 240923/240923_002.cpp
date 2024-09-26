/*
Definite due variabili booleane, stampate a video la tabella
di verità dell’operazione XOR.
(( not A ) and B) or (( not B) and A)
*/
#include <iostream>

using namespace std;

int main(){
    bool a,b;
    a=false;
    b=false;
    cout << "A\tB\tA XOR B"<<endl;
    cout << a << "\t" << b << "\t" << ((!a && b) || (!b && a)) << endl;
    a=true;
    cout << a << "\t" << b << "\t" << ((!a && b) || (!b && a)) << endl;
    a=false;
    b=true;
    cout << a << "\t" << b << "\t" << ((!a && b) || (!b && a)) << endl;
    a=true;
    cout << a << "\t" << b << "\t" << ((!a && b) || (!b && a)) << endl;
    return 0;
}