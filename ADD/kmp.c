#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNext(char *T, int next[])
{
	/*
		src = "abcab"
	*/
	next[1] = 0;
	int j = 1,len = strlen(T);
	int k = 0;
	while(j<len - 1)
	{
		if ((k==0)||(T[j] == T[k]))
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


int main()
{
	char *str = "abaababc";
	unsigned int len = strlen(str);
	int next[10] = {0} ;
	getNext(str,next);
	int i = 0;
	for(i = 1;i <= len;++i)
		printf("next[%d] = %d\n",i , next[i]);
	return 0;
}
