bool u[1111111];
int su[1111111], nn=1000000;
void prepare()
{
	int i, j, num=0;
	memset(u, 1, sizeof(u));
	for (i = 2;i <= nn;++i)
	{
		if (u[i]) su[++num] = i;
		for (j = 1;j <= num;++j)
		{
			if (i*su[j] > nn) break;
			u[i*su[j]] = 0;
			if (i%su[j] == 0) break;//保证合数只被它最小的质数筛去
		}
	}
}
int main()
{
	prepare();
	int i, j, n, k;
	while (scanf("%d",&n)>0&&n)
	{
		bool ok = false;
		for (i = 2;i <= nn;++i)
		{
			if (su[i] * 2 > n)
				break;
			if (u[n - su[i]])
			{
				ok = true;
				break;
			}
		}
		if (!ok) puts("goldbach's conjecture is wrong.");
		else printf("%d=%d+%d\n", n, su[i], n - su[i]);
	}
}