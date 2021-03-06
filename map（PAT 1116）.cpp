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
bool isPrime(int x)
{
	if (x < 2)
		return 0;
	int r = floor(sqrt(x) + 0.5);
	for (int i = 2;i <= r;++i)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int n;
	scanf("%d\n", &n);
	map<string, int> mp;
	for (int i = 1;i <= n;++i)
	{
		string s;
		cin >> s;
		mp[s] = i;
	}
	int k;
	scanf("%d\n", &k);
	while (k--)
	{
		string s;
		cin >> s;
		cout << s << ":";
		if (mp.count(s))
		{
			if (mp[s] == 0)
				puts("Checked");
			else if (mp[s] == 1)
				puts("Mystery Award");
			else if (isPrime(mp[s]))
				puts("Minion");
			else
				puts("Chocolate");
			mp[s] = 0;

		}
		else
			puts("Are you kidding?");
	}
	return 0;
}
