#include <stdio.h>
#include <stdlib.h>

int merge(int src[],int low,int mid,int high)
{
	int *tmp_arr = (int *)malloc((high + 1) * sizeof(int));
	int i = low,j = mid + 1,k = low;
	while(i<= mid && j <= high) {
		if (src[i] <= src[j])
			tmp_arr[k++] = src[i++];
		else
			tmp_arr[k++] = src[j++];
	}
	if (i<=mid){
		while(i<=mid) {
			tmp_arr[k++] = src[i++];
		}
	}else {
		while(j<=high) {
			tmp_arr[k++] = src[j++];
		}
	}
	
	for ( i = low;i<=high;++i){
		src[i] = tmp_arr[i];
	}
	free(tmp_arr);
	return 0;
}

int merge_sort(int src[],int low,int high)
{
	if (low < high)
	{
		int mid = (low + high)/2;
		merge_sort(src,low,mid);
		merge_sort(src,mid+1,high);
		merge(src,low,mid,high);
	}
	
	return 0;
}

int main()
{
	int src[] = {-1,0,-3,4,8,2,9,1,5};
	int i;
	#define  MAX_NUM  8
	merge_sort(src,0,MAX_NUM);
	for (i = 0;i<=MAX_NUM;++i)
		printf("src[%d]=%d\n",i , src[i]);
	return 0;
}
