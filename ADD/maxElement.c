/*================================================================
*   Copyright (C) 2016 Sangfor Ltd. All rights reserved.
*   
*   文件名称：maxElement.c
*   创 建 者：AF_duyong
*   创建日期：2016年11月09日
*   描    述：求数组中的最大元素
*
================================================================*/


#include <stdio.h>
#include <assert.h>
/*
	通用求解最大元素的方法
*/
int PF_maxnum(int src[] , int n)
{
	assert(src != NULL);
	int max = 0 , i = 0;
	for(i = 0;i < n;++i)
	{
		if(src[i] > max)
			max = src[i];
	}
	return max;
}
int main()
{
	int src[] = {8,4,2,6,7,19,20};
	int rtn = PF_maxnum(src,7);
	printf("max num is [%d]\n",rtn);
	return 0;
}
