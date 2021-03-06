//给定一个字符串s和字符串t，计算s中的t的不同子序列的数目
//s=rabbbit，t=rabbit，返回3
//我们要求的就是长度为i的子串在长度为j的母串中出现的次数，设为t[i][j]
//t[i][j]=t[i][j-1] if t[i]!=s[j]
// or =t[i][j-1]+t[i-1][j-1] if t[i]==s[j]
int numDistinct(string s, string t)
{
	int match[200];
	if (s.size() < t.size()) return 0;
	match[0] = 1;
	for (int i = 1;i <= t.size();++i)
		match[i] = 0;
	for (int i = 1;i <= s.size();++i)
		for (int j = t.size();j >= 1;--j)
			if (s[i - 1] == t[j - 1])
				match[j] += match[j - 1];
	return match[t.size()];
}
