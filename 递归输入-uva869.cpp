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
using namespace std;
//输入一个子天平，返回天平是否平衡，参数w修改为子天平的总质量
bool solve(int& w)
{
	int w1, d1, w2, d2;
	bool b1 = 1, b2 = 1;
	cin >> w1 >> d1 >> w2 >> d2;
	if (!w1)
		b1 = solve(w1);
	if (!w2)
		b2 = solve(w2);
	//w = w1 + w2;
	return b1 && b2 && (w1*d1 == w2 * d2);
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int t, w;
	cin >> t;
	while (t--)
	{
		if (solve(w))
			cout << "yes\n";
		else
			cout << "no\n";
		if (t)
			cout << "\n";
	}
	return 0;
}
