/* 
 Este programa verifica se, partindo da posição (linha, coluna) de um tabuleiro nxn, 
 é possível, com n^2 - 1 pulos, cobrir todas as posições do 
 tabuleiro. Neste caso, imprime a sequência de pulos.  
*/

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int **alocaMatriz (int linha, int coluna) {
    int i;
    int **matriz = malloc (linha * sizeof(int *));
    for (i = 0; i < linha; i++)
        matriz[i] = malloc (coluna * sizeof(int));
    return matriz;        
}

void liberaMatriz (int **tabuleiro, int tamTabuleiro) {
    int i;
    for (i = 0; i < tamTabuleiro; i ++)
        free(tabuleiro[i]);
    free(tabuleiro);    
}

void imprimeMatriz (int **tabuleiro, int tamTabuleiro) {
    int i,j;
    for (i = 0; i < tamTabuleiro; i++){
        for (j = 0; j < tamTabuleiro; j++)
	    printf("+---");
        printf("+\n");
        for (j = 0; j < tamTabuleiro; j++)
          if(tabuleiro[i][j] != 0)
	      printf("|%3d", tabuleiro[i][j]);
          else
	      printf("|   ");
        printf("|\n");
    }
    for (j = 0; j < tamTabuleiro; j++)
        printf("+---");
    printf("+\n");    
}

puloCavalo proximo (puloCavalo atual) {
    puloCavalo prox;

    int px[9] = {0, -2, -1, 1, 2,  2,  1, -1, -2};
    int py[9] = {0,  1,  2, 2, 1, -1, -2, -2, -1};

    prox.linha = atual.linha + px[atual.movimento];
    prox.coluna = atual.coluna + py[atual.movimento];
    prox.movimento = 1;
    return prox;
}

int puloValido (int **tabuleiro, int tamTabuleiro, puloCavalo atual) {
    puloCavalo prox = proximo (atual);
    if (prox.linha >= 0 && prox.coluna >= 0 && prox.linha < tamTabuleiro 
        && prox.coluna < tamTabuleiro && tabuleiro[prox.linha][prox.coluna] == 0) {
        return 1;
    }
    return 0;
}

void cavalo (tamTabuleiro, linha, coluna) {
    pilha *decisoes = criaPilha (tamTabuleiro * tamTabuleiro);
    puloCavalo atual;
    int **tabuleiro = alocaMatriz (tamTabuleiro, tamTabuleiro);
    int i, j, ok, nPulos;

    /* cria tabuleiro zerado */
    for (i = 0; i < tamTabuleiro; i++)
        for (j = 0; j < tamTabuleiro; j++)
	    tabuleiro[i][j] = 0;

    atual.linha = linha;
    atual.coluna = coluna;
    atual.movimento = 1;
    nPulos = 0;

    /* como ocupa uma casa do tabuleiro, resta tamTabuleiro^2 -1 casas para ocupar */
    while (nPulos < tamTabuleiro * tamTabuleiro - 1) {
        ok = 0;

	/* tenta dar um pulo válido */
	while (!ok && atual.movimento <= 8) {
            if (puloValido (tabuleiro, tamTabuleiro, atual))
	        ok = 1;
            else
	        atual.movimento++;	    
	}

	/* se deu um pulo válido */
	if (ok) {
	    /* atualiza o número de pulos */
	    nPulos++;
            
            /* empilha o pulo do cavalo */
	    empilha (decisoes, atual);
         
	    /* coloco o número do pulo na casa do tabuleiro e pego o próximo pulo */
            tabuleiro[atual.linha][atual.coluna] = nPulos;
            atual = proximo (atual);	    
	}
	else { /* backtrack  */
            if (pilhaVazia (decisoes)) {
                printf ("Não tem solução :(..\n");
		liberaMatriz (tabuleiro, tamTabuleiro);
		destroiPilha (decisoes);
                return;
	    }
	    
	    atual = desempilha (decisoes);
	    tabuleiro[atual.linha][atual.coluna] = 0;
            atual.movimento++;
	    nPulos--;
	}
    }
    nPulos++;
    tabuleiro[atual.linha][atual.coluna] = nPulos;

    imprimeMatriz (tabuleiro, tamTabuleiro);
    liberaMatriz (tabuleiro, tamTabuleiro);
    destroiPilha (decisoes);

    return;
}


int main() {
    int tamTabuleiro, linha, coluna;
    printf("Entre o tamanho do tabuleiro, linha e coluna da posição inicial:  ");
    scanf("%d %d %d", &tamTabuleiro, &linha, &coluna);
    cavalo(tamTabuleiro, linha, coluna);
    return 0;
}
