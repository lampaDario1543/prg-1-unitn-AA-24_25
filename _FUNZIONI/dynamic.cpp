#include <iostream>

using namespace std;

int main(){

    const int ROW = 3;
    const int COL = 4;

    int **m = new int *[ROW];
    for (int i = 0; i < ROW; i++)
        m[i] = new int[COL];
    /*
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            m[i][j] = i+j;
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    */
    //deallocazione
    for (int i = 0; i < ROW; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}