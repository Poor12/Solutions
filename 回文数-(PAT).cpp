#include <iostream>
#include <string>
using namespace std;
bool ispalin(string k) {
	for (int i = 0, j = k.size() - 1;i < k.size(), j >= 0;++i, --j) {
		if (k[i] != k[j])
			return false;
	}
	return true;
}
string add(string k) {
	string kk = "", sum = "", sum1 = "";
	for (auto it = k.rbegin();it != k.rend();it++) {
		kk += *it;
	}
	bool flag = false;int add;
	for (int i = 0;i < k.size();++i) {
		int a = k[i] - '0';
		int b = kk[i] - '0';
		if (flag)
			add = a + b + 1;
		else
			add = a + b;
		if (add >= 10)
			flag = true;
		else flag = false;
		sum += add % 10 + 48;
	}
	if (flag)
		sum += '1';
	for (auto it = sum.rbegin();it != sum.rend();it++) {
		sum1 += *it;
	}

	return sum1;
}
int main() {
	string n;
	int m;
	cin >> n >> m;
	int count = 0;
	while (!ispalin(n) && count < m) {
		n = add(n);
		count++;
	}
	for (int i = 0;i < n.size();++i)
	{
		cout << n[i];
	}
	cout << endl;
	cout << count;
}