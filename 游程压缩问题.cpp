#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//游程压缩问题

int main()
{
	cout << "请输入01序列（以#结束）:";
	queue<int> picture;
	char a;
	float pow = 0;
	float oriSize;
	do {
		cin >> a;
		if (a != '#')
			picture.push(a);
	} while (a!='#');
	char pic = picture.front();
	picture.pop();
	int size = picture.size() + 1;
	oriSize = size;
	cout << "编码后：";
	while (!picture.empty())
	{
		if (pic == picture.front()) {
			picture.pop();
		}
		else
		{
			cout << size - picture.size();
			pow++;
			size = picture.size();
			pic = picture.front();
			picture.pop();
		}
	}
	cout << size << endl;
	pow++;
	cout << "压缩率为:" << pow / oriSize << endl;
	return 0;
}
