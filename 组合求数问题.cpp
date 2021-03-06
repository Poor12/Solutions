//给定候选数字集合c和一个目标数字t，找出c中所有的唯一的组合，使得候选数字的加和等于t
//可以从c中无限次选择相同的重复的数字
#include <vector>
#include <algorithm>
void getcombinations(vector<int>& candidates, int& sum, int level, int target, vector<int>& solution, vector<vector<int>>& result)
{
	if (sum > target)
		return;
	if (sum == target) {
		result.push_back(solution);
		return;
	}
	for (int i = level;i < candidates.size();++i)
	{
		sum += candidates[i];
		solution.push_back(candidates[i]);
		getcombinations(candidates, sum, i, target, solution, result);
		solution.pop_back();
		sum -= candidates[i];
	}
}
vector<vector<int>> combinationsum(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> solution;
	int sum = 0;
	sort(candidates.begin(), candidates.end());
	getcombinations(candidates, sum, 0, target, solution, result);
}

//c中的每个数字只能选择一次
void getcombinations2(vector<int>& candidates, int& sum, int level, int target, vector<int>& solution, vector<vector<int>>& result)
{
	if (sum > target)
		return;
	if (sum == target) {
		result.push_back(solution);
		return;
	}
	for (int i = level;i < candidates.size();++i)
	{
		sum += candidates[i];
		solution.push_back(candidates[i]);
		getcombinations(candidates, sum, i+1, target, solution, result);
		solution.pop_back();
		sum -= candidates[i];
		while (i<candidates.size()-1&&candidates[i]==candidates[i+1])//优化条件
		{
			i++;
		}
	}
}
vector<vector<int>> combinationsum2(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> solution;
	int sum = 0;
	sort(candidates.begin(), candidates.end());
	getcombinations2(candidates, sum, 0, target, solution, result);
}

//给定两个整数n和k，返回1...n中的k个数的所有可能情况
void getcombine(int n, int k, int level, vector<int>& solution, vector<vector<int>>& result)
{
	if (solution.size() == k)
	{
		result.push_back(solution);
		return;
	}
	for (int i = level;i <= n;++i)
	{
		solution.push_back(i);
		getcombine(n, k, i + 1, solution, result);
		solution.pop_back();
	}
}
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> result;
	vector<int> solution;
	getcombine(n, k, 0, solution, result);
	return result;
}