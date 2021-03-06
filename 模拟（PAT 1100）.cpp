
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
string unitdigit[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string tendigit[13] = { "tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
string numtostring[170];
map<string, int> stringtonum;
void init()
{
	for (int i = 0;i <= 12;++i)
	{
		numtostring[i] = unitdigit[i];
		stringtonum[unitdigit[i]] = i;//十位数为0
		numtostring[i * 13] = tendigit[i];
		stringtonum[tendigit[i]] = i * 13;//个位数为0
	}
	for (int i = 1;i <= 12;++i)
	{
		for (int j = 1;j <= 12;++j)
		{
			string str = tendigit[i] + " " + unitdigit[j];
			numtostring[i * 13 + j] = str;
			stringtonum[str] = i * 13 + j;
		}
	}
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	init();
	int n;
	scanf("%d%*c", &n);
	while (n--)
	{
		string str;
		getline(cin, str);
		if (str[0] >= '0'&&str[0] <= '9')
		{
			int num = 0;
			for (int i = 0;i < str.length();++i)
				num = num * 10 + (str[i] - '0');
			cout << numtostring[num] << endl;
		}
		else
			cout << stringtonum[str] << endl;
	}
	return 0;
	
}
