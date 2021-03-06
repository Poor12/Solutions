#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;


string str;

int judge(int x) {
	int v = int(sqrt(x) + 1e-8);
	if (v*v == x) return v;
	else return 0;
}

int main() {

	int N;
	scanf("%d\n", &N);

	for (int i = 1;i <= N;i++) {
		getline(cin, str);//gets,getline将\n回收，scanf("%s",str)不回收
		int x = judge(str.length());
		if (x) {
			for (int i = 0;i < x;i++)
				for (int j = 0;j < x;j++)
					putchar(str[i + x * j]);
			puts("");
		}
		else puts("INVALID");//puts结尾后输出一个\n
	}

	return 0;
}