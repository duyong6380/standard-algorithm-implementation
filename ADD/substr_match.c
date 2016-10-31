#include <string.h>
#include <stdio.h>

int pattern_match(char *src,char *dst)
{
	unsigned int dst_len = strlen(dst);
	int flag = 0;
	while(strlen(src)>= dst_len)
	{
		if (strncmp(src,dst,dst_len) == 0 )
		{
			flag = 1;
			break;
		}
		src++;
	}
	if (flag == 1)
		printf("find str [%s]\n",src);
	else
		printf("not find match string\n");
	return 0;
}


int main()
{
	char *src = "ababcabcacbab";
	char *dst = "abcac";
	pattern_match(src,dst);
	return 0;
}
