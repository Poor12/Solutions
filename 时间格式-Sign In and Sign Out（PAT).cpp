#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
using namespace std;
int getSTime(string time)
{
	int hour = (time[0] - 48) * 10 + (time[1] - 48);
	int minute = (time[3] - 48) * 10 + time[4] - 48;
	int s = (time[6] - 48) * 10 + time[7] - 48;
	return hour * 3600 + minute * 60 + s;
}
struct Stu
{
	//char id[50];
	string id;
	int startTime;
	int endTime;
};
int cmpStartTime(Stu a, Stu b)
{
	return a.startTime < b.startTime;
}

int cmpEndTime(Stu a, Stu b)
{
	return a.endTime > b.endTime;
}

int main() {
	freopen("D:\\data.txt", "r", stdin);
	int N = 0;
	vector<Stu> results;
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		//char tmpID[50];
		//char tmpBegTime[9];
		//char tmpEndTime[9];
		string tmpID;
		string tmpBegTime;
		string tmpEndTime;
		//scanf("%s %s %s", tmpID, tmpBegTime, tmpEndTime);
		cin >> tmpID >> tmpBegTime >> tmpEndTime;
		Stu tmp;
		tmp.id = tmpID;
		tmp.startTime = getSTime(tmpBegTime);
		tmp.endTime = getSTime(tmpEndTime);
		results.push_back(tmp);
	}

	sort(results.begin(), results.end(), cmpStartTime);
	cout << results[0].id << " ";
	sort(results.begin(), results.end(), cmpEndTime);
	cout << results[0].id << endl;
	return 0;
}
