#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int n, k;
string isin;
struct ti
{
	int hour, minute, second;
	bool operator<(const ti b) const
	{
		return hour != b.hour ? hour < b.hour : (minute != b.minute ? minute < b.minute : second < b.second);
	}
	bool operator<=(const ti b) const
	{
		return hour != b.hour ? hour <= b.hour : (minute != b.minute ? minute <= b.minute : second <= b.second);
	}
	bool operator>(const ti b) const
	{
		return hour != b.hour ? hour > b.hour : (minute != b.minute ? minute > b.minute : second > b.second);
	}
	bool operator>=(const ti b) const
	{
		return hour != b.hour ? hour >= b.hour : (minute != b.minute ? minute >= b.minute : second >= b.second);
	}
	bool operator==(const ti b) const
	{
		return hour == b.hour && minute == b.minute &&second == b.second;
	}
};
struct record {
	string car;
	struct ti t;
	bool flag;
};
struct tl {
	string car;
	ti t;
	ti begintime;
	ti endtime;

};
vector<record> res;
queue<record> qres;
vector<ti> times;
vector<tl> result;
vector<string> maxcar;
bool cmp(record &r1, record &r2) {
	if (r1.car != r2.car)
		return r1.car < r2.car;
	else
	{
		if (r1.t.hour != r2.t.hour)
			return r1.t.hour < r2.t.hour;
		else
		{
			if (r1.t.minute != r2.t.minute)
				return r1.t.minute < r2.t.minute;
			else
			{
				return r1.t.second < r2.t.second;
			}
		}
	}
}
bool cmp2(tl &ttl1, tl &ttl2) {
	return ttl1.t == ttl2.t ? ttl1.car > ttl2.car:ttl1.t < ttl2.t;
}

struct ti getlength(ti t1, ti t2) {
	ti t;
	if (t2.second > t1.second) {
		t.second = t2.second - t1.second;
	}
	else
	{
		t.second = t2.second + 60 - t1.second;
		t2.minute--;
	}
	if (t2.minute > t1.minute) {
		t.minute = t2.minute - t1.minute;
	}
	else
	{
		t.minute = t2.minute + 60 - t1.minute;
		t2.hour--;
	}
	t.hour = t2.hour - t1.hour;
	return t;
}
struct ti getsum(ti t1, ti t2) {
	ti t;
	if (t2.second + t1.second < 60) {
		t.second = t2.second + t1.second;
	}
	else
	{
		t.second = t2.second - 60 + t1.second;
		t2.minute++;
	}
	if (t2.minute + t1.minute < 60) {
		t.minute = t2.minute + t1.minute;
	}
	else
	{
		t.minute = t2.minute - 60 + t1.minute;
		t2.hour++;
	}
	t.hour = t2.hour + t1.hour;
	return t;
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	cin >> n >> k;
	res.resize(n);
	times.resize(k);
	for (int i = 0;i < n;++i) {
		cin >> res[i].car;
		scanf("%d:%d:%d", &res[i].t.hour, &res[i].t.minute, &res[i].t.second);
		cin >> isin;
		if (isin[0] == 'i')
			res[i].flag = 1;
		else
		{
			res[i].flag = 0;
		}
	}
	for (int i = 0;i < k;++i) {
		scanf("%d:%d:%d", &times[i].hour, &times[i].minute, &times[i].second);
	}
	sort(res.begin(), res.end(), cmp);
	for (auto it = res.begin();it != res.end();it++) {
		qres.push(*it);
	}
	record t1;int f = 0;
	while (!qres.empty())
	{
		record r = qres.front();
		if (r.flag == 0)
		{
			if (f != 0 && t1.car == r.car) {
				ti length = getlength(t1.t, r.t);
				tl ttl;ttl.car = r.car;ttl.begintime = t1.t;ttl.endtime = r.t;ttl.t = length;
				result.push_back(ttl);
				f = 0;
			}
			qres.pop();
		}
		else
		{
			t1 = r;
			f = 1;
			qres.pop();
		}
	}
	sort(result.begin(), result.end(), cmp2);
	set<string> car;
	for (int i = 0;i < k;++i) {
		car.clear();
		for (int j = 0;j < result.size();++j) {
			if (times[i] < result[j].endtime&&times[i] >= result[j].begintime)
				car.insert(result[j].car);
		}
		cout << car.size() << endl;
	}
	map<string, ti> m;
	for (int i = 0;i < result.size();++i) {
		if (m.find(result[i].car) == m.end())
			m.insert(make_pair(result[i].car, result[i].t));
		else
		{
			m[result[i].car] = getsum((m[result[i].car]), (result[i].t));
		}
	}

	ti length = (*max_element(m.begin(), m.end())).second;
	auto it = m.begin();
	//maxcar.push_back(it->first);
	for (;it != m.end();++it) {
		if (it->second == length) {
			maxcar.push_back(it->first);
		}

	}
	for (int i = 0;i < maxcar.size();++i) {
		cout << maxcar[i] << " ";
	}
	printf("%02d:%02d:%02d", length.hour, length.minute, length.second);
}
