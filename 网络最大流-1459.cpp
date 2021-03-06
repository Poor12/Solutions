#include <math.h>
#include <memory>
int n, np, nc, m, s, t;//节点数为n，源点为s，汇点为t，节点数为n，发电站数目为np，用电场所数目为nc，电力传输线数目为m
int fa[104], q[104], f[104][104], c[104][104];//fa存储增广路，其中fa[j]为增广路上节点j的前驱节点，正数表示该弧为前向弧，负数表示该弧为后向弧，q为队列，f、c记录网络中的流量和容量，存储方式为邻接矩阵
void proc() {//求最大流
	int qs, qt, d, d0, i, j, ans = 0;
	fa[t] = 1;//汇点的前驱节点初始化
	while (fa[t] != 0) {//若增广路存在
		qs = 0;qt = 1;//队列的首尾指针初始化
		q[qt] = s;//源点进入队尾
		memset(fa, 0, sizeof(fa));//增广路初始化
		fa[s] = s;//源点的前驱指向自己
		while (qs<qt&&fa[t]==0)//队列非空且没有找到至汇点的增广路
		{
			i = q[++qs];//取出队首
			for(j=1;j<=t;++j)//枚举未在增广路的节点j
				if(fa[j]==0)
					if (f[i][j] < c[i][j])//若（i，j）的流量可增加，则（i，j）作为前向弧加入增广路，j进入队列；若（i，j）可退流，则（i，j）作为后向弧加入增广路，j进入队列
					{
						fa[j] = i;
						q[++qt] = j;
					}
					else
					{
						if (f[j][i] > 0)
						{
							fa[j] = -i;
							q[++qt] = j;
						}
					}
		}
		if (fa[t] != 0)//如果找到一条从源点到汇点的增广路就改进当前流
		{
			d0 = 10000000;
			i = t;//从汇点出发计算最大可改进量
			while (i != s) {//未倒推至源点
				if (fa[i] > 0)//i节点为尾的弧是前向弧
				{
					if ((d = c[fa[i]][i] - f[fa[i]][i]) < d0)
						d0 = d;
				}
				else//后向弧
				{
					if (f[i][-fa[i]] < d0)
						d0 = f[i][-fa[i]];
				}
				i = abs(fa[i]);//继续沿前驱指针倒推计算改进量
			}
			ans += d0;//总流量增加
			i = t;//从汇点出发倒推增广路上流量
			while (i!=s)
			{
				if (fa[i] > 0)//前向弧
					f[fa[i]][i] += d0;
				else//后向弧
				{
					f[i][-fa[i]] -= d0;
				}
				i = abs(fa[i]);
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
	int i, u, v, cc;
	while (scanf("%d%d%d%d",&n,&np,&nc,&m)==4)//输入节点数、发电厂数目、用电场数目和电力传输线数目
	{
		s = n + 2;t = n + 1;//设置源点汇点
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		for (i = 1;i <= m;++i) {//对于原图中边(u,v)连一条容量为cc的弧
			while (getchar() != '(');
			scanf("%d,%d)%d", &u, &v, &cc);
			c[u + 1][v + 1] = cc;
		}
		for (i = 1;i <= np;++i) {//源点向每一个发电站连一条容量为cc的弧
			while (getchar() != '(');
			scanf("%d)%d", &u, &cc);
			c[s][u + 1] = cc;
		}
		for (i = 1;i <= nc;++i) {//每个用电厂向汇点连一条容量为cc的弧
			while (getchar() != '(');
			scanf("%d)%d", &u, &cc);
			c[u+1][t] = cc;
		}
		proc();//求最大流
	}
}