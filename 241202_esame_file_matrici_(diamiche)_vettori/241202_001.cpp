/*
02 - Es. 2 Appello Gennaio 2011
Scrivere un programma che verifichi in modo ricorsivo se una sequenza
di numeri contenuta in un array di al più 100 interi è palindroma.
Chiedere all’utente la dimensione dell’array (controllare sia <=100),
acquisire gli elementi e infine controllare se palindroma.
Non si possono usare cicli se non durante l’acquisizione dei parametri
(e.g., dimensione dell’array e sequenza)
*/
#include <iostream>

const int MAX = 100;

using namespace std;

bool isPalindrome(int *, const int);
bool isPalindrome(int *, const int, int, int);

int main(){
    int dim;
    do{
        cout << "Dimensione array: ";
        cin >> dim;
    } while (dim <= 0 || dim > MAX);
    int *v = new int[dim];
    for (int i = 0; i < dim; i++){
        cout << "Inserire elemento " << (i + 1) << ": ";
        cin >> v[i];
    }
    cout << "Il vettore " << (isPalindrome(v, dim) ? " " : "non ") << "e' palindromo." << endl;
    delete[] v;
}

bool isPalindrome(int *v, const int DIM){
    return isPalindrome(v, DIM, 0, DIM - 1);
}

bool isPalindrome(int *v, const int DIM, int first, int last){
    if (first == DIM - 1 || last == 0){
        if (v[first] == v[last])
            return true;
        else
            return false;
    }
    else{
        if (v[first] == v[last])
            return isPalindrome(v, DIM, first + 1, last - 1);
        else
            return false;
    }
}