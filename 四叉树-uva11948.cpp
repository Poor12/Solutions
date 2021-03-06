//四叉树-先序遍历得到二维空间图
#include <sstream>
#include <string>
#include <cstdio>
#include <math.h>
char g[1024][1024];//整个区域的邻接矩阵，1表示（i，j）为白像素，0表示黑像素
char line[32767];
int idx;
//设根节点为1，代表左上角为（0，0）、右下角为（n-1，n-1）的子矩阵
//节点k（中心mx，my）对应的子矩阵分别为：
//（1）节点4*k代表左上子矩阵，以（lx，ly）为左上角，（mx，my）为右下角
//（2）节点4*k+1代表左下子矩阵，以（mx+1，ly）为左上角，（rx，my）为右下角
//（3）节点4*k+2代表右上子矩阵，以（lx，my+1）为左上角，（mx，ry）为右下角
//（4）节点4*k+3代表右下子矩阵，以（mx+1，my+1）为左上角，（rx，ry）为右下角
void build(int k, int lx, int ly, int rx, int ry) {//从节点k（代表左上角为（lx，ly),右下角为（rx,ry)的子矩阵出发，构建以其为根的四叉树
	char type = line[idx++];
	if (type == '*') {
		int mx = (lx + rx) / 2, my = (ly + ry) / 2;//如果是一块子矩阵，找到它的中心点
		build(k * 4, lx, ly, mx, my);
		build(k * 4 + 1, mx + 1, ly, rx, my);
		build(k * 4 + 2, lx, my + 1, mx, ry);
		build(k * 4 + 3, mx + 1, my + 1, rx, ry);
	}
	else {//涂色
		for (int i = lx;i <= rx;++i) {
			for (int j = ly;j <= ry;++j)
				g[i][j] = type;
		}
	}
}
int main() {
	float b = pow(10, -6.0);
	int testcase;
	int n, sx, sy, ex, ey;//矩阵大小，子区域左上角（sx，sy），右下角（ex,ey)
	scanf("%d", &testcase);
	//while (getchar() != '\n');
	while (testcase--) {
		scanf("%d %s", &n, line);
		float a = log(n) / log(2) - int(log(n) / log(2));
		if ((a>b||a<-b)||n<=1)//__builtin_popcount(n)!=1
		{
			puts("Size is invalid");
			continue;
		}
		memset(g, 0, sizeof(g));
		idx = 0;
		build(1, 0, 0, n - 1, n - 1);
		int f = 0;
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < n;++j) {
				if (g[j][i] == '1') {//若为白色像素，则计算i行上连续的白像素区间[l,r-1]
					int l = j, r = j;//白像素区间的首尾指针初始化
					while (r<n&&g[r][i]=='1')
					{
						r++;
					}
					if (f) putchar(',');
					f = 1;
					if (l + 1 != r)
						printf("(%d-%d，%d)", l + 1, r, i + 1);
					else
						printf("(%d,%d)", r, i + 1);
					j = r;//从i行的r列开始继续向右搜索
				}
			}
		}
		puts("");
	}
	return 0;
}
