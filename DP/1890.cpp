#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<vector<int>> arr;
    vector<vector<unsigned long long>>dp;
    cin >> n;
    arr.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i].resize(n + 1);
        dp[i].resize(n + 1);
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k < i; k++) {
                if (k == arr[i - k][j]) {
                    dp[i][j] += dp[i - k][j];
                }
            }
            for (int k = 1; k < j; k++) {
                if (k == arr[i][j - k]) {
                    dp[i][j] += dp[i][j - k];
                }
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[n][n];
    return 0;
}