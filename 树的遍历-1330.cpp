//树的表示 1.求每个节点的层次 2.分析x与y的层析，若x较深，取x的父指针为x，否则取y的父指针为y，以此类推直到x==y
//先序遍历树（MLR）：从上到下、从左到右地访问树中的节点，常被用于计算树中节点的层次、节点至根的路径等
/*
	void preorder(int v){
		访问处理节点v;
		for(i属于v相邻的子节点）//通常往下
			if（节点i未被访问）
				preorder(i);
	};
*/
//后序遍历树（LRM）：从下到上、从左到右地访问树中的节点，由于在后序遍历中任一个节点处的工作是在它的所有子节点被处理之后进行的。
//它十分适宜于统计相连的下层节点的状态，如计算节点高度、子树的节点总数和节点权和
/*
	void preorder(int v){
		for(i属于v相邻的子节点）//通常往下
			if（节点i未被访问）
				preorder(i);
		访问处理节点v;
	};
*/
#include <string>
#include <vector>
#include <algorithm>
const int maxn = 10000;
vector<int> a[maxn];//树的多重链表 a[i]存放着以i为父节点的子节点的指针
int f[maxn], r[maxn];//f双亲表示、r层次表示
void DFS(int u, int dep) {//先序遍历
	r[u] = dep;
	for (auto it = a[u].begin();it != a[u].end();++it)
		DFS(*it, dep + 1);
}
int main() {
	int casenum, num, n, i, x, y;
	scanf("%d", &casenum);
	for (num = 0;num < casenum;++num) {
		scanf("%d", &n);
		memset(f, 255, sizeof(f));//memset(f,-1,sizeof(f))
		for (i = 0;i < n - 1;++i) {
			scanf("%d %d", &x, &y);
			f[y - 1] = x - 1;
			a[x - 1].push_back(y - 1);
		}
		for (i = 0;f[i] >= 0;i++);//找到根节点
		DFS(i, 0);
		scanf("%d %d", &x, &y);
		x--;y--;
		while (x!=y)
		{
			if (r[x] > r[y]) x = f[x];
			else y = f[y];
		}
		printf("%d\n", x + 1);
	}
	
	return 0;
}