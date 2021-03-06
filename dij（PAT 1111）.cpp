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
#define maxn 510
struct edge
{
	int to;
	int length;
	int time;
};
vector<edge> e[maxn];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
bool vis[maxn];
int pre[maxn];
int dist[maxn];
int length[maxn];
int zhongzhuan[maxn];
void dijstra(int s,int d)
{
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	for (int i = 0;i < maxn;++i)
	{
		dist[i] = INT16_MAX;
		length[i] = INT16_MAX;
	}
	dist[s] = 0;
	length[s] = 0;
	q.push(make_pair(dist[s], s));
	while (!q.empty())
	{
		pii p = q.top();
		q.pop();
		int u = p.second;
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = 0;i < e[u].size();++i)
		{
			int uu = e[u][i].to;
			if (vis[uu])
				continue;
			if (dist[uu] > dist[u] + e[u][i].length || (dist[uu] == dist[u] + e[u][i].length&&length[uu] > length[u] + e[u][i].time))
			{
				dist[uu] = dist[u] + e[u][i].length;
				length[uu] = length[u] + e[u][i].time;
				pre[uu] = u;
				q.push(make_pair(dist[uu], uu));
			}
		}
	}
}
void dijstra1(int s, int d)
{
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	for (int i = 0;i < maxn;++i)
	{
		//dist[i] = INT16_MAX;
		length[i] = INT16_MAX;
		zhongzhuan[i] = INT16_MAX;
	}
	//dist[s] = 0;
	zhongzhuan[s] = 0;
	length[s] = 0;
	q.push(make_pair(length[s], s));
	while (!q.empty())
	{
		pii p = q.top();
		q.pop();
		int u = p.second;
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = 0;i < e[u].size();++i)
		{
			int uu = e[u][i].to;
			if (vis[uu])
				continue;
			if (length[uu] > length[u] + e[u][i].time||(length[uu] == length[u] + e[u][i].time&&zhongzhuan[uu]>zhongzhuan[u]+1) )
			{
				//dist[uu] = dist[u] + e[u][i].length;
				length[uu] = length[u] + e[u][i].time;
				zhongzhuan[uu] = zhongzhuan[u] + 1;
				pre[uu] = u;
				q.push(make_pair(length[uu], uu));
			}
		}
	}
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m,v1,v2,isone,l,t,s,d;
	cin >> n >> m;
	
	for (int i = 0;i < m;++i)
	{
		cin >> v1 >> v2>>isone>>l>>t;
		edge ee;
		ee.to = v2;
		ee.length = l;
		ee.time = t;
		e[v1].push_back(ee);
		if (isone == 0)
		{
			ee.to = v1;
			e[v2].push_back(ee);
		}
	}
	cin >> s >> d;
	dijstra(s, d);
	//cout << "Distance = " << dist[d] << ": ";
	int k = d;
	vector<int> path;
	vector<int> path1;
	while (k != -1)
	{
		path.push_back(k);
		k = pre[k];
	}
	dijstra1(s, d);
	//cout << "Time = " << length[d] << ": ";
	k = d;
	while (k != -1)
	{
		path1.push_back(k);
		k = pre[k];
	}
	if (path == path1)
	{
		//cout << "Time = " << length[d] << ": ";
		printf("Distance = %d; Time = %d: ", dist[d], length[d]);
		for (int i = path.size() - 1;i >= 0;i--)
		{
			cout << (i == path.size() - 1 ? "" : " -> ") << path[i];
		}
	}
	else
	{
		cout << "Distance = " << dist[d] << ": ";
		for (int i = path.size() - 1;i >= 0;i--)
		{
			cout << (i == path.size() - 1 ? "" : " -> ") << path[i];
		}
		cout << endl;
		cout << "Time = " << length[d] << ": ";
		for (int i = path1.size() - 1;i >= 0;i--)
		{
			cout << (i == path1.size() - 1 ? "" : " -> ") << path1[i];
		}
	}
	
	return 0;
	
}
