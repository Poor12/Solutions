//三个数最接近
//给定n个整数的数组，给出target找出最接近target的三数之和
#include <vector>
#include <algorithm>
int threesum(vector<int>& num,int target)
{
	sort(num.begin(), num.end());
	int len = num.size();
	int minv = INFINITY, record;
	for (int i = 0;i < len;++i)
	{
		int start = i + 1, end = len - 1;
		while (start<end)
		{
			int sum = num[start] + num[end];
			if ( sum== target)
			{
				minv = 0;
				record = sum;
				break;
			}
			else if (sum < target)
			{
				if (target - sum < minv)
				{
					minv = target - sum;
					record = sum;
				}
				start++;
			}	
			else
			{
				if (sum-target < minv)
				{
					minv = sum-target;
					record = sum;
				}
				end--;
			}
				
		}
		if (record == target) break;
		while (i<len-1&&num[i]==num[i+1])
		{
			i++;
		}
	}
	return record;
}