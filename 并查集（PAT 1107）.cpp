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
const int maxn = 1010;
int father[maxn];
vector<int> hobby[maxn];
int num[maxn] = { 0 };
int getfather(int i)
{
	if (father[i] < 0)
		return i;
	return father[i] = getfather(father[i]);
}
void Union(int i, int j)
{
	int lf = getfather(i);
	int rf = getfather(j);
	if (lf != rf)
		father[lf] = rf;
}
bool cmp(int a, int b)
{
	return a > b;
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m;
	scanf("%d", &n);
	for (int i = 1;i <= n;++i)
		father[i] = i;
	int a, b;
	for (int i = 1;i <= n;++i)
	{
		father[i] = -1;
	}
//	int a, b;
	for (int i = 1;i <= n;++i)
	{
		scanf("%d:", &m);
		for (int j = 1;j <= m;++j)
		{
			scanf("%d", &a);
			hobby[a].push_back(i);
		}
	}
	for (int i = 1;i < maxn;++i)
	{
		if (hobby[i].size() != 0)
		{
			for (int j = 0;j < hobby[i].size() - 1;++j)
			{
				Union(hobby[i][j], hobby[i][j + 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 1;i < maxn;++i)
	{
		if (father[i] < 0)
			ans++;
	}
	for (int i = 1;i <= n;++i)
	{
		num[getfather(i)]++;
	}
	sort(num, num + maxn, cmp);
	printf("%d\n", ans);
	for (int i = 0;i < ans;++i)
	{
		printf("%d", num[i]);
		if (i < ans - 1)
			printf(" ");
	}
	return 0;
	
}