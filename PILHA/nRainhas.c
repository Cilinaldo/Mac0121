/* Este programa imprime, caso exista, uma forma de colocar n rainhas em um tabuleiro
 * nxn sem que elas se ataquem
 */


#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int **alocaMatriz (int lin, int col) {
    int ** mat = malloc (lin * sizeof(int *));
    int i;
    for (i = 0; i < lin; i++) {
        mat[i] = malloc (col * sizeof(int));
    }
    return mat;
}

void liberaMatriz (int **tab, int n) {
    int i;
    for (i = 0; i < n; i++)  
            free(tab[i]);
    free(tab);
}

void imprimeMatriz (int **tab, int n) {
    int i, j;
    int m = n * 2 + 1;
    int **mat = alocaMatriz(m, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
	    if (tab[i][j] == 1) {
                mat[2 * i + 1][2 * j + 1] = 1;
	    }
	    else {
	        mat[2 * i + 1][2 * j + 1] = 0;
	    }
	}
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
	    if (i == 0 || i == m - 1) {
		if (j == m - 1)
		    printf ("-\n");
		else
                    printf ("--");
	    }
	    else if (j%2 == 0) {
                if (j == m - 1)
		    printf ("|\n");
		else
		    printf ("|");
	    }
	    else if (i%2 == 0) {
                if (i == m - 1)
                    printf ("---\n");
                else
                    printf ("---");
            }
	    else {
	        if (mat[i][j] == 1)
	            printf (" R ");
                else
	            printf ("   ");		
	    } 
	}
    }
}

int posicaoLivre (int **mat, int n, int lin, int col) {
    int livre = 1;
    int i, j;
    /* verifica linhas e colunas */
    for (i = 0; i < n; i++)
        if (mat[lin][i] == 1 || mat[i][col] == 1)
		livre = 0;
    /* verifica diagonais*/
    for (i = 0; i < lin; i++) {
        j = (col - lin) + i;
	if (j >= 0 && mat[i][j] == 1)
	    livre = 0;
        j = (col + lin) - i;
        if (j < n && mat[i][j] == 1)
	    livre = 0;
    }
    return livre;
}

void tabuleiroVazio (int ** tab, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
            tab[i][j] = 0;
}

void nRainhas (int n) {
    pilha * pos = criaPilha(n);
    int ** tab = alocaMatriz(n, n);
    int rainha, col, ok;
    tabuleiroVazio(tab, n);
    rainha = 0;
    col = 0;
    
    while (rainha < n) {
        ok = 0;
	while (!ok && col < n) {
            if (posicaoLivre(tab, n, rainha, col)) 
                ok = 1;
	    else 
                col++;
	}

	if (ok) {
            empilha(pos, col);
	    tab[rainha][col] = 1;
	    rainha++;
	    col = 0;
	}
	else { /* BACKTRACK */
	    if (pilhaVazia(pos)) {
                printf ("Não tem solução\n");
		destroiPilha(pos);
		liberaMatriz(tab, n);
		return;
	    }
            col = desempilha(pos);
	    rainha--;
	    tab[rainha][col] = 0;
	    col++;
	}
    }

    imprimeMatriz(tab, n);
    destroiPilha(pos);
    liberaMatriz(tab, n);
}


int main () {
    int n;
    printf ("Digite n: ");
    scanf ("%d", &n);
    nRainhas(n);
    return (0);
}
