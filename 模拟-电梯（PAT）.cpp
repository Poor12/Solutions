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
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
const int maxn = 10001;
int a[maxn], dp[maxn];
int main() {
	int num;
	cin >> num;
	vector<int> list(num);
	for (int i = 0;i < list.size();++i) {
		cin >> list[i];
	}
	int pre = 0, time = 0;
	for (int i = 0;i < list.size();++i) {
		if (list[i] >= pre) {
			time += (list[i] - pre) * 6 + 5;
			pre = list[i];
		}
		else {
			time += (pre - list[i]) * 4 + 5;
			pre = list[i];
		}
	}
	cout << time;
	return 0;
}