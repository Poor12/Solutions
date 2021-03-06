#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 201;
map<string, int> number;
int happ[maxn];
int rehapp[maxn];
bool vis[maxn];
int costt[maxn];
int countt[maxn];
int path[maxn];
struct edge
{
	int to;
	int cost;
};
vector<edge> ee[maxn];
typedef pair<int, int> pii;
priority_queue < pii, vector<pii>, greater<pii>> q;
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int n, k;
	string d,s;
	cin >> n >> k>>s;
	number[s] = 0;
	happ[0] = 0;
	for (int i = 1;i < n;++i)
	{
		string city;
		int hap;
		cin >> city >> hap;
		number[city] = i;
		happ[i] = hap;
	}
	for (int i = 0;i < n;++i)
	{
		vis[i] = 0;
		costt[i] = INT32_MAX;
		path[i] = -1;
		rehapp[i] = 0;
		countt[i] = 0;
	}
	for (int i = 0;i < k;++i)
	{
		string city1, city2;
		int cost;
		cin >> city1 >> city2 >> cost;
		edge e;
		e.to = number[city2];
		e.cost = cost;
		ee[number[city1]].push_back(e);
		e.to = number[city1];
		ee[number[city2]].push_back(e);
		//costt[number[city1]][number[city2]] = cost;
		//costt[number[city2]][number[city1]] = cost;
	}
	costt[0] = 0;
	q.push(make_pair(costt[0], 0));
	while (!q.empty())
	{
		pii p = q.top();
		q.pop();
		int u = p.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0;i < ee[u].size();++i)
		{
			edge ed = ee[u][i];
			int v = ed.to;
			if (vis[v]) continue;
			//countt[v]++;
			if (costt[v] > costt[u] + ed.cost||(costt[v]=costt[u]+ed.cost&&rehapp[v]<rehapp[u]+happ[v])||(costt[v] = costt[u] + ed.cost&&rehapp[v] == rehapp[u] + happ[v]&&countt[u]+1<countt[v]))
			{
				costt[v] = costt[u] + ed.cost;
				rehapp[v] = rehapp[u] + happ[v];
				countt[v]= countt[u] + 1;
				path[v] = u;
				q.push(make_pair(costt[v], v));
			}
		}
	}
	stack<int> ss;
	int x = number["ROM"];
	while (x != -1)
	{
		ss.push(x);
		x = path[x];
	}
	while (!ss.empty())
	{
		int temp = ss.top();
		ss.pop();
		printf("%d ", temp);
	}
	cout << endl << rehapp[number["ROM"]];
	return 0;
}