// #include "push_swap.h"
#include <stdio.h>

// int sorted[size];
static void	merge_ascending(int *arr,int mid, int left, int right){
	int i,j,k;
	i = left;
	j = mid+1;
	k = left;

	while (i <= mid && j <= right){
		if (arr[i] <= arr[j]){
			sorted[k++] = arr[i++];
		}
		else{
			sorted[k++] = arr[j++];
		}
	}
	if (i > mid){
		while (j <= right)
			sorted[k++]=arr[j++];
	}
	else{
		while(i<=mid)
			sorted[k++]=arr[i++];
	}
	for(int i=j;i<size;i++){
		sorted[i]=arr[i];
	}
	
	for(int i=0;i<size;i++){
		arr[i]=sorted[i];
	}
}

// static void	merge_decending(int *arr, int mid, int left, int right){
// 	int i,j,k;
// 	int sorted[size];
// 	i = left;
// 	j = mid+1;
// 	k = left;
// 	while(i<=mid && j<=right){
// 		if(arr[i]>=arr[j]){
// 			sorted[k++]=arr[i++];
// 		}
// 		else{
// 			sorted[k++]=arr[j++];
// 		}
// 	}
// 	if(i>mid){
// 		while(j<=right)
// 			sorted[k++]=arr[j++];
// 	}
// 	else if(j>right){
// 		while(i<=mid)
// 			sorted[k++]=arr[i++];
// 	}
// 	for(int i=j;i<size;i++){
// 		sorted[k++]=arr[i];
// 	}
// 	for(int i=0;i<size;i++){
// 		arr[i]=sorted[i];
// 	}
// }

typedef struct s_m_sort_info
{
	int left;
	int right;
	int mid;
	int size;
	int *sorted;
}t_m_sort_info;

void	merge_sort(int *arr, int left, int right){
	int mid = (left+right)/2;
	if(mid >= right){
		return;
	}
	else{
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		// merge_ascending(arr,mid,left,right);
		merge_ascending(arr,mid,left,right);
	}
}

void static init(t_m_sort_info *info,int size)
{
	info->left = 0;
	info->right = 0;
	info->mid = 0;
	info->size = size;
	info->sorted = malloc(sizeof(int) *size);
}

int main(){
	int arr[8] = {0,100,-32,18,39,2,5,-121};
	merge_sort(arr,0,size-1);
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
}