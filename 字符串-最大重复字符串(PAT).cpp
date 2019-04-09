#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, int> hashh;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	string str;
	getline(cin,str);
	bool isword = false;
	int start, end;
	for (int i = 0;i < str.size();++i)
	{
		if ((str[i] >= '0'&&str[i] <= '9') || (str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
				str[i] = 'a' + str[i] - 'A';
			if (isword == 0)
			{
				isword = 1;
				start = i;
			}
		}
		else
		{
			if (isword)
			{
				end = i;
				string s = str.substr(start, end - start);
				if (hashh.find(s) == hashh.end())
					hashh[s] = 1;
				else
					hashh[s]++;
				isword = 0;
				
			}
		}
	}

	
	int maxm = 0;
	string maxmm;
	for (auto it = hashh.begin();it != hashh.end();it++)
	{
		if (it->second > maxm)
		{
			maxmm = it->first;
			maxm = it->second;
		}
	}
	cout << maxmm << " " << maxm;
	
	
	return 0;
}