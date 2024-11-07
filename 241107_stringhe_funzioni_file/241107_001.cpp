/*Si scriva una funzione che riceva come parametro una stringa di caratteri str e
restituisca come valore di ritorno un numero intero. Dopo avere verificato che
la stringa sia composta da caratteri alfabetici (escluso il carattere nullo), la
funzione converte eventuali caratteri alfabetici maiuscoli in minuscoli; quindi
calcola e restituisce un punteggio per la stringa str dato dalla somma delle
differenze assolute tra ciascuna coppia di caratteri consecutivi. Ad esempio,
data la stringa str = “aa”, la funzione restituisce 0; data la stringa str = “abf”, la
funzione restituisce 5. Se la stringa non contiene solo caratteri alfabetici, la
funzione restituisce -1. Si scriva quindi un main che, finché l’utente lo
desidera, gli chieda di immettere da tastiera una stringa contenente al
massimo 31 caratteri, chiami la funzione di cui sopra e, in caso di dato valido,
ne stampi a video il valore di ritorno.*/

#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 32;

int sum_couple(char *);
bool isAlphabetic(char *);
void to_lower(char *);
int abs(int);

int main(){
    char s[LEN];
    char opt = ' ';
    do{
        cout << "Inserisci stringa: ";
        cin.getline(s, LEN);
        int sum = sum_couple(s);
        if (sum != -1)
            cout << "Somma delle lettere: " << sum << endl;
        else
            cout << "Inserire una stringa con solo caratteri alfabetici." << endl;
        cout << "Vuoi continuare [y/n]? ";
        cin >> opt;
        cin.ignore();
    } while (opt == 'y' || opt == 'Y');
    return 0;
}
int sum_couple(char *s){
    int sum = 0;
    const int len = strlen(s);
    if (!isAlphabetic(s))
        return -1;
    to_lower(s);
    for (int i = 0; i < len - 1; i++)
        sum += abs(((int)s[i] - s[i + 1]));
    return sum;
}

void to_lower(char *s){
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
}

bool isAlphabetic(char *s){
    for (int i = 0; s[i] != '\0'; i++)
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == ' '))
            return false;
    return true;
}

int abs(int n){
    if (n < 0)
        return -n;
    return n;
}