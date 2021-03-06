#include <string>
struct node {
	int k, step;
};
node h[100000];
int s[11000];//目前得到的素数x的最短路径
int tot,x,y;
bool p[11000];
void make(int n) {
	memset(p, 0, sizeof(p));//0表示素数
	p[0] = 1;
	p[1] = 1;
	for (int i = 2;i <= n;++i) {
		if (!p[i]) {
			for (int j = i * i;j <= n;j += i)
				p[j] = 1;
		}
	}
}
int change(int x, int i, int j) {
	if (i == 1) return (x / 10) * 10 + j;
	else if (i == 2) return (x / 100) * 100 + x % 10 + j * 10;
	else if (i == 3) return (x / 1000) * 1000 + x % 100 + j * 100;
	else if (i == 4) return (x % 1000) + j * 1000;
}
int main() {
	make(9999);
	cin >> tot;
	while (tot--)
	{
		cin >> x >> y;
		h[1].k = x;
		h[1].step = 0;
		int l = 1, r = 1;
		memset(s, 100, sizeof(s));
		int ans = -1;
		while (1) {
			if (h[l].k == y) {//避免首位两个数相同
				ans = h[l].step;
				break;
			}
			int tk, ts;
			for (int i = 1;i <= 4;++i)//bfs
				for (int j = 0;j <= 9;++j)
					if (!((j == 0) && (i == 4))) {
						tk = change(h[l].k, i, j);
						if (p[tk]) continue;
						ts = h[l].step + 1;
						if (ts >= s[tk]) continue;
						if (tk == y) {
							ans = ts;
							break;
						}
						s[tk] = ts;
						r++;
						h[r].k = tk;//入队
						h[r].step = ts;
					}
			if (l == r || ans >= 0) break;
			l++;
		}
		if (ans >= 0) cout << ans << endl;
		else cout << "impossible" << endl;
	}
}