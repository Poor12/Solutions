#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct node
{
	int weight;
	vector<int> children;
};
int n, m, s, sum;
vector<node> nodes;
vector<int> path;
multiset<vector<int>> allPath;
void dfs(int root)
{
	sum += nodes[root].weight;
	path.push_back(nodes[root].weight);
	int numofchildren = nodes[root].children.size();
	if (numofchildren)
	{
		for (int i = 0;i < numofchildren;++i)
			dfs(nodes[root].children[i]);
	}
	else
	{
		if (sum == s)
		{
			allPath.insert(path);
		}
	}
	sum -= nodes[root].weight;
	path.pop_back();
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> m >> s;
	nodes.resize(n);
	for (int i = 0;i < n;++i)
	{
		cin >> nodes[i].weight;
	}
	int id, k;
	for (int i = 0;i < m;++i)
	{
		cin >> id >> k;
		nodes[id].children.resize(k);
		for (int j = 0;j < k;++j)
			cin >> nodes[id].children[j];
	}
	dfs(0);
	bool first;
	multiset<vector<int>>::reverse_iterator iter = allPath.rbegin();
	for (;iter != allPath.rend();iter++)
	{
		path = *iter;
		first = 1;
		for (int i = 0;i < path.size();++i)
		{
			if (first)
			{
				cout << path[i];
				first = 0;
			}
			else
				cout << " " << path[i];
		}
		cout << endl;
	}
	return 0;

}