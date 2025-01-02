// Inserire tutto quello che serve qui
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

const int LEN = 11; // massima lunghezza numero

int makeOperation(const int n1, const int n2, const char op);
int convertToDec(const char *);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage " << argv[0] << " <input_filename> <output_filename>" << endl;
        exit(1);
    }
    fstream in(argv[1], ios::in);
    if (in.fail())
    {
        cerr << argv[1] << " doesn't exists." << endl;
        exit(1);
    }
    fstream out(argv[2], ios::out);
    if (out.fail())
    {
        in.close();
        cerr << argv[2] << " error making file." << endl;
        exit(1);
    }
    char num1[LEN];
    char num2[LEN];
    char op;
    while (in >> num1 >> op >> num2)
    {
        int n1 = convertToDec(num1);
        int n2 = convertToDec(num2);
        out << makeOperation(n1, n2, op) << endl;
    }
    in.close();
    out.close();
    return 0;
}

int makeOperation(const int n1, const int n2, const char op)
{
    int res = 0;
    switch (op)
    {
    case '+':
        res = n1 + n2;
        break;
    case '^':
        res = pow(n1, n2);
        break;
    case '*':
        res = n1 * n2;
        break;
    default:
        cerr << "Error: no operation with sign '" << op << "'" << endl;
        break;
    }
    return res;
}
int convertToDec(const char *s)
{
    int res = 0;
    const int DIM = strlen(s);
    for (int i = 0; i < DIM; i++)
    {
        int n = 0;
        if (s[i] >= 'A' && s[i] <= 'G')
            n = (s[i] - 'A') + 10;
        else if (s[i] >= '0' && s[i] <= '9')
            n = s[i] - '0';
        res += n * pow(17, DIM - i - 1);
    }
    return res;
}