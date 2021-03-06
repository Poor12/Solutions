#define maxn 9
int parvalue[maxn] = { 10000,5000,2000,1000,500,100,50,10 };
int num[maxn] = { 0 };
int exchange(int n)
{
	int i, j;
	for (i = 0;i < maxn;++i)
	{
		if (n >= parvalue[i]) break;//找到比n小的最大面额
	}
	while (n > 0 && i < maxn)
	{
		if (n >= parvalue[i])
		{
			n -= parvalue[i];
			num[i]++;
		}
		else if (n < 10 && n >= 5)//没有相应的面额
		{
			num[maxn - 1]++;
			break;
		}
		else
		{
			i++;
		}
	}
	return 0;
}
int main()
{
	int i;
	float m;
	printf("输入需要找零的金额：");
	scanf("%f", &m);
	exchange((int)100 * m);
	printf("\n%.2f元零钱的组成：\n", m);
	for (i = 0;i < maxn;++i)
		if (num[i] > 0)
			printf("%6.2f: %d张\n", (float)parvalue[i] / 100.0, num[i]);
	return 0;
}