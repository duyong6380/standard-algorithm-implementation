#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
 *	BM 匹配算法,时间复杂度为O(n * m)
 */
int pattern_match(char *src,char *dst)
{
	assert(src != NULL && dst != NULL);
	char *first = src;
	unsigned int dst_len = strlen(dst);
	while(strlen(src)>= dst_len)
	{
		if (strncmp(src,dst,dst_len) == 0 )
		{
			return (src - first);
		}
		src++;
	}
	return 0;
}
/*********************************KMP start ************************/
/*
 *	KMP 匹配算法,时间复杂度为O(n+m)
 */
void getNext(char *T, int next[])
{
	/*
	   src = "abcab"
	 */
	int j = 0,len = strlen(T);
	int k = -1;
	next[0] = k;
	while(j <= len)
	{
		if ((k < 0)||(T[j] == T[k]))
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
int KMP(char *src,char *dst)
{
#define	 MAXLEN  100
	int next[MAXLEN] = {};
	(void)getNext(dst,next);
	
	int i = 0,j = 0 ;
	int len = strlen(src),dst_len = strlen(dst);
	while((i-j) < (len - dst_len))
	{
		if((j < 0) || (src[i] == dst[j]))
		{
			++i;
			++j;
			if(j == dst_len)
			{
				return i - dst_len;
			}
		}
		else
		{
			j = next[j];
		}
	}
	return 0;
}
/**************************************KMP end ************************/
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("param is error\n");
		return 0;
	}
	int match_func_num = 0;
	printf("\t0:基础的模式匹配\n\
			\t1:KMP匹配算法\n\
			\tPlease enter the num:");
	scanf("%d",&match_func_num);
	char *src = "ababcabcacbab";
	char *dst = "abcab";
	int rtn = 0;
	switch(match_func_num)
	{
		case 0:
			rtn = pattern_match(src,dst);
			break;
		case 1:
		default:
			rtn = KMP(src,dst);
			break;
	}
	if(rtn != 0)
	{
		printf("rtn:[%d],match_str is[%s]\n",rtn,src+rtn);
	}
	else
	{
		printf("not match substring\n");
	}
	return 0;
}
