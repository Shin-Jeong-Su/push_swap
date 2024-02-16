#include <stdio.h>
#include "my_deque.h"

#define size 20

#include <time.h>

void r_sort(int *arr,int cur_depth,int m_depth){
	if (cur_depth >= m_depth)
		return ;
	t_dq dq;
	int unit=1;
	int mod=10;
	for(int i=0;i<cur_depth;i++){
		unit*=10;
	}
	init_dq(&dq);
	for(int i=0;i<10;i++){
		for(int j=0;j<size;j++){
			if (i == (arr[j]/unit) % mod){
				push_back_dq(&dq, arr[j]);
			}
		}
	}

	for(int i=0;i<size;i++){
		arr[i] = front_dq(&dq);
		pop_front_dq(&dq);
	}
	r_sort(arr,cur_depth+1,m_depth);
}

void radix_sort(int *arr){
	int max = arr[0];
	for(int i=1;i<size;i++){
		if(max<arr[i])
			max = arr[i];
	}
	int rept=1;
	while(max>=10){
		max/=10;
		rept++;
	}
	r_sort(arr,0,rept);
}

int main(){
	srand(time(NULL));
	int arr[size];
	for(int i=0;i<size;i++){
		arr[i]=rand()%100;
	}
	printf("befor : ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	radix_sort(arr);

	printf("sorted  : ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}	