//数组转换为二叉树
#include <vector>
struct node {
	int data;
	node* left;
	node* right;
	node(int d) :data(d) {}
};
node* buildtree(vector<int>& num, int start, int end)
{
	if (start > end) return NULL;
	if (start == end) return new node(num[start]);
	int mid = (start + end) / 2;
	node* n = new node(num[mid]);
	n->left = buildtree(num, start, mid - 1);
	n->right = buildtree(num, mid + 1, end);
	return n;
}

//排序链表转换为二叉树
struct listnode {
	int data;
	listnode* next;
};
node* buildtree2(listnode*& list, int start, int end)//中序遍历树，在遍历过程中创建节点
{
	if (start > end) return NULL;
	int mid = (start + end) / 2;
	node* left = buildtree2(list, start, mid - 1);
	node* parent = new node(list->data);
	parent->left = left;
	list = list->next;
	parent->right = buildtree2(list, mid + 1, end);
	return parent;
}
node* sortedlisttobst(listnode* head)
{
	int len = 0;
	listnode* p = head;
	while (p)
	{
		len++;
		p = p->next;
	}
	return buildtree2(head, 0, len - 1);
}
