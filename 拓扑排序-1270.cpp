//拓扑排序不同于通常意义上的线性表排序。线性表排序按照关键字key的值递增顺序重新线性表排列。拓扑排序则是将无回路图DAG中的所有节点排成一个线性序列:如果dag包含有向边（u，v），则在这个序列中u出现在v前。拓扑排序可以看成是dag的所有节点沿水平线排成的一个序列，使得有向边均从左指到右
//在许多应用中，两个事件发生时间的先后经常用有向图的有向边表示。如果图中发现回路则矛盾
//常用于判别议题和假设成立与否，计算使得议题和假设成立的可能方案
//常用方法：（1）删边法（2）采用dfs计算拓扑排序
//1.删边法
/*
	由于每一条拓扑子路径的首节点的入度为0，因此可采取如下办法:
	步骤一：从图中选择一个入度为0的节点且输出
	步骤二：从图中删除该节点及其所有出边（与之相邻的所有节点的入度-1）
	反复执行这两个操作，直至所有节点都输出或者直至剩下的图中再没有入度为0的节点，说明图中有回路
	分析算法的时间复杂度：统计所有节点入度的时间复杂度为O（VE），删边花费时间也为O（VE），总的花费时间为O（VE）
	使用一次删边法，计算一个拓扑方案，可以采用递归来计算所有的可能方案
*/

//2.利用dfs计算拓扑排序
/*
	一个有向图是无回路的，当且仅当对图进行dfs遍历时没有反向边B.怎样发现反向边，方法很简单：调用dfs(y)算法计算y可达的节点集。若x在该节点集，则<x,y>为反向边，时间复杂度为O（E）。
	由此得出方法：以访问一个节点算作时间单位，把遍历了u的后代的时间称作结束时间f[u]，显然对图进行dfs遍历时没有反向边b，则对于图中任意边（u，v），都有f[v]<f[u]
	拓扑序列表为栈topo，topo栈中的节点按照f[u]递减顺序由上而下排列，即拓扑排序的节点是以与其完成时刻相反的顺序出现的。
	void dfs-visit(u)//遍历以u为根的子树
	{
		u设访问标志；
		time=time+1；
		对所有与u相邻的未访问的节点v进行一次dfs-visit(v)(若存在f[v]>f[u]的有向边失败退出)
		f[u]=time;
		u压入topo栈；
	};
	初始时time=0，所有节点设未访问标志，然后对每个未访问节点v执行dfs-visit，便可得到topo栈和每个节点的结束时间，若发现反向边失败，否则从topo栈顶开始往下栈中所有节点组成一个拓扑排序
	dfs的运行时间为O(E),每个节点压入栈的时间为O(1)，总时间O（E）
*/
//例 poj1270
#include <string>
#include <vector>
bool has[1 << 8];//判断节点是否存在于图中
int pre[1 << 8];
vector<char> graph;
int siz;
string line;
void dfs(int dep, string res) {
	if (dep == siz + 1) {
		cout << res << "\n";
		return;
	}
	for (int j = 0;j<graph.size();++j) {
		int i = graph[j];
		if (has[i] && pre[i] == 0) {
			has[i] = false;
			for (int k = 0;k < line.length();k+=4) {
				if (line[k] == i)
					--pre[line[k + 2]];
			}
			dfs(dep + 1, res + (char)i);
			for (int k = 0;k < line.length();k += 4) {
				if (line[k] == i)
					++pre[line[k + 2]];
			}
			has[i] = 1;
		}
	}
}
int main() {
	while (getline(cin,line)) {
		siz = line.length() / 2 + 1;
		for (int i = 0;i < line.length();i+=2) {
			graph.push_back(line[i]);
			has[line[i]] = 1;
		}
		getline(cin, line);
		for (int i = 0;i < line.length();i += 4) {
			++pre[line[i + 2]];//计算入度
		}
		dfs(1, "");
		printf("\n");
	}
}