#include <queue>
#include <vector>
#define inf 99999999
#define n 1100
typedef struct nnn {//定义优先队列的元素类型
	int f, g, s;//对应节点s，起点至该节点的距离g，经过s的路长f
	friend bool operator<(nnn a, nnn b)//路长越小，优先级越高
	{
		return a.f > b.f;
	}
}path;
typedef struct nn {//邻接表节点
	int v, w;//邻接点v，边长w
}node;
vector<node> map[n], tmap[n];//邻接表map，辅助邻接表tmap，均为存储节点i的所有相邻点信息的容器
int h[n];//反向距离表 end至节点i的距离为h[i]
//计算反向图中终点可达节点的最短路用于估价函数
void findh(int s) {//使用spfa计算s可达的每个节点的距离值h[]
	queue <int> q;
	int inq[n] = { 0 };//设所有元素非队列元素
	q.push(s);inq[s] = 1;h[s] = 0;//s进入队列，距离为0
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		inq[s] = 0;
		int m = tmap[s].size();//计算s的出度，（即tmap[s]的容器的大小）
		for (int i = 0;i < m;++i)//枚举每条出边
		{
			int j = tmap[s][i].v;//计算s的第i条出边的端点j
			if (h[j] > tmap[s][i].w + h[s])
			{
				h[j] = tmap[s][i].w + h[s];//计算节点j的距离
				if (!inq[j]) inq[j] = 1, q.push(j);//若j非在队列入队
			}
		}

	}
}
//F[i]=G[i]+H[i] G[i]表示起点到节点i的路长，H[i]表示节点i到终点的最短路长
int astar(int st, int end, int kk) {//计算由st至end的第kk短的路径长度
	priority_queue<path> q;
	path p, tp;//被扩展的元素p，扩展出的新元素tp
	int k[n] = { 0 };//节点经过的次数k[]初始化为0
	findh(end);//计算反向距离表
	if (h[st] == inf) return -1;//若end不可达st
	p.s = st;//st对应的元素p入队
	p.g = 0;
	p.f = h[st];
	q.push(p);
	while (!q.empty())//若非空，则取出估价函数（路长）最小的元素
	{
		p = q.top();
		q.pop();
		k[p.s]++;//走过该元素对应节点的次数+1
		if (k[p.s] > kk) continue;//每个节点最多走kk次，超过不必走
		if (p.s == end && k[end] == kk) return p.f;//若第kk次走到终点，返回路长
		int m = map[p.s].size();//计算出度
		for (int i = 0;i < m;++i)//枚举每条出边
		{
			int j = map[p.s][i].v;//取第i条出边的端点j
			if (h[j] != inf)//若节点j可通向终点，则计算j的估价函数
			{
				tp.g = p.g + map[p.s][i].w;
				tp.f = h[j] + tp.g;
				tp.s = j;
				q.push(tp);
			}
		}
	}
	return -1;
}
int main() {
	int N, m, ss, tt, kk, a, b, t;
	node p;
	scanf("%d%d", &N, &m);//节点数、边数
	for (int i = 1;i <= n;++i)//初始化
	{
		map[i].clear();
		tmap[i].clear();
		h[i] = inf;
	}
	while (m--)
	{
		scanf("%d%d%d", &a, &b, &t);//正向边（a，b）存入容器map[a],反向边（b，a）存入容器tmap[b]
		p.v = b;
		p.w = t;
		map[a].push_back(p);
		p.v = a;
		tmap[b].push_back(p);
	}
	scanf("%d%d%d", &ss, &tt, &kk);//输入起点、终点、最短路径序号
	if (ss == tt) kk++;//若起点与终点重合，则每个节点走过的次数+1
	printf("%d\n", astar(ss, tt, kk));
}