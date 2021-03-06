#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
 
int main()
{
    int n, course;
    cin >> n >> course;
    map<string, vector<int> > mp;
    int classNum, stuNum;
    string name;
    for (int i = 0; i < course; i++)
    {
        cin >> classNum >> stuNum;
        for (int j = 0; j < stuNum; j++)
        {
            cin >> name;
            mp[name].push_back(classNum);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cout << name << " ";
        cout << mp[name].size();
        sort(mp[name].begin(), mp[name].end());
        for (int j = 0; j < mp[name].size(); j++)
        {
            cout << " " << mp[name][j];
        }
        cout << endl;
    }
    system("pause");
}