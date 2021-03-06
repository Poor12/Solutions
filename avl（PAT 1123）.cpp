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

const int maxn = 30;
int n;
struct node
{
	int key;
	node* left;
	node* right;
	int height;
	node(int k) :key(k), left(NULL), right(NULL), height(0) {}
	node() {}
};
typedef node* AVLtree;
int height(node* n)
{
	return n ? n->height : -1;
}
node* ll(node* k2)
{
	node* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k2->left), height(k2)) + 1;
	return k1;
}
node* rr(node* k2)
{
	node* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->right), height(k2)) + 1;
	return k1;
}
node* lr(node* k3)
{
	k3->left = rr(k3->left);
	return ll(k3);
}
node* rl(node* k3)
{
	k3->right = ll(k3->right);
	return rr(k3);
}
node* insert(AVLtree root, int key)
{
	if (!root)
		root = new node(key);
	else if (root->key < key)
	{
		root->right = insert(root->right, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (key > root->right->key)
				root = rr(root);
			else
				root = rl(root);
		}
	}
	else if(root->key>key)
	{
		root->left = insert(root->left, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (key < root->left->key)
				root = ll(root);
			else
				root = lr(root);
		}
	}
	root->height = 1 + max(height(root->left), height(root->right));
	return root;
}
void travel(AVLtree root)
{
	queue<node*> q;
	vector<int> levelseq;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		levelseq.push_back(root->key);
		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);
	}
	for (int i = 0;i < levelseq.size();++i)
	{
		if (i) cout << " ";
		cout << levelseq[i];
	}
}
bool isCompleteAvlTree(AVLtree root)
{
	queue<node*> q;
	q.push(root);
	bool haveNULL = false;
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		if (haveNULL)
		{
			if (root->left || root->right)
				return 0;
		}
		if (root->left&&root->right)
		{
			q.push(root->left);
			q.push(root->right);
		}
		else if (root->left && !root->right)
		{
			q.push(root->left);
			haveNULL = 1;
		}
		else if (!root->left&&root->right)
			return 0;
		else
			haveNULL = 1;
	}
	return 1;
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	cin >> n;
	int key;
	AVLtree root = 0;
	for (int i = 0;i < n;++i)
	{
		cin >> key;
		root = insert(root,key);
	}
	travel(root);
	printf("\n%s", isCompleteAvlTree(root) ? "YES" : "NO");
	return 0;
}