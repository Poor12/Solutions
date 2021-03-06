链接：https://www.nowcoder.com/questionTerminal/0171de2cf94a43d690c336a363a41693
来源：牛客网

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    // 读入数据
    int N, M, L; cin >> N >> M;
    vector<int> fc(M+1);
    for(int i=1; i<=M; i++) cin >> fc[i];
    cin >> L; vector<int> stripe(L+1);
    for(int i=1; i<=L; i++) cin >> stripe[i];
 
    // 动态规划处理
    vector<vector<int> > dp(M+1, vector<int>(L+1, 0));
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=L; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]);
            if(stripe[j] == fc[i]) {
                dp[i][j]++;
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[M][L] << endl;
    return 0;
}