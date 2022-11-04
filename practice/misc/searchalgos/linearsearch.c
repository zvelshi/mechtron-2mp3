#include <stdio.h>

struct returns{
	int return1, return2;
};

typedef struct returns Struct;

Struct linearsearch(int *x, int val, int size);
Struct binarysearch(int *x, int val, int size);

int main (){
	int x[] = {1,1,2,4,6,9,14,15,18,22,26,29,32,34,41};
	int val = 34;
	int size = sizeof(x)/sizeof(x[0]);
	
	Struct returns = linearsearch(x,val,size);

	printf("index of value %d using linear search is: %d in this many operations: %d\n", val, returns.return1, returns.return2); 
	
	returns = binarysearch(x,val,size);

	printf("index of value %d using binary search is: %d in this many operations: %d\n", val, returns.return1, returns.return2);

	return 0;
}

Struct linearsearch(int *x, int val, int size){
	int num_ops = 0;
	int index = -1;
		
	for (int i = 0; i < size; i++){
		num_ops++;
		if (x[i] == val){
		       	index = i;
			break;
		}	
	}
	
	Struct returns;
	returns.return1 = index;
	returns.return2 = num_ops;

	return returns;
}

Struct binarysearch(int *x, int val, int size){
	int index = -1;
	int num_ops = 0;
	
	int a = 0, b = size-1;
	int m = (b+a)/2;

	while (a <= b){
		
		if (x[m] == val){
			num_ops++;
			index = m;
			break;
		}else if (x[m] < val){
			num_ops++;
			a = m + 1;
		}else if (x[m] > val){
			num_ops++;
			b = m - 1;
		}

		m = (b+a)/2;
	}

	Struct returns;
	returns.return1 = index;
	returns.return2 = num_ops;

	return returns;
}	
