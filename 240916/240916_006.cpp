/*
Stampa a video la tabella di verità dell’operatore AND (&&) e OR (||);
*/

#include <iostream>

using namespace std;

int main(){
    bool a,b;
    a=false;
    b=false;
    cout << "a\tb\ta AND b\ta OR b"<<endl;
    cout << a << "\t" << b << "\t"<< (a&&b) <<"\t"<< (a||b)<<endl;
    a=false;
    b=true;
    cout << a << "\t" << b << "\t"<< (a&&b) <<"\t"<< (a||b)<<endl;
    a=true;
    b=false;
    cout << a << "\t" << b << "\t"<< (a&&b) <<"\t"<< (a||b)<<endl;
    a=true;
    b=true;
    cout << a << "\t" << b << "\t"<< (a&&b) <<"\t"<< (a||b)<<endl;
    return 0;
}