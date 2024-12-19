#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

// La funzione non va modificata, pena l'annullamento dell'esercizio
void sort_array(int *array, int len_array)
{
    for (int i = 0; i < len_array; i++)
    {
        for (int j = i + 1; j < len_array; j++)
        {
            if (array[i] > array[j])
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    // Inserisci qui il codice
    if(argc!=4){
        cerr << "usage ./a.out <filename> <DIM> <N>"<<endl;
        exit(0);
    }
    char *filename=argv[1];
    const int DIM= atoi(argv[2]);
    const int N= atoi(argv[3]);
    if(N>DIM){
        cerr << "N must be <= DIM"<<endl;
        exit(0);
    }
    fstream in;
    in.open(filename, ios::in);
    if(in.fail()){
        cerr << filename << " doesn't exists."<<endl;
        exit(0);
    }
    fstream out;
    out.open("output.txt", ios::out);
    if(out.fail()){
        in.close();
        cerr << "Error opening output.txt"<<endl;
        exit(0);
    }
    int *v= new int[DIM];
    for(int i=0;i< DIM;i++)
        in >> v[i];
    sort_array(v,DIM);
    for(int i=DIM-1;i>=DIM-N;i--)
        out << v[i] << endl;
    in.close();
    out.close();
    delete []v;
    return 0;
}