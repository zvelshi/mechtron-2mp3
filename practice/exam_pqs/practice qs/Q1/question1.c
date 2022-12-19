//Recursive Happy Numbers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int depth = 0;

int isHappy(int n);
char* toString(int n);

int main () { 
	depth = 0;
	printf("%d -> %d\n", 13, isHappy(13));
	depth = 0;
	printf("%d -> %d\n", 134, isHappy(134));
	for (int i = 0; i < 10; i ++) {
		depth = 0;
		printf("%d -> %d\n", i, isHappy(i));
	}
}

char* toString(int n){
	char* str = malloc(100);
	sprintf(str, "%d", n);
	return str;
}

int isHappy(int n){
	depth++;
	//printf("depth: %d, n: %d\n", depth, n);
	if (depth > 500) {
		return 0;
	} else if (n==1){
		return depth;
	} else if (n==0){
		return 0;
	}
	char* str = toString(n);
	int sum = 0;
	for (int i = 0; i < strlen(str); i ++) {
		int next = (str[i] - '0') * (str[i] - '0');
		sum += next;
	}
	return isHappy(sum);
}

/* Expected Output: 

13 -> 3
134 -> 0
0 -> 0
1 -> 1
2 -> 0
3 -> 0
4 -> 0
5 -> 0
6 -> 0
7 -> 6
8 -> 0
9 -> 0

// Here are some happy sequences for the above numbers:

isHappy(4) == 0
// sequence = 4, 16, 37, 58, 89, 145, 42, 20, 4, 16, 37, 58, 89 ...

isHappy(7) == 6
// sequence = 7, 49, 97, 130, 10, 1

isHappy(9) == 0
// 9, 81, 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, 58, 89, 145, 42, 20, 4, 16, 37 ...

*/