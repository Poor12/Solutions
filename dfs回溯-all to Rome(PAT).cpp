#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <string>
using namespace std;
void dfs(int start, int index, int end);
vector<bool> visited;
vector<vector<int>> graph;
map<string, int> city;
vector<int> cityhap;
vector<int> path, resultpath;
int n, k, happiness, costtime = 0, sumhappy, averhappy, resulttime = INT_MAX;
string start;
int Count;
int resultsum, resultaverage;
string acity;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k >> start;
	visited.resize(n, 0);
	cityhap.resize(n);
	graph.resize(n, vector<int>(n, 0));
	city[start] = 0;cityhap[city[start]] = 0;
	for (int i = 1;i < n;++i) {
		cin >> acity >> happiness;
		city[acity] = i;
		cityhap[i] = happiness;
	}
	string m, n;int dist;
	for (int i = 0;i < k;++i) {
		cin >> m >> n >> dist;
		graph[city[m]][city[n]] = dist;
		graph[city[n]][city[m]] = dist;
	}
	dfs(0, 0, city["ROM"]);
	cout << Count << ' ' << resulttime << ' ' << resultsum << ' ' << resultaverage << endl;
	for (int i = 0;i < resultpath.size();i++) {
		string key;
		for (auto it = city.begin();it != city.end();++it) {
			if (it->second == resultpath[i])
				key = it->first;
		}
		cout << (i == 0 ? "" : "->") << key;
	}
}

void dfs(int start, int index, int end) {
	visited[index] = 1;
	path.push_back(index);
	costtime += graph[start][index];

	if (index == end) {
		sumhappy = 0;averhappy = 0;
		for (int i = 0;i < path.size();++i) {
			sumhappy += cityhap[path[i]];
		}
		averhappy = sumhappy / (path.size() - 1);
		if (costtime != resulttime) {
			if (costtime < resulttime) {
				Count++;
				resulttime = costtime;
				resultpath = path;
				resultsum = sumhappy;
				resultaverage = averhappy;
			}
		}
		else if (sumhappy != resultsum) {
			Count++;
			if (sumhappy > resultsum) {
				resultpath = path;
				resultsum = sumhappy;
				resultaverage = averhappy;
			}
		}
		else if (averhappy > resultaverage) {
			Count++;
			resultpath = path;
			resultaverage = averhappy;
		}
	}
	else
	{
		for (int i = 1;i < n;++i) {
			if (visited[i] == 0 && graph[index][i] != 0) {
				dfs(index, i, end);
			}
		}
	}
	visited[index] = 0;
	path.pop_back();
	costtime -= graph[start][index];
}
