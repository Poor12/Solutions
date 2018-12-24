//29个数字中选7个，且互不相同
#define maxn 3
#define num 4
int nn[num];//29个数字
int lottery[maxn];//7个彩票数字
void combine(int n, int m)//29 7
{
	int i, j;
	for (i = n;i >= m;--i)
	{
		lottery[m - 1] = nn[i - 1];
		if (m > 1)
			combine(i - 1, m - 1);
		else {
			for (j = maxn - 1;j >= 0;--j)
				printf("%3d", lottery[j]);
			printf("\n");
		}
	}
}
int main()
{
	int i, j;
	for (i = 0;i < num;++i)
	{
		nn[i] = i + 1;
	}
	for (i = 0;i < maxn;++i)
	{
		lottery[i] = 0;
	}
	combine(num, maxn);
}