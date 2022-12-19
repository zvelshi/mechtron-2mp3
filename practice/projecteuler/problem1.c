#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int multiples(int n);

int main(){
    printf("sum below 1000: %d\n", multiples(1000));
    return 0;
}

int multiples(int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        if(i%3==0 || i%5==0){
            sum+=i;
        }
    }
    return sum;
}