//节省每个状态的存储量是一个需要考虑的问题，如果只需开关即可改变状态，可以用二进制整数记录状态，通过位运算实现状态转移
#include <queue>
#include <string>
#include <algorithm>
#define maxn 15//矩阵规模上限
#define maxs 20010//状态数的上限
#define moveto 20//移动的阈值
#define switchon 10//开灯阈值
#define switchoff 0//关灯阈值
int r;//房间数
int control[maxs];//状态转移：其中u的父状态为control[u]
int op[maxs];//op[i]存储状态i的控制信息
bool visited[maxs];//状态i的访问标志
bool g[maxn][maxn], light[maxn][maxn];//房间的邻接矩阵，开关的邻接矩阵
bool init() {//当前测试用例存在，输入并返回true，否则返回false
	int t1, t2, d, s;
	scanf("%d%d%d", &r, &d, &s);//门的数量、开关数
	if (r == 0) return false;
	memset(g, false, sizeof(g));
	for (int i = 0;i < d;++i) {
		scanf("%d%d", &t1, &t2);
		t1--;
		t2--;
		g[t1][t2] = g[t2][t1] = 1;
	}
	memset(light, false, sizeof(light));
	for (int i = 0;i < s;++i) {
		scanf("%d%d", &t1, &t2);
		t1--;
		t2--;
		light[t1][t2] = 1;
	}
	return 1;
}
bool checkstay(int u) {
	int pos = u % 16;
	int tmp = u / 16;
	int j = 1 << pos;
	if (tmp&j)//pos房间的灯亮
		return true;
	return false;
}
int bfs() {
	//房间区间为[0,r-1]，0为走廊，r-1为卧室,因此用u的后四位（u%16）表示当前房间号，u/16记录每间房间的状态。每个二进制位代表一个房间灯的状态，1表示亮，0表示暗
	queue<int> q;//状态队列
	queue<int> step;//步数队列
	int u = (1 << 4), k = 0;//初始状态2^4，步数为0，房间号0，房间状态00...01
	int target = (1 << (r + 4 - 1)) + r - 1;//目标状态，房间号r-1，房间状态100..0
	int u_new, uu, pos;
	memset(visited, 0, sizeof(visited));//所有状态未访问
	memset(control, 255, sizeof(control));//父状态为空
	visited[u] = true;
	q.push(u);
	step.push(k);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		k = step.front();
		step.pop();
		pos = u % 16;
		uu = u >> 16;
		if (u == target) return k;
		for (int i = 0;i < r;++i) {//move操作，枚举所有房间
			if (g[pos][i])//是否有门
			{
				u_new = u - pos + i;//计算移动一步的子状态
				if (!visited[u_new] && checkstay(u_new))//未被访问且为合法状态
				{
					q.push(u_new);
					step.push(k + 1);
					visited[u_new] = 1;//设置访问标志
					control[u_new] = u;//设置父状态
					op[u_new] = moveto + i;//设置u_new进入的房间号为i
				}
			}
		}
		for (int i = 0, j = (1 << 4);i < r;++i, j = j << 1, uu = uu >> 1)//关灯操作
		{
			if (light[pos][i])//若房间pos有一个开关控制房间i的灯
			{
				if (uu & 1)//若房间i的灯亮则关闭房间i的灯
				{
					u_new = u - j;//计算子状态
					if (!visited[u_new] && checkstay(u_new))
					{
						q.push(u_new);
						step.push(k + 1);
						visited[u_new] = 1;
						control[u_new] = u;
						op[u_new] = switchoff + i;//设置u_new关闭的是房间i的灯
					}
				}
				else
				{
					u_new = u + j;
					if (!visited[u_new] && checkstay(u_new))
					{
						q.push(u_new);
						step.push(k + 1);
						visited[u_new] = 1;
						control[u_new] = u;
						op[u_new] = switchon + i;//设置打开的是房间i的灯
					}
				}
			}
		}
	}
	return -1;
}
void dfsprint(int u) {//从目标状态u开始递归输出最短的步序列
	int u_new;
	if (u == (1 << 4)) return;//若递归到边界则回溯，否则取出父状态，并继续向上递归
	u_new = control[u];
	dfsprint(u_new);
	if (op[u] >= moveto)
		printf("-move to room %d.\n", op[u] - moveto + 1);
	else if(op[u] >= switchon)
		printf("-switch on light in room %d.\n", op[u] - switchon + 1);
	else if (op[u] >= switchoff)
		printf("-switch off light in room %d.\n", op[u] - switchoff + 1);
}
void print(int cs, int steps) {
	printf("villa #%d\n", cs);
	if (steps == -1)
		printf("the problem cannot be solved\n");
	else {
		printf("the problem can be solved in %d steps:\n",steps);
		dfsprint((1 << (r + 4 - 1)) + r - 1);
	}
	printf("\n");
}
int main() {
	int steps;
	for (int cs = 1;;cs++)
	{
		if (!init()) break;
		steps = bfs();
		print(cs, steps);
	}
}
