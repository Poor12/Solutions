#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
double cmax, d, ad, num;
struct gs
{
	double price;
	double dis;
};
bool cmp(gs &g1, gs &g2)
{
	return g1.dis < g2.dis;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> cmax >> d >> ad >> num;
	vector<gs> g(num+1);
	for (int i = 0;i < num;++i)
	{
		cin >> g[i].price >> g[i].dis;
	}
	
	sort(g.begin(), g.end()-1,cmp);
	for (int i = 0;i < num;++i)
	{
		//cin >> g[i].price >> g[i].dis;
		cout << g[i].price << " " << g[i].dis << endl;
	}
	g[num].dis = d;
	g[num].price = 0;
	if (g[0].dis != 0)
		printf("the maxinum travel distance = 0.00\n");
	else
	{
		int now = 0;
		double maxn = cmax * ad, sum = 0, nowc = 0;//max为一箱油能跑多远,nowc为当前油箱油量
		while (now < num)
		{
			int k = -1;
			double minprice = INT16_MAX;
			for (int i = now + 1;i <= num && g[i].dis - g[now].dis <= maxn;++i)
			{
				if (g[i].price < minprice)
				{
					minprice = g[i].price;
					k = i;
					if (minprice < g[now].price)
						break;
				}
			}
			if (k == -1)//范围内没有加油站
				break;
			double need = (g[k].dis - g[now].dis) / ad;//need为当前出发到达目标加油站所需油量
			if (minprice < g[now].price)//若目标加油站油钱低于当前加油站
			{
				if (need > nowc)
				{
					sum += (need - nowc)*g[now].price;
					nowc = 0;
				}
				else
					nowc -= need;
			}
			else
			{
				sum += (cmax - nowc)*g[now].price;
				nowc = cmax - need;
			}
			now = k;
		}
		if (now == num)
			printf("%.2f\n", sum);
		else
			printf("the maximum travel distance = %.2f\n", g[now].dis + maxn);
	}
	return 0;
}