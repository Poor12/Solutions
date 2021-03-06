//单词拆分
//给定字符串s和单词的一个字典dict，判断s是否能够分段为一个和多个字典单词所组成的空格隔开的序列
//给定s="leetcode",dict=["leet","code"],返回1
#include <unordered_set>
bool wordbreak(string s, unordered_set<string>& dict) {
	string s2 = '#' + s;
	int len = s2.size();
	vector<bool> possible(len, 0);
	possible[0] = 1;
	for (int i = 1;i < len;++i)
	{
		for (int k = 0;k < i;++k)
		{
			possible[i] = possible[k] && dict.find(s2.substr(k + 1, i - k)) != dict.end();
			if (possible[i]) break;
		}
	}
	return possible[len - 1];
}
  