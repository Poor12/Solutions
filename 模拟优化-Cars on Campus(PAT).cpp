#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
const int siz = 10050;
const int debug = 0;
const int range = 24 * 60 * 60;
int sumcnt[range];
string towatch(int time_point)
{
	char str[50];
	sprintf(str, "%02d:%02d:%02d", time_point / 60 / 60, time_point % (60 * 60) / 60, time_point % 60);
	return string(str);
}
struct log
{
	string name;
	int type;
	int time;
	void Print()
	{
		cout << name << ' ' << towatch(time) << ' ' << type << endl;
	}
	bool match(const log& cmper) const
	{
		return name == cmper.name&&time < cmper.time&&type == 0 && cmper.type == 1;
	}
	bool operator < (const log& cmper) const
	{
		if (name != cmper.name)
			return name < cmper.name;
		else if (time != cmper.time)
			return time < cmper.time;
		else
			return type < cmper.type;
	}
}car_log[siz];
int todec(int hour, int min, int sec)
{
	return (hour * 60 + min) * 60 + sec;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int i, j;
	int n, k;
	scanf("%d%d", &n, &k);
	string tmp;
	for (i = 0;i < n;++i)
	{
		cin >> car_log[i].name;
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		car_log[i].time = todec(hour, min, sec);
		cin >> tmp;
		car_log[i].type = tmp == "out";
	}
	sort(car_log, car_log + n);
	map<string, int> index;
	int maxrange = -1;
	for (i = 0;i < n;++i)
	{
		if (i + 1 < n&&car_log[i].match(car_log[i + 1]))
		{
			index[car_log[i].name] += car_log[i + 1].time - car_log[i].time;
			if (index[car_log[i].name] > maxrange) maxrange = index[car_log[i].name];
			sumcnt[car_log[i].time]++;
			sumcnt[car_log[i + 1].time]--;
		}
	}
	for (i = 1;i < range;++i)
		sumcnt[i] += sumcnt[i - 1];
	while (k--)
	{
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		printf("%d\n", sumcnt[todec(hour, min, sec)]);
	}
	map<string, int>::iterator it;
	for (it = index.begin();it != index.end();it++)
		if (it->second == maxrange)
			cout << it->first << ' ';
	cout << towatch(maxrange) << endl;
	return 0;
}