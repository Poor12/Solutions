#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

const int maxcol = 60;
const int maxn = 100 + 5;
string filenames[maxn];

void print(const string& s, int len, char extra)
{
	cout << s;
	for (int i = 0;i < len - s.length();++i)
		cout << extra;
}
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	int n;
	while (cin >> n)
	{
		int m = 0;
		for (int i = 0;i < n;++i)
		{
			cin >> filenames[i];
			m = max(m, (int)filenames[i].length());
		}
		//计算列数和行数
		int cols = (maxcol - m) / (m + 2) + 1, rows = (n - 1) / cols + 1;
		printf("", 60, '-');
		cout << "\n";
		sort(filenames, filenames + n);//排序
		for (int r = 0;r < rows;++r)
		{
			for (int c = 0;c < cols;++c)
			{
				int idx = c * rows + r;
				if (idx < n)
					print(filenames[idx], c == cols - 1 ? m : m + 2, ' ');
			}
			cout << "\n";
		}
	}
	return 0;
}