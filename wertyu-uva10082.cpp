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

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int i, c;
int main()
{
	while ((c = getchar()) != EOF)
	{
		for (i = 1;s[i] && s[i] != c;++i);
		if (s[i])
			putchar(s[i - 1]);
		else
			putchar(c);
	}
	return 0;
}

