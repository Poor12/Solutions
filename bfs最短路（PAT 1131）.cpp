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
#define M 100005
#define INF 0x7ffffff
vector<int> edg[M];
struct Road
{
	int s;
	int e;
	int id;
};
Road road[M];
struct state
{
	int dis;
	int cnum;
	int nowcity;
	int nowroad;
	vector<int> cv;
	vector<int> rv;
	bool operator <(const state & a) const
	{
		if (dis > a.dis)
			return 1;
		else if (dis == a.dis)
			return cnum > a.cnum;
		else
			return false;
	}
};
int vis[M];
void dijk(int start, int end)
{
	int i;
	priority_queue<state> q;
	memset(vis, 0, sizeof(vis));
	state sta;
	sta.cnum = 0;
	sta.nowcity = start;
	sta.dis = 0;
	sta.nowroad = -1;
	q.push(sta);
	int city;
	Road r;
	int e;
	state pushs;
	while (!q.empty())
	{
		sta = q.top();
		q.pop();
		city = sta.nowcity;
		vis[city] = 1;
		if (city == end)
		{
			int lastc;
			sta.cv.push_back(end);
			cout << sta.dis << endl;
			for (i = 0;i < sta.rv.size();++i)
			{
				printf("Take Line#%d from %04d to %04d.\n", sta.rv[i], sta.cv[i], sta.cv[i + 1]);
			}
			break;
		}
		for (i = 0;i < edg[city].size();++i)
		{
			pushs = sta;
			r = road[edg[city][i]];
			if (r.s == city)
				e = r.e;
			else
				e = r.s;
			if (vis[e])
				continue;
			if (r.id != sta.nowroad)
			{
				pushs.cnum++;
				pushs.cv.push_back(sta.nowcity);
				pushs.rv.push_back(r.id);
				pushs.nowroad = r.id;
			}
			pushs.dis++;
			pushs.nowcity = e;
			q.push(pushs);
		}
	}
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, i, m, k;
	int j, node, lastnode;
	scanf("%d", &n);
	j = 0;
	for (i = 1;i <= n;++i)
	{
		scanf("%d", &k);
		lastnode = -1;
		while (k--)
		{
			scanf("%d", &node);
			if (lastnode != -1)
			{
				edg[lastnode].push_back(j);
				edg[node].push_back(j);
				road[j].s = lastnode;
				road[j].e = node;
				road[j].id = i;
				j++;
			}
			lastnode = node;
		}
	}
	cin >> k;
	int s, e;
	while (k--)
	{
		cin >> s >> e;
		dijk(s, e);
	}
	return 0;
}