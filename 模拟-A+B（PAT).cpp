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
using namespace std;

int main() {
	freopen("D:\\data.txt", "r", stdin);
	int num1, num2;
	cin >> num1 >> num2;
	int sum = num1 + num2;
	vector<int> qian;
	if (sum<1000 && sum>-1000)
		cout << sum;
	else {
		//int hou=sum%1000;
		int summ = abs(sum);
		int digit;
		for (int x = 1;summ / x != 0;x = x * 10) {
			digit = summ / x % 10;
			qian.push_back(digit);

		}
		if (sum < 0)
			cout << '-';
		int count = 0;
		for (auto it = qian.rbegin();it != qian.rend();++it) {
			cout << *it;
			count++;
			if ((qian.size() - count) % 3 == 0 && it != qian.rend() - 1)
				cout << ',';
		}
	}
	return 0;
}