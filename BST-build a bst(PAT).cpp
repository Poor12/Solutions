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

int n;
struct node {
	int data;
	int left;
	int right;
};
vector<int> keys;
vector<node> trees;
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> n;
	keys.resize(n);
	trees.resize(n);
	vector<int> v;
	queue<node> q;
	vector<node> order;
	for (int i = 0;i < n;++i)
		cin >> trees[i].left >> trees[i].right;
	for (int i = 0;i < n;++i)
		cin >> keys[i];
	sort(keys.begin(), keys.end());
	int t = 0, i = 0;
	//中序遍历等于从小到大的顺序
	while (t!=-1||!v.empty())
	{
		while (t != -1)
		{
			v.push_back(t);
			t = trees[t].left;
		}
		if (!v.empty())
		{
			int j = v.back();
			v.pop_back();
			trees[j].data = keys[i];
			i++;
			t = trees[t].right;
		}
	}
	t = 0;
	q.push(trees[t]);
	bool isfirst = 1;
	while (!q.empty())
	{
		node a = q.front();
		q.pop();
		cout << (isfirst == 1 ? "" : " ") << a.data;
		isfirst = 0;
		if (a.left != -1)
			q.push(trees[a.left]);
		if (a.right != -1)
			q.push(trees[a.right]);
	}
}

