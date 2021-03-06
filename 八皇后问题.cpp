#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//八皇后问题--回溯

//用queens[]存储每个皇后的位置
//例如：queens[m]=n
#define max 8
int sum = 0;
class QueenPuzzle
{
public:
	int queens[max];
	void printOut() {
		for (int i = 0;i < max;++i)
		{
			for (int j = 0; j < max; j++)
			{
				if (j == queens[i])
					cout << "Q ";
				else
					cout << "0 ";
			}
			cout << endl;
		}
	}
	int isValid(int n) {	//判断第n个皇后放上去之后是否合法，即是否无冲突
		for (int i = 0;i < n;++i) {
			if (queens[i] == queens[n])
				return 0;
			if (abs(queens[i] - queens[n]) == (n - i))
				return 0;
		}
		return 1;
	}
	void placequeen(int i) {
		for (int j = 0;j < max;++j) {
			if (i == max) {
				sum++;
				cout << "第" << sum << "组解：" << endl;
				printOut();
				return;
			}
			queens[i] = j;
			if (isValid(i))
				placequeen(i + 1);
		}
	}

};
int main()
{
	QueenPuzzle queen;
	queen.placequeen(0);
	cout << "共" << sum << "组解" << endl;
	return 0;
}
