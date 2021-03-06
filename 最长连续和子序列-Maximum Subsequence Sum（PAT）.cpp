//最大连续和子序列
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
const int maxn = 10001;
int a[maxn], dp[maxn];
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int n, flag = 0, m, start, end, s, e;
	cin >> n;
	for (int i = 0;i < n;++i)
	{
		cin >> a[i];
		if (a[i] >= 0)
			flag = 1;
	}
	if (flag == 0)
	{
		cout << 0 << " " << a[0] << " " << a[n - 1] << endl;
		return 0;
	}
	m = dp[0] = a[0];
	start = end = s = e = 0;
	for (int i = 1;i < n;++i)
	{
		if (a[i] <= dp[i - 1] + a[i])
		{
			dp[i] = dp[i - 1] + a[i];
			e = i;
		}
		else
		{
			s = e= i;
			dp[i] = a[i];
		}
		if (m < dp[i])
		{
			m = dp[i];
			start = s;
			end = e;
		}
	}
	cout << m << " " << a[start] << " " << a[end] << endl;
	return 0;
}
