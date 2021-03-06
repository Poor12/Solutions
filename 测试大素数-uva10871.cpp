//1.筛选法+试除法
//先筛选法计算2..根号n的素数筛和素数表，x是素数，当且仅当x为素数表中的一个素数或x不能被素数表中的任何素数整除
//时间复杂度O（根号n）
bool u[10010];
int su[10010], num=0,nn=10001;
void prepare()
{
	memset(u, 1, sizeof(u));
	for (int i = 2;i < nn;++i)
	{
		if (u[i]) su[++num] = i;
		for (int j = 1;j <= num;++j)
		{
			if (i*su[j] >= nn) break;
			u[i*su[j]] = 0;
			if (i%su[j] == 0) break;
		}
	}
}
bool pri(int x)
{
	int i, j, k;
	if (x < 10010)
		return u[x];
	for (i = 1;i <= num;++i)
	{
		if (x%su[i] == 0)
			return false;
	}
	return true;
}
int n,s[10010];//s[i]为前i个正整数的和
int main()
{
	int i, j, k;
	prepare();
	int te;
	scanf("%d", &te);
	while (te--)
	{
		scanf("%d", &n);
		s[0] = 0;
		for (i = 1;i <= n;++i)
		{
			scanf("%d", &s[i]);
			s[i] += s[i - 1];
		}
		bool ok = false;
		for (i = 2;i <= n;++i)//枚举长度
		{
			for (j = 0;j + i <= n;++j)//枚举首指针
			{
				k = s[i + j] - s[j];
				if (pri(k))
				{
					ok = true;
					printf("shortest primed subsequence is length %d:", i);
					for (k = 1;k <= i;++k)
						printf("%d ", s[j + k] - s[j + k - 1]);
					puts("");
					break;
				}
			}
			if (ok) break;
		}
		if (!ok)
			puts("anti-primed");
	}
}
