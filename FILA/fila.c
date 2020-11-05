#include <stdlib.h>
#include "fila.h"

fila * criaFila (int tam) {
  fila * f = malloc (sizeof(fila));
  f->max = tam;
  f->ini = f->fim = 0;
  f->v = malloc (tam * sizeof(item));
  return f;
}

fila * aumentaFila (fila * f) {
  fila * g = criaFila (2 * f->max); 
  int i;
  for (i = 0; i < f->max - 1; i++){
    g->v[i] = f->v[(f->ini + i) % f->max];
  }
  g->fim = f->max;
  destroiFila (f);
  return (g);
}

void destroiFila (fila *f) {
  free (f->v);
  free (f); 
}

int filaVazia (fila *f) {
  return (f->fim == f->ini); 
}

item primeiroFila (fila *f) {
  if (!filaVazia(f))
    return (f->v[f->ini]); 
}

void insereFila (fila *f, item x) {
  if ((f->fim + 1) % f->max == f->ini)
    f = aumentaFila (f);
  f->v[f->fim] = x;
  f->fim = (f->fim + 1) % f->max;
}

item removeFila (fila *f) {
  item primeiro;
  if (!filaVazia(f)){
    primeiro = f->v[f->ini];
    f->ini = (f->ini + 1) % f->max;
    return primeiro;
  }
}
