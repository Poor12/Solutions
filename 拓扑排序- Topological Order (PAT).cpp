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
using namespace std;
int graph[1001][1001];
int indegree[1001];
bool Test(int *totest, int n, int *degree2)
{
	for (int i = 0;i < n;++i)
	{
		if (degree2[totest[i]] != 0)
			return false;
		else
		{
			for (int j = 0;j < n;++j)
				if (graph[totest[i]][j] == 1)
					degree2[j]--;
		}
	}
	return 1;
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;++i)
		indegree[i] = 0;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		a--;b--;
		graph[a][b] = 1;
		indegree[b]++;
	}
	int k, count = 0;
	cin >> k;
	int *indegree2=new int[n];
	vector<int> store;
	while (k--)
	{
		int *totest = new int[n];
		for (int i = 0;i < n;++i)
		{
			cin >> totest[i];
			totest[i]--;
			indegree2[i] = indegree[i];
		}
		if (!Test(totest, n, indegree2))
			store.push_back(count);
		count++;
	}
	vector<int>::iterator it, it1;
	it = store.begin();
	it1 = store.end();
	it1--;
	while (it != it1)
	{
		cout << *it << " ";
		it++;
	}
	cout << *it;
	return 0;
}