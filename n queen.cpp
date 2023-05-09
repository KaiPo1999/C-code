#include <iostream>
//#include <stdlib.h>
//using namespace std;

#define YES 1
#define NO  0

#define is_attacked(Q1,Q2,Assign) (abs(Q1-Q2)==abs(Assign[Q1]-Assign[Q2]))

int *seat;
int *assignment;
int queen_number;

void recur_permutation(int index);
int is_safe(void);

int main(void) {
	int i,
		index;
	printf("Inpuut the number of queens: ");
	scanf("%d", &queen_number);
	seat = (int *)malloc(sizeof(int)*queen_number);
	for (i = 0;i < queen_number;i++) {
		seat[i] = 0;
	}
	assignment = (int *)malloc(sizeof(int)*queen_number);
	for (i = 0; i < queen_number;i++) {
		assignment[i] = 0;
	}
	index = 0;
	recur_permutation(index);

	free(seat);
	free(assignment);

	system("pause");
	return 0;
}

void recur_permutation(int index) {
	static int permuntation = 0;
	int i,
		j;
	if (index == queen_number) {
		if (is_safe()){
			printf("%d\t", ++permuntation);
			for (j = 0;j < queen_number;j++) {
				printf("%d\t",assignment[j]);
			}
			printf("\n");
		}
	}else {
		for (i = 0;i < queen_number;i++) {
			if (!seat[i]){
				seat[i] = 1;
				assignment[index] = i;
				recur_permutation(index + 1);
				seat[i] = 0;
			}
		}
	}
}

int is_safe(void) {
	int i,
		j;


	for (i = 0;i < queen_number - 1;i++) {
		for (j = i + 1;j < queen_number;j++) {
			if (is_attacked(i, j, assignment)) {
				return NO;
			}
		}
	}
	return YES;
}