
/*
* 硬币中存在假币问题
*/

int DCoin(int src,int low,int high)
{
	if(low == high + 1)
	{
		if (src[low] == src[high]) 
			return 
	}
	int mid = (low-high+1)/3;
	s1 = Dsum(src,low,mid);
	s2 = Dsum(src,mid + 1,2*mid);
	s3 = Dsum(src,2*mid+1,high);
	if(s1 == s2)
	{
		return	DCoin(src,2*mid + 1, high);
	}
	else 
	{
		return DCoin(src,low,2*mid);
	}
	return 0;
}

int main()
{
	int src[] = {2,2,2,2,5,2,2,2};

}
