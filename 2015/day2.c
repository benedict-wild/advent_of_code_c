// Advent of Code 2015 - Day 1
#include <stdio.h>

void sort(int arr[3]);

int main(void){
	int answer1, answer2;
	answer1 = answer2 = 0;
	int arr[3];
	
	char line[20];
	FILE *fp;
	fp = fopen("input2.txt","r");
	while (fgets(line, 20, fp)!=NULL){
		sscanf(line, "%dx%dx%d",&arr[0], &arr[1], &arr[2]);
		sort(arr);
		answer1+=2*(arr[0]*arr[1]+arr[0]*arr[2]+arr[1]*arr[2])+arr[0]*arr[1];
		answer2+=2*(arr[0]+arr[1])+arr[0]*arr[1]*arr[2];
	}
	fclose(fp);

	printf("Part I: \t%d\n", answer1);
	printf("Part II:\t%d\n", answer2);
	return 0;
}

void sort(int arr[3]){
	int tmp;
	for (int i=0; i<2; i++){
		for (int j=i+1; j<3; j++){
			if (arr[j]<arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}