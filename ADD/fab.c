#include <stdlib.h>
#include <stdio.h>
/*
   f(n) = f(n-1) + f(n-2)
 */

int fab(int len)
{
	if(len == 0) return 0;
	if(len == 1) return 1;
	int *dst = (int *)malloc(len * sizeof(int));
	if(dst == NULL)
	{
		printf("dst malloc failed\n");
		return 0;
	}
	dst[0] = 0;
	dst[1] = 1;
	int i;
	for(i = 2;i <= len;++i)
	{
		dst[i] = dst[i-1] + dst[i-2];
	}
	int rtn = dst[len];
	free(dst);
	return rtn;
}

int main()
{
	int ret = fab(9);
	printf("fab=[%d]\n",ret);
	return 0;
}
