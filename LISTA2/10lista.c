#include <stdio.h>

int euclidesRecursiva (int m, int n) {
    if (m % n == 0)
	return n;
    else 
        return euclidesRecursiva (n, m % n);
}	


int main () {
    int m, n, e;
    scanf ("%i %i", &m, &n);
    e = euclidesRecursiva (m, n);
    printf ("%i\n", e);
    return 0;
}
