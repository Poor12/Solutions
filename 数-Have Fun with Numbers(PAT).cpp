#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;
int main() {
	multiset<int> num;
	multiset<int> num2;
	vector<int> num3;
	vector<int> num4;
	string s;
	cin >> s;
	//long long s2 = s * 2;
	for (int i = 0;i < s.size();++i) {
		num.insert(s[i]-'0');
		num3.push_back(s[i] - '0');
	}
	bool flag = false;
	int k;
	for (int i = s.size() - 1;i >= 0;i--) {
		if(flag)
			 k = num3[i] * 2+1;
		else k = k = num3[i] * 2;
		if (k >= 10) {
			flag = true;
			num2.insert(k % 10);
			num4.push_back(k % 10);
		}
		else { flag = false; num2.insert(k);num4.push_back(k );
		}
	}
    if (flag) {
		num2.insert(1);
		num4.push_back(1);
	}
	if (num == num2) {
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	for(auto it=num4.rbegin();it!=num4.rend();it++){
		cout << *it;
	}

}