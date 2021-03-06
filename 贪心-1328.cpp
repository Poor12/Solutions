#include <algorithm>
const int maxn = 1010;
struct tt
{
	double l, r;
}p[maxn];
int n, d;
void init()
{
	double x, y, h;
	for (int i = 1;i <= n;++i)
	{
		scanf("%lf%lf", &x, &y);
		if (y > d) {
			d = -1;
			return;
		}
		h = sqrt(d*d - y * y);
		p[i].l = x - h;
		p[i].r = x + h;
	}
}
bool cmp(tt a, tt b)
{
	if (a.r < b.r) return 1;
	if (a.r == b.r&&a.l < b.l) return true;
	return false;
}

void work()
{
	if (d == -1)
	{
		printf("-1\n");
		return;
	}
	sort(p + 1, p + n + 1, cmp);
	int ans = 0;
	double last = -100000000;
	for (int i = 1;i <= n;++i)
	{
		if (p[i].l <= last)
			continue;
		ans++;
		last = p[i].r;
	}
	printf("%d\n", ans);
}

int main()
{
	int t = 0;
	while (scanf("%d%d",&n,&d),n+d)
	{	
		printf("Case %d: ", ++t);
		init();
		work();
	}
}