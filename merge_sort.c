#include <stdio.h>
#define size 8
int sorted[size];
void	merge_ascending(int *arr,int mid, int left, int right){
	// printf("merged!\n");
	// printf("mid : %d\n",mid);

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
	// printf("arr    :\t");
	// for(int i=0;i<size;i++){
	// 	printf("%d\t",arr[i]);
	// }
	// printf("\n");

	// printf("sorted :\t");
	// for(int i=0;i<size;i++){
	// 	printf("%d\t",sorted[i]);
	// }
	// printf("\n");
	for(int i=j;i<size;i++){
		sorted[i]=arr[i];
	}
	
	for(int i=0;i<size;i++){
		arr[i]=sorted[i];
	}
	// printf("\n");
}
void	merge_decending(int *arr, int mid,int left,int right){
	int i,j,k;
	i = left;
	j = mid+1;
	k = left;
	while(i<=mid && j<=right){
		if(arr[i]>=arr[j]){
			sorted[k++]=arr[i++];
		}
		else{
			sorted[k++]=arr[j++];
		}
	}
	if(i>mid){
		while(j<=right)
			sorted[k++]=arr[j++];
	}
	else if(j>right){
		while(i<=mid)
			sorted[k++]=arr[i++];
	}
	for(int i=j;i<size;i++){
		sorted[k++]=arr[i];
	}
	for(int i=0;i<size;i++){
		arr[i]=sorted[i];
	}


}
void	merge_sort(int *arr, int left, int right){
	int mid = (left+right)/2;
	if(mid >= right){
		return;
	}
	else{
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		// merge_ascending(arr,mid,left,right);
		merge_decending(arr,mid,left,right);
	}
}
int main(){
	int arr[size] = {0,100,-32,18,39,2,5,-121};
	merge_sort(arr,0,size-1);
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}

}