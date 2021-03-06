//两数之和
//给定一个整数数组，找出这样的两个数使他们的和等于一个特定的值，算法复杂度小于O（n^2）
//1.哈希O（N）
#include <vector>
#include <map>
#include <algorithm>
vector<int> twosum(vector<int> &a, int target)
{
	map<int, int> mapping;
	vector<int> result;
	for (int i = 0;i < a.size();++i)
	{
		mapping[a[i]] = i;//记录索引
	}
	for (int i = 0;i < a.size();++i)
	{
		if (mapping.find(target - a[i]) != mapping.end()&& mapping[target - a[i]]>i)
		{
			result.push_back(i + 1);
			result.push_back(mapping[target - a[i]] + 1);
		}
	}
	return result;
}
//2.双指针O（N*lgN）
struct node 
{
	int val;
	int index;
	node(int pval, int pindex) :val(pval), index(pindex) {}
};
static bool compare(const node& left, const node& right)
{
	return left.val < right.val;
}
vector<int> twosum(vector<int>& a, int target) {
	vector<node> elements;
	vector<int> result;
	for (int i = 0;i < a.size();++i)
	{
		elements.push_back(node(a[i], i));
	}
	sort(elements.begin(), elements.end(), compare);
	int start = 0, end = a.size() - 1;
	while (start<end)
	{
		int sum = elements[start].val + elements[end].val;
		if (sum == target)
		{
			result.push_back(elements[start].index + 1);
			if (elements[start].index < elements[end].index)
			{
				result.push_back(elements[end].index + 1);
			}
			else
			{
				result.insert(result.begin(), elements[end].index + 1);
			}
			break;
		}
		else if (sum > target)
			end--;
		else
		{
			start++;
		}
	}
	return result;
}