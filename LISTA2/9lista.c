#include <stdio.h>

int soma;
int i = 0;
int j = 0;
int valor = 0;

typedef struct {
    int x;
    int y;
} par;

par tabela (n) {
    par parOrdenado;
    if (valor == n) {
	parOrdenado.x = i;
	parOrdenado.y = j;
        return parOrdenado; 
    }
    
    
		    
}

int main () {
    int n;
    par parOrdenado;
    scanf ("%i", &n);
    parOrdenado = tabela (n);
    printf ("(%i, %i)\n", parOrdenado.x, parOrdenado.y);
    return 0;
}

