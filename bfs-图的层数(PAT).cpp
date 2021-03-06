#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
using namespace std;

int n,l,tmp,num,q,qnum;
bool visited[1001];
vector<int> graph[1001];
void bfs(int member, int level, int cnt)
{
	for (int i = 1;i <= cnt;++i)
	{
		visited[i] = false;
	}
	queue<int> qq;
	qq.push(member);
	int l = 0, n = 0;
	int leftcnt = 1, curcnt = 0;
	while (!qq.empty()&&l<=level)
	{
		int f = qq.front();
		for (int j = 0;j < graph[f].size();++j)
		{
			qq.push(graph[f][j]);
			curcnt++;
		}
		visited[f] = 1;
		qq.pop();
		leftcnt--;
		if (leftcnt == 0)
		{
			leftcnt = curcnt;
			curcnt = 0;
			l++;
		}
	}
	for (int i = 1;i <= cnt;++i)
	{
		if (visited[i])
			n++;
	}
	cout << n - 1;

}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> l;
	memset(visited, 0, sizeof(visited));
	for (int i = 1;i <= n;++i)
	{
		cin >> num;
		for (int j = 0;j < num;++j)
		{
			cin >> tmp;
			graph[tmp].push_back(i);
		}
	}
	cin >> qnum;
	for (int i = 0;i < qnum;++i)
	{
		cin >> q;
		bfs(q, l, n);
		if (i != qnum - 1)
			cout << endl;
	}
	return 0;
}
