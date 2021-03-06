/*全排列
1.从最后往前找，直到找到第一个升序排列，即a[i] > a[i - 1]；
2.从a[i]开始向后找，找到比a[i]大的最小的元素a[p];
3.交换a[i - 1]与a[p]；
4.将a[i]及以后的数降序排列；
*/
int main()
{
	int t, n, k, i, index, temp, a[1025];
	scanf("%d", &t);
	while (t--)
	{
		a[0] = 1024;
		index = temp = 0;
		scanf("%d%d", &n, &k);
		for (i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		while (k--)
		{
			for (i = n;i > 1;i--)
			{
				if (a[i] > a[i - 1])
				{
					index = i - 1;
					break;
				}
			}
			if (index)
			{
				for (i = index + 1;i <= n;i++)
				{
					if (a[i] > a[index] && a[i] < a[temp])
					{
						temp = i;
					}
				}
				int m = a[index];
				a[index] = a[temp];
				a[temp] = m;
			}

			sort(a + index + 1, a + n + 1);
		}
		printf("%d", a[1]);
		for (i = 2;i <= n;i++)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}