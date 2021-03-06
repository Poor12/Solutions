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
vector<int> adj[1001];
int query;
bool vis[1001];
void dfs(int v)
{
	if (v == query) return;
	vis[v] = 1;
	for (int i = 0;i < adj[v].size();++i)
	{
		if (vis[adj[v][i]] == 0)
			dfs(adj[v][i]);
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}
	for (int i = 1;i <= k;++i)
	{
		cin >> query;
		int block = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1;i <= n;++i)
		{
			if (i != query && vis[i] == 0)
			{
				dfs(i);
				block++;
			}
		}
		cout << block - 1 << endl;
	}
	return 0;
}
