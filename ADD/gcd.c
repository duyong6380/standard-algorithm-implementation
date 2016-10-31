#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define False -1
#define True 0
int gcd(int m , int n)
{
	int i = 0;
	int k = m > n?n:m;
	printf("k = %d \n",k);
	for (i=k;i>1;--i)
	{
		if ( (m%i == 0) && (n%i == 0))
		{
			return i;
		}
	}
	return i;
}

int gcd_ou(int m,int n )
{
	assert(m !=0 && n != 0);
	int r = m%n;
	while(r != 0)
	{
		m = n ; 
		n = r ;
		r = m%n;
	}
	return n;
}

int main(int argc , char *argv[])
{
	if (argc != 3)
	{
		printf("param error");
		return False;
	}
	int a = atoi(argv[1]),b = atoi(argv[2]);
	printf("[a:(%d),b:(%d)] is gcd is value [%d]\n",a, b,gcd_ou(a,b));
	return True;
}
