#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
int n, k, p;
vector<int> fac, temp, ans;
int maxsqu = -1;
int power(int x, int y)
{
	int ans = 1;
	while (y)
	{
		ans = x * ans;
		y--;
	}
	return ans;
}
void init()
{
	int i = 1;
	int ans = 1;
	fac.push_back(0);
	while (ans <= n)
	{
		fac.push_back(ans);
		ans = power(++i, p);
	}
}
void dfs(int index, int nowk, int sum, int sumsqu)
{
	if (nowk == k && sumsqu == n)
	{
		if (sum > maxsqu)
		{
			maxsqu = sum;
			ans = temp;
		}
		return;
	}
	if (nowk > k || sumsqu > n)
		return;
	if (index >= 1)
	{
		temp.push_back(index);
		dfs(index, nowk + 1, sum + index, sumsqu + fac[index]);
		temp.pop_back();
		dfs(index - 1, nowk, sum, sumsqu);
	}
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	scanf("%d%d%d", &n, &k, &p);
	init();
	dfs(fac.size() - 1, 0, 0, 0);
	if (maxsqu == -1)
		printf("Impossible");
	else
	{
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1;i < ans.size();++i)
			printf(" + %d^%d", ans[i], p);
	}
	return 0;
	
}