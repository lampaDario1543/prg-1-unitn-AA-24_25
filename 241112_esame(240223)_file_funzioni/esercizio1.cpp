//non so perché salvo negli array, forse sono stupido
#include <iostream>
#include <fstream>

// Inserire qui sotto la soluzione all'esercizio

using namespace std;

int getElements(fstream &);
void readFiles(float *, float *, fstream &, fstream &);
int m1GreaterM2(float *, float *, const int);
float percentuale(int, int);

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Usage esercizio1 <filename_motore1> <filename_motore2>" << endl;
        exit(0);
    }
    fstream in_mot1;
    in_mot1.open(argv[1], ios::in);
    if (in_mot1.fail()){
        cerr << "Il file " << argv[1] << " non esiste." << endl;
        exit(0);
    }
    fstream in_mot2;
    in_mot2.open(argv[2], ios::in);
    if (in_mot2.fail()){
        cerr << "Il file " << argv[2] << " non esiste." << endl;
        exit(0);
    }
    int len = getElements(in_mot1);
    if (len == 0)    {
        cout << "Il numero delle misurazioni e' uguale a zero, per cui non posso calcolare la percentuale" << endl;
        exit(0);
    }
    float *m1 = new float[len];
    float *m2 = new float[len];
    in_mot1.open(argv[1], ios::in);
    readFiles(m1, m2, in_mot1, in_mot2);
    cout << m1GreaterM2(m1, m2, len) << " " << len<<endl;
    cout << "La percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 e' " << percentuale(m1GreaterM2(m1, m2, len), len) << "%" << endl;
    in_mot1.close();
    in_mot2.close();
    delete[] m1;
    delete[] m2;
    return 0;
}

int getElements(fstream &in){
    int ctr = 0;
    float f = 0;
    while (!in.eof())
    {
        in >> f;
        ++ctr;
    }
    in.close();
    return ctr;
}

void readFiles(float *m1, float *m2, fstream &in1, fstream &in2)
{
    int i = 0;
    while (!in1.eof())
    {
        in1 >> m1[i];
        ++i;
    }
    i = 0;
    while (!in2.eof())
    {
        in2 >> m2[i];
        ++i;
    }
}

int m1GreaterM2(float *m1, float *m2, const int DIM)
{
    int ctr = 0;
    for (int i = 0; i < DIM; i++)
        if (m1[i] > m2[i])
            ++ctr;
    return ctr;
}
float percentuale(int nGreater, int tot)
{
    return ((float)(nGreater * 100) / tot);
}