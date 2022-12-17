#include <stdio.h>

int P(int x, int y, int z);

int main(){
    int val = P(1,0,0);
    printf("result: %d\n", val);

    return 0;
}

int P(int x, int y, int z){
    if(x==0){
        if (y==0) return z+3;
        else if (y!=0) return P(x,y-1,z+y);

    } else return P(x-1,y+2*x,z+P(x-1,y-1,z-1));
}