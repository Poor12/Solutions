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

#define M 10005
#define INF 0x7fffffff
struct student
{
	int pg, mg, fg, g;
	string name;
};
map<string, student> Map;
bool cmp(student a, student b)
{
	if (a.g > b.g)
		return 1;
	else if (a.g == b.g)
		return a.name < b.name;
	else
		return false;
}
int getint(double x)
{
	if (x - int(x) >= 0.5)
		x = x + 1;
	return x;
}
int main() {
	int n, i, k;
	int a, b, c;
	int j, grade;
	char name[25];
	string s;
	student stu;
	scanf("%d%d%d", &a, &b, &c);
	while (a--)
	{
		cin >> s >> grade;
		stu.fg = stu.mg = stu.g = -1;
		stu.pg = grade;
		stu.name = s;
		Map[s] = stu;
	}
	while (b--)
	{
		cin >> s >> grade;
		if (Map.find(s) == Map.end())
		{
			stu.name = s;
			stu.fg = stu.pg = stu.g = -1;
			stu.mg = grade;
		}
		else
		{
			stu = Map[s];
			stu.mg = grade;
		}
		Map[s] = stu;
	}
	while (c--)
	{
		cin >> s >> grade;
		if (Map.find(s) == Map.end())
		{
			stu.name = s;
			stu.mg = stu.pg = stu.g = -1;
			stu.fg = grade;
		}
		else
		{
			stu = Map[s];
			stu.fg = grade;
		}
		Map[s] = stu;
	}
	int G;
	vector<student> ans;
	for (map<string, student>::iterator it = Map.begin();it != Map.end();it++)
	{
		stu = it->second;
		if (stu.pg < 200)
			continue;
		if (stu.mg == -1 && stu.fg == -1)
			continue;
		else
		{
			if (stu.fg == -1)
				stu.g = getint(double(stu.mg) * 4 / 10);
			else
				stu.g = getint(double(stu.mg) * 4 / 10 + double(stu.fg) * 6 / 10);
		}
		if (stu.g >= 60 && stu.g <= 100)
			ans.push_back(stu);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (i = 0;i < ans.size();++i)
	{
		stu = ans[i];
		printf("%s %d %d %d %d\n", stu.name.c_str(), stu.pg, stu.mg, stu.fg, stu.g);
	}
	return 0;

}
