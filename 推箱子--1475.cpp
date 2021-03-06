#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int MAX = 20000;
char map[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
char walks[4] = { 'e','w','s','n' };//行走
char pushes[4] = { 'E','W','S','N' };//推箱子
bool visPerson[MAX][MAX];
bool visBox[MAX][MAX];//箱子被推行前进的路径
string path;
int R, C;
struct NODE
{
	int br, bc;
	int pr, pc;
	string ans;//移动序列
};
bool InMap(int r, int c)
{
	return (r >= 1 && r <= R && c >= 1 && c <= C);
}
bool Bfs2(int sr, int sc, int er, int ec, int br, int bc, string &ans)//(sr,sc)行走到(er,ec),(er,ec)必须与（br,bc)
{
	memset(visPerson, false, sizeof(visPerson));//初始化
	queue<NODE> q;//q用于存储状态
	NODE node, tmpNode;//node:q队首，tmpNode:新的扩展状态
	node.pr = sr;node.pc = sc;
	node.ans = "";
	q.push(node);
	visPerson[br][bc] = true;//箱子当前位置
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node.pr == er && node.pc == ec)
		{
			ans = node.ans;return 1;
		}
		if (visPerson[node.pr][node.pc] == 1) continue;
		visPerson[node.pr][node.pc] = 1;
		for (int i = 0;i < 4;++i)
		{
			int nr = node.pr + dir[i][0];
			int nc = node.pc + dir[i][1];
			if (InMap(nr,nc) && !visPerson[nr][nc] && map[nr][nc] != '#')
			{
				tmpNode.pr = nr;
				tmpNode.pc = nc;
				tmpNode.ans = node.ans + walks[i];
				q.push(tmpNode);
			}
		}
	}
	return false;
}
bool Bfs1(int sr, int sc, int br, int bc)//你的位置（sr，sc），箱子的位置（br，bc）
{
	memset(visBox, false, sizeof(visBox));
	queue<NODE> q;
	NODE node, tmpNode;
	node.pr = sr;node.pc = sc;//你的位置
	node.br = br;node.bc = bc;
	node.ans = "";
	q.push(node);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (visBox[node.br][node.bc]) continue;
		visBox[node.br][node.bc] = 1;
		if (map[node.br][node.bc] == 'T')
		{
			path = node.ans;
			return 1;
		}
		for (int i = 0;i < 4;++i)//箱子在方向i的相邻方格（nextr，nextc），其反方向的相邻方格（backr，backc），箱子可以被推到（nextr，nextc）当且仅当你可以走到（backr，backc）
		{
			int nextr = node.br + dir[i][0];
			int nextc = node.bc + dir[i][1];
			int backr = node.br - dir[i][0];
			int backc = node.bc - dir[i][1];
			string ans = "";
			if (InMap(backr, backc) && InMap(nextr, nextc) && map[nextr][nextc] != '#'&&map[backr][backc] != '#' && !visBox[nextr][nextc])
			{
				if (Bfs2(node.pr, node.pc, backr, backc, node.br, node.bc, ans))
				{
					tmpNode.pr = node.br;//你的位置跑到箱子处
					tmpNode.pc = node.bc;
					tmpNode.br = nextr;
					tmpNode.bc = nextc;
					tmpNode.ans = node.ans + ans + pushes[i];
					q.push(tmpNode);
				}
			}
		}
	}
	return false;
}
int main()
{
	int sr, sc;//你的起始位置
	int br, bc;//箱子的位置
	int cases = 1;//测试用例的数目
	while (scanf("%d%d", &R, &C) && R&&C)
	{
		for (int r=1;r<=R; r++)
		{
			for (int c = 1;c <= C;c++)
			{
				cin >> map[r][c];
				if (map[r][c] == 'S') {
					sr = r;
					sc = c;
				}
				else if (map[r][c] == 'B')
				{
					br = r;
					bc = c;
				}
			}
			path = "";
			(Bfs1(sr, sc, br, bc)) ? cout << "Maze #" << cases << endl << path << endl : cout << "Maze #" << cases << endl << "impossible." << endl;
			cases++;
			cout << endl;
		}
	}
}