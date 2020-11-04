#include <stdio.h>


double f(double x, double y) {
    if (x >= y)
        return ((x+y)/2);
    return (f(f(x+2, y-1), f(x+1, y-2)));
}


int main() {
    double a, b;
    scanf ("%lf %lf", &a, &b);
    printf ("%.2f\n", f (a, b));
    return 0;
}
