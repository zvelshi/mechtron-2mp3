#include <stdio.h>
#include <assert.h>
#include <math.h>

int minutes (int m, int h, int d);

int main () {
    printf("test 1: %d\n", minutes(1,1,1));
    printf("test 2: %d\n", minutes(30,15,2));
    printf("test 3: %d\n", minutes(0,0,0));
    return 0;
}

int minutes (int m, int h, int d){
    return m + 60*(h + 24*d);
}