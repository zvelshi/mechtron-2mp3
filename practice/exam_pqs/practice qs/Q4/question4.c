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