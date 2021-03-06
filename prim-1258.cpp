#include <algorithm>
#define inf 1<<25
int g[100][100];
int used[100];
int dist[100];
int main() {
	int n,tmp;
	cin >> n;
	for (int i = 0;i < n;++i)
		for (int j = 0;j < n;++j)
			cin >> g[i][j];
	for (int i = 0;i < n;++i) {
		used[i] = 0;
	}
	dist[0] = 0;
	for (int i = 1;i < n;++i) {
		dist[i] = g[0][i];
	}
	int ans = 0;
	for (int i = 0;i < n;++i) {
		int x = inf;
		for (int k = 0;k < n;++k) {
			if (dist[k] < x && !used[k])
			{
				x = dist[k];
				tmp = k;
			}
		}
		if (tmp != 0) {
			ans += dist[tmp];
		}
		used[tmp] = 1;
		for (int i = 0;i < n;++i)
			if (!used[i])
				dist[i] = min(dist[i], g[tmp][i]);
	}
	printf("%d\n", ans);

	
}