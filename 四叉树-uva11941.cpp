//四叉树 每个节点要么没有节点，要么有四个子节点
//四叉树通常表示一个二维空间，一个二维空间用一个四叉树的节点表示，这个二维空间又可以划分成四个象限区域，每个区域继续存入四叉树的四个节点，这样的区域可以正方形、矩形或是任意形状
//四叉树的数据结构给出了一种对二维空间进行压缩编码的方法。二维空间的每个子区域都有一个属性值（例如同色子区的颜色标志或不同色子区域的灰色标志），其数据结构的基本思想是将一个二维空间等分为四个部分，逐块检查其子区域的属性值；如果某个子区域的所有格具有相同的属性值，则这个子区域不再继续分割；否则这个区域为灰色，继续分割，直到每个子块属性值相同
//显然产生四叉树的过程中，产生的节点要么是叶节点要么是灰色的分支节点，一般来说二维空间一般为边长为2的次幂的正方体，细分log2n次可达边长
//对四叉树进行先序或后序遍历，顺序记下节点的属性值，便可以得到二维空间的压缩编码，也可以计算出二维空间的真实情形。
//四叉树被用于计算机图形学、图像处理；八叉树用于3d图形处理
#include <sstream>
#include <string>
#include <cstdio>
#include <math.h>
char g[1024][1024];//整个区域的邻接矩阵，1表示（i，j）为白像素，0表示黑像素
char node[1024 * 1024];//四叉树节点k的值为node[k],3表示k为分支点，1表示黑色节点，2表示白色节点
//设根节点为1，代表左上角为（0，0）、右下角为（n-1，n-1）的子矩阵
//节点k（中心mx，my）对应的子矩阵分别为：
//（1）节点4*k代表左上子矩阵，以（lx，ly）为左上角，（mx，my）为右下角
//（2）节点4*k+1代表左下子矩阵，以（mx+1，ly）为左上角，（rx，my）为右下角
//（3）节点4*k+2代表右上子矩阵，以（lx，my+1）为左上角，（mx，ry）为右下角
//（4）节点4*k+3代表右下子矩阵，以（mx+1，my+1）为左上角，（rx，ry）为右下角
int build(int k, int lx, int ly, int rx, int ry) {//从节点k（代表左上角为（lx，ly),右下角为（rx,ry)的子矩阵出发，构建以其为根的四叉树
	if (lx == rx && ly == ry)//若节点k为像素
		return node[k] = (1 << g[lx][ly]);//根据像素颜色确定叶节点k的值 1左移g位
	int mx = (lx + rx) / 2, my = (ly + ry) / 2;//如果是一块子矩阵，找到它的中心点
	int v = 0;//计算四个子矩阵或等的结果
	v |= build(k * 4, lx, ly, mx, my);
	v |= build(k * 4 + 1, mx + 1, ly, rx, my);
	v |= build(k * 4 + 2, lx, my + 1, mx, ry);
	v |= build(k * 4 + 3, mx + 1, my + 1, rx, ry);
	return node[k]= v;
}
void dfs(int u) {
	if (node[u] == 3) {
		if (u > 1)//跳过根节点
			putchar('*');
		dfs(u * 4);
		dfs(u * 4 + 1);
		dfs(u * 4 + 2);
		dfs(u * 4 + 3);
	}
	else {
		if (node[u] == 1)//全黑
			putchar('0');
		else
			putchar('1');//全白
	}
}
int main() {
	float b = pow(10, -6.0);
	int testcase;
	int n, sx, sy, ex, ey;//矩阵大小，子区域左上角（sx，sy），右下角（ex,ey)
	char line[32767];//列表串
	scanf("%d", &testcase);
	while (getchar() != '\n');
	while (testcase--) {
		gets_s(line);//gets前都要清回车
		stringstream sin(line);//line放入sin对象
		string token;
		sin >> n;
		float a = log(n) / log(2) - int(log(n) / log(2));
		if ((a>b||a<-b)||n<=1)//__builtin_popcount(n)!=1
		{
			puts("Size is invalid");
			continue;
		}
		memset(g, 0, sizeof(g));
		while (sin >> token) {//自动过滤空格
			sscanf(token.c_str(), "(%d,%d)", &sx, &sy);//左上角
			if (sin >> token) {
				sscanf(token.c_str(), "(%d,%d)", &ex, &ey);//右下角
				sx--;
				sy--;
				ex--;
				ey--;//以左上角（0，0）为基准
				for (int i = sx;i <= ex;++i) {//每块白的涂色
					for (int j = sy;j <= ey;++j)
						g[i][j] = 1;
				}
			}
		}
		build(1, 0, 0, n - 1, n - 1);
		dfs(1);
		puts("");
	}
	return 0;
}
