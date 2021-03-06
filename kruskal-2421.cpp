int fa[100];
int g[100][100];
int getfather(int x) {
	if (fa[x] < 0)
		return x;
	return fa[x] = getfather(fa[x]);
}
int main() {
	int n, m, x, y;
	cin >> n;
	for (int i = 0;i < n;++i)
		for (int j = 0;j < n;++j)
			cin >> g[i][j];
	for (int i = 0;i < n;++i)
		fa[i] = -1;
	cin >> m;
	for (int i = 0;i < m;++i) {
		cin >> x >> y;
		fa[x - 1] = y - 1;
	}
	int ans = 0;
	for (int k = 1;k <= 1000;++k)
		for (int i = 0;i < n;++i)
			for (int j = 0;j < n;++j)
				if (g[i][j] == k && getfather(i) != getfather(j)) {			
					fa[i] = j;
					ans += k;
				}
	printf("%d\n", ans);
}