#define INF 0x3fffffff
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
struct stu
{
	int id;
	int totalscore = 0;
	map<int, int> scores;
	int perfectnum = 0;
	bool submit = false;
};
bool cmp(stu &a, stu &b)
{
	if (a.totalscore != b.totalscore)
		return a.totalscore > b.totalscore;
	else if (a.perfectnum != b.perfectnum)
		return a.perfectnum > b.perfectnum;
	else
		return a.id < b.id;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int n, k, s;
	while (cin >> n >> k >> s)
	{
		vector<int> allscores(k);
		vector<stu> students(n);
		for (int i = 0;i < n;++i)
		{
			students[i].id = i + 1;
			for (int j = 0;j < k;++j)
				students[i].scores[j + 1] = -2;
		}
		for (int i = 0;i < k;++i)
		{
			cin >> allscores[i];
		}
		int id, problem, score;
		for (int i = 0;i < s;++i)
		{
			cin >> id >> problem >> score;
			if (score >= students[id - 1].scores[problem])
			{
				if (score >= 0)
					students[id - 1].submit = 1;
				students[id - 1].scores[problem] = score;
			}
		}
		for (int i = 0;i < n;++i)
		{
			for (auto it = students[i].scores.begin();it != students[i].scores.end();it++)
			{
				if (it->second >= 0)
					students[i].totalscore += it->second;
				if (allscores[it->first - 1] == it->second)
					students[i].perfectnum++;
			}
		}
		sort(students.begin(), students.end(), cmp);
		int rank = 1;
		int countnum = 0;
		int lastscore = 0;
		for (int i = 0;i < n;++i)
		{
			if (students[i].totalscore == 0)
			{
				if (!students[i].submit)
					continue;
			}
			countnum++;
			if (i != 0 && students[i].totalscore != lastscore)
				rank = countnum;
			cout << rank << " ";
			cout << setfill('0') << setw(5) << students[i].id << " ";
			cout << students[i].totalscore;
			for (int j = 1;j <= k;++j)
			{
				if (students[i].scores[j] != -2)
				{
					cout << " " << (students[i].scores[j] == -1 ? 0 : students[i].scores[j]);
				}
				else
					cout << "-";
			}
			lastscore = students[i].totalscore;
			cout << endl;
		}
	}
	return 0;
}

