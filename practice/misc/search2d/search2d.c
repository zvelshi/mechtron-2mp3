#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

int search2d(int **x, int m, int n, int val);
void printarr(int **matrix, int m, int n);

int main(){
	
	int **matrix = (int**)malloc(M*sizeof(int*));
	for (int i = 0; i < M; i++){
		matrix[i] = (int*)malloc(N*sizeof(int*));
	}
	
	int x[] = {1,3,5,7,10,11,16,20,23,30,34,60};
	
	int index = 0;	
	for(int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			matrix[i][j] = x[index];
			index++;
		}
	}

	printarr(matrix, M, N);

	
	int target = 23;
	
	printf("%d\n", search2d(matrix, M, N, target));
}

int search2d(int **matrix, int m, int n, int val){
	int found = 0;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){	
			if (matrix[i][j] == val)
				found = 1;
		}
	}
	return found;
}

void printarr(int **matrix, int m, int n){
	printf("[");
	for (int i = 0; i<m; i++){
		for (int j = 0; j<n; j++){
			printf("%d,", matrix[i][j]);
		}
		if(i<m-1)
			printf("\n");
	}
	printf("]\n");
}
