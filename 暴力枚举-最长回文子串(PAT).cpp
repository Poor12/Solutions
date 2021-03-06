#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int sum1, sum2, ans = 0;
    for(int i = 0; i < s.length(); i++) {
        sum1 = sum2 = 0;
        int j = i + 1;
        while(i - sum1 >= 0 && i + sum1 < s.length() && s[i-sum1] == s[i+sum1]) sum1++;//长度为奇数
        while(i - sum2 >= 0 && j + sum2 < s.length() && s[i-sum2] == s[j+sum2]) sum2++;//长度为偶数
        ans = max(ans, max(2*sum1 - 1, 2 * sum2));
    }
    cout << ans;
    return 0;
}