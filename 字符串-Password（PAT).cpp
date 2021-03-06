#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct info {
	string username;
	string password;
};
int main() {
	int n;
	cin >> n;
	info Info;
	vector<info> ortable;
	vector<info> nexttable;
	int count = 0;
	for (int i = 0;i < n;i++) {
		cin >> Info.username >> Info.password;
		ortable.push_back(Info);
	}
	bool ex = false;
	for (auto elem : ortable) {
		for (auto it = elem.password.begin();it != elem.password.end();++it) {
			if (*it == '1' || *it == '0' || *it == 'l' || *it == 'O') {
				if (!ex)
					ex = true;
				if (*it == '1')
					*it = '@';
				if (*it == '0')
					*it = '%';
				if (*it == 'l')
					*it = 'L';
				if (*it == 'O')
					*it = 'o';
			}
		}
		if (ex) {
			count++;
			ex = false;
			nexttable.push_back(elem);
		}
	}
	if (count) {
		cout << count << endl;
		for (auto &elem : nexttable)
			cout << elem.username << ' ' << elem.password << endl;
	}
	else if (!count&&n > 1)
		cout << "There are " << n << " accounts and no account is modified";
	else
		cout << "There is 1 account and no account is modified";
	return 0;

}