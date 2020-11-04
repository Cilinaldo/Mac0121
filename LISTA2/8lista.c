#include <stdio.h>


int zzz(int n) {
    int aux;
    if (n <= 2)
        return(1);
    n--;
    aux = zzz(n);
    n--;
    return (aux + zzz(n));
}



int main () {
    int n;
    scanf ("%i", &n);
    n = zzz (n);
    printf ("%i\n", n);
    return 0;
}
