#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sumsquare(int n);
int squaresum(int n);

int main(){
    int diff=squaresum(100)-sumsquare(100);
    printf("diff: %d\n", diff);
    return 0;
}

int sumsquare(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum+=i*i;
    }
    return sum;
}

int squaresum(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum+=i;
    }
    return sum*sum;
}