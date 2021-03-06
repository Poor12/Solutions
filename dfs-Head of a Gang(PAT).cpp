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
using namespace std;

const int maxn = 2010;
map<string, int> ston, gang;
map<int, string> ntos;
vector<int> adj[maxn];
bool vis[maxn] = { false };
int weight[maxn] = { 0 };//存储每个节点的权
int n, limit, vnum = 0, tmpnum, tmpweight, head,renum=0;//vnum为图中节点个数
int change(string s)
{
	if (ston.count(s) != 0)
		return ston[s];
	else
	{
		ston[s] = vnum;
		ntos[vnum] = s;
		return vnum++;
	}
}
void dfs(int u)
{
	vis[u] = 1;
	tmpnum++;
	tmpweight += weight[u];
	if (weight[u] > weight[head])
		head = u;
	for (int i = 0;i < adj[u].size();++i)
	{
		if (vis[adj[u][i]])
			continue;
		dfs(adj[u][i]);
	}
}
void  DFSTrave()
{
	for (int i = 0;i < n;++i)
	{
		if (vis[i])
			continue;
		vis[i] = 1;
		tmpnum = 1;
		tmpweight = weight[i];
		head = i;
		for (int j = 0;j < adj[i].size();++j)
		{
			int u = adj[i][j];
			if (vis[u]) continue;
			dfs(u);
		}
		if (tmpnum > 2 && tmpweight > 2 * limit)
		{
			gang.insert(make_pair(ntos[head], tmpnum));
			//renum++;
		}
		
	}
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> limit;
	string s1, s2;
	int w;
	for (int i = 0;i < n;++i)
	{
		cin >> s1 >> s2 >> w;
		int idx1 = change(s1);
		int idx2 = change(s2);
		adj[idx1].push_back(idx2);
		adj[idx2].push_back(idx1);
		weight[idx1] += w;
		weight[idx2] += w;
	}
	DFSTrave();
	cout << gang.size() << endl;
	for (auto it = gang.begin();it != gang.end();it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}