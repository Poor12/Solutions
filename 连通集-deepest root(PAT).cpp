# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <set>
# include <vector>
using namespace std;
const int siz = 10000;
const int debug = 1;
vector<int> v[siz];
int vis[siz];//记录每个节点在dfs搜索中的距离
class disjointset
{
private:
	int *T, size, sum;
	int FindRoot(int i)
	{
		return T[i] < 0 ? i : (T[i] = FindRoot(T[i]));
	}
public:
	disjointset(int _size) :size(_size)
	{
		T = new int[size];
		init();
	}
	void init()
	{
		sum = size;
		memset(T, -1, sizeof(int)*size);
	}
	bool unioned(int i, int j)
	{
		return FindRoot(i) == FindRoot(j);
	}
	void Union(int i, int j)
	{
		if ((i = FindRoot(i)) != (j = FindRoot(j)))
		{
			//T[i] = T[i] + T[j];
			T[j] = i;
			sum--;
		}
	}
	int sumofunits()
	{
		return sum;
	}
	~disjointset()
	{
		delete[] T;
	}
};
void dfs(int i, int dist, int &m)
{
	vis[i] = dist;
	m = max(m, vis[i]);
	for (int k = 0;k < v[i].size();k++)
		if (vis[v[i][k]] == -1)
			dfs(v[i][k], dist + 1, m);
}
int main()
{
	int i, j, temp;
	int n;
	scanf("%d", &n);
	disjointset ds(n);
	for (i = 0;i < n - 1;++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
		ds.Union(a, b);
	}
	if (ds.sumofunits() == 1)
	{
		int start, mmax;
		set<int> s;
		for (mmax = start = i = 0;i < 2;++i)
		{
			memset(vis, -1, sizeof(vis));//找到距离最远的点，然后以这个点遍历，取距离最远的点，2次遍历
			dfs(start, 0, mmax);
			for (j = 0;j < n;++j)
				if (vis[j] == mmax)
					s.insert(j);
			start = *s.begin();
		}
		for (set<int>::iterator it = s.begin();it != s.end();it++)
			printf("%d\n", (*it) + 1);
	}
	else
		printf("error: %d components\n", ds.sumofunits());
}