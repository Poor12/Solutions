#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    //ifstream cin("case.txt");
    while (cin >> n)
    {
        cin.get();
        vector<string> v(n);
        int minSize = 0;
        for (int i = 0; i < n; i++)
        {
            getline(cin, v[i]);
            reverse(v[i].begin(), v[i].end());
            minSize = v[0].size();
            if (v[i].size() < minSize)
            {
                minSize = v[i].size();
            }
        }
        bool equal = true;
        string rlt;
 
        for (int j = 0; j < minSize; j++)
        {
            for (int i = 0; i < n-1; i++)
            {
                if (v[i][j] != v[i + 1][j])
                {
                    equal = false;
                    break;
                }
            }
            if (equal == false)
                break;
            rlt += v[0][j];
        }
        reverse(rlt.begin(), rlt.end());
        if (rlt == "")
            cout << "nai" << endl;
        else
            cout << rlt << endl;
    }
    system("pause");
}