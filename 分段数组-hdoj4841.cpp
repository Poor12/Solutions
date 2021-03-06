//选择数据逻辑结构的基本原则
//分析数据元素之间关系的不同特性，通常有以下四种基本逻辑结构：集合、线性结构、树形结构、图状结构
//集合：数据元素之间只有同属于一个集合的关系
//线性：一对一
//树形：一对多
//图状：多对多

//圆桌问题初版 hdoj4841
/*
#include <iostream>
using namespace std;
struct node
{
	int n;
	node* next;
	node() :next(NULL) {}
	node(int x) {
		n = x;
		next = NULL;
	}
};
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	node *l,*c,*pre;
	bool *b = new bool[2 * n];
	memset(b, 0, sizeof(b));
	l = new node();
	c = l;
	for (int i = 0;i < 2*n;++i) {
		node* a = new node(i);
		c->next = a;
		c = a;
	}
	c->next = l->next;
	pre = l;
	c = l->next;
	int ans = 2 * n;
	while (ans!=n) {
		for (int i = 0;i < m - 1;i++) {
			pre = pre->next;
			c = c->next;
		}
		node *d = c;
		b[(d->n)] = 1;
		c = c->next;
		pre->next = c;
		delete d;
		ans--;
	}
	for (int i = 0;i < 2 * n;++i) {
		if (b[i] == 0)
			cout << "G";
		else
			cout << "B";
	}
	return 0;
}
*/

//改进版 直接去点法 数组善于找点，链表善于去点
#include <string>
const int nn = 65535;//人数上限
int n, m, j, l, g;//好人坏人人数n,步长m,段数g，上次出列元素的段内位移p
int k, p;//当前出列元素位于上次出列的元素右方第k个位置，段内位移为k+p
int t[nn], amount[nn];//t为当前排列，分段式数组为amount，其中第i段元素个数为amount
bool ans[nn];//排列方案，其中ans[i]为第i个元素的出列标志
void solve() {
	memset(amount, 0, sizeof(amount));
	g = 1;//从第一段开始构建分段式数组
	for (int i = 1;i <= n + n;++i) {
		t[i] = i;//设置第i个位置的序号
		amount[g]++;//累计第g段的数量
		if (amount[g] == m) g++;//段满
	}
	j = 1;p = 0;//起始段和段内位移初始化
	memset(ans, 0, sizeof(ans));//初始化全好人
	for (int i = 1;i <= n;++i) {//依次出列n个元素,计算第i个出列元素所在段号j和段内偏移k+p
		k = m;
		while (k > amount[j] - p) {//超过当前段
			k = k - amount[j] + p;
			j = (j%g) + 1;//下一段
			p = 0;
		}
		ans[t[(j - 1)*m + k + p]] = true;
		for (l = (j - 1)*m + k + p;l <= (j - 1)*m + amount[j] - 1;l++) {
			t[l] = t[l + 1];//第j段k+p位置右方的所有元素依次左移一位
		}
		p = p + k - 1;//记下当前段内位移
		amount[j]--;//第j段元素减一
	}
	for (int i = 1;i <= n + n;++i) {
		if (ans[i]) printf("B");
		else printf("G");
		if (i % 50 == 0 && i != n * 2 && i > 0) printf("\n");
	}
	printf("\n");
	printf("\n");
}
int main() {
	while (2 == scanf("%d%d", &n, &m)) {
		solve();
	}
}