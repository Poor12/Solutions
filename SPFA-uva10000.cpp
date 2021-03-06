const int maxn = 110;
int n, x, y, st, en, length, r, l, a[maxn][maxn], dist[maxn], h[100 * maxn];
bool visited[maxn];
int main() {
	freopen("a.txt", "r", stdin);
	int ca = 0;
	cin >> n;
	while (n) {
		memset(a, 0, sizeof(a));//邻接矩阵
		memset(visited, 0, sizeof(visited));//访问标志
		memset(dist, 0, sizeof(dist));//距离
		memset(h, 0, sizeof(h));//队列
		length = -1;//最长路长初始化
		cin >> st;//起点
		cin >> x >> y;//输入第一条有向边
		while (x||y)
		{
			a[x][y] = 1;
			cin >> x >> y;
		}
		l = r = 1;
		h[l] = st;
		visited[st] = 1;
		while (1)
		{
			int x = h[l];
			//if (dist[x] > length || (dist[x] == length && x < en)) {
			//	en = x;
			//	length = dist[x];
			//}
			for (int y = 1;y <= n;++y)
				if (a[x][y])
				{
					if (dist[x] + 1 > dist[y])
					{
						dist[y] = dist[x] + 1;
						if (!visited[y])
						{
							h[++r] = y;
							visited[y] = 1;
						}
					}
				}
			if (l == r)
				break;
			visited[x] = 0;//撤去x的访问标志
			l++;
		}
		for(int i=1;i<=n;++i)
			if (dist[i] > length)
			{
				length = dist[i];
				en = i;
			}
		cout << "case" << ++ca << ": the longest path from " << st;
		cout << " has length " << length << ", finishing at " << en << "." << endl;
		cout << endl;
		cin >> n;
	}
}