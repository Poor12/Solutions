#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

int main() {
	freopen("D:\\data.txt", "r", stdin);
	string str;
	int a;
	cin >> str >> a;
	str = str.substr(0, a);
	int l,maxlength=0;
	for (l=1;l<str.length();++l)
	{
		string str1 = str.substr(0, l);
		string str2 = str.substr(str.length() - l, str.length());
		if (str1 == str2 && l > maxlength)
			maxlength = l;
	}
	cout << maxlength;
	
	return 0;
	
}