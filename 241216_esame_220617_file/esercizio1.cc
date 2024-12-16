// Inserisci qui il codice
#include <iostream>
#include <fstream>
#include <cstring>

const int LEN = 101;
using namespace std;

int readFile(fstream &in, char **&strs);
void writeFile(fstream &out, fstream &order, char **&strs, const int DIM);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Usage ./a.out <file_input> <file_integer> <file_output>" << endl;
        exit(0);
    }
    char *filename_in = argv[1];
    char *filename_order = argv[2];
    char *filename_out = argv[3];
    fstream in, order, out;
    in.open(filename_in, ios::in);
    if (in.fail())
    {
        cerr << filename_in << " doesn't exists." << endl;
        exit(0);
    }
    order.open(filename_order, ios::in);
    if (order.fail())
    {
        in.close();
        cerr << filename_order << " doesn't exists." << endl;
        exit(0);
    }
    out.open(filename_out, ios::out);
    if (out.fail())
    {
        in.close();
        order.close();
        cerr << filename_out << " doesn't exists." << endl;
        exit(0);
    }
    char **strs;
    const int DIM = readFile(in, strs);
    writeFile(out, order, strs, DIM);
    for (int i = 0; i < DIM; i++)
        delete strs[i];
    delete[] strs;
    in.close();
    order.close();
    out.close();
    return 0;
}
int readFile(fstream &in, char **&strs)
{
    if (in.eof())
    {
        cout << "Empty input file." << endl;
        return 0;
    }
    int dim;
    in >> dim;
    char buffer[LEN];
    strs = new char *[dim];
    for (int i = 0; i < dim; i++)
        strs[i] = new char[LEN];
    int j = 0;
    while (in >> buffer)
    {
        strcpy(strs[j], buffer);
        ++j;
    }
    return dim;
}
void writeFile(fstream &out, fstream &order, char **&strs, const int DIM)
{
    int n = 0;
    while (order >> n)
    {
        if (n >= 0 && n < DIM)
        {
            out << strs[n] << " ";
        }
        else
        {
            out << "MISSING ";
        }
    }
}
