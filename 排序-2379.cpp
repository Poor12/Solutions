//线性表排序 
#include <string>
#include <algorithm>
const int maxn = 1100;
struct judgement
{
	int c, p, t, r;
};
struct team
{
	int id, ac, t;
	int p[25];//i题解答错误的标志
	bool sol[25];//i题解答正确的标志
};
bool cmp_t(const judgement &a, const judgement &b) {
	return a.t < b.t;
}
bool cmp_ac(const team &a, const team &b) {
	if (a.ac != b.ac)
		return a.ac < b.ac;
	if (a.t != b.t)
		return a.t < b.t;
	return a.id < b.id;
}
judgement a[maxn];
team t[maxn];
int n, m;
int main() {
	memset(a, 0, sizeof(a));
	memset(t, 0, sizeof(t));
	cin >> n >> m;
	for (int i = 1;i <= m;++i) {
		cin >> a[i].c >> a[i].p >> a[i].r >> a[i].t;
	}
	for (int i = 1;i <= n;++i) {
		t[i].id = i;
	}
	//sort(a + 1, a + m + 1, cmp_t);//先处理提交时间小的提交
	for (int i = 1;i <= m;++i) {
		int x = a[i].c, y = a[i].p;
		if (t[x].sol[y])
			continue;
		if (a[i].r) {
			t[x].t += 1200 * t[x].p[y] + a[i].t;
			t[x].sol[y] = 1;
			t[x].ac++;
		}
		else
		{
			t[x].p[y]++;
		}
	}
	sort(t + 1, t + n + 1, cmp_ac);
	for (int i = 1;i < n;++i)
		cout << t[i].id << ' ';
	cout << t[n].id << endl;
	return 0;
}