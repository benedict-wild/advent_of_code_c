// Advent of Code 2015 - Day 3
#include <stdio.h>
#include <string.h>

int main(void){
	
	FILE *fp;
	char input[10000];
	fp = fopen("input3.txt", "r");
	fscanf(fp, "%s", input);
	fclose(fp);
	
	int n = strlen(input);
	int answer1, answer2;
	answer1 = answer2 = n;
	int x1,y1,x2,y2;
	x1=y1=x2=y2=0;


	int list[2][n+1]; // list of visited houses
	
// PART I
	list[0][0] = list[1][0] = 0;
	for (int i=0; i<n; i++){
		// add house to the list
		switch (input[i]){
			case '<': x1--; break;
			case '>': x1++; break;
			case 'v': y1--; break;
			case '^': y1++; break;
		}
		list[0][i+1]=x1;
		list[1][i+1]=y1;
		// check if house has already been visited
		for (int j=0; j<i-1; j++){
			if (list[0][j]==list[0][i] && list[1][j]==list[1][i]){
				answer1--;
				break;
			}
		}
	}
	// PART II
	list[0][0] = list[1][0] = 0;
	x1=y1=x2=y2=0;
	for (int i=0; i<n; i++){
		if (i%2==0){
			switch (input[i]){
				case '<': x1--; break;
				case '>': x1++; break;
				case 'v': y1--; break;
				case '^': y1++; break;
			}
			list[0][i+1]=x1;
			list[1][i+1]=y1;
		}
		if (i%2==1){
			switch (input[i]){
				case '<': x2--; break;
				case '>': x2++; break;
				case 'v': y2--; break;
				case '^': y2++; break;
			}
			list[0][i+1]=x2;
			list[1][i+1]=y2;
		}
		for (int j=0; j<i-1; j++){
			if (list[0][j]==list[0][i] && list[1][j]==list[1][i]){
				answer2--;
				break;
			}
		}
	}
	
	printf("Part I: \t%d\n", answer1);
	printf("Part II:\t%d\n", answer2);
	return 0;
}