//左上角（0，0），右下角（m-1，n-1），由于机器人是一个直径为1.6m的圆形，格子边长为1m，因此其圆心不可能为0行、0列、m-1行、n-1列。按照由上而下、由左而右的输入顺序，在（1，1）为左上角、（m-1，n-1）为右下角，若（i，j）为障碍物，则机器人不可能通过（i-1，j）、（i，j-1）、（i-1，j-1）。
#include <queue>
typedef int Byte;
struct node
{
	Byte x, y, s, step;//当前坐标，方向s，步数step
};
node qt[300000], start, endd;//队列qt[],起点start,终点end
bool used[51][51][4];//状态记忆表，其中used[x][y][d]标志机器人曾经以d方向走入（x，y）
bool map[51][51];//商店矩阵
Byte movee[4][5][4] = {//转移函数 机器人沿方向i移动j步后的水平增量为move[i][j][0],垂直增量为move[i][j][1],移动后方向为move[i][j][2]
	//机器人由(x,y)出发，沿方向i移动j步后的坐标（x+move[i][j][0],y+move[i][j][1]）,到达该格的方向变为move[i][j][2].
	//为了避免重复搜索，若走入的位置和方向之前没访问过，则指令有效，生成新状态，新状态的指令条数为之前的指令条数+1，否则废弃该状态
	{{0,0,1},{0,0,2},{1,0,0},{2,0,0},{3,0,0}},
	{{0,0,0},{0,0,3},{0,1,1},{0,2,1},{0,3,1}},
	{{0,0,0},{0,0,3},{0,-1,2},{0,-2,2},{0,-3,2}},
	{{0,0,1},{0,0,2},{-1,0,3},{-2,0,3},{-3,0,3}},
};
int n, m;
int searchans() {//bfs
	if (start.x==endd.x&&start.y == endd.y)//起点终点重合
	{
		return 0;
	}
	node *cur = qt, *next = qt;//队列首尾
	int i;
	memset(used, 0, sizeof(used));//标志所有状态未访问
	start.step = 0;//起点步数为0
	used[start.x][start.y][start.s] = 1;//设起始状态访问
	*next++ = start;//起点状态入队
	while (cur != next) {
		for (i = 0;i < 5;++i) {
			next->x = cur->x + movee[cur->s][i][0];
			next->y = cur->y + movee[cur->s][i][1];
			next->s = movee[cur->s][i][2];
			if (map[next->x][next->y]) break;//遇到障碍物
			if (next->x == endd.x&&next->y == endd.y) return cur->step + 1;//到达目的地
			if (!used[next->x][next->y][next->s])//未被访问
			{
				used[next->x][next->y][next->s] = 1;
				next->step = cur->step + 1;
				next++;
			}
		}
		cur++;
	}
	return -1;//从起点到终点不存在任何路径
}
int main() {
	int i, j, t, t1, t2, t3, t4;//起点坐标（t1，t2），终点坐标（t3，t4）
	char buf[10];//方向串
	memset(map[0], 1, sizeof(map[0]));
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if (n == 0 && m == 0)
			break;
		for (i = 1;i <= n;++i) {
			memset(map[i], 0, sizeof(map[i]));
			map[i][0] = map[i][m] = 1;//设i行的0列和m列为障碍物
			for (j = 1;j <= m;++j) {
				scanf("%d", &t);
				if (t == 1)
					map[i][j] = map[i - 1][j] = map[i][j - 1] = map[i - 1][j - 1];
			}
		}
		memset(map[n], 1, sizeof(map[n]));
		scanf("%d%d%d%d%s", &t1, &t2, &t3, &t4, buf);
		start.x = t1;
		start.y = t2;
		endd.x = t3;
		endd.y = t4;
		if (buf[0] == 's') start.s = 0;
		else if (buf[0] == 'e') start.s = 1;
		else if (buf[0] == 'w') start.s = 2;
		else if (buf[0] == 'n') start.s = 3;
		printf("%d\n", searchans());
	}
}


