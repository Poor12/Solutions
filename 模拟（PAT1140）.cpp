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
	string s;
	int n, j;
	cin >> s >> n;
	for (int cnt = 1; cnt < n; cnt++) {
		string t;
		for (int i = 0; i < s.length(); i = j) {
			for (j = i; j < s.length() && s[j] == s[i]; j++);
			t += to_string((s[i] - '0') * 10 + j - i);
		}
		s = t;
	}
	cout << s;
	return 0;
}