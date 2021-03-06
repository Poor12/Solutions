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
const int maxn = 35;
int n;
int in[maxn];
int post[maxn];
struct node
{
	int data;
	node *l, *r;
};
node* create(int l1, int r1, int l2, int r2)
{
	if (l1 > r1 || l2 > r2)
		return NULL;
	node *root = new node;
	root->data = post[r2];
	int i = l1;
	for (;i <= r1;++i)
		if (in[i] == post[r2])
			break;
	root->l = create(l1, i - 1, l2, l2 + i - 1 - l1);
	root->r = create(i + 1, r1, l2 + i - l1, r2 - 1);
	return root;
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	cin >> n;
	for (int i = 0;i < n;++i)
		cin >> in[i];
	for (int i = 0;i < n;++i)
		cin >> post[i];
	node *root = create(0, n - 1, 0, n - 1);
	queue<node*> q;
	q.push(root);
	vector<int> vec;//存放一层的数据
	node *last = root;
	node *newnode;
	int flag = 1;
	int m = 0;
	while (!q.empty())
	{
		node *f = q.front();
		vec.push_back(f->data);
		q.pop();
		if (f->l) {
			q.push(f->l);
			newnode = f->l;
		}
		if (f->r)
		{
			q.push(f->r);
			newnode = f->r;
		}
		if (last == f)
		{
			last = newnode;
			if (flag == 1)
			{
				for (int i = 0;i < vec.size();++i)
				{
					cout << vec[vec.size() - 1 - i];
					m++;
					if (m != n)
						cout << " ";
				}
				vec.clear();
				flag = 0;
			}
			else
			{
				for (int i = 0;i < vec.size();++i)
				{
					cout << vec[i];
					m++;
					if (m != n)
						cout << " ";
				}
				vec.clear();
				flag = 1;
			}
		}
	}
	return 0;
}
