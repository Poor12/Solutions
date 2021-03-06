#define maxn 500//节点上限
#define maxq 10000//队列长度上限
#define mx 1000000//∞
long c[maxn][maxn] = { 0 }, g[maxn][maxn] = { 0 }, d[maxn] = { 0 };
//初始时赋权有向图的邻接矩阵g，最短路长矩阵d，网络流图的流量矩阵c均为0
int q[maxq] = { 0 }, pre[maxn] = { 0 };//初始时队列q、增广路的前驱指针为空
bool vis[maxn] = { 0 };//初始时所有节点未在增广路
bool b = 1;//设增广路存在
long n, s = 1, t;//集装箱和垃圾种类数为n，源点s=1，汇点为t
long p = 0;//分类所有垃圾所需的最小代价初始化为0
void augment() {//调整增广路上各边的流量
	int i = t;//从汇点出发计算增广路上的最小流量a
	long a = mx;//最小流量a初始化为无穷
	while (i > s) {
		if (c[pre[i]][i] < a)
			a = c[pre[i]][i];
		i = pre[i];//沿前驱指针倒推
	}
	i = t;//从汇点出发调整增广路上的各边流量
	while (i>s)
	{
		c[pre[i]][i] -= a;c[i][pre[i]] += a;
		i = pre[i];
	}
}
void spfa() {//使用spfa计算源点至汇点的最短路
	memset(q, 0, sizeof(q));//初始时队列空
	memset(vis, 0, sizeof(vis));//初始时所有节点未访问
	memset(pre, 0, sizeof(pre));//初始时所有节点未在增广路
	int l = 1, r = 1;//队列首尾指针
	for (int i = 1;i <= t;++i)//初始时所有节点的最短路长为一个较大值
		d[i] = mx;
	d[s] = 0;q[l] = s;vis[s] = 1;//源点路长为0，入队
	while (l<=r)
	{
		if (l == 1 && r == maxq) break;//循环队列满
		long x = q[l];//取队首元素x
		for(int i=1;i<=t;++i)//枚举所有出边
			if (d[x] + g[x][i] < d[i] && c[x][i]>0)//若出边存在且可松弛
			{
				d[i] = d[x] + g[x][i];
				pre[i] = x;//（x，j）记入增广路
				if (!vis[i])//若i未在队列
				{
					vis[i] = 1;
					++r;
					if (r > maxq)
						r = 1;
					q[r] = i;
				}
			}
		vis[x] = 0;//x出队
		++l;
		if (l > maxq)
			l = 1;
	}
	if (d[t] != mx)//若可达汇点t，则累计总输送费用，调整增广路上各边的流量，设增广路存在标志返回
	{
		p += d[t];
		augment();
		b = 1;
		return;
	}
	b = 0;//设增广路不存在标志
}
int main() {
	cin >> n;
	t = 2 * n + 2;//设置汇点
	for (int i = 1;i <= n;++i) {//枚举x中的集装箱
		int s = 0;
		for (int j = 1;j <= n;++j)//枚举y中的每类垃圾
		{
			c[1 + i][1 + n + j] = 1;
			cin >> g[1 + i][1 + n + j];//输入集装箱i中j类垃圾的数量
			s += g[1 + i][1 + n + j];//累计集装箱i中的垃圾总数
		}
		for (int j = 1;j <= n;++j)//枚举y中的每类垃圾：x中的集装箱i向y中的垃圾j连一条有向边，长度为集装箱i除去垃圾j后的剩余量；y中的垃圾j向x中的集装箱i连一条有向边，长度为集装箱i除去垃圾j后的剩余量取负
		{
			g[1 + i][1 + n + j] = s - g[1 + i][1 + n + j];
			g[1 + n + j][1 + i] = -g[1 + i][1 + n + j];
		}
	}
	for (int i = 1;i <= n;++i)//源点向x中的每个集装箱连一条容量为1的有向边，y中的每类垃圾向汇点t连一条容量为1的有向边
	{
		c[1][1 + i] = 1;
		c[1 + n + i][t] = 1;
	}
	b = 1;//设增广路存在标志
	while (b) spfa();//反复使用spfa计算最小费用最大流，直至增广路不存在
	cout << p << "\n";
	return 0;
}