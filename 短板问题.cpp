//给定n个非负的数a1...an，其中每个整数表示坐标为（i，ai）的一个点。从（i，ai）到（i，0）的两点之间绘制线段i，从而绘制出n条垂直的线段。找出两条线段，他们与x轴一起形成一个容器，这个容器所能装的水最多。
//容器的体积取决于短板
#include <vector>
#include <algorithm>
int maxarea(vector<int>& height)
{
	int start = 0;
	int end = height.size() - 1;
	int maxv = INT_MIN;
	while (start<end)
	{
		int contain = min(height[end], height[start])*(end - start);
		maxv = max(maxv, contain);
		if (height[start] <= height[end])
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	return maxv;
}