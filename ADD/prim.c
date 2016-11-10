#define N 50
int g[N][N];
int prim(int n)
{
	int min[] ={0};
	int lowcost[] = {0};
	for(i = 1;i <= n;++i)
	{
		for(j = 1;j < = n;++j)
		{
			if(g[i][j] < min)
			{
				min[i] = g[i][j]; 
				lowcost[i] = j;
			}
		}
	}

}


int init_graph()
{
	int i , j ;
	for(i = 0;i<=n;++i)
	{
		for(j = 0;j <= n;++j)
		{
			if(i == j)
				g[i][j] = 65535;
			else
				g[i][j] = 0;
		}
	}
	return 0;
}
int main()
{
	int i=1,j=1;
	int MAXLINE = 10;
	int w;
	printf("Please enter the number of the nodes:\n");
	scanf("%d",&n);
	if(n > N)
	{
		printf("input value is too bigger,do not accpet input\n");
		return -1;
	}
	(void)init(n);
	printf("Please enter the number of the edges:\n");
	int edgenum;
	scanf("%d",&edgenum);
	int v1,v2;
	FILE *fp = fopen("input.txt","r+");
	if(fp == NULL)
	{
		printf("input file is empty !!!!\n");
		return -1;
	}
	for(i=1;i<=edgenum;i++)
	{
		while(fgets(buf,sizeof(MAXLINE),fp))
		{
			rtn = sscanf(buf, "%d %d %d",&v1,&v2,&w);
			if(rtn != 3)
				continue;
			
			g[v1][v2]=g[v2][v1]=w;
		}
	}
	ans=prim();
	printf("The sum of the weight of the edges is:%d\n",ans);
	return 0;}

