#include <stdio.h>

void maxmin (int *lista, int tam) {
    int max, min, i;
    max = min = lista[0];
    for (i = 1; i < tam; i++) {
        if (min > lista[i])
            min = lista[i];
        if (max < lista[i])
	    max = lista[i];
    }
    printf ("Máximo = %i\nMínimo = %i", max, min);
}

int main() {
    int lista[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    maxmin (lista, 10);
    return 0;
}
