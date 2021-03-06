#define INF 0x3fffffff
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		left = 0;
		right = 0;
	}
};
void insert(node* &root, int data)
{
	if (root == 0)
	{
		root = new node();
		root->left = 0;
		root->right = 0;
		root->data = data;
		return;
	}
	if (data < root->data)
		insert(root->left, data);
	else
		insert(root->right, data);
}
void preorder(vector<int> &pre, node* &root)
{
	if (root == 0)
		return;
	pre.push_back(root->data);
	preorder(pre, root->left);
	preorder(pre, root->right);
}
void postorder(vector<int> &post, node* &root)
{
	if (root == 0)
		return;
	postorder(post, root->left);
	postorder(post, root->right);
	post.push_back(root->data);
}
void premirrororder(vector<int> &pre, node* &root)
{
	if (root == 0)
		return;
	pre.push_back(root->data);
	premirrororder(pre,root->right);
	premirrororder(pre, root->left);
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int num;
	cin >> num;
	vector<int> shuru, pre, post,mirrorpre;
	node* root = 0;
	for (int i = 0;i < num;++i)
	{
		int n;
		cin >> n;
		shuru.push_back(n);
		insert(root, n);
	}
	preorder(pre, root);
	if (shuru == pre)
	{
		printf("YES\n");
		postorder(post, root);
		for (int i = 0;i < post.size();++i)
			cout << (i == 0 ? "" : " ") << post[i];
	}
	else
	{
		premirrororder(mirrorpre, root);
		if (shuru == mirrorpre)
		{
			printf("YES\n");
			postorder(post, root);
			for (int i = 0;i < post.size();++i)
				cout << (i == 0 ? "" : " ") << post[i];
		}
		else
		{
			printf("NO");
		}
	}
	return 0;
}