#ifndef CODA_H
#define CODA_H

struct nodoCoda {
	int value;
	nodoCoda* next;
};
typedef nodoCoda* listaCoda;

struct coda {
    listaCoda tail;
    listaCoda head;
};

coda coda_init();
bool coda_enqueue(coda &, int);
bool coda_first(coda &, int &);
bool coda_dequeue(coda &);
void coda_deinit(coda &);
void coda_print(const coda &);

#endif



