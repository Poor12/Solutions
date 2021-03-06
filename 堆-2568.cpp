//树的度的使用 构建树的邻接矩阵（因为从根出发单向向下只需将子节点加到根节点的向量下即可）
#include <fstream>
#include <queue>
#include <string>
#include <strstream>
#include <sstream>
#include <vector>
ifstream in("decode.in");//从文件中读数据
typedef vector<int> ivec;
typedef vector<ivec> imat;
/*
vector<int> a[10];
vector<int> *a;
vector<vector<int>> a;
*/
void print(imat &adj, int x, int p = 0) {//p 前驱节点
	cout << "(" << x;//留在最后的节点是x节点
	for (ivec::iterator it = adj[x].begin();it != adj[x].end();it++) {
		//if (*it != p) {
			cout << " ";
			print(adj, *it, x);
		//}
	}
	cout << ")";
}
int main() {
	string line;
	while (getline(cin,line)) {
		istrstream lstr(line.c_str());//将测试用例转为istrstream类
		//stringstream sin(line);
		ivec v;
		int x;
		while (lstr >> x)
			v.push_back(x);
		int n = v.size() + 1;//总点数
		ivec deg(n + 1, 0);//度数序列，deg[x]表示节点x的度数
		for (int i = 0;i < n - 1;++i) {
			deg[v[i]]++;//计算度数，节点的度数就是子节点的个数，树的节点就是所有节点的度的最大值
		}
		priority_queue<int, ivec, greater<int>> leafs;//小根堆
		for (int i = 1;i <= n;++i) {//将度数为0的节点即叶子节点压入
			if (deg[i] == 0)
				leafs.push(i);
		}
		imat adj(n + 1, ivec());//树的邻接表
		for (int i = 0;i < n - 1;++i) {
			assert(!leafs.empty());
			x = leafs.top();
			leafs.pop();
			//adj[x].push_back(v[i]);
			adj[v[i]].push_back(x);
			if (--deg[v[i]] == 0)
				leafs.push(v[i]);
		}
		print(adj, n,0);
		cout << endl;
	}
	return 0;
}