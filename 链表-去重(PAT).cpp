#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

struct node
{
	int x;       //记录下当前的序号
	int next;   //记录下下一个节点的地址
	int index;   //记录下当前的地址
};
node list_ans[100000];
vector<node> dl;
//set<int> ds;
int dup[100000] = { 0 };//下标为地址
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	int start, num,temp_address;
	cin >> start >> num;
	for (int i = 0;i < num;++i)
	{
		cin >> temp_address;
		list_ans[temp_address].index = temp_address;
		cin >> list_ans[temp_address].x >> list_ans[temp_address].next;
	}
	int k = start,pre=INT16_MAX,data;
	bool first = 1;
	while (k!=-1)
	{
		data = list_ans[k].x;
		if (find(ds.begin(),ds.end(),data)==ds.end()&& find(ds.begin(), ds.end(), -data) == ds.end())
		{
			if (first != 1)
				printf("%05d\n",list_ans[k].index);
			//cout << list_ans[k].index << ' ' << list_ans[k].x << ' ';
			printf("%05d %d ", list_ans[k].index, list_ans[k].x);
			first = 0;
			ds.insert(data);
		}
		else
		{
			dl.push_back(list_ans[k]);
		}
		pre = data;
		k = list_ans[k].next;
	}
	cout << -1 << endl;
	
	for (int i = 0;i < dl.size();++i)
	{
		if (i != 0)
			//cout << dl[i].index << endl;
			printf("%05d\n", dl[i].index);
		//cout << dl[i].index <<" "<< dl[i].x<<" ";
		printf("%05d %d ", dl[i].index, dl[i].x);
	}
	cout << -1;
	return 0;
	
}