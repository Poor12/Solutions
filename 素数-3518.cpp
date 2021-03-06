//任何两个素数之间的任何合数素数间隔相同
const int maxn = 1299710;
bool u[maxn];
int ans[maxn];
void prepare()
{
	int i, j, k;
	for (int i = 2;i < maxn;++i) u[i] = 1;
	for (i = 2;i < maxn;++i)
		if (u[i])
			for (j = 2;j*i < maxn;j++)
				u[i*j] = 0;
	for (i = 2;i < maxn;++i)
		if (!u[i])
		{
			j = i;
			while (j < maxn && !u[j]) j++;
			j--;
			for (k = i;k <= j;++k) ans[k] = j - i + 2;
			i = j;
		}
		else
			ans[i] = 0;
}
int main()
{
	int i, j, k;
	prepare();
	while (scanf("%d",&k)>0&&k>0)
	{
		printf("%d\n", ans[k]);
	}
}