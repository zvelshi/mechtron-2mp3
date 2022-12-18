#include <stdio.h>
#include <assert.h>
#include <math.h>

float onethird (int n);

int main () {
    printf("test 1: %f\n", onethird(1));
    printf("test 2: %f\n", onethird(10));
    printf("test 3: %f\n", onethird(9999));
    return 0;
}

float onethird(int n){
    float val;
    for (int i = 1; i <= n; i++){
        val += i*i;
    }
    return val/pow(n,3);
}

