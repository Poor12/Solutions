#include <algorithm>
const int maxn = 1010;
struct job {
	double a;
	int num;
}p[maxn];
int n;
void init()
{
	double a1, a2;
	scanf("%d", &n);
	for (int i = 1;i <= n;++i)
	{
		scanf("%lf%lf", &a1, &a2);
		p[i].a = a2 / a1;
		p[i].num = i;
	}
}

bool cmp(job x, job y)
{
	if ((x.a > y.a) || (x.a == y.a) && (x.num < y.num)) return true;
	return false;
}
void work()
{
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1;i <= n;++i)
		printf("%d ", p[i].num);

}

int main()
{
	int t;
	scanf("%d\n", &t);
	while (t--)
	{
		init();
		work();
	}
}