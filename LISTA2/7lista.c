#include <stdio.h>
#include <stdlib.h>

void imprime (int a[]) {
    int i;
    for (i = 0; i < 9; i++) {
        printf ("%i ", a[i]);
    }
    printf ("\n");
}


void misterio (int A[], int inic, int fim) {
    int aux;
    if (inic < fim) {            
        while (A[fim] % 2 == 0)
            fim --;
        while (A[inic] % 2 == 1)
            inic++;
	if (inic < fim) {
            aux = A[inic];
            A[inic] = A[fim];
            A[fim] = aux;
            imprime (A);
            misterio(A, inic, fim);
	}
    }
}


int main () {
    int a[] = {8, 10, 3, 6, 5, 2, 9, 1, 4};
    imprime (a);
    misterio (a, 0, 8);
    imprime (a);
    return 0;
}
