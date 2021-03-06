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
#define maxn 500+10
#define inf INT32_MAX
int res[maxn];//每座城的
int ress[maxn];//c1到x的
bool visited[maxn];
int countt[maxn];
int dist[maxn];
int count[maxn];
int n, m, c1, c2;
int x, y, l;
struct edge
{
	int to;
	int dist;
};
vector<edge> G[maxn];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> m >> c1 >> c2;
	for (int i = 0;i < n;++i)
	{
		cin >> res[i];
	}
	for (int i = 0;i < n;++i)
	{
		visited[i] = 0;
		dist[i] = inf;
		ress[i] = res[i];
		countt[i] = 0;
	}
	for (int i = 0;i < m;++i)
	{
		cin >> x >> y >> l;
		edge e;
		e.to = y;
		e.dist = l;
		G[x].push_back(e);
		e.to = x;
		G[y].push_back(e);
	}
	dist[c1] = 0;
	countt[c1] = 1;
	q.push(make_pair(dist[c1], c1));
	while (!q.empty())
	{
		pii a = q.top();
		q.pop();
		int u = a.second;
		if (visited[u]) continue;
		visited[u] = 1;
		for (int i = 0;i < G[u].size();++i)
		{
			edge ee = G[u][i];
			int v = ee.to;
			if (visited[v]) continue;
			/*
			if (dist[v] > dist[u] + ee.dist)
				countt[v] = countt[u];
			else if (dist[v] == dist[u] + ee.dist)
				countt[v] += countt[u];
			if (dist[v] > dist[u] + ee.dist || (dist[v] == dist[u] + ee.dist&&ress[v] < ress[u] + res[v]))
			{
				dist[v] = dist[u] + ee.dist;
				ress[v] = ress[u] + res[v];
				q.push(make_pair(dist[v], v));
			}
			*/
			if (dist[v] > dist[u] + ee.dist)
			{
				dist[v] = dist[u] + ee.dist;
				ress[v] = ress[u] + res[v];
				countt[v] = countt[u];
				q.push(make_pair(dist[v], v));
			}
			else if (dist[v] == dist[u] + ee.dist)
			{
				countt[v]+=countt[u];
				if (ress[v] < ress[u] + res[v])
					ress[v] = ress[u] + res[v];
				q.push(make_pair(dist[v], v));
			}
		}
	}
	cout << countt[c2] << " " << ress[c2];
	return 0;
}
