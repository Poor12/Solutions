const int maxn = 50;
const int maxl = 1005;
char str[maxn][maxl], stra[maxl], strb[maxl];
long double dist[maxn][maxn];
int n, m;
int find(char* a) {
	for (int i = 0;i < n;++i)
		if (strcmp(a, str[i]) == 0)
			return i;
	return -1;
}
int main() {
	while (scanf("%d",&n)&&n)
	{
		int cnt = 0;
		for (int i = 0;i < n;++i)
			for (int j = 0;j < n;++j)//求最长路径可初始化为0，求最短路径初始化为inf
				dist[i][j] = 0;
		for (int i = 0;i < n;++i)
			scanf("%s", str[i]);
		scanf("%d", &m);
		for (int i = 0;i < m;++i) {
			double w;
			scanf("%s %lf %s", stra,&w, strb);
			dist[find(stra)][find(strb)] = w;
		}
		for (int k = 0;k < n;++k)
			for (int i = 0;i < n;++i)
				for (int j = 0;j < n;++j)
					if (i != j && j != k && k != i)//避免回路，减少计算
						if (dist[i][k] * dist[k][j] > dist[i][j])
							dist[i][j] = dist[i][k] * dist[k][j];
		bool flag = 0;
		for (int i = 0;i < n;++i)
			for (int j = 0;j < n;++j)
				if (dist[i][j] * dist[j][i] > 1)
					flag = 1;
		printf("case %d: %s\n", ++cnt, flag ? "yes" : "no");
	}
}