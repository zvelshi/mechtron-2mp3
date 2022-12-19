#include<stdio.h>

int highfives (char hall[]) {
	int i = 0;
	int r = 0, hf = 0;
	while (hall[i] != '\0') {
		switch (hall[i]) {
			case '>':
				r += 1;
				break;
			case '<':
				hf += r;
				break;
			default:
				break;
		}
		i += 1;
	}
	return hf;
}

int main () {
	char hall1[] = ">><<";
	char hall2[] = ">-<<->----<><>>-";
	char hall3[] = ">-<->--<<>><->-<-->-<--->-<>->>->>-<<<->";
	printf("Hall 1 should have 4 high fives.  You got %d\n", highfives(hall1));
	printf("Hall 2 should have 7 high fives.  You got %d\n", highfives(hall2));
	printf("Hall 3 should have 63 high fives.  You got %d\n", highfives(hall3));
}


