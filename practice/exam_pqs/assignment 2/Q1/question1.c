#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);

int main () {
    int x[] = {1,2,5,6,8,9};
    int size = sizeof(x)/sizeof(x[0]);
    printf("mean: %f, median: %f\n", mean(x,size), median(x,size));
    return 0;
}

double mean(int* x, int size){
    int i = 0;
    double sum = 0;
    while (i < size){
        sum+=x[i];
        i++;
    }
    return sum/size;
}

double median(int *x, int size){
    int i = 0;
    if (size%2==0) i++;
    int mid = floor((size-i)/2);
    return x[mid];
}
