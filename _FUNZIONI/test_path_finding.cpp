#include <iostream>

using namespace std;

struct cell{
        int row;
        int col;
    };
bool getPath(int** m, const int ROW, const int COL, cell arrivo, cell*& res, int dim, int i, int j, bool** visited) {
    // Verifica i limiti della matrice e se la cella è un muro o già visitata
    if (i < 0 || i >= ROW || j < 0 || j >= COL || m[i][j] != 1 || visited[i][j]) {
        return false;
    }

    // Segna la cella come visitata
    visited[i][j] = true;

    // Controlla se hai raggiunto la destinazione
    if (i == arrivo.row && j == arrivo.col) {
        res = new cell[dim];
        res[dim - 1] = {i, j}; // Aggiungi la cella corrente
        return true;
    }

    // Prova tutte le direzioni (su, giù, sinistra, destra e diagonali)
    static const int moves[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    for (int k = 0; k < 8; ++k) {
        int ni = i + moves[k][0];
        int nj = j + moves[k][1];

        // Ricorsione per il prossimo passo
        if (getPath(m, ROW, COL, arrivo, res, dim + 1, ni, nj, visited)) {
            res[dim - 1] = {i, j}; // Aggiungi la cella corrente al percorso
            return true;
        }
    }

    // Backtrack: segna la cella come non visitata
    visited[i][j] = false;
    return false;
}

bool findPath(int** m, const int ROW, const int COL, cell start, cell end, cell*& res) {
    // Crea una matrice per tracciare le celle visitate
    bool** visited = new bool*[ROW];
    for (int i = 0; i < ROW; ++i) {
        visited[i] = new bool[COL]();
    }

    // Trova il percorso
    bool result = getPath(m, ROW, COL, end, res, 1, start.row, start.col, visited);

    // Libera la memoria della matrice visitata
    for (int i = 0; i < ROW; ++i) {
        delete[] visited[i];
    }
    delete[] visited;

    return result;
}
int main() {
    int ROW = 5, COL = 5;

    // Crea un array dinamico e copia i valori da test1
    int** m = new int*[ROW];
    int test1[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    for (int i = 0; i < ROW; ++i) {
        m[i] = new int[COL];
        for (int j = 0; j < COL; ++j) {
            m[i][j] = test1[i][j];
        }
    }

    // Dati iniziali
    cell start = {0, 0};
    cell end = {4, 4};
    cell* path = nullptr;

    // Trova il percorso
    if (findPath(m, ROW, COL, start, end, path)) {
        for (int i = 0; i < 5; i++) {
            cout << path[i].row << " " << path[i].col << endl;
        }
    } else {
        cout << "Path not found" << endl;
    }

    // Dealloca la memoria
    delete[] path;
    for (int i = 0; i < ROW; ++i) {
        delete[] m[i];
    }
    delete[] m;

    return 0;
}