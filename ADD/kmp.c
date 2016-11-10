#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNext(char *T, int next[])
{
	/*
		src = "abcab"
	*/
	int j = 1,len = strlen(T);
	int k = 0;
	next[1] = k;
	while(j <= len)
	{
		if ((k == 0)||(T[j - 1] == T[k - 1]))
		{
			j++;
			k++;
			next[j] = k;
			printf("next[%d]=[%d]\n",j,k);
		}
		else
		{
			k = next[k];
		}
	}
}

#define MAXSIZE 100
int main()
{

	char *str = "abaababc";
	unsigned int len = strlen(str);
	int next[MAXSIZE] = {0} ;
	getNext(str,next);
	int i = 0;
	for(i = 1;i <= len;++i)
		printf("next[%d] = %d\n",i , next[i]);
	return 0;
}
