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


int main() {
	freopen("D:\\data.txt", "r", stdin);
	int m = 0, n = 0, s = 0;
	cin >> m >> n >> s;
	vector<string> forward(m + 1);
	for (int i = 1;i <= m;++i)
	{
		string nickname;
		cin >> nickname;
		forward[i] = nickname;
	}
	if (s > m)
		cout << "Keep going..." << endl;
	else
	{
		map<string, bool> winner;
		cout << forward[s] << endl;
		winner[forward[s]] = 1;
		int i = s;
		while (i < m)
		{
			int cnt = 0;
			while (i < m&&cnt < n)
			{
				i++;
				if (winner[forward[i]] == 0)
					cnt++;
			}
			if (n == cnt)
			{
				cout << forward[i] << endl;
				winner[forward[i]] = 1;
			}
		}
	}
	return 0;
}
