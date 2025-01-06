//IL FILE DEVE TERMINARE CON UN \n
/*
COME INTERPRETARE UN FILE DIMACS:

HEADER:
*   p cnf <numero di clausole> <numero di variabili>

*   numero di clausole: sono le righe sul file

*   numero di variabili: è il numero massimo di x esempio se nVar=3 => x1,x2,x3

*    es.
    p cnf 2 3
    2 indica che ci sono 2 righe nel file.
    3 indica che ci sono 3 variabili x1,x2,x3

CLAUSOLE:
*   il primo numero della riga è il numero di letterali che compongono la clausola
    es. 2 6 5 => 2 è il numero di letterali, 1 e 2 sono i letterali

*   il meno davanti a un numero indica che quella variabile è negata:
    es. 2 -6 5 => x6 è negato

*   Se non ci sono indicazioni diverse ogni numero sulla riga è OR con il successivo:
    es. 2 -6 5 => not(x6) OR x5

*   Se non ci sono indicazioni diverse ogni riga è AND con la successiva:
    es.
    2 -6 5
    3 1 2 3
    => (not(x6) OR x5) AND (x1 OR x2 OR x3)
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>


using namespace std;

bool checkHeader(fstream &, int &, int &);

int main(int argc, char ** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        exit(1);
    }

    fstream in(argv[1], std::ios::in);
    if (in.fail()) {
        std::cerr << "Error opening file \"" << argv[1] << "\"" << std::endl;
        return 1;
    }
    int nClauses, nVar;
    if(!checkHeader(in, nClauses, nVar)) { //l'header non va bene => chiudo e termino
        in.close();
        std::cerr << "Error reading header of file \"" << argv[1] << "\"" << std::endl;
        exit(1);
    }
    int ** clauses = new int * [nClauses+1]; //creo matrice
    int i = 0;
    bool error = false;
    for (i = 0; !error && i < nClauses && !in.eof(); i++) {
        int n;
        in >> n; //leggo quanti litterali ci sono nella clausola
        clauses[i] = new int[n + 1]; //creo l'array con +1 perché devo mettere 0 alla fine.
        for (int j = 0; j < n; j++) { //leggo i litterali
            in >> clauses[i][j];
            if (in.eof() || abs(clauses[i][j]) > nVar || clauses[i][j] == 0) { // se sono a fine file/numero fuori range/0 => errore
                error = true;
                break;
            }
        }
        //metto il terminatore alla fine dell'array (0)
        if (!error) clauses[i][n] = 0;
    }
    //IL FILE DEVE TERMINARE CON UN \n
    //controllo che effettivamente sia finito il file
    char c;
    in >> c;
    if (!in.eof()) error = true;

    in.close();
    if (i != nClauses || error) {
        //se il numero delle clausole non è uguale oppure se c'è stato un errore prima dealloco e termino
        cerr << "Error reading file \"" << argv[1] << "\": eof or clause out of bound, or 0 encountered, or more clauses encountered" << endl;
        for (int j = 0; j < i; j++) {
            delete [] clauses[j];
        }
        delete [] clauses;
        exit(1);
    }
    clauses[i] = nullptr;
    //dealloco.
    for(i = 0; i < nClauses && clauses[i] != nullptr; i++) {
        delete [] clauses[i];
    }
    delete [] clauses;
    return 0;
}
bool checkHeader(fstream &in, int &nClauses, int &nVar) { //controllo l'header false se non va bene, true se ok
    char prefix[100];
    char cnf[100];
    in >> prefix >> cnf >> nClauses >> nVar;
    if (strcmp(prefix, "p") != 0 || strcmp(cnf, "cnf") != 0 || nClauses <= 0 || nVar <= 0) return false;
    return true;
}