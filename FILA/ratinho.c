/* 

Faça uma função 

void labirinto (int **lab, int m, int n, pos rato, pos queijo); 

que receba um labirinto m x n, a posição do rato e a posição do 
queijo e numera as posições do labirinto a partir da posição do 
rato com a distância do rato até aquela posição. Com isso, mostra
o menor caminho do rato até o queijo naquele labirinto. 

*/
#include <stdio.h> 
#include <stdlib.h>
#include "fila.h"

int diferente (pos x, pos y) {
  return (x.l != y.l || x.c != y.c); 
} 

void imprimeMatriz (int ** v, int m, int n){
  int i, j; 
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++)
      printf("%3d ", v[i][j]); 
    printf("\n");
  }
  printf ("\n\n\n"); 
}



void labirinto (int **lab, int m, int n, pos rato, pos queijo) {
  fila * caminho = criaFila (m*n);
  int px[4] = {1, 0, -1, 0};
  int py[4] = {0, 1, 0, -1};
  int d; 
  pos atual, prox; 

  insereFila (caminho, rato);
  lab[rato.l][rato.c] = 1;
  atual = rato;
  while (diferente (atual, queijo)) {
    if (filaVazia (caminho)) {
      printf("Não tem caminho do rato até o queijo\n");
      destroiFila (caminho); 
      return;
    }
    atual = removeFila(caminho);
    for (d = 0; d < 4; d++){
      prox.l = atual.l + px[d];
      prox.c = atual.c + py[d]; 
      if (prox.l >= 0 && prox.l < m && prox.c >= 0 && prox.c < n &&
	  lab[prox.l][prox.c] == 0){
	lab[prox.l][prox.c] = lab[atual.l][atual.c] + 1;
	insereFila (caminho, prox);
      }
    }
  }
  imprimeMatriz (lab, m, n);
  destroiFila (caminho);
} 
    
int ** alocaMatriz (int m, int n) {
  int **a = malloc (m * sizeof (int *));
  int i;
  for (i = 0; i < m; i++){
    a[i] = malloc (n * sizeof (int));
  } 
  return a;
} 

void liberaMatriz (int ** a, int m) {
  int i; 
  for (i = 0; i < m; i++)
    free (a[i]);
  free (a); 
} 

int main()
{
  int **lab, m, n, i, j;
  pos rato, queijo;

  printf("m e n:");
  scanf ("%d %d", &m, &n); 

  lab = alocaMatriz (m, n); 

  printf ("Entre lab:");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &lab[i][j]); 

  printf("rato: ");
  scanf("%d %d", &rato.l, &rato.c);
  printf("queijo: ");
  scanf("%d %d", &queijo.l, &queijo.c); 
  printf("\n"); 
  labirinto (lab, m, n, rato, queijo); 
  liberaMatriz (lab, m); 
  return 0;
} 
