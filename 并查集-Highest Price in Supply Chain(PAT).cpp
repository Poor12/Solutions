#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
float p, r;
vector<int> pre;
//vector<int,vector<int>> length;
vector<int> length;
int maxlength;
void getlength(int i) {
	int p = i;
	length[p] = 1;
	while(pre[i] != -1)
	{
		length[p]++;
		i = pre[i];
	}
}
int main() {
	cin >> n >> p >> r;
	pre.resize(n);
	length.resize(n);
	for (int i = 0;i < n;++i) {
		cin >> pre[i];
	}
	for (int i = 0;i < n;++i) {
		getlength(i);
	}
	sort(length.begin(), length.end());
	auto it = length.rbegin();
	maxlength = *it;
	int num = 1;
	cout << fixed << setprecision(2) << p * pow(1+r/100, maxlength - 1) << ' ';
	for (it= length.rbegin()+1;it != length.rend();it++) {
		if (*it == maxlength)
			num++;
		else
		{
			break;
		}
	}
	cout << num;
}