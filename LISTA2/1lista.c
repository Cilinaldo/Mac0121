#include <stdio.h>

void minmax (int * array, int length, int * min, int * max) {
    if(!length)
	return;
    if(array[length - 1] > *max) 
        *max = array[length - 1];
    if(array[length - 1] < *min)
        *min = array[length - 1];
    minmax (array, length - 1, min, max);
}


int main () {
    int array[] = { 1, -2, 33, -54, -5, 6, -7, 8, 9, 0};   
    int *min = &array[0];
    int *max = &array[9];
    minmax(array, 10, min, max);
    printf("min: %d, max: %d", *min, *max);
    return 0;
}
