#include <stdlib.h>
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

/*
 0-1背包问题
*/

int v[5][11] = {0};

int knapSack(int n , int w[] ,int single_value[] , int sum_count)
{
	int i = 0,j = 0;
	for(i = 0;i <= n;++i)
	{
		v[i][0] = 0;
	}
	for(j = 0;j <= sum_count;++j)
	{
		v[0][j] = 0;
	}

	for(i = 1;i <= n;++i)
	{
		for(j = 1;j <= sum_count;++j)
		{
			if(w[i] > j)
				v[i][j] = v[i-1][j];
			else
			{
				v[i][j] = max(v[i-1][j],v[i-1][j-w[i-1]] + single_value[i-1]);
				printf("v[%d][%d] = %d\n",i,j,v[i][j]);
			}
		}
	}
	return v[n][sum_count];
}

int main()
{
	int w[] = {2,2,6,5,4},v1[] = {6,3,5,4,6};
	printf("v value is %d\n",knapSack(4,w,v1,10));
}
