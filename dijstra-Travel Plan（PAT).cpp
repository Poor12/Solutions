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
#include <cstring>
#include <limits.h>
using namespace std;
const int maxn = 500 + 10;
const int inf = 0x3f3f3f3f;
bool visited[maxn];
int dist[maxn];
int pay[maxn];
int pre[maxn];
int dd[maxn][maxn];
int pp[maxn][maxn];
/*
struct Edge {
	int to;
	int dist, cost;
	Edge() {}
	void set_value(int v, int d, int c)
	{
		to = v;
		dist = d;
		cost = c;
	}
};

vector<Edge> G[maxn];
*/
typedef pair<int, int> pii;
priority_queue<pii,vector<pii>,greater<pii>> Q;

int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	for (int i = 0;i < n;++i)
	{
		dist[i] = inf;
		pay[i] = inf;
		visited[i] = 0;
		pre[i] = -1;
	}

	/*
	for (int i = 0;i < m;++i)
	{
		int v, w, x, y;
		cin >> v >> w >> x >> y;
		Edge e;
		e.set_value(w, x, y);
		G[v].push_back(e);
		e.to = v;
		G[w].push_back(e);
	}
	*/
	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			dd[i][j] = inf;
			pp[i][j] = inf;
		}
	}
	for (int i = 0;i < n;++i)
	{
		int v, w, x, y;
		cin >> v >> w >> x >> y;
		dd[v][w] = x;
		pp[v][w] = y;
		dd[w][v] = x;
		pp[w][v] = y;
	}
	dist[s] = 0;
	pay[s] = 0;
	Q.push(make_pair(dist[s], s));
	while (!Q.empty())
	{
		pii p= Q.top();
		Q.pop();
		int u = p.second;
		//if (visited[u]) continue;
		visited[u] = 1;
		for (unsigned int i = 0;i < n;++i)
		{
			//Edge e = G[u][i];
			//int v = e.to;
			if (visited[i]) continue;
			if (dist[i] > dist[u] + dd[u][i] || (dist[i] == dist[u] + dd[u][i] && pay[i] > pay[u] + pp[u][i]))
			{
				pay[i] = pay[u] + pp[u][i];
				dist[i] = dist[u] + dd[u][i];
				pre[i] = u;
				Q.push(make_pair(dist[i], i));
			}
		}
	}
	stack<int> ss;
	int x = d;
	while (x != -1)
	{
		ss.push(x);
		x = pre[x];
	}
	while (!ss.empty())
	{
		int temp = ss.top();
		ss.pop();
		printf("%d ", temp);
	}
	printf("%d %d\n", dist[d], pay[d]);
	
	
	return 0;
}
