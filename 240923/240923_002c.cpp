/*
Definite due variabili booleane, stampate a video la tabella
di verità dell’operazione XOR.
bool xor_operation = a^b
*/
#include <iostream>

using namespace std;

int main(){
    bool a,b;
    a=false;
    b=false;
    cout << "A\tB\tA XOR B"<<endl;
    cout << a << "\t" << b << "\t" << (a^b) << endl;
    a=true;
    cout << a << "\t" << b << "\t" << (a^b) << endl;
    a=false;
    b=true;
    cout << a << "\t" << b << "\t" << (a^b) << endl;
    a=true;
    cout << a << "\t" << b << "\t" << (a^b) << endl;
    return 0;
}