//解码方法
//包含了字母a-z的一条消息，将使用如下的映射来编码成数字 a->1 z->26
//例，给定编码消息‘12’，它将会解码成ab或l，共两种
//count[i]=count[i-1] if s[i-1] is a valid char
//or =count[i-1]+count[i-2] if s[i-1] and s[i-2] together is still a valid char
int check(char one)
{
	return (one != '0') ? 1 : 0;
}
int check(char one, char two)
{
	return (one == '1' || (one == '2'&&two <= '6')) ? 1 : 0;
}
int numDecording(string s)
{
	if (s.empty() || s[0] == '0') return 0;
	if (s.size() == 1) return check(s[0]);
	int fn = 0, fn_1 = 0, fn_2 = 1;
	fn_1 = (check(s[0])*check(s[1])) + check(s[0], s[1]);
	for (int i = 2;i < s.size();++i)
	{
		if (check(s[i])) fn += fn_1;
		if (check(s[i - 1], s[i])) fn += fn_2;
		if (fn == 0)
			return 0;
		fn_2 = fn_1;
		fn_1 = fn;
		fn = 0;
	}
	return fn_1;
}