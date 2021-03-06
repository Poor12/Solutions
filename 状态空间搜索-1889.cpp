#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
#include <map>
struct pacnode//包装盒
{
	int q[4];//i种规格的数量
	double price;//价格
	int id;
}pac[60];
int n,met[60],nowmet[60],need[4],rankby[4][60];//nowmet[]包装盒组合，need[]4种规格灯泡的剩余需求，rankby[i][j]存储i规格的灯泡在n个包装盒中单价上限最j小的包装盒序号，minave[i][j]存储i规格的灯泡在包装盒j至包装盒n中的最小单价上限
double ans, ave[4][60], minave[4][60];//ave[i][j]为第j个包装盒单装规格i的灯泡的单价上限（第j个包装盒价格/第j个包装盒中i规格灯泡的数量），若第j个包装盒内没有规格i的灯泡，则ave[i][j]=∞
void init() {
	for (int i = 0;i < n;++i) {
		scanf("%d%lf", &pac[i].id, &pac[i].price);
		memset(pac[i].q, 0, sizeof(pac[i].q));
		char tmp[1000];
		gets_s(tmp);
		istringstream in(tmp);
		while (true)
		{
			char kind;
			int x;
			if (in >> kind >> x)
				pac[i].q[kind - 'a'] += x;
			else
				break;
		}
	}
	for (int i = 0;i < 4;++i)//求单价上限
		for (int j = 0;j < n;++j)
			if (pac[j].q[i] == 0)
				ave[i][j] = 1e100;
			else
				ave[i][j] = pac[j].price / pac[j].q[i];
	for (int i = 0;i < 4;++i) {//枚举每种规格i，按照单价上限为第一关键字，包装盒序号为第二关键字递增排序
		pair<double, int> x[60];//第一个对象ave[i][j]，第二个对象为j
		for (int j = 0;j < n;++j) {
			x[j].first = ave[i][j];
			x[j].second = j;
		}
		sort(x, x + n);
		for (int j = 0;j < n;++j)
			rankby[i][j] = x[j].second;
		minave[i][n - 1] = ave[i][n - 1];
		for (int j = n - 2;j >= 0;--j)
			minave[i][j] = min(minave[i][j + 1], ave[i][j]);
	}
}
//dfs
void search(int st, double now) {//从第st个包装盒和目前价格now出发，递归计算最优价格和包装组合
	if (now > ans) return;//当前价格高于最低价格
	if (need[0] <= 0 && need[1] <= 0 && need[2] <= 0 && need[3] <= 0)//满足客户要求
	{
		ans = now;
		memcpy(met, nowmet, sizeof(met));//复制数组
		return;
	}
	for (int i = 0;i < 4;++i) {//一旦发现计入该规格的剩余需求后大于，其价格大于最优价格，回溯
		if (now + minave[i][st] * need[i] > ans) return;
	}
	int br = 0;//计算剩余需求数最多的灯泡规格
	for (int i = 1;i < 4;++i) {
		if (need[i] > need[br])
			br = i;
	}
	for (int i = 0;i < n;++i) {//按照br规格的灯泡在n个包装盒中单价上限递增的顺序搜索
		int p = rankby[br][i];//第i小的包装盒序号为p
		if (p < st) continue;//若包装盒已搜索过
		bool use = false;//判断包装盒p中是否有客户需要的灯泡类型
		for (int j = 0;j < 4;++j) {
			if (need[j] > 0 && pac[p].q[i] > 0)
			{
				use = 1;
				break;
			}
		}
		if (!use) continue;//若没有需要的类型
		++nowmet[p];//买入当前包装盒，调节剩余需求
		for (int j = 0;j < 4;++j)
			need[j] -= pac[p].q[j];
		search(p, now + pac[p].price);
		--nowmet[p];//回溯
		for (int j = 0;j < 4;++j)
			need[j] += pac[p].q[j];
	}
}
void work() {
	memset(need, 0, sizeof(need));
	char tmp[1000];
	gets_s(tmp);
	istringstream in(tmp);
	while (true)//输入用户需求
	{
		char kind;
		int x;
		if (in >> kind >> x) {
			if (kind == 'a') need[0] += x;
			else if (kind == 'b') need[1] += x;
			else if (kind == 'c') need[2] += x;
			else if (kind == 'd') need[3] += x;
		}
		else
			break;
	}
	memset(nowmet, 0, sizeof(nowmet));//包装盒组合初始化为空
	ans = 1e100;//价格初始化为无穷
	search(0, 0.0);
	printf("%8.2lf", ans);
	vector<pair<int, int>> oa;
	for (int i = 0;i < n;++i) {
		if (met[i] != 0)//数量不为空
			oa.push_back(make_pair(pac[i].id, met[i]));//将最优组合的包装盒编号与数量送入数组
	}
	sort(oa.begin(), oa.end());
	for (int i = 0;i < oa.size();i++) {
		if (oa[i].second != 1)
			printf("%d(%d)", oa[i].first, oa[i].second);
		else
			printf("%d", oa[i].first);
	}
	printf("\n");
}
int main() {
	int testno = 0;
	while (true) {
		if (scanf("%d", &n) == EOF) break;
		if (n == 0) break;
		init();
		++testno;
		printf("input set #%d:\n", testno);
		int m;
		scanf("%d\n", &m);
		for (int i = 0;i < m;++i) {
			printf("%d:", i + 1);
			work();
		}
	}
	return 0;
}

