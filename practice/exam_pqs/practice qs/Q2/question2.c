//File I/O
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float avgCSV (char* inputName);

int main () {
	printf("%f\n", avgCSV("sample_data.csv"));
	// Expected Value = 523.899109
	printf("%f\n", avgCSV("sample_data_2.csv"));
	// Expected Value = 506.371246
}

float avgCSV(char* inputName){
	FILE *fp = fopen(inputName, "r");
	char line[100];
	float sum = 0;
	int count = 0;
	while (fgets(line, 100, fp) != NULL) {
		char* token = strtok(line, ",");
		while (token != NULL) {
			sum += atof(token);
			count ++;
			token = strtok(NULL, ",");
		}
	}
	fclose(fp);
	return sum / count;
}