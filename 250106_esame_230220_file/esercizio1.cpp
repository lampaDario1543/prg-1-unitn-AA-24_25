/*
totale minuti 57:48
  *es1: 29:02
  *es2: 21:07
  *es3: 07:37
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

// è possibile definire proprie funzioni
const int LEN = 256;

char *cutTailHead(char *, int &);
void shift(char *, const int, const int);
void toUpper(char *, const int);

int main(int argc, char *argv[])
{

  // inserire qui il codice
  if (argc != 3)
  {
    cerr << "Usage " << argv[0] << " <input_filename> <output_filename>" << endl;
    exit(1);
  }
  fstream in(argv[1], ios::in);
  if (in.fail())
  {
    cerr << "Error: " << argv[1] << " doesn't exists." << endl;
    exit(1);
  }
  fstream out(argv[2], ios::out);
  if (out.fail())
  {
    in.close();
    cerr << "Error: Opening " << argv[2] << endl;
    exit(1);
  }
  char word[LEN];
  int n;
  do
  {
    cout << "Numero di shift: ";
    cin >> n;
  } while (n < 0);
  while (in >> word)
  {
    int tail = 0;
    char *newWord = cutTailHead(word, tail);
    shift(newWord, n, tail);
    toUpper(newWord, tail);
    out << word << " ";
  }
  in.close();
  out.close();
  return 0;
}
char *cutTailHead(char *s, int &tailStart)
{
  tailStart = 0;
  char *pc = &s[0];
  int i = 0;
  while (s[i] != '\0' && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
    ++i;
  pc = &s[i];
  tailStart = strlen(pc) - 1;
  while (tailStart >= 0 && !((pc[tailStart] >= 'a' && pc[tailStart] <= 'z') || (pc[tailStart] >= 'A' && pc[tailStart] <= 'Z')))
    --tailStart;
  ++tailStart;
  return pc;
}
void shift(char *s, const int n, const int TAIL)
{
  const int ITER = n % TAIL;
  for (int i = 0; i < ITER; i++)
  {
    int prev = s[TAIL - 1];
    s[TAIL - 1] = s[0];
    for (int j = TAIL - 2; j >= 0; j--)
    {
      int prev2 = s[j];
      s[j] = prev;
      prev = prev2;
    }
  }
}

void toUpper(char *s, const int TAIL)
{
  for (int i = 0; i < TAIL; i++)
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] -= 'a' - 'A';
}