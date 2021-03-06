//树堆，修改了顺序的二叉排序树，树节点x的属性通常包含两个：（1）关键字值key[x]（2）优先级priority[x]，一个独立选取的随机数。
//假设所有的优先级是不同的，所有的关键字也是不同的。树堆的节点排列成让关键字遵循二叉排序树性质且优先级遵循最大堆的顺序性质
//（1）性质一：如果v是u的左孩子，则key[v]<key[u]；右孩子则大于
//（2）性质二：如果v是u的孩子，则priority[v]<priority[u]
//插入关联关键字的节点x1...xn到树堆中，最终的树堆是这些节点以优先级顺序插入一棵正常的二叉排序树中，（？即priority[x]>priority[y]表示x在y之前插入）
//树堆较二叉排序树的优点：
//（1）树堆的形态由随机顺序确定，不再依赖输入顺序
//（2）树堆的操作更高效 O（logn)
//（3）树堆的编程比avl简单，仅需左旋与右旋
//树堆的五种基本操作，其中分离和合并是最为重要的操作
//（1）查找，同BST按照中序遍历顺序查找
//（2）分离，将树堆中的前k个节点划分给树堆a，剩余节点划分给树堆b，分四种情况:
/*
	1.k=0，树堆a空，树堆全部划入树堆b
	2.若树堆的规模不大于k，则树堆b空，树堆全部划入树堆a
	3.树堆的规模大于k的情况下，若树堆的左子树规模不小于k，则树堆的左子树中前k个元素划分给树堆a，剩余元素划分给树堆b的左子树，树堆的右子树划分给树堆b的右子树
	4.树堆的规模大于k的情况下，若树堆的左子树规模小于k，则树堆的左子树划分给树堆a的左子树，树堆的右子树中前（k-1-树堆左子树规模)个节点划分给树堆a的右子树，剩余节点划分给树堆b
	期望复杂度为O(logn)
*/
//（3）合并。将树堆a和树堆b合并成树堆treap。分析a和b的优先级：若a的优先级小于b的优先级，则将b合并至a的右子树，合并结果作为treap的右子树，treap的左子树即为a的左子树，否则将a合并b的左子树，合并结果作为treap的左子树，treap的右子树即为b的右子树
//（4）插入。在树堆treap的pos位置后插入x个元素，形成新树堆treap2
/*
	构建含x个待插元素的树堆c。
	分离：将树堆treap的前pos个节点变成树堆a，剩下的元素变成树堆b。
	合并：将树堆a并入树堆c。
	合并：树堆a和b合并成树堆treap2
	期望复杂度为O（logn）
*/
//（5）删除。删除treap中的ax，形成新树堆treap2.
/*
	分离：将treap划分成a1...ax-1的树堆a和ax+1...的树堆b
	合并：将a和b形成新树堆treap2
	期望复杂度为O（logn）
*/
#include <ctime>
#include <algorithm>
#include <ctime>
int n;
const int maxn = 50005;
struct node;
node *null, *root[maxn];//空指针null,树堆序列root[],存储所有版本
struct node {
	node *c[2];//c[0]左指针，c[1]右指针
	char v;//字符
	int r, sz;//随机优先级r，子树规模sz
	void up() {//调整子树规模
		sz = c[0]->sz + c[1]->sz + 1;
	}
	node(char v = 0) :v(v) {//定义单节点
		sz = 1;r = rand();//规模为1，优先级为随机数
		c[0] = c[1] = null;
	}
};
void init() {
	null = new node();//构建空树堆
	null->sz = 0;
	for (int i = 0;i < maxn;++i)//所有树堆初始化为空
		root[i] = null;
}
int dlt;//先前版本中字符c的个数
char s[203];
inline void copy(node* &a, node* b) {//b复制到a
	if (b == null)
		a = b;
	else
		a = new node(), *a = *b;
}
void merge(node* &o, node* a, node *b) {//a与b合并成o
	if (a == null) copy(o, b);
	else if (b == null) copy(o, a);
	else if (a->r < b->r) {
		copy(o, a);
		merge(o->c[1], a->c[1], b);
		o->up();
	}
	else {
		copy(o, b);
		merge(o->c[0], a, b->c[0]);
		o->up();
	}
}
void split(node* o, node* &a, node* &b, int k) {//将树堆o的全部k个节点变成树堆a，剩下为树堆b
	if (!k) {
		copy(b, o);
		a = null;
	}
	if (o->sz <= k) {
		copy(a, o);
		b = null;
	}
	else if (o->c[0]->sz >= k) {
		copy(b, o);
		split(o->c[0], a, b->c[0], k);
		b->up();
	}
	else {
		copy(a, o);
		split(o->c[1], a->c[1], b, k-o->c[0]->sz - 1);
		a->up();
	}
}
void build(node* &o, int l, int r) {//构建字符s[l]...s[r]的树堆
	if (l > r) return;
	int m = (l + r) >> 1;
	o = new node(s[m]);
	build(o->c[0], l, m - 1);
	build(o->c[1], m + 1, r);
	o->up();
}
void ins(node* &o, node* pre, int pos) {//在树堆pre的pos位置插入字串s，形成新树堆o
	node *a, *b, *c;
	int len = strlen(s);
	split(pre, a, b, pos);//树堆pre的前pos个节点变成树堆a，剩下节点变成树堆b
	build(c, 0, len - 1);//为插入字串c构建树堆c
	merge(a, a, c);//树堆a并入树堆c
	merge(o, a, b);//a和b合并成树堆c
}
void del(node* &o, node* pre, int pos, int len) {
	node *a, *b, *c;
	split(pre, a, b, pos - 1);
	split(b, b, c, len);
	merge(o, a, c);
}
void out(node *o) {//中序遍历，并累计c的个数
	if (o == null) return;
	out(o->c[0]);
	if (o->v == 'c') dlt++;
	printf("%c", o->v);
	out(o->c[1]);
}
void out(node *o, int pos, int len) {//输出树堆o中pos位置开始的len个字符
	node *a, *b, *c;
	split(o, a, b, pos - 1);//将树堆o的前pos-1个节点变成树堆a，剩余节点变成树堆b
	split(b, b, c, len);//树堆b取len个节点
	out(b);//遍历树堆b
	puts("");
}
int main() {
	scanf("%d", &n);//指令数
	init();
	int op, pos, len, v, nowv = 0;//命令类型字op，位置pos，版本号v，当前版本now
	while (n--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%s", &pos, s);
			pos -= dlt;
			ins(root[nowv + 1], root[nowv], pos);
			nowv++;
		}
		else if (op == 2) {
			scanf("%d%d", &pos, &len);
			pos -= dlt;
			len -= dlt;//计算位置和长度的绝对值
			del(root[nowv + 1], root[nowv], pos, len);
			nowv++;
		}
		else
		{
			scanf("%d%d%d", &v, &pos, &len);
			v -= dlt;pos -= dlt;len -= dlt;
			out(root[v], pos, len);
		}
	}
	return 0;
}