//最长回文子串
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
using namespace std;

//dp
//令dp[i][j]表示s[i]到s[j]的子串是否为回文子串，是则为1，否则为0
//如果s[i]=s[j]，只要s[i+1]到s[j-1]是回文子串，那么s[i]到s[j]也是回文子串
//如果s[i]!=s[j],那么s[i]到s[j]肯定不是回文子串
//dp[i][j]=dp[i+1][j-1]+2 s[i]==s[j]&&dp[i+1][j-1]=1
//dp[i][j]=max(dp[i+1][j],dp[i][j-1])
#define maxn 1010
int dp[maxn][maxn];//dp[i][j]表示从i到j的字符串中的最长回文串
bool dp_b[maxn][maxn];//dp[i][j]是否为回文串
string s;
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	getline(cin, s);
	memset(dp, 0, sizeof(dp));
	memset(dp_b, 0, sizeof(dp_b));
	for (int i = 0;i < s.length();++i)
	{
		dp[i][i] = 1;
		dp_b[i][i] = 1;
	}
	for (int j = 1;j < s.length();++j)
	{
		for (int i = j - 1;i >= 0;--i)
		{
			if (s[i] == s[j] && i + 1 == j)
			{
				dp_b[i + 1][j - 1] = 1;
				dp_b[i][j] = 1;
			}
			if (s[i] == s[j] && dp_b[i + 1][j - 1])
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
				dp_b[i][j] = 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			}
		}
	}
	cout << dp[0][s.length() - 1];
	return 0;
}


