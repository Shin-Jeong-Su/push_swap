#include "my_deque.h"
#include <stdio.h>
#include <time.h>
int main(){

	srand(time(NULL));
	t_dq dq;
	dq_init(&dq);
	printf("Data  : ");
	for(int i=0;i<5;i++){
		int data=rand()%19;
		printf("%d\t",data);
		push_front_dq(&dq,data);
	}
	printf("\n");
	printf("in Qu : ");
	for(int i=0;i<5;i++){
		printf("%d\t",back_dq(&dq));
		pop_back_dq(&dq);
	}
	system("leaks a.out");
}
