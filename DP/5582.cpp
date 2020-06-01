#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr, dp, dp2;
    arr.resize(n + 1);
    dp.resize(n + 1);
    dp2.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i].resize(m + 1);
        dp[i].resize(m + 2);
        dp2[i].resize(m + 2);
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        dp[1][i] = dp[1][i - 1] + arr[1][i];
        dp2[1][i] = dp2[1][i - 1] + arr[1][i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m + 1; j++) {
            dp[i][j] = (-2147483647 - 1);
            dp2[i][j] = (-2147483647 - 1);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int p1 = max({ dp[i][j - 1], dp[i - 1][j], dp2[i - 1][j] });
            dp[i][j] = max(dp[i][j], p1 + arr[i][j]);
        }
        for (int j = m; j >= 1; j--) {
            int p1 = max({ dp2[i][j + 1], dp2[i - 1][j], dp[i - 1][j] });
            dp2[i][j] = max(dp2[i][j], p1 + arr[i][j]);
        }
    }

    cout << (dp[n][m] > dp2[n][m] ? dp[n][m] : dp2[n][m]);

    return 0;
}