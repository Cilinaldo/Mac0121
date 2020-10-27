#include <stdio.h>

/* typedef char item; */
typedef struct {
    int linha;
    int coluna;
    int movimento;
} puloCavalo;

typedef puloCavalo item;

typedef struct {
    item * v;
    int topo;
    int tam;
} pilha;

pilha * criaPilha (int tam);
void destroiPilha (pilha * p);
void empilha (pilha * p, item x);
item desempilha (pilha * p);
int pilhaVazia (pilha * p);
item topoDaPilha (pilha *p);
pilha * aumentaPilha (pilha * p); 



