#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    string s1;
    string s2;
    cin >> s2 >> s1;
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> dp;
    dp.resize(l1 + 1);
    dp[0].resize(l2 + 1);
    int mi = -1, mj = -1;
    int mx = 0;
    for (int i = 1; i <= l1; i++) {
        dp[i].resize(l2 + 1);
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
                if (mx < dp[i][j]) {
                    mx = dp[i][j];
                    mi = i;
                    mj = j;
                }
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << mx << "\n";
    stack<char> dap;
    for (int i = mi; i >= 1; i--) {
        if (mj == 1) break;
        int current = dp[i][mj];
        for (int j = mj; j >= 1; j--) {
            if (dp[i][j] != dp[i][j - 1] && dp[i][j] != dp[i - 1][j] && dp[i][j] == current) {
                dap.push(s2[j - 1]);
                mj = j;
                break;
            }
        }
    }

    while (!dap.empty()) {
        cout << dap.top();
        dap.pop();
    }

    return 0;
}