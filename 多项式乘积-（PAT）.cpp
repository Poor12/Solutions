#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, double>a, b;
map<int, double, greater<int>>mp;//内置类型的从大到小排序 less从小到大
int main() {
	int n, x;
	double y;
	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> x >> y;
		a.insert(make_pair(x, y));
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		b.insert(make_pair(x, y));
	}
	for (auto it = a.begin();it != a.end();it++) {
		for (auto st = b.begin();st != b.end();st++) {
			x = it->first + st->first;
			y = it->second*st->second;
			if (mp.find(x) != mp.end())
				mp[x] += y;
			else
			{
				mp.insert(make_pair(x, y));
			}
		}
	}
	for (map<int, double, greater<int>>::iterator it = mp.begin();it != mp.end();) {
		if (!it->second)
			it = mp.erase(it);
		else
		{
			it++;
		}
	}
	cout << mp.size();
	for (auto it = mp.begin();it != mp.end();it++) {
		printf(" %d %.1f", it->first, it->second);
	}
}