//最小边覆盖
const int v = 1100;
int n, m, k, x, y, pre[v];//集合x和集合y的节点数各为n、m，边数为k，匹配边集为pre
bool V[v], a[v][v];//访问标志，邻接矩阵
bool dfs(int i) {
	for(int j=1;j<=m;++j)
		if ((!V[i]) && (a[i][j])) {
			V[j] = 1;
			if (pre[j] == 0 || dfs(pre[j])) {
				pre[j] = i;
				return 1;
			}
		}
	return 0;
}
int main() {
	cin >> n >> m >> k;
	memset(a, 0, sizeof(a));
	memset(pre, 0, sizeof(pre));
	for (int i = 1;i <= k;i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	int ans = 0;
	for (int i = 1;i <= n;++i) {
		memset(V, 0, sizeof(V));
		if (dfs(i)) ans++;
	}
	cout << n + m - ans << endl;

}