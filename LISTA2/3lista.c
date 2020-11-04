#include <stdio.h>

int cont = 0;

int digitos (int n) {
    if (n/10 == 0) {
	cont++;
        return cont;
    }
    else {
	cont++;
        return digitos (n/10);
    }
}


int main () {
    int n, dig;
    scanf ("%i", &n);
    dig = digitos (n);
    printf ("Dígitos de %i = %i\n", n, dig);
    return 0;
}
