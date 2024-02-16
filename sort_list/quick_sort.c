#include <stdio.h>
#define SWAP(x,y,tmp) ((tmp)=(x), (x)=(y), (y)=(tmp))

static void	partition(int *arr,int *pivot,int left,int right){
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
}
void	quick_sort(int *arr,int left,int right)
{
	int pivot = left;
	if(left >= right)
		return ;
	partition(arr,&pivot,left,right);
	quick_sort(arr,left,pivot-1);
	quick_sort(arr,pivot+1,right);
}

int main()
{
	const int size = 2;
	// int arr[size] = {0,100,-32,18,39,2,5,-121};
	int arr[size] = {3,1};
	quick_sort(arr,0,size-1);
	// printf("\n");
	printf("sorted  : ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}	