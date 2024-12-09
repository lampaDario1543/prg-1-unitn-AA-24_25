#include <iostream>

/* Inserire qui sotto la dichiarazione della funzione extract */
char *extract(char *, int i = 0, int ctr = 0);
char *generateString(char *s, const int CTR, int i = 0);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char **argv)
{
  char input_string[DIM + 1];
  char *extracted;
  char answer;

  do
  {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete[] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char *extract(char *s, int i, int ctr)
{
  if (s[i] == '\0')
  {
    char *res = new char[ctr + 1];
    return generateString(res, ctr + 1);
  }
  if (s[i] == '@')
    ++ctr;
  return extract(s, i + 1, ctr);
}
char *generateString(char *s, const int CTR, int i)
{
  if (i == CTR - 1)
  {
    s[i] = '\0';
    return s;
  }
  s[i] = '@';
  return generateString(s, CTR, i + 1);
}
/* Inserire qui sopra la definizione della funzione estract */
