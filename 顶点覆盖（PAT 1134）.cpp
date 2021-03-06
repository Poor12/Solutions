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
#define rh -1
#define lh 1
#define eh 0
struct node
{
	int data;
	node *left, *right;
};
struct node *root;
bool flag;
void insert(node* &t, int data)
{
	if (t == 0)
	{
		t = (node*)malloc(sizeof(node));
		t->data = data;
		t->left = t->right = 0;
		return;
	}
	if (abs(data) < abs(t->data))
		insert(t->left, data);
	else
		insert(t->right, data);
}

void juge1(node *T)
{
	if (flag == false)
		return;

	if (T->left != NULL)
	{
		if (T->data < 0 && T->left->data < 0)
		{
			flag = false;
			return;
		}
		else juge1(T->left);
	}

	if (T->right != NULL)
	{
		if (T->data < 0 && T->right->data < 0)
		{
			flag = false;
			return;
		}
		else juge1(T->right);
	}
}
//各点到叶节点的黑色节点数相同
int juge2(node *t)
{
	int l1, l2;
	if (flag == 0)
		return -1;
	if (t == 0)
		return 1;
	l1 = juge2(t->left);
	l2 = juge2(t->right);
	if (l1 != l2)
	{
		flag = 0;
		return -1;
	}
	else
	{
		l1 = l1 + (t->data > 0);
	}
	return l1;
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int k, n, data;
	scanf("%d", &k);
	while (k--)
	{
		flag = 1;
		root = NULL;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &data);
			insert(root, data);
		}
		if (root->data < 0)
			printf("No\n");
		else
		{
			juge1(root);
			if (flag == false)
				cout << "No" << endl;
			else
			{
				juge2(root);
				if (flag == 0)
				{
					cout << "No" << endl;
				}
				else
					cout << "Yes" << endl;
			}
		}
	}
	return 0;
}
