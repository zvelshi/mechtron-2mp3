#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("%d", difference(7,82));
    return 0;
}

int difference(start, end){
    int count = 0;
    for (int i=start; i<end; i++){
        count++;
    }

    return count;
}
