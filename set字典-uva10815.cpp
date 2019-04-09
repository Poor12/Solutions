#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <sstream>
using namespace std;
set<string> dict;
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	string s, buf;
	while (cin >> s)
	{
		for (int i = 0;i < s.length();++i)
		{
			if (isalpha(s[i]))
				s[i] = tolower(s[i]);
			else
				s[i] = ' ';
		}
		cout << s << endl;
		stringstream ss(s);//将左起和右起的空格去掉
		while (ss >> buf)
			dict.insert(buf);
	}
	for (auto it = dict.begin();it != dict.end();it++)
	{
		cout << *it << "\n";
	}
	return 0;
}


