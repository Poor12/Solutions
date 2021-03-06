#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
using namespace std;
string inop;
struct node
{
	int v;
	node *left, *right, *par;
	bool pop;
	node(int value)
	{
		v = value;
		left = 0;
		right = 0;
		par = 0;
		pop = false;
	}
};
vector<int> postVec;
void postTravel(node *root) {
	if (root == 0) {
		return;
	}
	postTravel(root->left);
	postTravel(root->right);
	postVec.push_back(root->v);
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n,data;
	cin >> n;
	node *root=0, *cur=0;
	for (int i = 0;i < 2 * n;++i)
	{
		cin >> inop;
		if (inop.at(inop.length() - 1) == 'h')
		{
			cin >> data;
			node *n = new node(data);
			if (!cur)
			{
				cur = n;
				root = n;
			}
			else
			{
				if (!cur->left)
				{
					cur->left = n;
				}
				else
				{
					cur->right=n;
				}
				n->par = cur;
				cur = n;
			}
		}
		else
		{
			while (cur->pop)
				cur = cur->par;
			cur->pop = true;
		}
	}
	postTravel(root);
	for (int i = 0;i < postVec.size();i++) {
		cout << (i == 0 ? "" : " ") << postVec[i];
	}
	return 0;
}