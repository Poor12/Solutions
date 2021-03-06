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

int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int N, next = 0;
	cin >> N;
	vector<int> org(N), cur(N);
	enum property { insert, merge }pro = insert;
	for (int i = 0; i < N; ++i)
		cin >> org[i];
	for (int i = 0; i < N; ++i)
		cin >> cur[i];

	for (unsigned int i = 1; i < cur.size(); ++i) {
		if (cur[i] < cur[i - 1]) {
			next = i;
			for (; i < cur.size(); ++i) {
				if (cur[i] != org[i]) {//走到这里，说明就是归并了
					pro = merge;
					break;
				}
			}
		}
		if (pro == merge)
			break;
	}
	if (pro == insert) {
		cout << "Insertion Sort" << endl;
		sort(cur.begin(), cur.begin() + next+1);
		for (int i = 0;i < cur.size();++i)
			cout << cur[i] << " ";
	}
	else {
		cout << "Merge Sort" << endl;
		for (unsigned int i = 0; i < cur.size() / (next * 2); ++i)
			sort(cur.begin() + i * next * 2, cur.begin() + i * next * 2 + next * 2);
		for (unsigned int i = 0; i < cur.size(); ++i) {
			cout << cur[i];
			if (i != cur.size() - 1)
				cout << " ";
		}
	}
	return 0;
}