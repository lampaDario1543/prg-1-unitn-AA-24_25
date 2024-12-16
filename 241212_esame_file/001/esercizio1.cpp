#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

// è possibile definire funzioni di supporto
const int LEN = 256;

void toLow(char *);
void shift(char *, int);
int getOcc(fstream &, const char *);

int main(int argc, char *argv[])
{
    // inserire qui il codice
    if (argc != 2)
    {
        cerr << "Usage ./a.out <filename>" << endl;
        exit(0);
    }
    char *filename = argv[1];
    fstream in;
    in.open(filename, ios::in);
    if (in.fail())
    {
        cerr << "Il file non esiste." << endl;
        exit(0);
    }
    int n;
    char s[LEN];
    cout << "Inserisci una stringa: ";
    cin >> s;
    do
    {
        cout << "numero di shift: ";
        cin >> n;
    } while (n < 0);
    toLow(s);
    shift(s, n);
    int occ = getOcc(in, s);
    cout << "Occorrenze: " << occ << endl;
    in.close();
    return 0;
}
void toLow(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
}
void shift(char *s, int n)
{ // right shift
    const int DIM = strlen(s);
    const int iter = (n % DIM);
    for (int i = 0; i < iter; i++)
    {
        char prev = s[0];
        s[0] = s[DIM - 1];
        for (int j = 1; j < DIM; j++)
        {
            char prev2 = s[j];
            s[j] = prev;
            prev = prev2;
        }
    }
}
int getOcc(fstream &in, const char *s)
{
    int ctr = 0;
    char word[LEN];
    while (!in.eof())
    {
        in >> word;
        if (strcmp(word, s) == 0)
        {
            ++ctr;
        }
        char *newWord = word;
        while ((newWord = strstr(newWord, s)) != NULL)
        {
            ++(newWord);
            ++ctr;
        }
    }
    return ctr;
}