#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
typedef struct TreeNode *BinTree;
BinTree root = 0, cur = 0;
vector<int> postorder;
vector<int> inorder;
queue<BinTree> treenode;
bool flag;
struct TreeNode
{
	int data;
	BinTree left;
	BinTree right;
	TreeNode(int val) :data(val) {
		left = 0;
		right = 0;
	}
};
void buildTree(BinTree &root, vector<int> postorder, vector<int> inorder, int l1, int r1, int l2, int r2)
{
	root = new TreeNode(postorder[r1]);
	int i;
	for (i = l2;i <= r2;++i)
	{
		if (inorder[i] == postorder[r1])
			break;
	}
	int L = i - l2;
	if (i == l2)
		root->left = 0;
	else
		buildTree(root->left, postorder, inorder, l1, l1 + L - 1, l2, i - 1);
	if (i == r2)
		root->right = 0;
	else
		buildTree(root->right, postorder, inorder, l1 + L, r1 - 1, i + 1, r2);

}

void inOrder(BinTree root) {
	if (!root) {
		return;
	}
	else
	{
		treenode.push(root);
		while (!treenode.empty())
		{
			BinTree d = treenode.front();
			cout << (d == root ? "" : " ") << d->data;
			treenode.pop();
			if (d->left) treenode.push(d->left);
			if (d->right) treenode.push(d->right);
		}
	}
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int num;
	cin >> num;
	postorder.resize(num);
	inorder.resize(num);
	for (int i = 0;i < num;++i) {
		cin >> postorder[i];
	}
	for (int i = 0;i < num;++i) {
		cin >> inorder[i];
	}
	buildTree(root,postorder,inorder,0, num - 1, 0, num - 1);
	inOrder(root);
}
