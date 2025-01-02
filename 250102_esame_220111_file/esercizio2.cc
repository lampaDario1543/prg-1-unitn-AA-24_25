#include <iostream>
#include <cstdlib>
#include <cassert>

struct node {
		char info;
		node * next;
};

void dealloca(node *& s) {
		while(s != NULL) {
				node * t = s;
				s = s->next;
				delete t;
		}
}

void stampa_lista(const char * testo, node * s) {
		std::cout << testo;
		for( ; s!= NULL; s=s->next) {
				std::cout << " " << s->info;
		}
		std::cout << std::endl;
}

// Scrivere qui sotto la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char *, node *&, node *&);
void compute_lists_aux(const char *, node *&, node *&, int i=0);
// Scrivere qui sopra la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

int main(int argc, char **argv) {
		if (argc != 2) {
				std::cout << "Usage: " << argv[0]
														<< " \"stringa di caratteri\"" << std::endl;
				exit(1);
		}
		node * s1, * s2;
		std::cout << "La stringa da analizzare e': " << argv[1] << std::endl;

		compute_lists(argv[1], s1, s2);

		stampa_lista("Lista s1:", s1);
		stampa_lista("Lista s2:", s2);
		dealloca(s1);
		dealloca(s2);
}

// Scrivere qui sotto la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char *s, node *&l1, node *&l2){
	l1=nullptr;
	l2=nullptr;
	return compute_lists_aux(s,l1,l2);
}

void compute_lists_aux(const char *s, node *&l1, node *&l2, int i){
	if(s[i]=='\0')	return;
	compute_lists_aux(s,l1,l2, i+1);
	if(s[i] >= 'A' && s[i]<='M'){
		char c='M'-s[i] + 'a';
		l1 = new node{c, l1};
	}else if(s[i]>='N' && s[i]<='Z'){
		char c='Z'-s[i] + 'n';
		l2 = new node{c, l2};
	}
}

// Scrivere qui sopra la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
