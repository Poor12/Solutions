//优先队列，打印机的工作原理
//priority_queue 三个模板参数，第一个元素类型，第二个容器类型（默认为vector），第三个比较算子（默认大的先出队）
const int maxn = 100 + 5;//队列容量
inline int fabs(int k) {
	return k < 0 ? -k : k;
}
int main() {
	int loop;
	cin >> loop;
	while (loop--) {
		int n, m;
		cin >> n >> m;
		int st, ed, a[maxn];
		for (int i = 0;i < n;++i)
			cin >> a[i];
		a[m] = -a[m];//要打印的用负数标记
		st = 0;
		ed = n;
		int cnt = 0;
		while ((ed+1)%maxn!=st)//循环队列模拟
		{
			int k = a[st];
			st = (st + 1) % maxn;
			bool print = true;
			for (int i = st;i != ed;i = (i + 1) % maxn) {
				if (fabs(k) < fabs(a[i])) {
					print = false;
					a[ed] = k;
					ed = (ed + 1) % maxn;
					break;
				}
			}
			if (print) {
				++cnt;
				if (k < 0) {
					cout << cnt << endl;
					break;
				}
			}
		}
	}
	return 0;
}
