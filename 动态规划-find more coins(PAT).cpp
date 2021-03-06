#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
using namespace std;
int a[10100], b[110];
vector<int> dp[110];
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	dp[0].push_back(0);
	for (int i = n - 1;i >= 0;--i)
	{
		for (int j = m;j >= a[i];j--)
		{
			if (dp[j - a[i]].size() != 0)
			{
				dp[j] = dp[j - a[i]];
				dp[j].push_back(a[i]);
			}
		}
	}
	if (dp[m].size() == 0)
	{
		printf("no solution\n");
	}
	else
	{
		for (int i = dp[m].size() - 1;i >= 1;--i)
		{
			printf("%d ", dp[m][i]);
		}
	}
	return 0;
}