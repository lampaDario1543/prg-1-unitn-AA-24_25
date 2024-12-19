// Allowed include
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#define DIM 5000

using namespace std;

// Add your code hereafter
int ContaParole(char *v[DIM]);
void GeneraParole(char *v[DIM], const int, char *);

int main(int argc, char *argv[])
{
    time_t seed = time(NULL);
    cout << "Random seed generator: " << seed << endl
         << endl;
    srand(seed);
    if (argc != 2)
    {
        cerr << "usage " << argv[0] << " <filename>" << endl;
        exit(1);
    }
    fstream in(argv[1], ios::in);
    if (in.fail())
    {
        cerr << "Cannot open the input file \"" << argv[1] << "\"" << endl;
        exit(1);
    }
    char text[DIM];
    char *pwords[DIM];
    int i = 0;
    for (i = 0; i < DIM; i++)
        pwords[i] = nullptr;
    char c;
    i = 0;
    while (in.get(c) && i < DIM)
    {
        text[i] = c;
        ++i;
    }
    int k = 0;
    if ((text[0] >= 'a' && text[0] <= 'z') || (text[0] >= 'A' && text[0] <= 'Z'))
    {
        pwords[k] = &text[0];
        ++k;
    }
    for (int j = 1; j < i; j++)
    {
        if (text[j - 1] == ' ' || text[j - 1] == '\n')
        {
            pwords[k] = &text[j];
            ++k;
        }
    }
    char res[7];
    const int N_WORDS = ContaParole(pwords);
    GeneraParole(pwords, N_WORDS, res);
    cout << "Text: ";
    for (int j = 0; j < i; j++)
        cout << text[j];
    cout << endl;
    cout << "Number of words: " << N_WORDS << endl;
    cout << "Initials: ";
    for (int j = 0; pwords[j] != nullptr; j++)
        cout << *pwords[j];
    cout << endl
         << "Generdated word: " << res << endl;
    in.close();
    return 0;
}

int ContaParole(char *v[DIM])
{
    int ctr = 0;
    for (int i = 0; v[i] != nullptr; i++)
        ++ctr;
    return ctr;
}
void GeneraParole(char *v[DIM], const int LEN, char *res)
{
    for (int i = 0; i < 6; i++)
        res[i] = *v[rand() % LEN];
    res[6] = '\0';
}