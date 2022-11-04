#include <stdio.h>

void bubblesort(int arr[], int size);
void insertionsort(int arr[], int size);
void printarr(int arr[], int size);
void swap(int *i, int *j);

int main(){
	int x[6] = {8,5,0,1,6,2};
	int size = sizeof(x)/sizeof(x[0]);
	
	printarr(x, size);
	bubblesort(x, size);
	printarr(x, size);	
	
	int y[6] = {8,5,0,1,6,2};
	
	printarr(y,size);
	insertionsort(y,size);
	printarr(y,size);	

	return 0;
}

void printarr(int *arr, int size){
	printf("{");
	for (int i = 0; i < size; i++){
		printf("%d,", arr[i]); 
	}
	printf("}\n");
}

void bubblesort(int *arr, int size){
	for (int i = 0; i < size; i++){
		for (int j = i+1; j < size; j++){
			if (arr[i] > arr[j]){
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

void insertionsort(int *arr, int size){	
	for (int i = 0; i < size-1; i++){
		for (int j = i; j > 0; j--){
			if (arr[j-1] > arr[j]){
				swap(&arr[j-1], &arr[j]);
			}
		}
	}

}

void swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}
