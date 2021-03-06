
//给定一个字符串数组，返回能够形成anagram的所有字符串组合
#include <string>
#include <vector>
#include <map>
long footprint(string str)
{
	int index[26];
	memset(index, 0, sizeof(index));
	for (int i = 0;i < str.length();++i)
	{
		index[str[i] - 'a']++;
	}
	long footp = 0;
	int feed = 7;
	for (int i = 0;i < 26;++i)
		footp = footp * feed + index[i];
	return footp;
}
vector<vector<string> > anagrams(vector<string>& str)
{
	vector<vector<string>> result;
	if (str.size() == 0) return result;
	map<long, vector<string>> smap;
	for (int i = 0;i < str.size();++i)
	{
		smap[footprint(str[i])].push_back(str[i]);
	}
	for (auto it = smap.begin();it != smap.end();it++)
	{
		if (it->second.size() <= 1)
			continue;
		vector<string> a;
		a.insert(a.begin(),it->second.begin(), it->second.end());
		result.push_back(a);
	}
	return result;
}