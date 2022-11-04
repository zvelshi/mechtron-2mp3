#include <stdio.h>
#include <assert.h>
#include <math.h>

double det (int size, double matrix[size][size]);

int main(){
	return 0;
}

double det(int size, double matrix[size][size]){
	if(size == 1){
		return matrix[0][0];
	} else if (size == 2){
		return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
	} else {
		int det = 0;
		for (int i = 0; i < size; i++){
			det+=//then he uses malloc :(
		}
	}

	


	return 0;
}

double cofactor(int size, double matrix[size][size]){
	
}
