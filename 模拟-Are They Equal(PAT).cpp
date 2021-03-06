#include <iostream>
#include <string>
using namespace std;
int n;
string get(string s, int &e)
{
	int i = 0;//下标
	while (s.size()>0&&s[0]=='0')
	{
		s.erase(s.begin());
	}
	if (s[0] == '.')
	{
		s.erase(s.begin());
		while (s.size() > 0 && s[0] == '0')
		{
			s.erase(s.begin());
			e--;
		}
	}
	else
	{
		while (i<s.size()&&s[i]!='.')
		{
			i++;
			e++;
		}
		if (s[i] == '.')
			s.erase(s.begin() + i);
	}
	if (s.size() == 0)
		e = 0;
	int num = 0, k = 0;
	string res;
	while (num < n)
	{
		if (k < s.size())
			res += s[k++];
		else
			res += '0';
		num++;
	}
	return res;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	string s1, s2;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s1 = get(s1, e1);
	s2 = get(s2, e2);
	if (s1 == s2 && e1 == e2)
		cout << "YES 0." << s1 << "*10^" << e1;
	else
		cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2;
	return 0;
}
