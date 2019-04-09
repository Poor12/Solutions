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
char num[20100];
int ex;
char sign;
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	char t;
	scanf("%[+-]", &sign);
	scanf("%[123456789]", num);
	scanf("%c", &t);//.
	scanf("%[0123456789]", num + 1);
	scanf("%c", &t);//E
	scanf("%d", &ex);
	//cout << num;
	if (sign == '-')
		printf("%c", sign);
	if (ex == 0)
	{
		printf("%c.", num[0]);
		printf("%s", num + 1);
	}
	else if (ex > 0)
	{
		int len = strlen(num);
		if (ex >= len - 1)
		{
			printf("%s", num);
			for (int i = len - 1;i < ex;++i)
				printf("0");
		}
		else
		{
			for (int i = 0;i < ex + 1;++i)
				printf("%c", num[i]);
			printf(".");
			for (int i = ex + 1;i < len;++i)
				printf("%c", num[i]);
		}
	}
	else
	{
		ex = -ex;
		printf("0.");
		for (int i = 0;i < ex - 1;++i)
			printf("0");
		printf("%s", num);
	}
	return 0;
}