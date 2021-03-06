//常用数据结构的特点：
//（1）矩阵结构：随机存取，适用于递推和动态规划
//（2）单链表：顺向搜索线性序列，不便于回扫
//（3）双向链表：便于查找线性序列中元素间的前后联系
//（4）树：一对多，采用递归手段
#include <algorithm>
#include <string>
const int maxn = 2000000;//节点上限
struct node{
	int pre;
	int next;
	int val;
}node[maxn];
int tol;
char str[20];
int l, r, ll, rr, n;//左手的前驱节点，后手的后继节点，左手位置，右手位置，初始时整数
void moveleft_l() {
	if (l == 0) return;
	if (node[l].next == ll) {
		ll = l;
		l = node[l].pre;
	}
	else {
		ll = l;
		l = node[l].next;
	}
}
void moveleft_r() {
	if (rr == 0) return;//右手在最左侧，返回
	if (node[rr].next == r) {//计算右手的后继节点和右手指针
		r = rr;
		rr = node[rr].pre;
	}
	else {
		r = rr;
		rr = node[rr].next;
	}
}
void moveright_l() {
	if (ll == n+1) return;
	if (node[ll].pre == l) {
		l = ll;
		ll = node[ll].next;
	}
	else {
		l =ll;
		ll = node[ll].pre;
	}
}
void moveright_r() {
	if (r == n+1) return;
	if (node[r].next == rr) {
		rr= r;
		r = node[r].next;
	}
	else {
		rr = r;
		r = node[r].pre;
	}
}
void del_l() {//从左手的右边删除一个值
	if (ll == n + 1) return;//左手在右界外返回
	if (l == n + 1) return;
	int t;
	if (node[ll].pre == l)//计算被删节点的位置t
		t = node[ll].next;//设置t指针
	else
		t = node[ll].pre;
	if (node[t].pre == ll)
		node[t].pre = l;
	else
		node[t].next = l;
	if (node[l].next == ll)//设置l的指针
		node[l].next = t;
	else
		node[l].pre = t;
	ll = t;//左手位置指向t
}
void del_r() {
	if (rr==0) return;
	if (r==0) return;
	int t;
	if (node[rr].next == r)
		t = node[rr].pre;
	else
		t = node[rr].next;
	if (node[t].pre == rr)
		node[t].pre = r;
	else
		node[t].next = r;
	if (node[r].pre == rr)
		node[r].pre = t;
	else
		node[r].next = t;
	rr = t;
}
void insert_l(int v) {
	node[tol].val = v;
	node[tol].pre = l;
	node[tol].next = ll;
	if (node[l].next = ll)
		node[l].next = tol;
	else
		node[l].pre = tol;
	if (node[ll].pre == l)
		node[ll].pre = tol;
	else
		node[ll].next = tol;
	ll = tol;
	tol++;
}
void insert_r(int v) {
	node[tol].val = v;//设置node[tol]
	node[tol].pre = rr;
	node[tol].next = r;
	if (node[rr].next = r)//设置node[rr]的指针
		node[rr].next = tol;
	else
		node[rr].pre = tol;
	if (node[r].pre == rr)//设置node[r]的指针
		node[r].pre = tol;
	else
		node[r].next = tol;
	rr = tol;//插入节点为右手节点
	tol++;//节点数+1
}
void reverse() {
	if (node[l].next == ll)//用rr调整l的指针
		node[l].next = rr;
	else
		node[l].pre = rr;
	if (node[ll].pre == l)//用r调整ll的指针
		node[ll].pre = r;
	else
		node[ll].next = r;
	if (node[r].pre == rr)//用ll调整r的指针
		node[r].pre = ll;
	else
		node[r].next = ll;
	if (node[rr].next == r)//用l调整rr的指针
		node[rr].next = l;
	else
		node[rr].pre = l;
	int temp;//ll与rr交换
	temp = ll;
	ll = rr;
	rr = temp;
}
void output() {
	int flag = true;//设首字母标志
	int tt = 0;//上一个被输出的节点序号初始化
	for (int i = node[0].next;i != n + 1;) {//沿指针输出整数序列
		if (flag) flag = 0;//首字母取反
		else printf(" ");//整数与整数间空格
		printf("%d", node[i].val);//输出当前节点
		if (node[i].pre == tt) {//记下当前节点。若上一个被输出的节点是当前节点的前驱，则沿后继指针方向打印，否则沿前驱方向打印
			tt = i;
			i = node[i].next;
		}
		else {
			tt = i;
			i = node[i].pre;
		}
	}
	printf("\n");
}
int main() {
	int T;
	int m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1;i <= n;++i) {
			scanf("%d", &node[i].val);
			node[i].pre = i - 1;
			node[i].next = i + 1;
		}
		node[0].pre = -1;
		node[0].next = 1;
		node[n + 1].pre = n;
		node[n + 1].next = -1;
		tol = n + 2;//节点数
		scanf("%d%d", &ll, &rr);
		l = ll - 1;//前驱
		r = rr + 1;//后继
		scanf("%d", &m);
		while (m--) {
			scanf("%s", &str);//遇空格结束
			if (strcmp(str, "moveleft") == 0) {
				scanf("%s", &str);
				if (str[0] == 'L') moveleft_l();
				else moveleft_r();
			}
			else if (strcmp(str, "moveright") == 0) {
				scanf("%s", &str);
				if (str[0] == 'L') moveright_l();
				else moveright_r();
			}
			else if (strcmp(str, "delete") == 0) {
				scanf("%s", &str);
				if (str[0] == 'L') del_l();
				else del_r();
			}
			else if (strcmp(str, "insert") == 0) {
				scanf("%s", &str);
				if (str[0] == 'L') {
					int v;
					scanf("%d", &v);
					insert_l(v);
				}
				else {
					int v;
					scanf("%d", &v);
					insert_r(v);
				}
			}
			else reverse();
		}
		output();
	}
}
