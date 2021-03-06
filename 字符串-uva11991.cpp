//数组数据重复出现，避免预先排序的开销，要求按照出现次数给出被查数据的位置
const int maxx = 1000050;
vector<int> v[maxx];//二维数组 v[字符]=出现的索引
int main() {
	int n, m;
	while (scanf("%d%d",&n,&m)==2)
	{
		for (int i = 1;i < maxx;++i)
			v[i].clear();
		for (int i = 1;i <= n;++i) {
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for (int i = 1;i <= m;++i) {
			int k, x;
			scanf("%d%d", &k, &x);
			int ans = 0;
			if (v[x].size() < k)
				ans = 0;
			else
			{
				ans = v[x][k - 1];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}