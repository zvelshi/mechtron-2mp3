#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);

int main () {
    int x[] = {9, 10, 12, 13, 13, 13, 15, 15, 16, 16, 18, 22, 23, 24, 24, 25};
    int size = sizeof(x)/sizeof(x[0]);
    printf("mean: %f, median: %f, mode: %d\n", mean(x,size), median(x,size), mode(x,size));
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

int mode(int* x, int size){
    int i = 0;
    int j = 0;
    int count = 0;
    int max = 0;
    int mode = 0;
    while (i < size){
        while (j < size){
            if (x[i]==x[j]) count++;
            j++;
        }
        if (count > max){
            max = count;
            mode = x[i];
        }
        i++;
    }
    return mode;
}