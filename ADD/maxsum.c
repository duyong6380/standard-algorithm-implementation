#include <stdio.h>
#include <stdlib.h>
int BMS(int a[] , int len , int *index)
{
	if (len <= 0)
	{
		return 0;
	}
	int i = 0 , j =0,sum =0,maxsum=0,tmp_sum = 0;
	for(i=0;i<len;++i)
	{
		tmp_sum = a[i];
		sum = a[i];
		for(j=i+1;j<len;++j)
		{
			tmp_sum +=a[j];
			if(tmp_sum > sum)
			{
				sum = tmp_sum;
			}
		}
		if(maxsum < sum)
		{
			maxsum = sum;
			*index = i;
		}
	}
	return maxsum;
}

/*
* brief :使用分治法来获取最大字段和
* return：maxsum success or 0 false
*/
int dMS(int src[] ,int low,int high)
{
	if (low == high)
	{
		if(src[low] > 0) return src[low];
		else return 0;
	}
	else
	{
		int mid = (low + high)/2;
		int leftsum = dMS(src,low,mid);
		int rightsum = dMS(src,mid+1,high);
		int i,j,lefts = 0,rights = 0,s1 = 0,s2 = 0;
		for (i=mid;i>low;--i)
		{
			lefts +=src[i];
			if (lefts > s1 )
			{
				s1 = lefts;
			}
		}
		for(j = mid+1;j<high;++j)
		{
			rights += src[j];
			if(rights > s2)
			{
				s2 = rights;
			}
		}
		int sum = s1 + s2;
		/*取3者中最大者*/
		if(sum < s2) sum = s2;
		if(sum < s1) sum = s1;
		return sum;
	}
	return 0;
}

/*
* brief:使用动态规划法获取最大子段和
* 时间复杂度只有O(n),有点吓人
*/

int dpMS(int src[],int len)
{
	int sum = 0,i = 0;
	int *b = (int *)malloc(len * sizeof(int));
	if(!b)
	{
		printf("tmp array malloc failed\n");
		return 0;
	}
	b[0] = src[0];
	for(i = 1;i < len;++i)
	{
		if(b[i-1] > 0)
		{
			b[i] = b[i-1] + src[i];
		}
		else
			b[i] = src[i];
	}
	for(i = 0;i < len;++i)
	{
		if(b[i] > sum)
			sum = b[i];
	}
	free(b);
	return sum;
}
int main()
{
	int src[] = {-20,12,-5,11,-4,13,-5,-2};
	int index = 0;
	int maxsum = dpMS(src,8);
	printf("maxsum=%d,index=%d\n",maxsum,index);
	return 0;
}
