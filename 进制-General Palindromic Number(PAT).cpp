#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> ch;
void transform(int n, int b) {
    if (n == 0) {
		ch.push_back(n);
	}
	while (n != 0) {
		ch.push_back(n%b);
		n = n / b;
	}

}
int main() {
	int n, m;
	cin >> n >> m;
	transform(n, m);
	for (int i = 0, j = ch.size() - 1;i < ch.size(), j >= 0;++i, --j) {
		if (ch[i] != ch[j]) {
			cout << "No"<<endl;
            for (auto it = ch.rbegin();it != ch.rend();it++) {
		        cout << *it;
		        if (it != ch.rend() - 1)
			    cout << ' ';
	        }
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (auto it = ch.rbegin();it != ch.rend();it++) {
		cout << *it;
		if (it != ch.rend() - 1)
			cout << ' ';
	}
	return 0;

}