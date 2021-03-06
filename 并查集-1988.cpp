const int maxn = 100000 + 5;//元素数上限
int set[maxn], cnt[maxn], top[maxn];//cnt[k]表示区间k到set[k]的元素个数，top[k]元素k所在栈的栈顶元素序号
int set_find(int p) {//寻找栈顶元素
	if (set[p] < 0)
		return p;
	if (set[set[p]] >= 0) {//如果set[p]下方还有元素,调整元素p所在栈最下面的元素
		int fa = set[p];
		set[p] = set_find(fa);//路径优化
		cnt[p] += cnt[fa];//累加从fa到set[p]之间的元素个数
	}
	return set[p];

}
void set_join(int x, int y) {//x放在y的栈上
	x = set_find(x);
	y = set_find(y);
	set[x] = y;
	set_find(top[y]);//刷新y所在栈原先的栈顶元素到y之间的元素个数
	cnt[x] = cnt[top[y]] + 1;
	top[y] = top[x];//更新y所在栈的栈顶元素为x原先所在栈的栈顶元素

}
int main() {
	int p;
	scanf("%d", &p);
	memset(set, -1, sizeof(set));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0;i < maxn;++i) {
		top[i] = i;//初始时为元素本身
	}
	while (p--)
	{
		char s[5];
		scanf("%s", s);
		if (s[0] == 'M') {
			int x, y;
			scanf("%d%d", &x, &y);
			set_join(x, y);
		}
		else
		{
			int x;
			scanf("%d", &x);
			set_find(x);
			printf("%d\n", cnt[x]);
		}
	}
}