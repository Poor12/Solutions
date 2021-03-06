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
#include <queue>
using namespace std;

//getchar()读取一个字符
//fgets(buf,maxn,fin),读取完整的一行，其中buf的声明为char buf[maxn] fgets(buf, 20, stdin);

int main()
{
	int c, q = 1;
	while ((c = getchar()) != EOF)
	{
		if (c == '"')
		{
			printf("%s", q ? "``" : "''");
			q = !q;
		}
		else
			printf("%c", c);
	}
	return 0;
}
