#include <stdio.h>
#include <assert.h>
#include <math.h>

int juggler(int n);
int dojuggler(int n, int count);

int main () {
    printf("test: %d\n", juggler(20));
    printf("test: %d\n", juggler(10000));
    printf("test: %d\n", juggler(10001));
    return 0;
}

int juggler(int n){
	int count = 0;
	return dojuggler(n, count);
}

int dojuggler(int n, int count){
	if (n == 1) return count;
	count++;
	if (n % 2 == 0) count = dojuggler(floor(sqrt(n)), count);
	else if (n % 2 != 0) count = dojuggler(floor(pow(n,1.5)), count);
}
