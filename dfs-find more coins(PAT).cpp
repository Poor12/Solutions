#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
using namespace std;
int mark[10010];

vector<int> finalresult;
void dfs2(vector<int> input, int index, int sum, int m)
{
	if (sum > m || index > input.size() - 1 || input[index] > m)
		return;
	if (sum == m && finalresult.size() == 0)
	{
		for (int i = 0;i < input.size();++i)
			if (mark[i] > 0)
				finalresult.push_back(input[i]);
		return;
	}
	mark[index]++;
	dfs2(input, index + 1, sum + input[index], m);
	mark[index]--;
	dfs2(input, index + 1, sum, m);

}
int main() {
	freopen("D:\\data.txt", "r", stdin);

	memset(mark, 0, sizeof(mark));

	vector<int> input;

	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0;i < N;i++)

	{

		int tmp;

		scanf("%d", &tmp);

		input.push_back(tmp);

	}
	sort(input.begin(), input.end());
	//if (input.size() == 1 && M == input[0])
	//{
	//	cout << M << endl;
	//	return 0;
	//}
	dfs2(input, 0, 0, M);
	if (finalresult.size() == 0)
	{
		cout << "no solution";
	}
	else
	{
		for (int i = 0;i < finalresult.size();++i)
		{
			cout << finalresult[i];
			if (i != finalresult.size() - 1)
				cout << " ";
		}
	}
	cout << endl;
	return 0;
}