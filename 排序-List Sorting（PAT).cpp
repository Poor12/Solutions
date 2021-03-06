#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
struct student {
	string id;
	string name;
	int grade;
};

bool compare1(student &stu1, student &stu2) {
	return stu1.id < stu2.id;
}

bool compare2(student &stu1, student &stu2) {
	return stu1.name!=stu2.name ?stu1.name < stu2.name:stu1.id<stu2.id;
}

bool compare3(student &stu1, student &stu2) {
	return stu1.grade != stu2.grade? stu1.grade < stu2.grade: stu1.id < stu2.id;
}
int main() {
	
	int num, col;
	vector<student> vec;
	cin >> num >> col;
	student stu;
	for (int i = 0;i < num;i++)
	{
		cin >> stu.id >> stu.name >> stu.grade;
		vec.push_back(stu);
	}
	switch (col)
	{
	case 1:sort(vec.begin(), vec.end(), compare1);break;
	case 2:sort(vec.begin(), vec.end(), compare2);break;
	case 3:	sort(vec.begin(), vec.end(), compare3);break;
	}
	
	for (auto &elem : vec) {
		cout << elem.id << " " << elem.name << " " << elem.grade<<endl;
	}
}