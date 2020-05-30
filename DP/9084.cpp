#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n;
        vector<int> coin;
        vector<vector<int>> dp;
        coin.resize(n + 1);
        dp.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> coin[i];
        }
        cin >> m;
        for (int i = 0; i <= n; i++) {
            dp[i].resize(10001);
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < coin[i]; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = coin[i]; j <= m; j++) {
                dp[i][j] = dp[i][j - coin[i]] + dp[i - 1][j];
            }
        }
        /*for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/
        cout << dp[n][m] << "\n";
    }
    return 0;
}