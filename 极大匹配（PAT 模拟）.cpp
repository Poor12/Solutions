#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
const int maxv = 1010;
bool g[maxv][maxv];//无向图
bool M[maxv][maxv];//查询边集
bool isExist[maxv];//顶点是否已出现
int main() {
	freopen("D:\\data.txt", "r", stdin);
	memset(g, false, sizeof(g));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	int k;
	scanf("%d", &k);
	while (k--)
	{
		memset(M,0, sizeof(M));
		memset(isExist, false, sizeof(isExist));
		int l;
		scanf("%d", &l);
		bool ismatching = 1;
		for (int i = 0;i < l;++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (isExist[u] || isExist[v])
				ismatching = 0;
			M[u][v] = M[v][u] = 1;
			isExist[u] = isExist[v] = 1;
		}
		if (!ismatching)
			printf("Not a Matching\n");
		else
		{
			bool isMaximalMatching = 1;
			for (int u = 1;u <= n;++u)
			{
				for (int v = u + 1;v <= n;++v)
				{
					if (g[u][v] && !M[u][v] && !isExist[u] && !isExist[v])
						isMaximalMatching = 0;
				}
			}
			if (isMaximalMatching)
				cout << "Yes\n";
			else
				cout << "Not Maximal\n";
		}
	}
	return 0;
	
}