//购买股票的最佳时机
//1.只允许你完成一次交易
#include <vector>
int maxprofit(vector<int>& prices)
{
	int minv = INT_MAX;
	int max = 0;
	int diff = 0;
	for (int i = 0;i < prices.size();++i)
	{
		if (prices[i] < minv)
			minv = prices[i];
		diff = prices[i] - minv;
		if (max < diff)
			max = diff;
	}
	return max;
}

//2.任意多次交易,把所有交易差值大于0的值相加
int maxprofit1(vector<int>& prices)
{
	int max = 0;
	int sum = 0;
	for (int i = 1;i < prices.size();++i)
	{
		int diff = prices[i] - prices[i - 1];
		if (diff > 0)
			sum += diff;
	}
	return sum;
}

//3.最多进行两次交易
//finalmaxprofit=max(maxprofit(0,i)+maxprofit(i+1,n)) 0<=i<n
int maxprofit2(vector<int>& prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<int> maxfromleft(prices.size(), 0);
	vector<int> maxfromright(prices.size(), 0);
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0;i < prices.size();++i)
	{
		if (min > prices[i])
			min = prices[i];
		int temp = prices[i] - min;
		if (temp > max)
			max = temp;
		maxfromleft[i] = max;
	}
	int maxx = INT_MIN;
	max = INT_MIN;
	for (int i = prices.size() - 1;i >= 0;--i)
	{
		if (maxx < prices[i]) maxx = prices[i];
		int temp = maxx - prices[i];
		if (temp > max) max = temp;
		maxfromright[i] = max;
	}
	int maxprofit = INT_MIN;
	for (int i = 0;i < prices.size() - 1;i++)
	{
		int sum = maxfromleft[i] + maxfromright[i + 1];
		if (sum > maxprofit) maxprofit = sum;
	}
	if (maxprofit < maxfromright[0])
		maxprofit = maxfromright[0];
	return maxprofit;
}