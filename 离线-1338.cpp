const int maxn = 1500 + 1;
int a[maxn];
vector<int> b;

int main()
{
	for (int i = 1;i <= 1500;++i)
		a[i] = 0;
	for (int i = 1;i <= 1500;i *= 2) {
		for (int j = 1;j*i <= 1500;j *= 3) {
			for (int k = 1;i*j*k <= 1500;k *= 5) {
				a[i*j*k] = 1;
			}
		}
	}
	for (int i = 1;i <= 1500;++i) {
		if (a[i] == 1)
			b.push_back(i);
	}
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", b[n-1]);
	}
	return 0;
}