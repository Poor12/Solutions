#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
int school[101];

struct stu {
	int num;
	int ge;
	int gi;
	int fi;
	vector<int> choices;
	stu(int n,int gee, int gii, int fii)
	{
		num = n;
		ge = gee;
		gi = gii;
		fi = fii;
	}
};
vector<stu> schooll[101];
vector<stu> s;
bool compare(stu &a, stu &b)
{
	if (a.fi != b.fi)
		return a.fi > b.fi;
	else
		return a.ge > b.ge;
}
bool compare1(stu &a, stu &b)
{
	return a.num < b.num;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 0;i < m;++i)
	{
		cin >> school[i];
	}
	for (int i = 0;i < n;++i)
	{
		int tmpge, tmpgi,ch;
		cin >> tmpge >> tmpgi;
		stu ss = stu(i,tmpge, tmpgi, (tmpge + tmpgi));
		for (int i = 0;i < k;++i)
		{
			cin >> ch;
			ss.choices.push_back(ch);
		}
		s.push_back(ss);
	}
	sort(s.begin(), s.end(), compare);
	
	for (int i = 0;i < s.size();++i)
	{
		for (int j = 0;j < k;++j)
		{
			if (schooll[s[i].choices[j]].size() < school[s[i].choices[j]]||(s[i].fi==(*(schooll[s[i].choices[j]].end()-1)).fi&&s[i].ge == (*(schooll[s[i].choices[j]].end() - 1)).ge))
			{
				schooll[s[i].choices[j]].push_back(s[i]);
				break;
			}
		}
	}
	for (int i = 0;i < m;++i)
	{
		if (schooll[i].size() == 0)
			cout << endl;
		else
		{
			sort(schooll[i].begin(), schooll[i].end(),compare1);
			for (int j = 0;j < schooll[i].size();++j)
			{
				cout << (j == 0 ? "" : " ") << schooll[i][j].num;
			}
			cout << endl;
		}
	}
	return 0;	
}