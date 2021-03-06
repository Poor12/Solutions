#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <string>
#include <queue>
using namespace std;
int n, m;
int par, num, child;
vector<vector<int>> tree;
vector<int> length;
vector<int> countt;
int maxheight = 0;
void dfs(int root, int level)
{
	if (level > maxheight)
		maxheight = level;
	length[root] = level;
	for (int i = 0;i < tree[root].size();++i)
		dfs(tree[root][i], level + 1);
}
void bfs(int root)
{
	queue<int> qu;
	qu.push(root);
	length[1] = 1;
	while (!qu.empty())
	{
		int a = qu.front();
		qu.pop();
		if (length[a] > maxheight)
			maxheight = length[a];
		for (int i = 0;i < tree[a].size();++i)
		{
			length[tree[a][i]] = length[a]+1;
			qu.push(tree[a][i]);
		}
	}
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> m;
	tree.resize(n + 1);
	length.resize(n + 1, 1);
	
	for (int i = 0;i < m;++i)
	{
		cin >> par >> num;
		for (int j = 0;j < num;++j)
		{
			cin >> child;
			tree[par].push_back(child);
		}
	}
	//dfs(1, 1);
	bfs(1);
	countt.resize(maxheight+1,0);
	int maxium = 0,v=0;
	for (int i = 1;i < maxheight + 1;++i)
	{
		for (int j = 1;j <= n;++j)
		{
			if (length[j] == i)
			{
				countt[i]++;
			}
		}
		if (countt[i] > maxium)
		{
			maxium = countt[i];
			v = i;
		}
	}
	cout << maxium << " " << v;
}
