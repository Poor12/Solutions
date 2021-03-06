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
#define maxn 10001
int father[maxn];
int mestate[maxn];
int area[maxn];
set<int> ids;
map<int, int> flag,num,ee,aa;
map<int, set<int> > minid;
int getfather(int id)
{
	if (father[id] < 0)
		return id;
	return father[id] = getfather(father[id]);
}
void Union(int id1, int id2)
{
	int lz = getfather(id1);
	int rz = getfather(id2);
	if (lz != rz)
	{
		father[lz] = rz;
	}
}
struct node {
	int id;
	int num;
	double avs, ava;
};
bool cmp(node& a, node& b)
{
	if (a.ava != b.ava)
		return a.ava > b.ava;
	else
		return a.id < b.id;
}
vector<node> re;
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int n;
	int id, fid, mid,cid, k, m, a;
	cin >> n;
	memset(father, -1, sizeof(father));
	memset(mestate, 0, sizeof(mestate));
	memset(area, 0, sizeof(area));
	for (int i = 0;i < n;++i)
	{
		cin >> id >> fid >> mid;
		ids.insert(id);
		cin >> k;
		if (fid != -1)
		{
			Union(id, fid);
			ids.insert(fid);
		}
		if (mid != -1)
		{
			Union(id, mid);
			ids.insert(mid);
		}
		for (int i = 0;i < k;++i)
		{
			cin >> cid;
			Union(id, cid);
			ids.insert(cid);
		}
		cin >> mestate[id] >> area[id];
	}
	int cnt = 0;
	for (auto it = ids.begin();it != ids.end();it++)
	{
		int u = getfather(*it);
		flag[u]++;
		minid[u].insert(*it);
		num[u] += 1;
		ee[u] += mestate[*it];
		aa[u] += area[*it];
		if (u == *it)
			cnt++;
	}
	cout <<cnt<<endl;
	for (auto it = flag.begin();it != flag.end();it++)
	{
		node n;
		n.id = *minid[it->first].begin();
		n.num = num[it->first];
		n.avs = (double)ee[it->first] / n.num;
		n.ava = (double)aa[it->first] / n.num;
		re.push_back(n);
	}
	sort(re.begin(), re.end(),cmp);
	for (int i = 0;i < re.size();++i)
		printf("%04d %d %.3lf %.3lf\n", re[i].id, re[i].num, re[i].avs, re[i].ava);
	return 0;
	
}