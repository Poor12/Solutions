//由于迷失方向，因此在某一时刻，你可能位于（x，y），也有可能位于（n-1-y，x），（y，n-1-x）或（n-1-x，n-1-y）
//践踏尽可能少的花就需要四个方向可能踩到的花数的最大值最小
#include <queue>
#include <algorithm>
const int n = 21;//花园规模上限
const int d[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };//四个方向的垂直与水平位移
int n, vis[n][n][11][11][11][11];//记忆表，其中vis[x][y][d1][d2][d3][d4]表示行至(x,y)，上、左、下、右四个方位踩到的花数分别为d1，d2，d3，d4的标志
char g[n][n];//平方图
struct state {//状态的结构定义
	int x, y, val;//当前坐标(x,y),4个方位上踩到花数的最大值val
	int up, left, down, right;//4个方位踩到的花数
	state() {
		x = y = up = left = right = down = 0;//初始状态
	}
	state(int x, int y, int up, int left, int down, int right) {//对当前状态进行封装
		this->x = x;
		this->y = y;
		this->up = up;
		this->down = down;
		this->left = left;
		this->right = right;
		val = max(max(max(up, down), left), right);
	}
	bool operator < (const state& c) const {//定义优先级
		return val > c.val;
	}
}s;
void init() {
	for (int i = 0;i < n;++i) {
		scanf("%s", g[i]);
		for (int j = 0;j < n;++j)
			if (g[i][j] == 'P')
				s.x = i, s.y = j;
	}
}
int bfs() {//记忆化搜索
	memset(vis, 0, sizeof(vis));
	priority_queue<state> q;
	q.push(s);//初始状态入队
	vis[s.x][s.y][0][0][0][0] = 1;//初始状态进入记忆表
	while (!q.empty())
	{
		state u = q.top();
		q.pop();
		if (u.x == 0 || u.x == n - 1 || u.y == 0 || u.y == n - 1)//若逃离花园
		{
			return u.val;
		}
		for (int i = 0;i < 4;++i)//枚举四个方向（实际）
		{
			int xx = u.x + d[i][0];//更新坐标与花数
			int yy = u.y + d[i][1];
			int up = u.up;
			int left = u.left;
			int down = u.down;
			int right = u.right;
			if (g[xx][yy] == 'R') up++;//累计四个方向的花数（可能）
			if (g[n - 1 - yy][xx] == 'R') left++;
			if (g[n - 1 - xx][n - 1 - yy] == 'R') down++;
			if (g[yy][n - 1 - xx] == 'R') right++;
			if (!vis[xx][yy][up][left][down][right]) {
				vis[xx][yy][up][left][down][right] = 1;
				q.push(state(xx, yy, up, left, down, right));
			}
		}
	}

}
int main() {
	while (~scanf("%d",&n)&&n)
	{
		init();
		printf("at most %d rose(s) trampled.\n", bfs());
	}
	return 0;
}