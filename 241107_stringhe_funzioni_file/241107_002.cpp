/*
Scrivere un programma che, dati a linea di comando tre valori,
due numeri e un operatore, ritorni a video il risultato
dell’operazione matematica definita dall’operatore.
./calcolatrice 1 3 +
Il risultato è 4
*/
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 4){
        cerr << "Inserire 3 argomenti." << endl;
        exit(0);
    }
    int n1 = 1;
    int n2 = 1;
    char operation = ' ';
    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
    operation = argv[3][0];
    switch (operation){
    case '+':
        cout << n1 << operation << n2 << "= " << (n1 + n2) << endl;
        break;
    case '*': // per inserire la moltiplicazione da shell bisogna fare ./nome_programa arg1 arg2 "*"
        cout << n1 << operation << n2 << "= " << (n1 * n2) << endl;
        break;
    case '/':
        if (n2 == 0)
            cout << "Operazione impossibile." << endl;
        else
            cout << n1 << operation << n2 << "= " << ((double)n1 / n2) << endl;
        break;
    case '-':
        cout << n1 << operation << n2 << "= " << (n1 - n2) << endl;
        break;
    default:
        cout << "Operazione non valida." << endl;
        break;
    }
    return 0;
}