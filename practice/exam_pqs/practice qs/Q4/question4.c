#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printBoard(const int board[7][7]); 

int parseMove(char *input, int *x1, int *y1, int *x2, int *y2);
int isValidMove(const int board[7][7], char *input);
void effectMove(int board[7][7], char *input);
int isWon(const int board[7][7]);

int main () {
	char buffer[50];
	int board[7][7] = {	{2, 2, 1, 1, 1, 2, 2}
					  , {2, 2, 1, 1, 1, 2, 2}
					  , {1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 0, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1}
					  , {2, 2, 1, 1, 1, 2, 2}
					  , {2, 2, 1, 1, 1, 2, 2}
					  };

// */ // Winning board 
/*					{	{2, 2, 0, 0, 0, 2, 2}
					  , {2, 2, 0, 0, 0, 2, 2}
					  , {0, 0, 0, 0, 0, 0, 0}
					  , {0, 0, 0, 1, 0, 0, 0}
					  , {0, 0, 0, 0, 0, 0, 0}
					  , {2, 2, 0, 0, 0, 2, 2}
					  , {2, 2, 0, 0, 0, 2, 2}
					  }; // */


	printf("><><><><><><><><><><><><\n");
	printf("  Welcome to Solitaire!\n");
	printf("><><><><><><><><><><><><\n");
	printf("Enter your moves by typing the character corresponding\nto the piece you wish to move, then typing the character\nof the place you wish to move it to.\nEnter 'q' to quit at any time.\n\n");
	int won = isWon(board);
	printf("won = %d\n", won);
	while (won != 1 && won != -1) {
		printBoard(board);
		printf("S >> ");
		scanf("%s", buffer);
		if (strcmp(buffer, "q") == 0) {
			break;
		}
		if (isValidMove(board, buffer)) {
			effectMove(board, buffer);
		} else {
			printf("Move Invalid\n");
		}
		won = isWon(board);
	}
	if (won == 1) {
		printf("A winner is you!\n");
	} else if (won == -1) {
		printf("Ya Done Son! No Moves Remaining!\n");
	} else {
		printf("Game Over, Yeah!\n");
	}
	printf("Solitaire Terminated!\n");
}

int parseMove(char* input, int* x1, int* y1, int* x2, int* y2){
	char* x1s = strtok(input, " ");
	char* y1s = strtok(NULL, " ");
	char* x2s = strtok(NULL, " ");
	char* y2s = strtok(NULL, " ");
	if (x1s == NULL || y1s == NULL || x2s == NULL || y2s == NULL) {
		return -1;
	}
	*x1 = x1s[0] - 'a';
	*y1 = y1s[0] - 'a';
	*x2 = x2s[0] - 'a';
	*y2 = y2s[0] - 'a';
	return 0;
}

int isValidMove(const int board[7][7], char* input){
	int x1, y1, x2, y2;
	if (parseMove(input, &x1, &y1, &x2, &y2) == -1) {
		return 0;
	}
	if (x1 < 0 || x1 > 6 || y1 < 0 || y1 > 6 || x2 < 0 || x2 > 6 || y2 < 0 || y2 > 6) {
		return 0;
	}
	if (board[x1][y1] == 0 || board[x2][y2] != 0) {
		return 0;
	}
	if (abs(x1 - x2) > 2 || abs(y1 - y2) > 2) {
		return 0;
	}
	if (abs(x1 - x2) == 2 && abs(y1 - y2) == 2) {
		if (board[(x1 + x2) / 2][(y1 + y2) / 2] == 0) {
			return 0;
		}
	}
	return 1;
}

void effectMove(int board[7][7], char* input){
	int x1, y1, x2, y2;
	parseMove(input, &x1, &y1, &x2, &y2);
	board[x1][y1] = 0;
	board[x2][y2] = 1;
	if (abs(x1 - x2) == 2 && abs(y1 - y2) == 2) {
		board[(x1 + x2) / 2][(y1 + y2) / 2] = 0;
	}
}

int isWon(const int board[7][7]){
	int i, j;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (board[i][j] == 1) {
				return 0;
			}
		}
	}
	return 1;
}

// THIS IS A GIFT: Don't touch until December 25th
void printBoard(const int board[7][7]){ 
	char temp[5];
	char buf[150]; 
	char moveKey[15][100]  =
{ "    ╔═╤═╤═╗     │     ╔═╤═╤═╗    "
, " ☻  ║a│b│c║  ☻  │     ║"
, "    ╟─┼─┼─╢     │     ╟─┼─┼─╢    "
, "    ║d│e│f║     │     ║"
, "╔═╤═╃─┼─┼─╄═╤═╗ │ ╔═╤═╃─┼─┼─╄═╤═╗"
, "║g│h│i│j│k│l│m║ │ ║"
, "╟─┼─┼─┼─┼─┼─┼─╢ │ ╟─┼─┼─┼─┼─┼─┼─╢"
, "║n│o│p│x│P│O│N║ │ ║"
, "╟─┼─┼─┼─┼─┼─┼─╢ │ ╟─┼─┼─┼─┼─┼─┼─╢"
, "║M│L│K│J│I│H│G║ │ ║"
, "╚═╧═╅─┼─┼─╆═╧═╝ │ ╚═╧═╅─┼─┼─╆═╧═╝"
, "    ║F│E│D║     │     ║"
, "    ╟─┼─┼─╢     │     ╟─┼─┼─╢"
, " ☻  ║C│B│A║  ☻  │     ║"
, "    ╚═╧═╧═╝     │     ╚═╧═╧═╝"
};
	for (int i = 0; i < 15; i++) {
		strcpy(buf, moveKey[i]);
		if (i == 1 || i == 3 || i == 11 || i == 13) {
			for (int j = 2; j <= 4; j++) {
				if (board[i>>1][j] == 1) {
					strcpy(temp,"●");
				} else {
					strcpy(temp," ");
				}
				strcat(buf, temp);
				if (j < 4) {
					strcat(buf, "│");
				} else {
					strcat(buf, "║");
				}
			}
		} else if (i == 5 || i == 7 || i == 9) {
			for (int j = 0; j < 7; j++) {
				if (board[i>>1][j] == 1) {
					strcpy(temp,"●");
				} else {
					strcpy(temp," ");
				}
				strcat(buf, temp);
				if (j < 6) {
					strcat(buf, "│");
				} else {
					strcat(buf, "║");
				}
			}
		}
		printf("%s\n", buf);
	}
}