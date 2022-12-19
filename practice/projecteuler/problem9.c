#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int pythagtrip();

int main(){
    printf("a*b*c= %d\n", pythagtrip());
    return 0;
}

int pythagtrip(){
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            for (int k = 0; k < 1000; k++){
                if((i<j) && (j<k) && (i+j+k==1000) & (i*i+j*j==k*k)){
                    printf("a: %d, b: %d, c: %d\n", i, j, k);
                    return i*j*k;
                }
            }
        }
    }
}