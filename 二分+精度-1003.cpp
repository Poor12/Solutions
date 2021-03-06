#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	POJ 1003 二分查找+精度 
*/
const int maxn = 300;
const double delta = 1e-8;
int zero(double x) {
	if (x < -delta)
		return -1;
	return x > delta;
}
int main()
{
	double len[maxn];
	int total;
	len[0] = 0.0;
	for (total = 1;zero(len[total - 1] - 5.20) < 0;total++) {
		len[total] = len[total - 1] + 1.0 / (total + 1);
	}
	double x;
	cin >> x;
	while (zero(x))
	{
		int l, r;
		l = 0;
		r = total;
		while (l+1<r)
		{
			int mid = (l + r) / 2;
			if (zero(len[mid] - x) < 0)
				l = mid;
			else
				r = mid;
		}
		cout << r << " card(s)" << endl;
		cin >> x;
	}
	return 0;
}
