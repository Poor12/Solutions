//三个数之和
//给定n个整数的数组，是否有元素a、b和c满足a+b+c=0？找出所有满足条件的集合
#include <vector>
#include <algorithm>
vector<vector<int>> threesum(vector<int>& num)
{
	sort(num.begin(), num.end());
	vector<vector<int>> result;
	int len = num.size();
	for (int i = 0;i < len;++i)
	{
		int target = 0 - num[i];
		int start = i + 1, end = len - 1;
		while (start<end)
		{
			if (num[start] + num[end] == target)
			{
				vector<int> solution;
				solution.push_back(num[i]);
				solution.push_back(num[start]);
				solution.push_back(num[end]);
				result.push_back(solution);
				start++;
				end--;
				while (start<end&&num[start]==num[start-1])//去重
				{
					start++;
				}
				while (start < end&&num[end] == num[end+1])
				{
					end--;
				}
			}
			else if (num[start] + num[end] < target)
				start++;
			else
				end--;
		}
	}
}