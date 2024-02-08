#include <stdio.h>
#define size 8
#define SWAP(x,y,tmp) ((tmp)=(x), (x)=(y), (y)=(tmp))

void	partition(int *arr,int *pivot,int left,int right){
	// printf("q_sort!\n");
	// printf("pivot : %d\n", *pivot);
	int low,high,tmp;

	low = left + 1;
	high = right;
	while(low <= high){
		while (arr[low] <= arr[*pivot] && low <= right){
			low++;
		}
		while (arr[high] >= arr[*pivot] && high >= left+1){
			high--;
		}
		if (low < high){
			SWAP(arr[low],arr[high],tmp);
		}
	}
	SWAP(arr[*pivot],arr[high],tmp);

	*pivot = high;
	// printf("changed pivot : %d\n",*pivot);
	// printf("arr  : ");
	// for(int i=0;i<size;i++){
	// 	printf("%d ",arr[i]);
	// }
	// printf("\n");
}
void	quick_sort(int *arr,int left,int right){
	int pivot = left;
	if(left >= right)
		return ;
	partition(arr,&pivot,left,right);
	quick_sort(arr,left,pivot-1);
	quick_sort(arr,pivot+1,right);
}
int main(){
	// int arr[size] = {0,100,-32,18,39,2,5,-121};
	int arr[size] = {3,3,3,3,3,3,3,3};
	quick_sort(arr,0,size-1);
	// printf("\n");
	printf("sorted  : ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}	