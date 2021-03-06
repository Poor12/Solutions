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
using namespace std;
const int maxn = 100;
vector<int> child[maxn];
int hashtable[maxn] = { 0 };//每一层的叶子节点数
int n, m;
int maxlevel = 0;
int level[maxn] = { 0 };//第i个节点在几层
void dfs(int root, int level)
{
	if (level > maxlevel) maxlevel = level;
	if (child[root].size() == 0) hashtable[level]++;
	for (int i = 0;i < child[root].size();++i)
	{
		dfs(child[root][i], level + 1);
	}
}
void bfs(int root)
{
	queue<int> q;
	q.push(root);
	level[1] = 1;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		if (child[a].size() == 0) hashtable[level[a]]++;
		for (int i = 0;i < child[a].size();i++)
		{
			level[child[a][i]] = level[a] + 1;
			if (level[child[a][i]] > maxlevel) maxlevel = level[child[a][i]];
			q.push(child[a][i]);
		}
	}
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> m;
	int parent, num;
	for (int i = 0;i < m;++i)
	{
		cin >> parent >> num;
		for (int i = 0;i < num;++i)
		{
			int ch;
			cin >> ch;
			child[parent].push_back(ch);
		}
	}
	//dfs(1, 1);
	bfs(1);
	for (int i = 1;i <= maxlevel;++i)
	{
		cout << hashtable[i];
		if (i != maxlevel)
			cout << " ";
	}
	return 0;
}
