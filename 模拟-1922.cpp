#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	POJ 1992 直叙式模拟 charley所需的时间就是其他同学所需的最少时间,只有从后面超过才会改变跟随，所以t<0是要弃掉
*/

int main()
{
	const double D = 4.50;
	int n;
	while (cin >> n, n > 0) {
		double v,t,x,min = 1e100;
		for (int i = 0;i < n;++i) {
			cin >> v >> t;
			if (t>=0&&(x = D * 3600 / v + t) < min)
				min = x;
		}
		printf("%.0lf\n", ceil(min));
		
	}
	return 0;
}
