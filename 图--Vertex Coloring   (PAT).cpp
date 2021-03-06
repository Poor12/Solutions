#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
using namespace std;
#define maxn 10001
int n, m,k;
vector<int> adj[maxn];
vector<int> color;
set<int> cc;
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0;i < m;++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	cin >> k;
	for (int i = 0;i < k;++i)
	{
		cc.clear();
		color.clear();
		int flag = 1;
		for (int j = 0;j < n;++j)
		{
			int col;
			cin >> col;
			color.push_back(col);
			cc.insert(color[j]);
		}
		for (int x = 0;x < n;++x)
		{
			for (int y = 0;y < adj[x].size();++y)
			{
				if (color[adj[x][y]] == color[x])
				{
					flag = 0;break;
				}
			}
			if (flag == 0)
				break;
		}
		if (flag == 0)
			cout << "No" << endl;
		else
			cout << cc.size() << "-coloring" << endl;
	}
}