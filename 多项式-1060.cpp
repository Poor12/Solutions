//数组-多项式
//（1）数值数组。a[指数值]=底数值
//（2）结构数组。a的下标是项序数，a[i].coef系数，a[i].exp指数

const int maxl = 1000 + 5;
int compare(int a[], int la, int b[], int bl) {
	if (la > bl)
		return 1;
	if (la < bl)
		return -1;
	for (int i = la - 1;i >= 0;--i) {
		if (a[i] && !b[i])
			return 1;
		else if (!a[i] && b[i])
			return -1;
	}
	return 0;
}
int main() {
	int loop;
	cin >> loop;
	while (loop--)
	{
		int f[maxl], g[maxl], h[maxl];
		int lf, gl, hl;
		cin >> lf;
		for (int i = lf - 1;i >= 0;--i)
			cin >> f[i];
		cin >> gl;
		for (int i = gl - 1;i >= 0;--i)
			cin >> g[i];
		cin >> hl;
		for (int i = hl - 1;i >= 0;--i)
			cin >> h[i];
		int sum[maxl + maxl], ls = lf + gl - 1;
		for (int i = 0;i < ls;++i)
			sum[i] = 0;
		for (int i = 0;i < lf;i++)
			for (int j = 0;j < gl;++j)
				sum[i + j] ^= (f[i] & g[j]);
		while (compare(sum,ls,h,hl)>=0)//如果被除数大于除数
		{
			int d = ls - hl;//计算余数
			for (int i = 0;i < hl;++i)
				sum[i + d] ^= h[i];
			while (ls&&!sum[ls-1])
			{
				--ls;
			}
		}
		if (ls == 0)
			ls = 1;
		cout << ls << ' ';
		for (int i = ls - 1;i > 0;--i)
			cout << sum[i] << ' ';
		cout << sum[0] << endl;
	}
	return 0;
}
