#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> coins;
        vector<vector<int>> dp;
        coins.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> coins[i];
        }
        int m;
        cin >> m;
        dp.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            dp[i].resize(m + 1);
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < coins[i]; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = coins[i]; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}