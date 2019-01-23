bool u[1000001];
int su[1000001];
int u2[1000001],n=1000000,nn;
void prepare()
{
	int num = 0;
	memset(u, 1, sizeof(u));
	for (int i = 2;i < n;++i)
	{
		if (u[i]) su[++num] = i;
		for (int j = 1;j <= num;++j)
		{
			if (i*su[j] >= n) break;
			u[i*su[j]] = 0;
			if (i%su[j] == 0) break;
		}
	}
	nn = num;
}
bool ok(int x)
{
	int k = 0;
	while (x)
	{
		k += x % 10;
		x = x / 10;
	}
	return u[k];
}
int main()
{
	int i, j, k=0,n,x,y;
	prepare();
	for (i = 1;i <= nn;++i)
	{
		if (ok(su[i]))
			u2[++k] = su[i];
	}
	k = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;++i)
	{
		scanf("%d %d", &x, &y);
		for (j = 1;u2[j] <= x;j++);
		for (k = 1;u2[k] <= y;k++);
		if((u2[j-1]==x||u2[k-1]==y)&&x!=1)
			cout << k - j +1<< endl;
		else
			cout << k - j << endl;
	}
}