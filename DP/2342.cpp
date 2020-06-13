#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[100001][5][5];

int main()
{
    int im = -1;
    vector<int> arr;
    int value[5][5] = {
        { 0, 2, 2, 2, 2 },
        { 2, 1, 3, 4, 3 },
        { 2, 3, 1, 3, 4 },
        { 2, 4, 3, 1, 3 },
        { 2, 3, 4, 3, 1 },
    };
    while (im != 0) {
        cin >> im;
        arr.push_back(im);
    }
    int n = arr.size();
    memset(dp, 999999, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i < n; i++) {
        int now = arr[i - 1];
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (dp[i][j][now] > dp[i - 1][j][k] + value[now][k]) {
                    dp[i][j][now] = dp[i - 1][j][k] + value[now][k];
                }
                if (dp[i][now][k] > dp[i - 1][j][k] + value[j][now]) {
                    dp[i][now][k] = dp[i - 1][j][k] + value[j][now];
                }
            }
        }
    }
    int mn = 999999;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            if (dp[n - 1][i][j] < mn && dp[n - 1][i][j] != 0) mn = dp[n - 1][i][j];
        }
    }
    /*for (int k = 0; k < n; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (dp[k][i][j] == 1061109567) {
                    cout << "-1 ";
                    continue;
                }
                cout << dp[k][i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }*/
    cout << mn;
    return 0;
}

