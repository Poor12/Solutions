#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//迷宫问题--暴力回溯,即深度优先搜索

class Crossing	//定义路口
{
public:
	int turn1;//左转、右转、直走
	int turn2;
	int turn3;
	Crossing(int turn1, int turn2, int turn3)
	{
		Crossing::turn1 = turn1;
		Crossing::turn2 = turn2;
		Crossing::turn3 = turn3;
	}
};
class Maze
{
public:
	int exit;//出口编码
	vector<Crossing> crossings;//路口集合
	vector<int> result;
	Maze(int the_exit, vector<Crossing> the_crossings) {
		exit = the_exit;
		crossings = the_crossings;
	}
	int findExit(int entrance) {
		if (entrance > 0) {
			if (entrance == Maze::exit) {
				result.push_back(entrance);
				return 1;
			}
			if (findExit(crossings[entrance].turn1)) {
				result.push_back(entrance);
				return 1;
			}
			if (findExit(crossings[entrance].turn2)) {
				result.push_back(entrance);
				return 1;
			}
			if (findExit(crossings[entrance].turn3)) {
				result.push_back(entrance);
				return 1;
			}
		}
		return 0;
	}
	void getResult() {
		findExit(1);
		for (int i = result.size();i > 0;--i)
			cout << result[i - 1] << "->";
		cout << "exit" << endl;
	}
};

int main()
{
	Crossing c1(2, 0, 0);
	Crossing c2(4, 0, 0);
	Crossing c3(0, 0, 0);
	Crossing c4(3, 5, 0);
	Crossing c5(6, 0, 0);
	Crossing c6(7, 0, 0);
	Crossing c7(8, 9, 0);
	Crossing c8(0, 0, 0);
	Crossing c9(10, 0, 0);
	Crossing c0(0, 0, 0);//死路
	vector<Crossing> crossings;
	crossings.push_back(c0);
	crossings.push_back(c1);
	crossings.push_back(c2);
	crossings.push_back(c3);
	crossings.push_back(c4);
	crossings.push_back(c5);
	crossings.push_back(c6);
	crossings.push_back(c7);
	crossings.push_back(c8);
	crossings.push_back(c9);
	Maze newMaze(10, crossings);
	newMaze.getResult();
	return 0;
}