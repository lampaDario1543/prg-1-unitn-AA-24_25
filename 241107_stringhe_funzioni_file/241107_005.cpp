/*
Scrivere un programma che, dato in input il nome di un file
F e una lettera L, stampi a video il contenuto di quel file,
sostituendo ogni occorrenza della lettera L con il simbolo
“?”
"Che magnifica giornata", a
=
"Che m?gnific? giorn?t?"
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char file_name[30];
    char sub;
    cout << "Nome file e carattere da sostituire: ";
    cin >> file_name >> sub;
    fstream f;
    f.open(file_name, ios::in);
    if (f.fail()){
        cerr << "Il file " << file_name << " non esiste." << endl;
        exit(0);
    }
    char c;
    while (!f.eof()){
        f.get(c);
        if (c == sub)
            cout << "?";
        else
            cout << c;
    }
    cout << endl;
    f.close();
    return 0;
}