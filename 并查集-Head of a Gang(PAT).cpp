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
using namespace std;

struct person
{
	string name;
	int weight, father;
	person(string _name, int _weight, int _father)
	{
		name = _name;
		weight = _weight;
		father = _father;
	}
};
struct group
{
	string head;
	int numofperson;
	int maxweight, sumweight;
	group()
	{
		numofperson = 0;
		sumweight = 0;
		maxweight = 0;
	}
	bool operator <(const group& that) const
	{
		return (head < that.head);
	}
};
vector<person> persons;
int getfather(int x)
{
	if (x != persons[x].father)
		persons[x].father = getfather(persons[x].father);
	return persons[x].father;
}
void unionSet(int x, int y)
{
	x = getfather(x);
	y = getfather(y);
	if (x != y)
		persons[x].father = y;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	map<string, int> link;
	vector<group> groups;
	string str1, str2;
	int weight,idx1,idx2;
	while (n--)
	{
		cin >> str1 >> str2 >> weight;
		if (link.count(str1) && link.count(str2))
		{
			idx1 = link[str1];
			idx2 = link[str2];
			persons[idx1].weight += weight;
			persons[idx2].weight += weight;
		}
		else if (link.count(str1) && !link.count(str2))
		{
			idx1 = link[str1];
			idx2 = persons.size();
			link[str2] = idx2;
			persons.push_back(person(str2, weight, idx2));
			groups.push_back(group());
			persons[idx1].weight += weight;
		}
		else if (!link.count(str1) && link.count(str2))
		{
			idx1 = persons.size();
			idx2 = link[str2];
			link[str1] = idx1;
			persons.push_back(person(str1, weight, idx1));
			groups.push_back(group());
			persons[idx2].weight += weight;
		}
		else
		{
			idx1 = persons.size();
			link[str1] = idx1;
			idx2 = idx1 + 1;
			link[str2] = idx2;
			persons.push_back(person(str1, weight, idx1));
			persons.push_back(person(str2, weight, idx2));
			groups.push_back(group());
			groups.push_back(group());
		}
		unionSet(idx1, idx2);
		groups[idx1].sumweight += weight;
	}
	int tf;
	int num = persons.size();
	set<group> result;
	for (int i = 0;i < num;++i)
	{
		tf = getfather(i);
		groups[tf].numofperson++;
		if (tf != i)
		{
			groups[tf].sumweight += groups[i].sumweight;
		}
		if (groups[tf].maxweight < persons[i].weight)
		{
			groups[tf].maxweight = persons[i].weight;
			groups[tf].head = persons[i].name;
		}
	}
	for (int i = 0;i < num;++i)
	{
		if (groups[i].sumweight > k&&groups[i].numofperson > 2)
		{
			result.insert(groups[i]);
		}
	}
	cout << result.size() << endl;
	for (auto it = result.begin();it != result.end();it++)
	{
		cout << it->head << " " << it->numofperson << endl;
	}

	return 0;
}
