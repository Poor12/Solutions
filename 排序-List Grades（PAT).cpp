#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct stu
{
	string name;
	string ID;
	int score;
};
bool Compare(stu &i, stu &j) {
	return i.score > j.score;
}
int main() {
	int num;
	cin >> num;
	vector<stu> students(num);
	for (int i = 0;i < num;i++)
	{
		cin >> students[i].name >> students[i].ID >> students[i].score;
	}
	int gradeMin, gradeMax;
	cin >> gradeMin >> gradeMax;
	sort(students.begin(), students.end(), Compare);
	bool count = false;
	for (int i = 0; i < num; i++)
	{
		if (students[i].score >= gradeMin && students[i].score <= gradeMax)
		{
			cout << students[i].name << " " << students[i].ID << endl;
			count = true;
		}
	}
	if (!count) {
		cout << "NONE";
	}
	return 0;
}