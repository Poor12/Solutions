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
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
using namespace std;

int main() {
	freopen("D:\\data.txt", "r", stdin);
	int len, k = 0, num = 0;
	char a[15], s[30][5], c[10][5] = { "Shi","Bai","Qian","Wan","Yi" };
	char b[15][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	cin >> a;
	len = strlen(a);
	if (a[0] == '-')
	{
		cout << "Fu ";
		k++;
	}
	if (len == 1 && a[0] == '0') cout << b[0];
	bool flag = false;
	for (int i = k;i < len;++i)
	{
		if (a[i] == '0'&&len - i - 1 != 4) flag = true;////当前位为0且不是个位，低一位不为0且不为千位(千位的高一位为0时不用读零,如808000)，输出“ling”
		if (a[i] != '0') {
			if (flag == true) {                                                       //没有i+1<len 这个条件的话输入10会输出"yi Shi ling"
				strcpy(s[num++], b[0]);
				flag = false;
			}
			strcpy(s[num++], b[a[i] - '0']);                                          //当前位不为0时
			if ((len - i) % 4 == 2) strcpy(s[num++], c[0]);                                //十，输出"Shi"
			if ((len - i) % 4 == 3) strcpy(s[num++], c[1]);                                //百，输出"Bai"
			if ((len - i) % 4 == 0) strcpy(s[num++], c[2]);                                //千，输出"Qian"
		}
		if (len - i == 5) {
			if (a[i] == '0'&&a[i - 1] == '0'&&a[i - 2] == '0'&&a[i - 3] == '0');                  //万，输出"Wan"（没有出现万这个小节位数全为0时，如800000008）
			else strcpy(s[num++], c[3]);
		}
		if (len - i == 9) strcpy(s[num++], c[4]);
	}
	for (int i = 0;i < num;i++) {
		cout << s[i];
		if (i != num - 1)
			cout << " ";
	}
	return 0;
}
