#include <iostream>
#include <vector>
#include <algorithm>
//0/1 knapsack prob
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    vector<int> cost;
    vector<vector<int>> dp;
    arr.resize(n + 1);
    cost.resize(n + 1);
    dp.resize(n + 1);
    int lim = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        lim += arr[i];
    }
    m = lim - m;
    for (int i = 0; i <= n; i++) {
        dp[i].resize(m + 1);
    }
    int cs = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        cs += cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                t = cost[i];
                cost[i] = cost[j];
                cost[j] = t;
            }
        }
    }

    for (int i = 1; i <= n; i++) {//arr
        for (int j = arr[i]; j <= m; j++) {
            dp[i][j] = max(cost[i], dp[i - 1][j - arr[i]] + cost[i]);
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << cs - dp[n][m];
    return 0;
}
