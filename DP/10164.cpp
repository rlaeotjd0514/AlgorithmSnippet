#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    vector<vector<int>> dp;
    cin >> n >> m;
    dp.resize(n + 1);
    dp[0].resize(m + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].resize(m + 1);
    }
    cin >> k;
    int dx, dy;
    if (k == 0) {
        dx = n;
        dy = m;
    }
    else {
        dx = (k - 1) / m + 1;
        dy = (k - 1) % m + 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= dx; i++) {
        for (int j = 1; j <= dy; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    for (int i = dx; i <= n; i++) {
        for (int j = dy; j <= m; j++) {
            if (i == dx && j == dy) continue;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[n][m];
    return 0;
}
