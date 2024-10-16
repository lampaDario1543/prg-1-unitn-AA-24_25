/*
Scrivere un programma che prenda in input un testo e riporti in
output il numero di vocali e consonanti nel testo.

*/
#include <iostream>

using namespace std;
const int DIM = 200;

int getVocali(char *s);
int getConsonanti(char *s);

int main()
{
    char s[DIM];
    cout << "Stringa: ";
    cin.getline(s,DIM);
    int v = getVocali(s);
    cout << "Il numero di vocali e': " << v << endl
         << "Il numero di consonanti e': " << getConsonanti(s) << endl;
    return 0;
}

int getVocali(char *s)
{
    int v = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == 'A' || 'E' == s[i] || 'I' == s[i] || 'O' == s[i] || 'U' == s[i] || 'a' == s[i] || 'e' == s[i] || 'i' == s[i] || 'o' == s[i] || 'u' == s[i])
            ++v;
    return v;
}
int getConsonanti(char *s){
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (!(s[i] == 'A' || 'E' == s[i] || 'I' == s[i] || 'O' == s[i] || 'U' == s[i] || 'a' == s[i] || 'e' == s[i] || 'i' == s[i] || 'o' == s[i] || 'u' == s[i]) && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')))
            ++c;
    return c;
}