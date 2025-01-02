#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cassert>

const int fprecision = 5;

struct list {
  int info;
  struct list * next;
};

void delete_list(list * & l) {
  while(l != NULL) {
    list * t = l;
    l = l->next;
    delete t;
  }
}

void print_list(list * l) {
  std::cout << "The list of terms is: ";
  while(l != NULL) {
    std::cout << l->info << ((l->next != NULL) ? " " : "");
    l = l->next;
  }
  std::cout << std::endl;
}

// Aggiungere qui sotto la dichiarazione della funzione da
// implementare

list * crea_lista(const int);
int getTriang(int i);
void crea_lista_aux(list *&res,int i,const int N);
void insert_first(list*&s, int v) {
    list * n = new list;
    n->info = v;
    n->next = s;
    s = n;
}
// Aggiungere qui sopra la dichiarazione della funzione da
// implementare


int main(int argc, char **argv) {
  int N;

  if (argc == 2) {
    N = atoi(argv[1]);
  } else {
    std::cerr << "Usage: " << argv[0] << " N ]" << std::endl;
    std::cerr << "N is an integer > 0" << std::endl;
    exit(1);
  }

  std::cout << "N = " << N << std::endl;
  list * result = crea_lista(N);
  print_list(result);
  delete_list(result);
  return 0;
}

// Aggiungere qui sotto la definizione della funzione da
// implementare
list * crea_lista(const int N){
  list * res=nullptr;
  crea_lista_aux(res,0,N);
  return res;
}
int getTriang(int i){
  return (i*(i+1))/2;
}
void crea_lista_aux(list *&res,int i,const int N){
  if(i==N)
    return;
  insert_first(res, getTriang(i));
  crea_lista_aux(res,i+1,N);
  return;
}
// Aggiungere qui sopra la definizione della funzione da
// implementare
