/*================================================================
*   Copyright (C) 2016 Sangfor Ltd. All rights reserved.
*   
*   �ļ����ƣ�maxElement.c
*   �� �� �ߣ�AF_duyong
*   �������ڣ�2016��11��09��
*   ��    �����������е����Ԫ��
*
================================================================*/


#include <stdio.h>
#include <assert.h>
/*
	ͨ��������Ԫ�صķ���
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
