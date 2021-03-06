//约瑟夫环
//任意指定起点元素，规定报数方向，限定出列元素数，变换步长值，或者两个方向同时报数
const int maxn = 20;
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	while (n || k || m) {
		bool exist[maxn];
		memset(exist, 1, sizeof(exist));
		int p = 0, q = n + 1;
		int left = n;
		while (left)
		{
			int cnt = (k%left ? k % left : left);
			while (cnt--)
			{
				do {
					p = ((p + 1) % n ? (p + 1) % n : n);
				} while (!exist[p]);
			}
			cnt = (m%left ? m % left : left);
			while (cnt--)
			{
				do {
					q = ((q - 1 + n) % n ? (q - 1 + n) % n : n);
				} while (!exist[q]);
			}
			if (left < n)
				putchar(',');
			printf("%3d", p);
			if (p != q)
				printf("%3d", q);
			exist[p] = exist[q] = 0;
			left -= (p == q ? 1 : 2);
		}
		putchar('\n');
		scanf("%d%d%d", &n, &k, &m);
	}
}