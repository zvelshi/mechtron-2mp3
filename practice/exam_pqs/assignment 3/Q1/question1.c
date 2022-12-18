#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str);
int count(char* str);
void swap(char *a, char *b);


int main () {
	char str[] = "McMasters";
	printf("num vowels: %d\n",count(str));

	reverse(str);	
	for(int i = 0; i < strlen(str); i++){
		printf("%c", str[i]);
	}
	printf("\n");


	return 0;
}

int count(char* str){
    int c = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') c++;
    return c;
}

void reverse(char* str){
	int len = strlen(str);
	int mid = len/2;
	
	char *a = str; //low
	char *b = str+len-1; //high

	for (int i = 0; i < mid; i++){
		swap(a,b);
		a++;
		b--;
	}
}

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}