#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(){
    int a = 1;
    int b = 2;

    printf("a: %d, b: %d\n", a, b);
    printf("a&b: %d, a|b: %d, a^b: %d, ~a: %d, ~b: %d\n", a&b, a|b, a^b, ~a, ~b);

    return 0;
}