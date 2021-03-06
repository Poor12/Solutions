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
const int maxn = 1000;
struct node
{
	int left, right;
}node[maxn];
bool table[maxn] = { 0 };
int test[maxn];
int k = 0;
void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		test[k++] = top;
		if (k > 100)
			return;
		if (top != -1)
		{
			q.push(node[top].left);
			q.push(node[top].right);
		}
	}
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int n;
	cin >> n;
	fill(test, test + maxn, -1);
	string a, b;
	for (int i = 0;i < n;++i)
	{
		cin >> a >> b;
		if (a.size() == 1 && a[0] != '-')
		{
			node[i].left = a[0] - '0';
			table[a[0] - '0'] = 1;
		}
		else if (a.size() == 1 && a[0] == '-')
			node[i].left = -1;
		else if (a.size() == 2)
		{
			node[i].left = (a[0] - '0') * 10 + a[1] - '0';
			table[node[i].left] = 1;
		}
		if (b.size() == 1 && b[0] != '-')
		{
			node[i].right = b[0] - '0';
			table[b[0] - '0'] = 1;
		}
		else if (b.size() == 1 && b[0] == '-')
			node[i].right = -1;
		else if (b.size() == 2)
		{
			node[i].right = (b[0] - '0') * 10 + b[1] - '0';
			table[node[i].right] = 1;
		}
	}
	int root;
	for (int i = 0;i < n;++i)
	{
		if (table[i] == 0)
		{
			root = i;
			break;
		}
	}
	bfs(root);
	for (int i = 0;i < n;++i)
	{
		if (test[i] == -1)
		{
			cout << "NO " << root;
			return 0;
		}
	}
	cout << "YES " << test[n - 1];
	return 0;
}