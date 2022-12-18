#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);


int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}


int main () {
    
    
    return 0;
}