#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>

// DO NOT MODIFY CODE BELOW
using namespace std;

struct List {
    int lit;
    List * next;
};

struct cnf_t {
    List * clause;
    cnf_t * next;
};

struct Dimacs {
    int n, m;
    cnf_t * clauses;
};

struct Assignment {
    int n;
    bool * values;
};

int length(const List * l) {
    if (l == nullptr) return 0;
    return 1 + length(l->next);
}

Dimacs read_dimacs(istream & in) {
    Dimacs d;
    d.n = d.m = 0;
    d.clauses = nullptr;
    cnf_t * cl = d.clauses;
    while (in) {
        string line;
        getline(in, line);
        if (line.empty() || line[0] == 'c') continue;
        if (line[0] == 'p') {
            istringstream iss(line);
            string p;
            iss >> p >> p >> d.n >> d.m;
        } else {
            istringstream iss(line);
            cnf_t * c = new cnf_t;
            c->clause = nullptr;
            c->next = nullptr;
            if (d.clauses) {
                cl->next = c;
                cl = cl->next;
            } else {
                d.clauses = c;
                cl = c;
            }
            List *l = c->clause;
            int lit;
            int count = 0;
            iss >> count;
            while (iss >> lit) {
                if (lit == 0) break;
                count--;
                if (abs(lit) > d.m) {
                    // Here I'm creating a memory leak, but I'm aware of it!
                    cout << "Errore" << endl;
                    exit(1);
                }
                List *lit_clause = new List;
                lit_clause->lit = lit;
                lit_clause->next = nullptr;
                if (c->clause) {
                    l->next = lit_clause;
                    l = l->next;
                } else {
                    c->clause = lit_clause;
                    l = lit_clause;
                }
            }
        }
    }
    return d;
}

void print_dimacs(ostream & out, const Dimacs & d) {
    out << "p cnf " << d.n << " " << d.m << endl;
    for (cnf_t * c = d.clauses; c; c = c->next) {
        out << length(c->clause) << " ";
        for (List * l = c->clause; l; l = l->next) {
            out << l->lit << " ";
        }
        out << endl; // out << "0" << endl;
    }
}

Assignment read_assignment(istream & in, int n) {
    Assignment a;
    int lit;
    a.n = n;
    a.values = new bool[n];
    while(in >> lit) {
        if (lit == 0) break;
        if (abs(lit) > n) {
            cout << "Errore" << endl;
            exit(1);
        }
        a.values[abs(lit) - 1] = lit > 0;
    }
    return a;
}

void print_assignment(ostream & out, const Assignment & a) {
    for (int i = 0; i < a.n; i++) {
        out << (a.values[i] ? "" : "-") << i + 1 << " ";
    }
    out << endl;
}
void destroy_assignment(Assignment & a) {
    delete[] a.values;
}

void destroy_dimacs(Dimacs & d) {
    while (d.clauses) {
        cnf_t * c = d.clauses;
        d.clauses = d.clauses->next;
        while (c->clause) {
            List * l = c->clause;
            c->clause = c->clause->next;
            delete l;
        }
        delete c;
    }
}
// DO NOT MODIFY CODE ABOVE THIS LINE

// Add declarations of check_assignment here below
bool check_assigment(Dimacs &, Assignment &);
bool check_assigment_aux(cnf_t *&, bool *);
bool checkClause(List *&, bool *);
int abs(int);
// Add declarations of check_assignment here above

int main(int argc, char ** argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <dimacs_file> <assignment>" << endl;
        return 1;
    }
    ifstream df(argv[1]);
    if (df.fail()) {
        cerr << "Cannot open " << argv[1] << endl;
        return 1;
    }
    Dimacs d = read_dimacs(df);
    df.close();

    ifstream af(argv[2]);
    if (af.fail()) {
        cerr << "Cannot open " << argv[2] << endl;
        destroy_dimacs(d);
        return 1;
    }

    Assignment a = read_assignment(af, d.m);

    cout << "Dimacs file: " << argv[1] << endl;
    print_dimacs(cout, d);
    cout << "Assignment file: " << argv[2] << endl;
    print_assignment(cout, a);

    if (check_assigment(d, a)) {
        cout << "Assignment is satisfying the formula" << endl;
    } else {
        cout << "Assignment is not satisfying the formula" << endl;
    }

    destroy_dimacs(d);
    destroy_assignment(a);
    return 0;
}

// Add the definition of check_assignment here below
bool check_assigment(Dimacs &d, Assignment &a){
    //cout << d.clauses->clause->lit<< endl;
    return check_assigment_aux(d.clauses, a.values);
}

bool check_assigment_aux(cnf_t *&clauses, bool *values){
    if(clauses->next==nullptr) return checkClause(clauses->clause,values);
    //cout << "controllo riga:"<<endl;
    bool res_row= checkClause(clauses->clause, values);
    //cout << "Risultato= "<< res_row<<endl;
    return res_row && check_assigment_aux(clauses->next, values);
}
bool checkClause(List *&c,bool *val){
    if(c->next==nullptr) {
        if(c->lit<0){
            return !val[abs(c->lit)-1];
        }
        return val[abs(c->lit)-1];
    }
    //cout <<"lit= "<<abs(c->lit)-1 <<" val= "<<val[abs(c->lit)-1]<<endl;
    bool toCheck=val[abs(c->lit)-1];
    if(c->lit<0) toCheck=!toCheck;
    return checkClause(c->next, val) || toCheck;
}
int abs(int n){
    return (n<0) ? (n*-1): n;
}
// Add the definition of check_assignment here above