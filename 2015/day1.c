// Advent of Code 2015 - Day 1
#include <stdio.h>
#include <string.h>

int main(void){
	// read the day's input
	FILE *fp;
	fp = fopen("input1.txt","r");
	char input[10000];
	fscanf(fp, "%s", input);
	fclose(fp);

	// define variables
	int n = strlen(input);
	int answer1 = 0;
	int answer2 = 0;

	// loop through input
	for (int i=0; i<n; i++){
		if (input[i]=='(') answer1++;
		else if (input[i]==')') answer1--;
		// check if basement was entered for the first time
		if (answer2==0 && answer1==-1){
			answer2=i+1;
		}
	}
	printf("Part I: %d\n", answer1);
	printf("Part II: %d\n", answer2);
	return 0;
}