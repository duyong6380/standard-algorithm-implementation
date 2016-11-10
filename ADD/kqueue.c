/*================================================================
*   Copyright (C) 2016 Sangfor Ltd. All rights reserved.
*   
*   文件名称：kqueue.c
*   创 建 者：AF_duyong
*   创建日期：2016年11月09日
*   描    述：
*
================================================================*/


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int low , int high)
{
	srand(time(NULL));
	int mid = high - low;
	return (rand()%mid + low);
}

int check(int i ,int j, int x[])
{
	int k = 0;
	for(k = 1;k < i;++k)
	{
		if(x[k] == j || abs(k - x[k]) == abs(i - j))
			return 1;
	}
	return 0;
}
#define MAX_SIZE 100
int kqueue(int n)
{
	assert(n != 0);
	int x[MAX_SIZE] = {0}, count = 0 , i= 0,j = 0;
	for(i = 1;i<= n ;++i)
	{
	repeat:
		j = getRandom(1,n);
		count += 1;
		printf("i=%d\n",i);
		if(check(i,j,x) == 0)
		{
			x[i] = j;
			count = 0;
			continue;
		}
		if(count == 8)
		{
			return 1;
		}
		else
		{
			goto repeat;
		}
	}
	for(i = 1;i <= n;++i)
		printf("queue[%d] is place[%d]\n",i , x[i]);
	return 0;
}

int main()
{
	int rtn = 0;
	while(1)
	{
		rtn = kqueue(8);
		if(rtn == 0)
			return 1;
	}
	return 0;
}
