#include <stdio.h>

int fusc (int n) {
    if (n <= 1)
	return (1);
    if (n % 2 == 0)
        return (fusc(n / 2));
    return (fusc((n-1)/2) + fusc((n+1)/2));
}
int main() {
    int m = 7;
    printf("Fusc = %d\n", fusc(m));
    return 0;
}
