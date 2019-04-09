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
string s;
int k, book[525];
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	cin >> k >> s;
	for (int i = 0, j = 0;j < s.size();i = j)
	{
		while (s[++j] == s[i]);
		if ((j - i) % k != 0)
			book[s[i]] = -1;
		else if (!book[s[i]])
			book[s[i]] = 1;
	}
	for (int i = 0;i < s.size();++i)
	{
		if (book[s[i]] == 1)
			cout << s[i], book[s[i]] = 2;
	}
	cout << endl;
	for (int i = 0;i < s.size();++i)
	{
		cout << s[i];
		if (book[s[i]] == 2)
			i += k - 1;
	}
	return 0;
}