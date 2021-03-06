//引入树状数组c,以访问时间为顺序，通过在后序遍历的过程中给节点加盖时间戳的办法，转化树为线性序列
//设d[u]--节点u的初访时间，f[u]--节点u的结束时间，即访问了以u为根的子树后回溯至u的时间
//显然区间[d[u],f[u]]反映了以u为根的子树结构
/*
	给出一棵二叉树：
				1
		6				2
	8		7					3
							5		4
后序遍历二叉树，d[u]和f[u]如下表中所示：
节点访问顺序	1	6	  8	    7	  6	    2	 3	   5	 4	   3	 2	   1
节点区间	  [1,] [1,] [1,1] [2,2] [1,3] [4,]  [4,] [4,4] [5,5] [4,6] [4,7] [1,8]
说明		 初访1 初6   终8   终7   终6   初2   初3  终5   终4   终3   终2   终1

按照后序遍历的节点顺序，其f[]正好递增(f[8]=1,f[7]=2,f[6]=3,f[5]=4...f[1]=8)
若[d[v],f[v]]是[d[u],f[u]]的子区间，则以u为根的子树包含了以v为根的子树。因此可用f[u]标志c[]的指针。计算[d[u],f[u]]的方法十分简答：
void dfs(int u){
	d[u]=time;//初次访问的时间设为区间左指针
	依次对u引出的每条出边的另一端点v进行dfs(v);
	f[u]=time++;//遍历u的所有后代后的时间为区间右指针，访问时间+1;
}

*/
#define max 100002//定义节点上限
struct node1 {//边表为edge，其中第i条边相连的节点为edge[i].tail，连接的下条边的序号是edge[i].next
	int next, tail;
}edge[max];
struct node2 {//苹果树为apple,以节点i为根的子树在后序序列的区间为[apple[i].l,apple[i].r]
	int r, l;
}apple[max];
int s[max], cnt, c[max], a[max];//后序遍历中第i个节点的权值为a[i]，后序遍历序号为cnt（最大即为节点数），树状数组为c，节点i相连的第i条边的序号为s[i]
void dfs(int u) {//从u出发，计算每个节点为根的子树区间[apple[].l,apple[].r]
	int i;
	apple[u].l = cnt;
	for (i = s[u];i != -1;i = edge[i].next)
		dfs(edge[i].tail);
	apple[u].r = cnt++;
}
inline int lowbit(int x) {
	return x & (-x);
}
void change(int x) {
	int i;
	if (a[x])//如果a序列的第x个元素权值非0，则树状元素相关元素值+1；否则-1
		for (i = x;i < cnt;i += lowbit(i))
			c[i]++;
	else
		for (i = x;i < cnt;i += lowbit(i))
			c[i]--;
}
int sum(int x) {
	int i, res = 0;
	for (i = x;i > 0;i -= lowbit(i))
		res += c[i];
	return res;
}
int main() {
	int i, n, m, t1, t2, t;
	char str[3];
	scanf("%d", &n);//读树的节点树
	memset(s, -1, sizeof(s[0])*(n + 1));
	memset(c, 0, sizeof(c[0])*(n + 1));
	memset(apple, 0, sizeof(apple[0])*(n + 1));
	for (i = 0;i < n - 1;++i) {//n个点，n-1条边
		scanf("%d%d", &t1, &t2);//读一条边
		edge[i].tail = t2;//第i条边连接t2，其后继指针指向t1连接的上一条边
		edge[i].next = s[t1];
		s[t1] = i;//设t1连接的边序号i
	}
	cnt = 1;
	dfs(1);//从节点1出发进行dfs，计算每个节点的后序值，节点权值为1
	scanf("%d", &m);
	for (i = 1;i <= n;++i) {//构建树状数组
		a[i] = 1;
		change(i);
	}
	while (m--) {
		scanf("%s%d", &str, &t);
		if (str[0] == 'Q')
			printf("%d\n", sum(apple[t].r) - sum(apple[t].l - 1));
		else {
			a[apple[t].r] = (a[apple[t].r] + 1) % 2;
			change(apple[t].r);
		}
	}
	return 0;
}

