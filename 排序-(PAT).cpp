#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stu {
	string id;
	int score;
	int location;
	int finalrank;
	int localrank;
};
bool cmp(stu &s1,stu &s2) {
	return s1.score == s2.score ? s1.id < s2.id : s1.score > s2.score;
}
bool cmp1(stu &s1, stu &s2) {
	return s1.location == s2.location?s1.score>s2.score:s1.location<s2.location;
}
int main() {
	int n,m;
	int num = 0;
	stu stu1;
	vector<stu> stus;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> m;
		stu1.location = i+1;
		for (int j = 0;j < m;++j) {
			cin >> stu1.id >> stu1.score;
			stus.push_back(stu1);
			num++;
		}
		sort(stus.begin() + num - m, stus.begin() + num, cmp);
		for (int p = 1; p < m; p++) {
			if (stus[num - m + p].score == stus[num - m + p - 1].score)
				stus[num - m + p].localrank = stus[num - m + p - 1].localrank;
			else stus[num - m + p].localrank = p + 1;
		}
	}
	cout << num << endl;
	sort(stus.begin(), stus.end(), cmp);
	int rank = 1;
	for (int i = 0; i < num; i++) {
		if (i > 0 && stus[i].score!= stus[i - 1].score) {
			rank = i + 1;
		}
	    cout<<stus[i].id<<' '<<rank<<' '<<stus[i].location<<' '<<stus[i].localrank<<endl;
	}
	return 0;
}