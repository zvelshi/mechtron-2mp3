//Encrypted-Key Dictionaries
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Edict {
	int n;
	struct Slot* slots;
	int (*encrypt)(int);
} Edict;

typedef struct Slot {
	int key;
	int n;
	int* values;
} Slot;

Edict* createEdict(int (*encrypt)(int)) {
	Edict* t = malloc(sizeof(Edict));
	t->n = 0;
	t->encrypt = encrypt;
	t->slots = NULL;
	return t;
}

void destroyEdict(Edict* t) {
	for (int i = 0; i < t->n; i++) {
		free(t->slots[i].values);
	}
	free(t->slots);
	free(t);
}

int insertValue(Edict* d, int val){
	if (d == NULL) {
		return -1;
	}
	int key = d->encrypt(val);
	for (int i = 0; i < d->n; i++) {
		if (d->slots[i].key == key) {
			d->slots[i].n++;
			d->slots[i].values = realloc(d->slots[i].values, d->slots[i].n * sizeof(int));
			if (d->slots[i].values == NULL) {
				return -1;
			}
			d->slots[i].values[d->slots[i].n - 1] = val;
			return 0;
		}
	}
	d->n++;
	d->slots = realloc(d->slots, d->n * sizeof(Slot));
	d->slots[d->n - 1].key = key;
	d->slots[d->n - 1].n = 1;
	d->slots[d->n - 1].values = malloc(sizeof(int));
	if (d->slots[d->n - 1].values == NULL) {
		return -1;
	}
	d->slots[d->n - 1].values[0] = val;
	return 0;
}

void printEntry (Slot* entry) {
	printf("| |--- Encrypted Value = %d ---\n", entry->key);
	printf("| | Number of Values = %d\n", entry->n);
	printf("| | ");
	for (int i = 0; i < entry->n; i++) {
		printf("%d  ", entry->values[i]);
	}
	printf("\n| |---------------------\n| \n");
}

void printEdict (Edict* t) {
	printf("----------------------\n");
	printf("| No. of Entries: %d\n| \n", t->n);
	for (int i = 0; i < t->n; i++) {
		printEntry(&(t->slots[i]));	
	}
	printf("----------------------\n\n");
}

int cypher1 (int n) {
	return (8*n*n - 21*n + 18) % 8;
}

int cypher2 (int n) {
	return ((n - 4)*(n + 12)*(n * 3)) % 8;
}

int main () {
	Edict* t = createEdict(&cypher1);
	printEdict(t);
	for (int i = 2360; i < 2400; i++) {
		if (insertValue(t, i) == -1) {
			break;
		}
	}
	printEdict(t);
	destroyEdict(t);
}

/* Expected Output 

----------------------
| No. of Entries: 0
| 
----------------------

----------------------
| No. of Entries: 8
| 
| |--- Encrypted Value = 2 ---
| | Number of Values = 5
| | 2360  2368  2376  2384  2392  
| |---------------------
| 
| |--- Encrypted Value = 5 ---
| | Number of Values = 5
| | 2361  2369  2377  2385  2393  
| |---------------------
| 
| |--- Encrypted Value = 0 ---
| | Number of Values = 5
| | 2362  2370  2378  2386  2394  
| |---------------------
| 
| |--- Encrypted Value = 3 ---
| | Number of Values = 5
| | 2363  2371  2379  2387  2395  
| |---------------------
| 
| |--- Encrypted Value = 6 ---
| | Number of Values = 5
| | 2364  2372  2380  2388  2396  
| |---------------------
| 
| |--- Encrypted Value = 1 ---
| | Number of Values = 5
| | 2365  2373  2381  2389  2397  
| |---------------------
| 
| |--- Encrypted Value = 4 ---
| | Number of Values = 5
| | 2366  2374  2382  2390  2398  
| |---------------------
| 
| |--- Encrypted Value = 7 ---
| | Number of Values = 5
| | 2367  2375  2383  2391  2399  
| |---------------------
| 
----------------------


*/