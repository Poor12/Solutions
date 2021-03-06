#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
using namespace std;
#define maxn 1000
#define dmax 10000
typedef long long ll;
int n;
int ismin=1, ismax=1;
int heap[maxn + 1];
vector<int> v;
void dfs(int index)
{
	if (index * 2 > n&&index * 2 + 1 > n)//叶子节点
	{
		if (index <= n)//对只有左叶子节点没有右叶子节点的点特判
		{
			for (int i = 0;i < v.size();++i)
				printf("%d%s", v[i], i != v.size() - 1 ? " " : "\n");
		}
	}
	else
	{
		v.push_back(heap[index * 2 + 1]);
		dfs(index * 2 + 1);
		v.pop_back();
		v.push_back(heap[index * 2]);
		dfs(index * 2);
		v.pop_back();
	}
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1;i <= n;++i)
	{
		scanf("%d", &heap[i]);
	}
	v.push_back(heap[1]);
	dfs(1);
	for (int i = 2;i <= n;++i)
	{
		if (heap[i / 2] > heap[i])
			ismin = 0;
		if (heap[i / 2] < heap[i])
			ismax = 0;
	}
	if (ismin == 1)
		printf("Min Heap");
	else
		printf("%s", ismax == 1 ? "Max Heap" : "Not Heap");
}



