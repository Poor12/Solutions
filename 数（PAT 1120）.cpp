#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
#define nn 100005


int main() {
	//freopen("D:\\data.txt", "r", stdin);
	set<int> s;
	int n, i, j;
	string str[nn];
	scanf("%d", &n);
	for (i = 0;i < n;++i)
		cin >> str[i];
	int sum = 0;
	for (i = 0;i < n;++i)
	{
		for (j = 0;j < str[i].size();++j)
			sum += str[i][j] - '0';
		s.insert(sum);
		sum = 0;
	}
	set<int>::iterator it;
	cout << s.size() << endl;
	for (it = s.begin();it != s.end();it++)
	{
		if (it == (--s.end()))
			cout << *it << endl;
		else
			cout << *it << " ";
	}
	return 0;
}
