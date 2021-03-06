#include <math.h>
const int maxn = 200;
int a[maxn][2];
double dist[maxn][maxn];
bool con[maxn][maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0;i < n;++i)
		for (int j = i;j < n;++j)
			dist[i][j]=dist[j][i]= sqrt((a[i][0]-a[j][0])*(a[i][0] - a[j][0])+ (a[i][1] - a[j][1])*(a[i][1] - a[j][1]));
	double l = 0, r = 1e5;//给定区间中寻找最小的边长上限k
	while (r-l>=1e-5)
	{
		double mid = (l + r) / 2;//计算区间的中间点 con[i][j]=0 (i,j)边长大于中间值；con[i][j]=1 (i,j)边长小于等于中间值
		for (int i = 0;i < n;++i)
			for (int j = i;j < n;++j)
				if (dist[i][j] > mid)
					con[i][j] =con[j][i]= 0;
				else
					con[i][j] =con[j][i]= 1;
		for (int k = 0;k < n;++k)//枚举中间节点
			for (int i = 0;i < n;++i)//枚举首尾节点
				for (int j = 0;j < n;++j)
					con[i][j] |= con[i][k] & con[k][j];//若原路径i->j满足条件或者i->k和k->
		if (con[0][1])
			r = mid;
		else
			l = mid;
	}
	cout << "Scenario #1" <<endl;
	printf("Frog distacne: %.03f", l);
}
