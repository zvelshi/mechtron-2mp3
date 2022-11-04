#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int computer(int score);

// Simulates user by entering random numbers
int user(int score){
	int i=rand() %2+1; // Random number Alternative
	printf("We're at %d User adds %d\n",score,i);
	return(i);
};

void game(void){
	    
	srand(time(NULL));
	int i=0;
	int score=0;
	int choice = 1; //0 for computer to start first 1 for user to star first
	    
	printf("Who says first 20 \n \n");
	    
	if (choice){
		score = user(score);
	}
	else{
		score = computer(score);
	}
	while(score <=20){
		score+=user(score);
		if(score>=20) {
			printf("USER WINS !!\n ");
			break;
		}
		score+=computer(score);
		if(score>=20) {
			printf("COMPUTER WINS !! \n ");
			break;
		}
	}   
}

int main(void){
	game();
	return(0);
}

int computer(int score){
	int ret = 1;
	
	if (score % 3 == 2){
		ret = 2;
	}

	printf("Computer adds %d\n",ret);
	return ret;
}
