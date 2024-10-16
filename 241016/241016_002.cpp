/*
Scrivere un programma che prenda in input un testo e riporti in
output il numero di occorrenze di ogni carattere.
*/
#include <iostream>

using namespace std;
const int DIM = 200;
const int ALFABETO = 1 + ('Z' - 'A');

void getOcc(char *s, int *occ);

int main(){
    char s[DIM];
    int occ[ALFABETO];
    cout << "Stringa: ";
    cin.getline(s, DIM);
    getOcc(s, occ);
    cout << "Occorrenze: " << endl
         << endl;
    char c = 'A';
    // stampo le occorrenze.
    for (int i = 0; i < ALFABETO; i++, c++)
        cout << c << "/" << (char)(c + ('a' - 'A')) << ": " << occ[i] << endl;
    return 0;
}

void getOcc(char *s, int *occ){
    char c = 'A';
    for (int i = 0; i < ALFABETO; i++, c++){
        for (int j = 0; s[j] != '\0'; j++)
            if (s[j] == c || s[j] == ((char)(c + ('a' - 'A'))))
                ++occ[i];
    }
}