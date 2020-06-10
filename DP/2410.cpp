#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coin;
    vector<vector<int>> dp;
    int ct = 1;
    while (ct <= n) {
        coin.push_back(ct);
        ct *= 2;
    }
    int cs = coin.size();
    dp.resize(cs);
    for (int i = 0; i < cs; i++) {
        dp[i].resize(n + 1);
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < cs; i++) {
        for (int j = 0; j < coin[i]; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = coin[i]; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]];
            dp[i][j] %= 1000000000;
        }
    }

    cout << dp[cs - 1][n];

    return 0;
}
