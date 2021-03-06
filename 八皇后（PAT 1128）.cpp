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

vector<int> pos;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int cases;
	cin >> cases;
	for (int i = 0;i < cases;++i)
	{
		bool flag = 1;
		int num;
		pos.clear();
		cin >> num;
		pos.resize(num);
		for (int i = 0;i < num;++i)
		{
			cin >> pos[i];
		}
		for(int i=0;i<num;++i)
			for (int j = i + 1;j < num;++j)
			{
				if (pos[i] == pos[j] || pos[j] - pos[i] == j - i)
				{
					flag = 0;
					break;
				}
			}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
