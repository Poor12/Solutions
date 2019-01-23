bool u[10000001];
int su[10000000], n = 10000000,nn;
void prepare()
{
	int num = 0;
	memset(u, 1, sizeof(u));
	for (int i = 2;i < n;i++)
	{
		if (u[i]) su[++num] = i;
		for (int j = 1;j <= num;++j)
		{
			if (i*su[j] > n) break;
			u[i*su[j]] = 0;
			if (i%su[j] == 0) break;
		}
	}
	nn = num;
}
int main()
{
	prepare();
	int n;
	while (scanf("%d", &n))
	{
		if (n == 8) { puts("2 2 2 2");continue; }
		if (n == 9) { puts("2 2 2 3");continue; }
		if (n == 10) { puts("2 2 3 3");continue; }
		if (n == 11) { puts("2 3 3 3");continue; }
		if (n == 12) { puts("3 3 3 3");continue; }
		if (n < 8) { puts("impossible");continue; }
		if (n % 2 == 0) { printf("2 2 ");n -= 4; }
		else { printf("2 3 ");n -= 5; }
		for (int i = 1;i <= nn;++i)//任何大于4的偶数都可以写成两个奇素数之和
		{
			//if (su[i] * 2 > n) break;
			if (u[n - su[i]])
			{
				printf("%d %d\n", su[i], n - su[i]);
				break;
			}
		}
	}
}