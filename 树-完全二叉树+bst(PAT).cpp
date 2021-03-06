#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> inorder;
vector<int> re;
int n;
int idx = 0;
void inord(int root)
{
	if (root > n)
		return;
	inord(root * 2);
	re[root] = inorder[idx++];
	inord(root * 2 + 1);
}
int main()
{
	cin >> n;
	re.resize(n + 1);
	for (int i = 1;i <=n;++i)
	{
		int data;
		cin >> data;
		inorder.push_back(data);
	}
	sort(inorder.begin(), inorder.end());
	inord(1);
	for (int i = 1;i <= n;++i)
		cout << (i == 1 ? "" : " ") << re[i];
}