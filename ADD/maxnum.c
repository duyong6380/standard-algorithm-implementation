/*================================================================
*   Copyright (C) 2016 Sangfor Ltd. All rights reserved.
*   
*   文件名称：maxnum.c
*   创 建 者：AF_duyong
*   创建日期：2016年11月13日
*   描    述：
*
================================================================*/
#include <stdio.h>

int maxnum(int src[] ,int n)
{
	int i = 0 , j = 1;
	while(i<n-1 && j != n)
	{
		if(src[i] < src[j])
		{
			i = j;
			j = i + 1;
		}
		else
			++j;
	}
	return src[i];
}

int main()
{
	int src[] = {2,8,6,3,11,9};
	printf("maxnum is %d\n",maxnum(src,6));
	return 0;
}
